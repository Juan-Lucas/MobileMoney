#include <stdio.h>
#include "dataTypes.h"

// D�finir le montant minimum du d�p�t en USD
const double MIN_DEPOT_USD = 5.0;

// D�finir le montant minimum du d�p�t en Francs Congolais (FC)
const double MIN_DEPOT_FC = 5000.0;

// Tableau contenant les soldes pour chaque devise
double soldes[] = {0.0, 0.0};

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


