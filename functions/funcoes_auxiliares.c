#include "../headers/estrutura.h"
#include <stdio.h>

// Inicializar contador
int contador_referencias = 0;

void guardar_contador() {
  contador_referencias++; // Incrementar 1 ao contador antes de passar-lo para o ficheiro.
  FILE* arquivo = fopen("contador_referencias.dat", "w");
  if (arquivo == NULL){
    return;
  }
  fwrite(&contador_referencias, sizeof(int), 1, arquivo);
  fclose(arquivo);
}

int carregar_contador() {
  FILE* arquivo = fopen("contador_referencias.dat", "r");
  if (arquivo != NULL) {
      fread(&contador_referencias, sizeof(int), 1, arquivo);
  }
  fclose(arquivo);
  return contador_referencias;
}

void reset_contador(){
  contador_referencias = 0;
  guardar_contador();
}

//Pausa na consola:
void pausar_mensagem() {
    getchar();
    printf("\n\n\n");
    printf("\tPressione qualquer tecla para continuar...");
    getchar();
}

// infos do sistema:

int informacoes_Sistema(){
    limpar_tela();
    printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
    printf("        +---------------------------------------------------------+\n");
    printf("        |                 Informacoes sobre o sistema             |\n");
    printf("        +---------------------------------------------------------+\n");
     printf("\n");
    printf("        ___________________________________________________________\n");
     printf("\n");
     Taxi lista[NUM_TAXIS];
    int tamanhoTaxis = read_arquivo(lista);
    if(tamanhoTaxis == -1){
        return -1;
    }
    printf("        |   # O sistema tem %.2d taxis disponiveies e cada um deles pode efetuar ate %d viagens.\n\n", NUM_TAXIS, MAX_VIAGENS);
    for (int i = 0; i < tamanhoTaxis; i++)
    {
        printf("        |   # Taxi %.2d:....... %d\n", lista[i].num, lista[i].num_viagens);
    }
    return 0;
}