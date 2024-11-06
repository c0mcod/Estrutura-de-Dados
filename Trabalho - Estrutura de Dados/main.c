// ---------------------------------------------------------------- FUNÇÃO PRINCIPAL ----------------------------------------------------------------
// Esse arquivo só compõe a função principal com o menu usando SWITCH CASE
// O arquivo de funções fica nessa mesma pasta com o nome "funcoes.h"
// --------------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    int codigo, quantidade;
    No *listaFrutas = criarLista();
    int op;

    do
    {
        printf("\n--- Mercado de Frutas ---\n");
        printf("1 - Cadastrar fruta\n");
        printf("2 - Listar frutas\n");
        printf("3 - Buscar fruta\n");
        printf("4 - Alterar fruta\n");
        printf("5 - Excluir fruta\n");
        printf("6 - Vender fruta\n");
        printf("7 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            listaFrutas = cadastrarFruta(listaFrutas);
            // anotação de debug:
            // fazer a função se repetir para colocar um novo codigo se o usuario tiver inserido um codigo que já existe
            break;
        case 2:
            exibirListaFruta(listaFrutas);
            break;
        case 3:
            listaFrutas = buscarFruta(listaFrutas);
            break;
        case 4:
            listaFrutas = alterarFruta(listaFrutas);
            break;
        case 5:
            int codigoExclu;

            printf("Digite o código da fruta que deseja excluir: ");
            scanf("%d", &codigoExclu);
            excluirFruta(&listaFrutas, codigoExclu);

            // Com a função que percorre a lista e verifica se ela realmente tá lá, ela faz a verificação para saber se o codigo não foi encontrado
            if (verificarFruta(listaFrutas, codigoExclu))
            {
                excluirFruta(&listaFrutas, codigoExclu);
            }
            else
            {
                printf("Fruta com código %d não encontrada. Não é possível excluir.\n", codigoExclu);
            }

            break;
        case 6:
            printf("Digite o código da fruta para venda: ");
            scanf("%d", &codigo);
            printf("Digite a quantidade para vender: ");
            scanf("%d", &quantidade);
            venderFruta(listaFrutas, codigo, quantidade);
            break;
        case 7:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (op != 7);

    return 0;
}
