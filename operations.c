#include <stdio.h>
#include "dataTypes.h"

// Définir le montant minimum du dépôt en USD
const double MIN_DEPOT_USD = 5.0;

// Définir le montant minimum du dépôt en Francs Congolais (FC)
const double MIN_DEPOT_FC = 5000.0;

// Tableau contenant les soldes pour chaque devise
double soldes[] = {0.0, 0.0};

// Fonction permettant d'obtenir le solde dans une devise spécifique

double getSolde(Devise devise) {
    // S'assurer que la devise est comprise dans les limites du tableau des soldes.
    int nombreDevises = sizeof(soldes) / sizeof(soldes[0]);
    if (devise >= 0 && devise < nombreDevises) {
        return soldes[devise];
    }
    return 0.0; // Renvoie une valeur par défaut si la devise n'est pas trouvée
}

// Fonction permettant de vérifier le solde dans une devise spécifique

double verifierSolde(Devise devise)
{
    return getSolde(devise);// Retourne le solde de la devise donnée.

}

// Fonction permettant de calculer le nouveau solde après un dépôt dans une devise spécifique

double depotMontant(Devise devise, double montantDepot)
{
    soldes[devise] += montantDepot;
    return verifierSolde(devise);
}

// Fonction permettant d'effectuer une opération de dépôt dans une devise spécifique

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

// Fonction permettant de calculer le nouveau solde après un retrait dans une devise spécifique

double retraitMontant(Devise devise, double montantRetrait)
{
    soldes[devise] -= montantRetrait;
    return verifierSolde(devise);
}

// Fonction permettant d'effectuer une opération de retrait dans une devise spécifique

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


