#include "../headers/estrutura.h"
#include "stdio.h"
#include "float.h"


float calcular_valor_total_viagens() {
    
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

int contar_numero_viagens(){
    
    Taxi lista[NUM_TAXIS];
    int tamanho = read_arquivo(lista);
    
    int total = 0;
    for (int i = 0; i < tamanho; i++){
        total += lista[i].num_viagens;
    }
    return total;
}

int numero_viagens_tipo(TipoViagem tipo){
    
    Taxi lista[NUM_TAXIS];
    int tamanho = read_arquivo(lista);

    int total = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < lista[i].num_viagens; j++) {
            if (lista[i].viagens[j].tipo == tipo){
                total++;
            }
        }
    }
    return total;
}

float contabilizar_valor_tipo(TipoViagem tipo){
    Taxi lista[NUM_TAXIS];
    int tamanho = read_arquivo(lista);
    float total = 0;
    
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < lista[i].num_viagens; j++){
                if(lista[i].viagens[j].tipo == tipo){

                total += lista[i].viagens[j].valor;
            }
        }  
    }
    return total;
}

float calcular_viagens_menor_valor() {
    
    Taxi lista[NUM_TAXIS];
    int tamanho = read_arquivo(lista);

    float menor_valor = FLT_MAX; // FLT_MAX é a maior representação possível para um float
    
    for(int i = 0; i< tamanho; i++){
        for (int j = 0; j < lista[i].num_viagens; j++){
            if(lista[i].viagens[j].valor < menor_valor){
            menor_valor = lista[i].viagens[j].valor;
            }
        }
    }
    return menor_valor;
}

float calcular_viagem_maior_valor(int num_taxi){
    Taxi lista[NUM_TAXIS];
    int tamanho = read_arquivo(lista);
    float maior_valor  = FLT_MIN; // FLOAT_MIN reprensenta o menor float possivel


    for (int i = 0; i < tamanho; i++){
       for (int j=0; j< lista[i].num_viagens; j++){
        
            if(lista[i].viagens[j].valor > maior_valor){
            maior_valor = lista[i].viagens[j].valor;
            }
        }
    } 
    return maior_valor;
}


float calcular_media_viagens() {
    
    int num_viagens = contar_numero_viagens();
    float total = calcular_valor_total_viagens();
   
    return total / num_viagens;
}


float calcular_iva_total(){
    
    float total_sem_iva = calcular_valor_total_viagens();
    float total_iva = total_sem_iva * IVA;
    if (total_iva < 0){
        return 0;
    }
    
    return total_iva;
}

float calcular_TotalComIVA(){
    float total_sem_iva = calcular_valor_total_viagens();
    float total_iva = calcular_iva_total();
    float total_com_iva = total_sem_iva + total_iva;
    return total_com_iva;
}