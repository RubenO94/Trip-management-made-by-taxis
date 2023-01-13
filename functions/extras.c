#include <stdio.h>
#include <float.h>
#include "../headers/estrutura.h"
//Funções Extra trabalho:

//FUNÇÃO EM ANDAMENTO....
int contabilizar_viagens_taxi(){
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                    Folha de Estatisticas                |\n");
    printf("        +---------------------------------------------------------+\n");
     printf("\n");
    printf("        ___________________________________________________________\n");
     printf("\n");
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
        return -1;
    }

    Taxi taxi;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        printf("        |   # Taxi %.2d:....... %d\n", taxi.num, taxi.num_viagens);
    }

    fclose(arquivo);

    return 0;
}


// Desafio do professor: Encontrar o top 10 das viagens mais baratas
int top10_viagens_baratas(){
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL)
    {
        return -1;
    }

    float top10[10] = {FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX};
    Taxi taxi;
    int count = 0;

    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1)
    {
        for (int i = 0; i < taxi.num_viagens; i++)
        {
            if (taxi.viagens[i].valor < top10[i])
            {
                for (int j = 10; j > i; j--)
                {
                    top10[j] = top10[j-1];
                }
                top10[i] = taxi.viagens[i].valor;
                break;
            }
            
        }
        count++;
        if (count == 10)
        {
            break;
        }   
    }   
    fclose(arquivo);

    for (int i = 0; i < 10; i++)
    {
        printf("%d - %.2f EUR\n", i+1, top10[i]);
    }
    
    return 0;
}