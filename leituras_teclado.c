#include "estrutura.h"
#include <stdio.h>
#include <stdlib.h>

int ler_num_referencia(){
    int ref;
    printf("     # Insira a referencia da viagem: ");
    scanf("%d", &ref);
    return ref;
}

int ler_num_taxi() {
    int num;
    do{
        printf("     # Insira o numero do taxi: ");
        scanf("%d", &num);
        if (num < 1 || num > NUM_TAXIS)
        {
            printf("\nErro: O numero tem ser entre 1 e %d!\nTente novamente.\n", NUM_TAXIS);
        }
        
    } while (num < 1 || num > NUM_TAXIS);
    return num;
}

TipoViagem ler_tipo(){
    TipoViagem tipo;
    printf("     # Insira o tipo de viagem (L - local, N - nacional, I - internacional, O - outra): ");
    char tipo_str[2];
    scanf("%s", tipo_str);
    switch (tipo_str[0]) {
        case 'L':
        tipo = LOCAL;
        break;
        case 'N':
        tipo = NACIONAL;
        break;
        case 'I':
        tipo = INTERNACIONAL;
        break;
        case 'O':
        tipo = OUTRA;
        break;
    }
    return tipo;
}

float ler_distancia(){
    float distancia;

    do
    {
        printf("     # Insira a distancia percorrida: ");
        scanf("%f", &distancia);
        if (distancia < 0)
        {
            printf("\nErro: A distancia nao pode ter valor negativo!\nTente novamente.\n");
        }
        
    } while (distancia < 0);
    return distancia;
}

float ler_valor(){
    float valor;

    do
    {
        printf("     # Insira o valor da viagem: ");
        scanf("%f", &valor);
        if (valor < 0)
        {
            printf("\nErro: O valor da viagem nao pode ser negativo!\nTente novamente.\n");
        }
        
    } while (valor < 0);
    return valor;
}