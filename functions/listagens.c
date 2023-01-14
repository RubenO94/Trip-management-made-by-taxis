#include "../headers/estrutura.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <float.h>

int imprimir_IVA_total(){
    float iva = calcular_iva_total();
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                   IVA total da Empresa                  |\n");
    printf("        +---------------------------------------------------------+\n");
    printf("\n");
    printf("            # IVA atual:............. %.2f EUR\n", iva);
    printf("\n");
    printf("        ___________________________________________________________\n");
    return 0;
}

int listar_viagens(const char* nome_arquivo) {

    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                      Lista de Viagens                   |\n");
    printf("        +---------------------------------------------------------+\n");

    FILE* arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        return -1;
    }

    int totalViagens = contar_numero_viagens();
    Taxi taxi;
    int viagem_encontrada = 0;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        for (int i = 0; i < taxi.num_viagens; i++) {
            Viagem *viagem = &taxi.viagens[i];
            imprimir_viagem(taxi, viagem);
            if (viagem != NULL)
            {
                viagem_encontrada = 1;
            }
        
        }
    }
     printf("\n");
    printf("            # Total de viagens:............. %d\n", totalViagens);
    printf("\n");
    printf("        ___________________________________________________________\n");
    printf("\n");
    fclose(arquivo);
    if (!viagem_encontrada)
    {
        return -4; 
    }
    
    return 0;
}

int listar_viagens_taxi(int num_taxi) {
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                    Viagens do Taxi - %.2d                 |\n", num_taxi);
    printf("        +---------------------------------------------------------+\n");
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
        return -1;
    }

    Taxi taxi;
    int taxi_encontrado = 0;
    int viagem_encontrada = 0;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        if (taxi.num == num_taxi) {
            taxi_encontrado = 1;
            for (int j = 0; j < taxi.num_viagens; j++) {
                Viagem* viagem = &taxi.viagens[j];
                imprimir_viagem(taxi, viagem);
                if (viagem != NULL)
                {
                    viagem_encontrada = 1;
                }
                
            }
            break;
        }  
    }

    fclose(arquivo);
    if(!taxi_encontrado){
        return -5;
    }else if(!viagem_encontrada){
        return -3;
    }
    printf("\n");
    printf("            # Total de viagens efetuadas pelo taxi %.2d: %d\n",taxi.num, taxi.num_viagens);
    printf("\n");
    printf("        ___________________________________________________________\n");

    return 0; 
}

int listar_viagem_por_referencia(int referencia){
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                    Viagem por Referencia                |\n");
    printf("        +---------------------------------------------------------+\n");
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
    return -1;
    }

    Taxi taxi;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        for (int j = 0; j < taxi.num_viagens; j++) {
            Viagem *viagem = &taxi.viagens[j];
            if (viagem->ref == referencia) {
            imprimir_viagem(taxi, viagem);
            fclose(arquivo);
            return 0;
            }
        }
    }

    fclose(arquivo);
    return -8;
}

int listar_viagens_tipo (TipoViagem tipo){
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    switch (tipo)
    {
    case LOCAL:
        printf("        |                    Viagens do Tipo Local                |\n");
        break;
    case NACIONAL:
        printf("        |                  Viagens do Tipo Nacional               |\n");
        break;
    case INTERNACIONAL:
        printf("        |              Viagens do Tipo Internacional              |\n");
        break;
    case OUTRA:
        printf("        |                    Viagens do Tipo Outra                |\n");
        break;            
    default:
        break;
    }
    printf("        +---------------------------------------------------------+\n");
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
    return -1;
    }

    Taxi taxi;
    int tipo_encontrado = 0;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        for (int j = 0; j < taxi.num_viagens; j++) {
            Viagem *viagem = &taxi.viagens[j];
            if (viagem->tipo == tipo) {
            imprimir_viagem(taxi, viagem);
            tipo_encontrado = 1;
            }
        }
    }

    fclose(arquivo);
    if (!tipo_encontrado)
    {
        return -6;
    }

    return 0;
}


int listar_viagens_valor_acima_media(){
    float media = calcular_media_viagens();
    int viagemEncontrada = 0;
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |               Viagens com valor acima da media          |\n");
    printf("        +---------------------------------------------------------+\n");
    printf("\n");
    if (media <= 0) {
        return -7;
    }
    printf("            # Media Atual:.......... %.2f EUR\n", media);
    printf("\n");
    printf("        ___________________________________________________________\n");
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
        return -1;
    }
    Taxi taxi;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        for (int j = 0; j < taxi.num_viagens; j++) {
            Viagem* viagem = &taxi.viagens[j];
            if (viagem->valor > media)
            {
                imprimir_viagem(taxi, viagem);
                viagemEncontrada = 1;
            }
        }
    }

    fclose(arquivo);
    if (!viagemEncontrada)
    {
        return -9;
    }
    
    return 0;
}

int listar_numero_viagens_tipo(){
    int viagens_local = numero_viagens_tipo(LOCAL);
    int viagens_nacional = numero_viagens_tipo(NACIONAL);
    int viagens_internacional = numero_viagens_tipo(INTERNACIONAL);
    int viagens_outra = numero_viagens_tipo(OUTRA);
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                Numero de viagens de cada tipo           |\n");
    printf("        +---------------------------------------------------------+\n");
    printf("\n");
    printf("\n");
    printf("            # Local:............ %d\n", viagens_local);
    printf("            # Nacional:......... %d \n", viagens_nacional);
    printf("            # Internacional:.... %d\n", viagens_internacional);
    printf("            # Outra:............ %d\n", viagens_outra);

    return 0;

}

int listar_valor_total_tipo(){
   limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                  Valor total de cada tipo               |\n");
    printf("        +---------------------------------------------------------+\n");
    printf("\n");
    printf("\n");
    float viagens_local = contabilizar_valor_tipo(LOCAL);
    float viagens_nacional = contabilizar_valor_tipo(NACIONAL);
    float viagens_internacional = contabilizar_valor_tipo(INTERNACIONAL);
    float viagens_outra = contabilizar_valor_tipo(OUTRA);
    printf("            # Local:............. %.2f EUR\n", viagens_local);
    printf("            # Nacional:.......... %.2f EUR\n", viagens_nacional);
    printf("            # Internacional:..... %.2f EUR\n", viagens_internacional);
    printf("            # Outra:............. %.2f EUR\n", viagens_outra);
    return 0;
}

int listar_viagem_mais_cara(int num_taxi){
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                  Viagem mais cara do Taxi - %.2d          |\n", num_taxi);
    printf("        +---------------------------------------------------------+\n");
    printf("\n");
    printf("\n");
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL) {
        return -1;
    }

    Taxi taxi;
    float maior_valor = calcular_viagem_maior_valor(num_taxi);
    int taxi_encontrado = 0;
    int viagem_encontrada = 0;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        if (taxi.num == num_taxi) {
            taxi_encontrado = 1;
            for (int j = 0; j < taxi.num_viagens; j++) {
                Viagem* viagem = &taxi.viagens[j];
                if (viagem->valor == maior_valor) {
                    imprimir_viagem(taxi, viagem);
                    viagem_encontrada = 1;
                }
            }
        }  
    }
    fclose(arquivo);
    if(!taxi_encontrado){
        return -5;
    }
    if (!viagem_encontrada)
    {
        return -3;
    }  
    
    return 0;
}

//Impressões:

int imprimir_valor_total(){
    float total = calcular_valor_total_viagens();
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                     Valor total (S/IVA)                 |\n");
    printf("        +---------------------------------------------------------+\n");
    printf("\n");
    printf("\n");
    printf("            # Valor total (S/IVA):.... %.2f EUR\n", total);
    printf("\n");
    printf("        ___________________________________________________________\n");

    return 0;
}

int imprimir_media_viagens(){
    float media = calcular_media_viagens();
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                   Valor medio (S/IVA)                   |\n");
    printf("        +---------------------------------------------------------+\n");
    printf("\n");
    printf("            # Media Atual:.......... %.2f EUR\n", media);
    printf("\n");
    printf("        ___________________________________________________________\n");

    return 0;
}

int imprimir_menor_valor (float valor){
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                Viagens com o preco mais barato          |\n");
    printf("        +---------------------------------------------------------+\n");
    FILE* arquivo = fopen("taxis.dat", "rb");
    if (arquivo == NULL)
    {
        return -1;
    }

    Taxi taxi;
    while (fread(&taxi, sizeof(Taxi), 1, arquivo) == 1) {
        for (int j = 0; j < taxi.num_viagens; j++) {
            Viagem* viagem = &taxi.viagens[j];
            if (viagem->valor == valor) {
                imprimir_viagem(taxi, viagem);
            }
        }
    }    
    
    fclose(arquivo); 

    if (valor == FLT_MAX)
    {
        return -4;
    }

    return 0;
}

int imprimir_viagem(Taxi taxi, Viagem* viagem){
    Sleep(400); // Foi uma maneira de adicionar um "loading" entre viagens para que quando a lista seja longa nao aparecer tudo de uma vez
    printf("\n");
    printf("\n");
    printf("            # Viagem: %.3d              # Taxi: %.2d\n", viagem->ref, taxi.num);
    printf("\n");
    printf("            # Distancia: %.2f km\n", viagem->distancia);
    switch (viagem->tipo) {
        case LOCAL:
        printf("            # Tipo: Local\n");
        break;
        case NACIONAL:
        printf("            # Tipo: Nacional\n");
        break;
        case INTERNACIONAL:
        printf("            # Tipo: Internacional\n");
        break;
        case OUTRA:
        printf("            # Tipo: Outra\n");
        break;
    } 
    float iva = viagem->valor * IVA;
    float total = viagem->valor + iva;
    printf("\n");
    printf("\n");
    printf("            # Valor:.......... %.2f EUR\n", viagem->valor);
    printf("            # IVA:............ %.2f EUR\n", iva);
    printf("            # Total:.......... %.2f EUR\n", total);
    printf("\n");
    printf("        ___________________________________________________________\n");
    return 0;
}