#include "estrutura.h"
#include <stdio.h>

void mensagem_retorno(int retorno){

    switch (retorno)
    {
    case 0:
        printf("\n\n\tProcesso concluido com sucesso!");
        break;
    case -1:
        printf("\n\n\tErro: Nao foi possivel abrir o ficheiro!");
        break;
    case -2:
        printf("\n\n\tErro: O Taxi inserido ja atingiu o limite maximo de %d viagens permitidas!", MAX_VIAGENS);
        break;
    case -3:
        printf("\n\n\tErro: O Taxi nao tem viagens efetuadas!");
        break;
    case -4:
        printf("\n\n\tErro: Ainda nao foi efetuda nenhuma viagem!");
        break;  
    case -5:
        printf("\n\n\tErro: Nao foi encontrado nenhum taxi com o id inserido!");
        break;
    case -6:
        printf("\n\n\tErro: Ainda nao foi efetuada nenhuma viagem do tipo inserido!");
        break;
    case -7:
        printf("\n\n\tErro: Nao foi possivel fazer o calculo!"); 
        break;
    case -8:
        printf("\n\n\tErro: A referencia inserida nao existe no sistema!");
        break;
    case -9:
        printf("\n\n\tErro: Ainda nao existe viagens com valor acima da media!");
        break;
    default:
        printf("\n\n\tNao foi possivel concluir o processo!");
        break;
    }
}