#include <stdio.h>
#define USD 0
#define FC 1

double soldes[2] = {0.0, 0.0};


// Solde

double soldeUSD()
{
    for (int i = 0; i < 2; ++i)
    {
        if(i == USD)
             return soldes[i];
    }
}
double soldeFC()
{
    for (int i = 0; i < 2; ++i)
    {
        if(i == FC)
            return soldes[i];
    }
}

double verifierSolde(int devise)
{
    return (devise == USD) ? soldeUSD() : soldeFC();
}


// Depot

double depotUSD(double mnt_depot_usd)
{
    for(int i = 0; i < 2; i++)
    {
        if(i == USD)
        {
            soldes[i] += mnt_depot_usd;
            return soldes[i];
        }
    }
}

double depotFC(double mnt_depot_fc)
{
    for(int i = 0; i < 2; i++)
    {
        if(i == FC)
        {
            soldes[i] += mnt_depot_fc;
            return soldes[i];
        }
    }
}

void effectuerDepot(int devise, double mnt_dpt)
{
    if(devise == USD && mnt_dpt > 5)
    {
        printf("\nLe depot du montant %.2f USD a ete effectue avec succes. Votre nouveau solde est de %.2f USD\n\n", mnt_dpt,  depotUSD(mnt_dpt));
    }
    else if(devise == FC&& mnt_dpt > 5000)
    {
        printf("\nLe depot du montant %.2f FC a ete effectue avec succes. Votre nouveau solde est de %.2f FC\n\n", mnt_dpt,  depotFC(mnt_dpt));
    }else
    {
        if(devise == USD)
        {
             printf("\nLe montant %.2f USD est insuffisant pour effectuer cette operation.\n\n", mnt_dpt);
        }
        else if(devise == FC)
        {
             printf("\nLe montant %.2f FC est insuffisant pour effectuer cette operation.\n\n", mnt_dpt);
        }

    }
}




// Retrait

double retraitUSD(double mnt_rt_usd)
{
    for(int i = 0; i < 2; i++)
    {
        if(i == USD)
        {
            soldes[i] -= mnt_rt_usd;
            return soldes[i];
        }
    }
}

double retraitFC(double mnt_rt_fc)
{
    for(int i = 0; i < 2; i++)
    {
        if(i == FC)
        {
            soldes[i] -= mnt_rt_fc;
            return soldes[i];
        }
    }
}

void effectuerRetrait(int devise, double mnt_rt)
{
    if(devise == USD &&  mnt_rt < verifierSolde(devise)  && verifierSolde(devise) > 0)
    {
        printf("\nLe retrait du montant %.2f USD a ete effectue avec succes. Votre nouveau solde est de %.2f USD\n\n", mnt_rt,  retraitUSD(mnt_rt));
    }
    else if(devise == FC  &&  mnt_rt < verifierSolde(devise)  && verifierSolde(devise) > 0)
    {
        printf("\nLe retrait du montant %.2f FC a ete effectue avec succes. Votre nouveau solde est de %.2f FC\n\n", mnt_rt,  retraitFC(mnt_rt));
    }
    else
    {
        printf("\nVotre solde est insuffisant pour effectuer cette operation.\n\n");
    }
}


// Historiques




