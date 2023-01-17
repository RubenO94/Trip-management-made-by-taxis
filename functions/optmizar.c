#include "../headers/estrutura.h"
#include "stdio.h"
#include "float.h"


float calcular_valor_total_viagens1() {
    
    Taxi lista[NUM_TAXIS];
    int tamanho = read_arquivo(lista);

    float total = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < lista[i].num_viagens; j++) {
            total += lista[i].viagens[j].valor;
        }
    }
    return total;
}