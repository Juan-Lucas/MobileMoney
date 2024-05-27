#include "dataTypes.h"

// Fonction permettant d'obtenir le solde dans une devise sp�cifique
double getSolde(Devise devise);

// Fonction permettant de v�rifier le solde dans une devise sp�cifique
double verifierSolde(Devise Devise);

// Fonction permettant de calculer le nouveau solde apr�s un d�p�t dans une devise sp�cifique
double depotMontant(Devise devise, double montantDepot);

// Fonction permettant d'effectuer une op�ration de d�p�t dans une devise sp�cifique
void effectuerDepot(Devise devise, double montantDepot);

// Fonction permettant de calculer le nouveau solde apr�s un retrait dans une devise sp�cifique
double retraitMontant(Devise devise, double montantRetrait);

// Fonction permettant d'effectuer une op�ration de retrait dans une devise sp�cifique
void effectuerRetrait(Devise devise, double montantRetrait);
