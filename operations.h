// Constantes représentant les types de devises
typedef enum Devise { USD, FC }Devise;

// Fonction permettant d'obtenir le solde dans une devise spécifique
double getSolde(Devise devise);

// Fonction permettant de vérifier le solde dans une devise spécifique
double verifierSolde(Devise Devise);

// Fonction permettant de calculer le nouveau solde après un dépôt dans une devise spécifique
double depotMontant(Devise devise, double montantDepot);

// Fonction permettant d'effectuer une opération de dépôt dans une devise spécifique
void effectuerDepot(Devise devise, double montantDepot);

// Fonction permettant de calculer le nouveau solde après un retrait dans une devise spécifique
double retraitMontant(Devise devise, double montantRetrait);

// Fonction permettant d'effectuer une opération de retrait dans une devise spécifique
void effectuerRetrait(Devise devise, double montantRetrait);

// Fonction permettant d'enregistrer toutes les transactions effectuees
struct Transaction* enregistrerTransaction(struct Transaction* transactions, int* taille,struct Transaction n_transaction);

// Fonction permettant d'afficher toutes les transactions effectuees
void afficherTransactions();
