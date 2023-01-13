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