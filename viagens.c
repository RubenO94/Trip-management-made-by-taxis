#include "estrutura.h"
#include <stdio.h>

Viagem ler_viagem() {
    Viagem viagem;
    viagem.ref = carregar_contador();
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                  Novo registro de viagem                |\n");
    printf("        +---------------------------------------------------------+\n");
    printf("\n");
    printf("\n");
    printf("            # A referencia da viagem sera guardada com o numero: %.3d\n\n", viagem.ref);
    viagem.tipo = ler_tipo();
    viagem.distancia = ler_distancia();
    viagem.valor = ler_valor();
    return viagem;
}