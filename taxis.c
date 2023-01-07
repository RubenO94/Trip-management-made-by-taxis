#include "estrutura.h"
#include <stdio.h>

// Procura no arquivo taxis.dat o taxi pertendido e adiciona a nova viagem

int registrar_viagem(const char* nome_arquivo, int num_taxi, Viagem viagem) {
    // Abre o arquivo em modo de read/write binario
    FILE* fp = fopen(nome_arquivo, "r+b");
    if (fp == NULL) {
        return -1; // Erro: falha ao abrir o arquivo
    }

    // Procura o táxi no arquivo
    Taxi taxi;
    fseek(fp, (num_taxi - 1) * sizeof(Taxi), SEEK_SET); // A posição é o index mutiplicado pelo tamanho em bytes de uma struct Taxi
    fread(&taxi, sizeof(Taxi), 1, fp);

    // Verifica se o táxi tem espaço para mais uma viagem
    if (taxi.num_viagens == MAX_VIAGENS) {
        fclose(fp);
        return -2; // Erro: táxi já está cheio
    }

    // Caso tenha espaço adiciona a nova viagem ao táxi
    guardar_contador(); // guarda o contador de referencias
    taxi.viagens[taxi.num_viagens] = viagem;
    taxi.num_viagens++;

    // Volta ao início do táxi no arquivo e escreve as alterações
    fseek(fp, (num_taxi - 1) * sizeof(Taxi), SEEK_SET);
    fwrite(&taxi, sizeof(Taxi), 1, fp);

    fclose(fp);

    return 0; //sucesso
}
