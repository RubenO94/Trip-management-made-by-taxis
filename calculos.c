#include "estrutura.h"
#include <stdio.h>
#include <float.h>
   
float calcular_valor_total_viagens() {
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
        return 0;
    }

    float total = 0;
    Taxi taxi;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        for (int j = 0; j < taxi.num_viagens; j++) {
        Viagem* viagem = &taxi.viagens[j];
        total += viagem->valor;
        }
    }

    fclose(arquivo);
    return total;
}

float calcular_media_viagens() {
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
        return 0;
    }

    int num_viagens = 0;
    float total = 0;
    Taxi taxi;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        num_viagens += taxi.num_viagens;
        for (int j = 0; j < taxi.num_viagens; j++) {
        Viagem* viagem = &taxi.viagens[j];
        total += viagem->valor;
        }
    }

    fclose(arquivo);
    if (num_viagens == 0) {
        return 0;
    }
    return total / num_viagens;
}


float calcular_viagens_menor_valor() {
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
        return 0;
    }

    Taxi taxi;
    float menor_valor = FLT_MAX; // FLT_MAX é a maior representação possível para um float

    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        for (int j = 0; j < taxi.num_viagens; j++) {
            Viagem* viagem = &taxi.viagens[j];
            if (viagem->valor < menor_valor) {
                menor_valor = viagem->valor;
            }
        }
    }    
    fclose(arquivo);

    return menor_valor;
}

int numero_viagens_tipo(TipoViagem tipo){
     FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
        return 0;
    }

    int num_viagens = 0;
    Taxi taxi;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        for (int j = 0; j < taxi.num_viagens; j++) {
            Viagem* viagem = &taxi.viagens[j];
            if (viagem->tipo == tipo)
            {
                num_viagens++;
            }
        }
    }

    fclose(arquivo);
    if (num_viagens == 0) {
        return 0;
    }

    return num_viagens;
}


float contabilizar_valor_tipo(TipoViagem tipo){
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
    return 0;
    }

    Taxi taxi;
    float total = 0;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        for (int j = 0; j < taxi.num_viagens; j++) {
            Viagem *viagem = &taxi.viagens[j];
            if (viagem->tipo == tipo) {
            total += viagem->valor;
            
            }
        }
    }

    if (!total)
    {
        return 0;
    }
    
    fclose(arquivo);
    return total;
}


float calcular_iva_total(){
    
    float total_sem_iva = calcular_valor_total_viagens();
    float total_iva = total_sem_iva * IVA;
    if (total_iva < 0)
    {
        return 0;
    }
    
    //printf("        |   # IVA total:............. %.2f EUR        |\n", total_iva);
    //printf("\n Valor total em IVA atual: %.2f EUR", total_iva);

    return total_iva;
}

//Funções Extra trabalho:

//Opção 15 Menu:
int contabilizar_viagens_taxi(){
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
        return -1;
    }

    Taxi taxi;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        printf("        |   # Taxi %.2d:....... %d viagens           |\n", taxi.num, taxi.num_viagens);
    }

    fclose(arquivo);

    return 0;
}

float calcular_TotalComIVA(){
    float total_sem_iva = calcular_valor_total_viagens();
    float total_iva = total_sem_iva * IVA;
    float total_com_iva = total_sem_iva + total_iva;
    return total_com_iva;
}