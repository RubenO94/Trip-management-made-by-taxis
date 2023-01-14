#include "../headers/estrutura.h"
#include <stdio.h>

// EM DESENVOLVIMENTO

int read_arquivo(const char* nome_arquivo, Taxi *taxis) {
    FILE* fp = fopen(nome_arquivo, "rb");
    if (fp == NULL) {
        return -1; 
    }

    fread(taxis, sizeof(Taxi), NUM_TAXIS, fp);
    fclose(fp);
    return 0; 
}

int write_arquivo(const char* nome_arquivo, Taxi *taxis) {
    FILE* fp = fopen(nome_arquivo, "wb");
    if (fp == NULL) {
        return -1; 
    }

    fwrite(taxis, sizeof(Taxi), NUM_TAXIS, fp);
    fclose(fp);
    return 0; 
}
