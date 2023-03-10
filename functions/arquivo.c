#include "../headers/estrutura.h"
#include <stdio.h>

// Função para ler os dados e guardar numa lista de taxis
int read_arquivo(Taxi lista[]) {
    FILE* fp = fopen("taxis.dat", "rb");
    if (fp == NULL) {
        return -1; 
    }

    Taxi taxi;
    int index = 0;
    while (fread(&taxi, sizeof(Taxi), 1, fp) == 1)
    {
       lista[index] = taxi;
       index++;
    }
    fclose(fp);
    return index; 
}
