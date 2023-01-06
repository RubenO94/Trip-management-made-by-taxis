#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "limpar_consola.h"

//Constantes globais:
#define MAX_VIAGENS 2
#define NUM_TAXIS 5
#define IVA 0.23


//Declaração de Estruturas:
typedef enum {
  LOCAL,
  NACIONAL,
  INTERNACIONAL,
  OUTRA
} TipoViagem;

typedef struct {
  int ref;
  TipoViagem tipo;
  float valor;
  float distancia;
} Viagem;

typedef struct {
  int num;
  Viagem viagens[MAX_VIAGENS];
  int num_viagens;
} Taxi;



//    *** Declaração de funções ***

// Criar / Reniciar arquivo taxis.dat
int criar_taxis(const char* nome_arquivo);

// Adicionar nova viagem a um taxi:
int registrar_viagem(const char* nome_arquivo, int num_taxi, Viagem viagem);

// Listagens:
int listar_viagens(const char* nome_arquivo);
int listar_viagem_por_referencia(int referencia);
int listar_viagens_taxi(int num_taxi);
int listar_numero_viagens_tipo();
int listar_viagens_tipo(TipoViagem tipo);
int listar_viagens_valor_acima_media();
int listar_valor_total_tipo();
int listar_viagem_mais_cara(int num_taxi);
int imprimir_viagem(Taxi taxi, Viagem* viagem);
int imprimir_valor_total();
int imprimir_media_viagens();
int imprimir_menor_valor (float valor);
int imprimir_IVA_total();

//Calculos:
int numero_viagens_tipo(TipoViagem tipo);
float calcular_valor_total_viagens();
float calcular_media_viagens();
float calcular_iva_total();
float contabilizar_valor_tipo(TipoViagem tipo);
float calcular_viagens_menor_valor();
float calcular_TotalComIVA(); // EXTRA

//Leituras do teclado:
TipoViagem ler_tipo();
Viagem ler_viagem();
int ler_num_taxi();
int ler_num_referencia();
float ler_valor();
float ler_distancia();

// Funções auxiliares:
void guardar_contador();
int carregar_contador();
void reset_contador();
void pausar_mensagem();
void mensagem_retorno(int retorno);


// Funções extra Trabalho:
int contabilizar_viagens_taxi();
#endif