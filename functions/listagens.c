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

int listar_viagens() {

    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                      Lista de Viagens                   |\n");
    printf("        +---------------------------------------------------------+\n");

    Taxi lista[NUM_TAXIS];
    int tamanhoTaxis = read_arquivo(lista);
    if (tamanhoTaxis == -1)
    {
        return -1;
    }
    int totalViagens = contar_numero_viagens();
    int viagem_encontrada = 0;

    for (int i = 0; i < tamanhoTaxis; i++){
        for (int j = 0; j < lista[i].num_viagens; j++) {
            imprimir_viagem(lista[i], &lista[i].viagens[j]);
            if (lista[i].num_viagens != 0)
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
    
    Taxi lista[NUM_TAXIS];
    int tamanhoTaxis = read_arquivo(lista);
    if (tamanhoTaxis == -1)
    {
        return -1;
    }
    int taxi_encontrado = 0;
    int viagem_encontrada = 0;
    for (int i = 0; i < tamanhoTaxis; i++)
    {
        if(lista[i].num == num_taxi){
            taxi_encontrado= 1;
            for (int j = 0; j < lista[i].num_viagens; j++)
            {
                imprimir_viagem(lista[i], &lista[i].viagens[j]);
                if (lista[i].num_viagens != 0)
                {
                    viagem_encontrada = 1;
                }
                
            }
            printf("\n");
            printf("            # Total de viagens efetuadas pelo taxi %.2d: %d\n",lista[i].num, lista[i].num_viagens);
            printf("\n");
            printf("        ___________________________________________________________\n");
            break;
        }
    }
    if(!taxi_encontrado){
        return -5;
    }else if(!viagem_encontrada){
        return -3;
    }
    return 0; 
}

int listar_viagem_por_referencia(int referencia){
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                    Viagem por Referencia                |\n");
    printf("        +---------------------------------------------------------+\n");
    Taxi lista[NUM_TAXIS];
    int tamanhoTaxis = read_arquivo(lista);
    int viagemEncontrada = 0;
    if (tamanhoTaxis == -1)
    {
        return -1;
    }

    for (int i = 0; i < tamanhoTaxis; i++)
    {
        for (int j = 0; j < lista[i].num_viagens; j++)
        {
            if(lista[i].viagens[j].ref == referencia){
                viagemEncontrada = 1;
                imprimir_viagem(lista[i], &lista[i].viagens[j]);
                return 0;
            }
        }
        
    }
    if(!viagemEncontrada){
        return -8;
    }
    return -10;
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
     Taxi lista[NUM_TAXIS];
    int tamanhoTaxis = read_arquivo(lista);
    int tipoEncontrado = 0;
    if (tamanhoTaxis == -1)
    {
        return -1;
    }

    for (int i = 0; i < tamanhoTaxis; i++)
    {
        for (int j = 0; j < lista[i].num_viagens; j++)
        {
            if(lista[i].viagens[j].tipo == tipo){
                tipoEncontrado = 1;
                imprimir_viagem(lista[i], &lista[i].viagens[j]);
            }
        }
        
    }
    if (!tipoEncontrado)
    {
        return -6;
    }

    return 0;
}


int listar_viagens_valor_acima_media(){
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |               Viagens com valor acima da media          |\n");
    printf("        +---------------------------------------------------------+\n");
    printf("\n");

    Taxi lista[NUM_TAXIS];
    int tamanhoTaxis = read_arquivo(lista);
    if (tamanhoTaxis == -1)
    {
        return -1;
    }
    float media = calcular_media_viagens();
    int viagemEncontrada = 0;
    if (media <= 0) {
        return -7;
    }
    printf("            # Media Atual:.......... %.2f EUR\n", media);
    printf("\n");
    printf("        ___________________________________________________________\n");

    for (int i = 0; i < tamanhoTaxis; i++)
    {
        for (int j = 0; j < lista[i].num_viagens; i++)
        {
            if(lista[i].viagens[j].valor > media){
                viagemEncontrada = 1;
                imprimir_viagem(lista[i], &lista[i].viagens[j]);
            }
        }
        
    }
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
    Taxi lista[NUM_TAXIS];
    int tamanhoTaxis = read_arquivo(lista);
    if (tamanhoTaxis == -1)
    {
        return -1;
    }
    float maior_valor = calcular_viagem_maior_valor(num_taxi);
    int taxi_encontrado = 0;
    int viagem_encontrada = 0;

    for (int i = 0; i < tamanhoTaxis; i++)
    {
        if(lista[i].num == num_taxi){
            taxi_encontrado = 1;
            for (int j = 0; j < lista[i].num_viagens; j++)
            {
                if(lista[i].viagens[j].valor == maior_valor){
                    viagem_encontrada = 1;
                    imprimir_viagem(lista[i], &lista[i].viagens[j]);
                }
            } 
        }
    }
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

int imprimir_valor_total1(){
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

int imprimir_menor_valor (){
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                Viagens com o preco mais barato          |\n");
    printf("        +---------------------------------------------------------+\n");
    
    Taxi lista[NUM_TAXIS];
    int tamanhoTaxis = read_arquivo(lista);
    if (tamanhoTaxis == -1)
    {
        return -1;
    }
    int viagemEncontrada = 0;
    float menorValor = calcular_viagens_menor_valor();

    for (int i = 0; i < tamanhoTaxis; i++)
    {
        for (int j = 0; j < lista[i].num_viagens; j++)
        {
            if(lista[i].viagens[j].valor == menorValor){
                viagemEncontrada = 1;
                imprimir_viagem(lista[i], &lista[i].viagens[j]);
            }
        }
        
    }
    if (!viagemEncontrada)
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