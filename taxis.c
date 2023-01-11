#include "estrutura.h"
#include <stdio.h>

int registrar_viagem(const char* nome_arquivo, int num_taxi, Viagem viagem) {
   
    FILE* fp = fopen(nome_arquivo, "r+b");
    if (fp == NULL) {
        return -1;
    }

    Taxi taxi;
    fseek(fp, (num_taxi - 1) * sizeof(Taxi), SEEK_SET); // A posição é o index (num_taxi - 1) mutiplicado pelo tamanho em bytes de uma struct Taxi
    fread(&taxi, sizeof(Taxi), 1, fp);

    if (taxi.num_viagens == MAX_VIAGENS) {
        fclose(fp);
        return -2; // Erro: táxi já está cheio
    }

    
    guardar_contador(); // chamei esta função aqui para só guardar depois de fazer a validação anterior.
    taxi.viagens[taxi.num_viagens] = viagem;
    taxi.num_viagens++;

    fseek(fp, (num_taxi - 1) * sizeof(Taxi), SEEK_SET);
    fwrite(&taxi, sizeof(Taxi), 1, fp);

    fclose(fp);

    return 0;
}
