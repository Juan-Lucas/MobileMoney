#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include "constants.h"

#include "dataStores.h"

int taille = 0;

// Fonction permettant d'enregistrer toutes les transactions effectuees

struct Transaction* enregistrerTransaction(struct Transaction* transactions, int* taille,struct Transaction n_transaction)
{
    (*taille)++;

    transactions = realloc(transactions, (*taille)* sizeof(struct Transaction));

    transactions[(*taille) - 1] = n_transaction;

    return transactions;
}

// Fonction permettant d'afficher toutes les transactions effectuees

void afficherTransactions()
{
    for (int i = 0; i < taille; i++) {
        printf("Transaction %d:\n", i + 1);
        printf("Date: %d/%d/%d\n", transactions[i].date.jour, transactions[i].date.mois, transactions[i].date.annee);
        printf("Montant: %.2f\n", transactions[i].montant);
        printf("Devise: %s\n", transactions[i].devise == USD ? "USD" : "FC");
        printf("Type: %s\n", transactions[i].type == DEPOT ? "DEPOT" : "RETRAIT");
        printf("\n");
    }
}


// Fonction permettant d'obtenir le solde dans une devise sp�cifique

double getSolde(Devise devise) {
    // S'assurer que la devise est comprise dans les limites du tableau des soldes.
    int nombreDevises = sizeof(soldes) / sizeof(soldes[0]);
    if (devise >= 0 && devise < nombreDevises) {
        return soldes[devise];
    }
    return 0.0; // Renvoie une valeur par d�faut si la devise n'est pas trouv�e
}

// Fonction permettant de v�rifier le solde dans une devise sp�cifique

double verifierSolde(Devise devise)
{
    return getSolde(devise);// Retourne le solde de la devise donn�e.

}

// Fonction permettant de calculer le nouveau solde apr�s un d�p�t dans une devise sp�cifique

double depotMontant(Devise devise, double montantDepot)
{
    // Get the current time
    time_t now = time(NULL);

    struct tm *local = localtime(&now);

    struct Transaction transaction;

    transaction.date.jour = local->tm_mday;
    transaction.date.mois = local->tm_mon + 1;
    transaction.date.annee = local->tm_year + 1900;
    transaction.montant = montantDepot;
    transaction.devise = devise;
    transaction.type= DEPOT;

    transactions = enregistrerTransaction(transactions, &taille, transaction);

    soldes[devise] += montantDepot;

    return verifierSolde(devise);
}

// Fonction permettant d'effectuer une op�ration de d�p�t dans une devise sp�cifique

void effectuerDepot(Devise devise, double montantDepot)
{
    double minDepot = (devise == USD) ? MIN_DEPOT_USD : MIN_DEPOT_FC;
    char *deviseCode = (devise == USD) ? "USD" : "FC";

    if (montantDepot > minDepot)
    {
        printf("\nLe depot du montant %.2f %s a ete effectue avec succes. Votre nouveau solde est de %.2f %s\n\n",
               montantDepot, deviseCode, depotMontant(devise, montantDepot), deviseCode);
    }
    else
    {
        printf("\nLe montant %.2f %s est insuffisant pour effectuer cette operation.\n\n",
               montantDepot, deviseCode);
    }
}

// Fonction permettant de calculer le nouveau solde apr�s un retrait dans une devise sp�cifique

double retraitMontant(Devise devise, double montantRetrait)
{
        // Get the current time
    time_t now = time(NULL);

    struct tm *local = localtime(&now);

    struct Transaction transaction;

    transaction.date.jour = local->tm_mday;
    transaction.date.mois = local->tm_mon + 1;
    transaction.date.annee = local->tm_year + 1900;
    transaction.montant = montantRetrait;
    transaction.devise = devise;
    transaction.type= RETRAIT;

    transactions = enregistrerTransaction(transactions, &taille, transaction);

    soldes[devise] -= montantRetrait;

    return verifierSolde(devise);
}

// Fonction permettant d'effectuer une op�ration de retrait dans une devise sp�cifique

void effectuerRetrait(Devise devise, double montantRetrait)
{
    double nouveauSolde = retraitMontant(devise, montantRetrait);
    char *deviseCode = (devise == USD) ? "USD" : "FC";

    if (montantRetrait < verifierSolde(devise) && verifierSolde(devise) > 0) {
        printf("\nLe retrait du montant %.2f %s a ete effectue avec succes. Votre nouveau solde est de %.2f %s\n\n",
                montantRetrait, deviseCode, nouveauSolde, deviseCode);
    } else {
        printf("\nVotre solde est insuffisant pour effectuer cette operation.\n\n");
    }
}



