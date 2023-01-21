#include "../headers/estrutura.h"
#include <stdio.h>

int sub_menu_Admin();
int sub_menu_Viagens();
int sub_menu_Listagens();
int sub_menu_Calculos();

int main() {
    int opt = 0;
    int retorno;

    do
    {
        limpar_tela();
        printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        |                   Menu Principal                        |\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        |                                                         |\n");
        printf("        |       1 - Registrar Nova Viagem                         |\n");
        printf("        |       2 - Listagens & Pesquisas                         |\n");
        printf("        |       3 - Calculos & Estatisticas                       |\n");
        printf("        |       4 - Ferramentas de Administrador                  |\n");
        printf("        |       0 - Sair do Programa                              |\n");
        printf("        |                                                         |\n");
        printf("        +---------------------------------------------------------+\n");
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            printf("\n\n\tPrograma terminado com sucesso!");
            printf("\n");
            break;
        case 1:
            retorno = registrar_viagem("taxis.dat", ler_num_taxi(), ler_viagem());
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 2:
            sub_menu_Listagens();
            break;
        case 3:
            sub_menu_Calculos();
            break;
        case 4:
            sub_menu_Admin();
            break;            
        default:
            printf("\n\n Opcao invalida. Tenta novamente");
            pausar_mensagem();
            break;
        }
    } while (opt != 0);

    return 0;
}


int sub_menu_Admin(){
    int opt = 0;
    int retorno;

    do
    {
        limpar_tela();
        printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        |                   Painel Administrativo                 |\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        |                                                         |\n");
        printf("        |       1 - Iniciar / Reniciar Empresa                    |\n");
        printf("        |       2 - Informacao sobre o programa                   |\n");
        printf("        |       0 - Voltar                                        |\n");
        printf("        |                                                         |\n");
        printf("        +---------------------------------------------------------+\n");
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            break;
        case 1:
            retorno = criar_taxis("taxis.dat");
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 2:
            // infos_empresa();
            printf("\n\tErro: Funcao ainda em desenvolvimento...\n");
            pausar_mensagem();
            break;   
        default:
            printf("\n\n Opcao invalida. Tente novamente");
            pausar_mensagem();
            break;
        }
    } while (opt != 0);

    return 0;

}

int sub_menu_Listagens(){
    int opt = 0;
    int retorno;

    do
    {
        limpar_tela();
        printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        |                   Listas & Pesquisas                    |\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        |                                                         |\n");
        printf("        |       1 - Pesquisar por viagem                          |\n");
        printf("        |       2 - Listar todas as viagens                       |\n");
        printf("        |       3 - Listar viagens por taxi                       |\n");
        printf("        |       4 - Listar viagens por tipo de viagem             |\n");
        printf("        |       5 - Listar as viagens mais baratas                |\n");
        printf("        |       6 - Listar as viagens com valor acima da media    |\n");
        printf("        |       7 - Listar a viagem mais cara de um taxi          |\n");
        printf("        |       0 - Voltar                                        |\n");
        printf("        |                                                         |\n");
        printf("        +---------------------------------------------------------+\n");
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            break;
        case 1:
            retorno = listar_viagem_por_referencia(ler_num_referencia());
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 2:
            retorno = listar_viagens("taxis.dat");
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 3:
            retorno = listar_viagens_taxi(ler_num_taxi());
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 4:
            retorno = listar_viagens_tipo(ler_tipo());
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 5:
            retorno = imprimir_menor_valor(calcular_viagens_menor_valor());
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 6:
            retorno = listar_viagens_valor_acima_media();
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 7:
            retorno = listar_viagem_mais_cara(ler_num_taxi());
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;                        
        default:
            printf("\n\n Opcao invalida. Tente novamente");
            pausar_mensagem();
            break;
        }
    } while (opt != 0);

    return 0;
}

int sub_menu_Calculos(){
    int opt = 0;
    int retorno;

    do
    {
        limpar_tela();
        printf("\n            //////////// # GESTAO DE VIAGENS # ////////////\n\n\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        |                   Calculos & Estatisticas               |\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        +---------------------------------------------------------+\n");
        printf("        |                                                         |\n");
        printf("        |       1 - Calcular valor total das viagens              |\n");
        printf("        |       2 - Calcular valor medio das viagens              |\n");
        printf("        |       3 - Calcular IVA total das viagens                |\n");
        printf("        |       4 - Calcular valor total por cada tipo de viagem  |\n");
        printf("        |       5 - Exibir numero de viagens de cada tipo         |\n");
        printf("        |       6 - Testes de funcoes                             |\n"); 
        printf("        |       0 - Voltar                                        |\n");
        printf("        |                                                         |\n");
        printf("        +---------------------------------------------------------+\n");
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            break;
        case 1:
            retorno = imprimir_valor_total();
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 2:
            retorno = imprimir_media_viagens();
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 3:
            retorno = imprimir_IVA_total();
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 4:
            retorno = listar_valor_total_tipo();
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 5:
            retorno = listar_numero_viagens_tipo();
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;
        case 6:
            retorno = contar_numero_viagens();
            //retorno = contabilizar_viagens_taxi(); // Função em desenvolvimento...
            mensagem_retorno(retorno);
            pausar_mensagem();
            break;                        
        default:
            printf("\n\n Opcao invalida. Tenta novamente");
            pausar_mensagem();
            break;
        }
    } while (opt != 0);

    return 0;
}

