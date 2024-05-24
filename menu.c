#include <stdio.h>
#include <stdlib.h>
#include "operations.h"


void menu()
{
    int choix, devise;
    int mnt_dpt, mnt_rt;

    do {
        printf("\t\t***** BIENVENU SUR MOBILE MONEY *****\n\n\n");

        printf("0. Verifier le solde.\n");
        printf("1. Effectuer un depot.\n");
        printf("2. Effectuer un retrait.\n");
        printf("3. Sortir du programme.\n");
        printf("\n\n");
        printf("Choisissez une option :");
        scanf("%d", &choix);

        switch (choix) {
            case 0:
                system("cls");
                printf("\n\n SOLDE\n");
                printf(" ===== \n\n");
                printf("\nSelectionnez une devise :\n\n");
                printf("0. USD.\n");
                printf("1. FC.\n\n");
                printf("Choisissez une option :");
                scanf("%d", &devise);
                switch(devise)
                {
                    case 0:
                        printf("\nVotre solde en USD est de %.2f USD\n\n\n", verifierSolde(devise));
                        break;
                    case 1:
                        printf("\nVotre solde en FC est de %.2f FC\n\n\n", verifierSolde(devise));
                        break;
                }
                break;
            case 1:
                system("cls");
                printf("\n\n DEPOT\n");
                printf(" ===== \n\n");
                printf("\nSelectionnez une devise :\n\n");
                printf("0. USD.\n");
                printf("1. FC.\n\n");
                printf("Choisissez une option :");
                scanf("%d", &devise);
                switch(devise)
                {
                    case 0:
                        system("cls");
                        printf("\n\n DEPOT\n");
                        printf(" ===== \n\n");
                        printf("Saisir le montant en USD :");
                        scanf("%d", &mnt_dpt);
                        effectuerDepot(devise,mnt_dpt);
                        break;
                    case 1:
                        system("cls");
                        printf("\n\n DEPOT\n");
                        printf(" ===== \n\n");
                        printf("Saisir le montant en FC :");
                        scanf("%d", &mnt_dpt);
                        effectuerDepot(devise, mnt_dpt);
                        break;
                }
                break;
            case 2:
                system("cls");
                printf("\n\n RETRAIT \n");
                printf(" ======= \n\n");
                printf("\nSelectionnez une devise :\n\n");
                printf("0. USD.\n");
                printf("1. FC.\n\n");
                printf("Choisissez une option :");
                scanf("%d", &devise);
                switch(devise)
                {
                    case 0:
                        system("cls");
                        printf("\n\n RETRAIT \n");
                        printf(" ======= \n\n");
                        printf("Saisir le montant en USD :");
                        scanf("%d", &mnt_rt);
                        effectuerRetrait(devise,mnt_rt);
                        break;
                    case 1:
                        system("cls");
                        printf("\n\n RETRAIT \n");
                        printf(" ======= \n\n");
                        printf("Saisir le montant en FC :");
                        scanf("%d", &mnt_rt);
                        effectuerRetrait(devise, mnt_rt);
                        break;
                }
                break;
            default:
                printf("\n Au revoir !\n");

        }
    } while (choix != 3);
}



