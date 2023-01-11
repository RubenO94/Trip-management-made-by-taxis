#include "estrutura.h"
#include <stdio.h>

//Esta é a função que incializa o ficheiro taxis.dat e adiciona os taxis

int criar_taxis(const char* nome_arquivo) {
    
    FILE* fp = fopen(nome_arquivo, "wb");
    if (fp == NULL) {
        return -1; // Erro: falha ao abrir o arquivo
    }

    // Cria os táxis 
    Taxi taxis[NUM_TAXIS];
    for (int i = 0; i < NUM_TAXIS; i++) {
        taxis[i].num = i + 1;
        taxis[i].num_viagens = 0;
    }

    // Grava os táxis no arquivo
    fwrite(taxis, sizeof(Taxi), NUM_TAXIS, fp);

    // Fecha o arquivo
    fclose(fp);

    //Reniciar o contador de referencias:
    reset_contador();

    // Mensagem alerta:
    printf("\n\n\tEmpresa incializada...");
    printf("\n\tForam adicionados %d taxis.", NUM_TAXIS);
    printf("\n\tSucesso! Programa pronto a funcionar.");
    return 0; // Sucesso
}