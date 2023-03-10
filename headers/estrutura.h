#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "limpar_consola.h"

//Constantes globais:
#define MAX_VIAGENS 5
#define NUM_TAXIS 20
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

// Função para ler o arquivo taxis.dat
int read_arquivo( Taxi lista[]);

// Criar / Reniciar arquivo taxis.dat
int criar_taxis(const char* nome_arquivo);

// Adicionar nova viagem a um taxi:
int registar_viagem(const char* nome_arquivo, int num_taxi, Viagem viagem);

// Listagens:
int listar_viagens();
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
int imprimir_menor_valor ();
int imprimir_IVA_total();

//Calculos:
int contar_numero_viagens();
int numero_viagens_tipo(TipoViagem tipo);
float calcular_valor_total_viagens();
float calcular_media_viagens();
float calcular_iva_total();
float contabilizar_valor_tipo(TipoViagem tipo);
float calcular_viagens_menor_valor();
float calcular_viagem_maior_valor(int num_taxi);
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
int informacoes_Sistema();

//Funções extra:

int top10_viagens_baratas(float top10[]);
int lista_top10();

#endif