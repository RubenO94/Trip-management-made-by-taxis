#include "../headers/estrutura.h"
#include <stdio.h>
#include <float.h>

int top10_viagens_baratas(float top10[]){

    Taxi lista[NUM_TAXIS];
    int tamanhoTaxis = read_arquivo(lista);

    float valores [NUM_TAXIS *  MAX_VIAGENS];
    int indice = 0;

    for (int i = 0; i < tamanhoTaxis; i++)
    {
        for (int j = 0; j < lista[i].num_viagens; j++)
        {
            valores[indice++] = lista[i].viagens[j].valor;
        }
        
    }

    for (int i = 0; i < 10 ; i++)
    {
        float menor_valor = FLT_MAX;
        int posicao = -1;

        for (int j = 0; j < indice ; j++)
        {
            if(valores[j] < menor_valor){
                menor_valor = valores[j];
                posicao = j;
            }
        }
        top10[i] = menor_valor;
        valores[posicao] = FLT_MAX;
    }
    
   return indice; 
}


int lista_top10(){

    float top10[10];
    int indice = top10_viagens_baratas(top10);
            limpar_tela();
        printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        |                Top 10 das viagens mais baratas          |\n");
        printf("        +---------------------------------------------------------+\n");

    printf("    Numero de posicoes com valores atribuidos = %d\n\n", indice);

    for (int i = 0; i < 10; i++)
    {
        if(top10[i] != FLT_MAX){
            printf("    .%d Lugar:.......%.2f EUR\n", i+1, top10[i]);
        }else{
            printf("    .%d Lugar:.......Valor nao atribuido\n", i+1);
        }
    }
    
    return 0;
}