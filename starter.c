#include <stdio.h>

#include <stdlib.h>

#include "menu.h"

// Fonction permettant d'afficher le menu et de gérer les choix de l'utilisateur
void menu()
{
    // Variable pour stocker le choix de l'utilisateur
    int choix;

    // Boucle jusqu'à ce que l'utilisateur choisisse de sortir (option 3)
    do {
        // Afficher le menu
        afficherMenu();

        // Inviter l'utilisateur à choisir une option
        printf("Choisissez une option :");

        // Lire le choix de l'utilisateur
        scanf("%d", &choix);

        // Effacer la console
        system("cls");

        // Gérer le choix de l'utilisateur
        switch (choix) {
            case 0:
                // Si l'utilisateur a choisi l'option 0, gérer les soldes des comptes
                gererSoldes();
                break;
            case 1:
                // Si l'utilisateur a choisi l'option 1, traiter les transactions de dépôt
                gererDepot();
                break;
            case 2:
                // Si l'utilisateur a choisi l'option 2, traiter les transactions de retrait
                gererRetrait();
                break;
            case 3:
                 // Si l'utilisateur a choisi l'option 3, afficher l'historique des transactions
                gererTransactions();
                break;
            default:
                // Si l'utilisateur a choisi une autre option, dire au revoir et sortir
                printf("\n Au revoir !\n");
        }
    } while (choix != 4);
}
