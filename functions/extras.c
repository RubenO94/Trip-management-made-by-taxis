#include <stdio.h>
#include <float.h>
#include "../headers/estrutura.h"
//Funções Extra trabalho:

int informacoes_Sistema(){
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                 Informacoes sobre o sistema             |\n");
    printf("        +---------------------------------------------------------+\n");
     printf("\n");
    printf("        ___________________________________________________________\n");
     printf("\n");
     Taxi lista[NUM_TAXIS];
    int tamanhoTaxis = read_arquivo(lista);
    if(tamanhoTaxis == -1){
        return -1;
    }
    printf("        |   # O sistema tem %.2d taxis disponiveies e cada um deles pode efetuar ate %d viagens.\n\n", NUM_TAXIS, MAX_VIAGENS);
    for (int i = 0; i < tamanhoTaxis; i++)
    {
        printf("        |   # Taxi %.2d:....... %d\n", lista[i].num, lista[i].num_viagens);
    }
    return 0;
}