//      1.Descrição:
//         Desenvolva um programa em C que simula um pequeno mercado de frutas. As frutas são um tipo de dados heterogêneos que possuem um código, nome, quantidade
//         e preço. O programa deve ter as seguintes funcionalidades:

//      •	Cadastrar fruta (Cadastra os dados de uma fruta)
//      •	Listar frutas (Lista as frutas que foram cadastradas no programa)
//      •	Buscar fruta (Busca uma fruta pelo código e exibe seus dados)
//      •	Alterar fruta (Altera dados da fruta)
//      •	Excluir fruta (Exclui uma fruta a partir do código passado por parâmetro, ela só pode ser excluída se não tiver estoque dela)
//      •	Vender fruta (Realiza a venda de uma fruta recebendo o código e a quantidade de frutas que será vendida)
//      •	Sair

//      2. Requisitos:
//      •	As frutas devem ser estruturas heterogêneas de dados
//      •	Os registros das frutas devem ser alocados dinamicamente e guardado os ponteiros em uma lista.
//      •	O programa deve funcionar de forma modular utilizando funções
//      •	O programa não deve permitir códigos de frutas repetidos no cadastro
//      •	O programa não deve permitir a venda de uma quantidade de frutas superior ao que contem em estoque.
//      •	As vendas devem ser registradas em um arquivo (vendas.txt).
// -------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura principal
typedef struct mercadoDeFrutas
{
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Fruta;

typedef struct No
{
    Fruta fruta;
    struct No *prox;
} No;

No *criarNo(Fruta fruta)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo)
    {
        novoNo->fruta = fruta;
        novoNo->prox = NULL;
    }
    return novoNo;
}

// Função para criar a lista
No *criarLista()
{
    return NULL;
}

No *cadastrarFruta(No *lista)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Não foi possível alocar memória para a nova fruta.\n");
        return lista;
    }

    printf("Digite o código da fruta: ");
    scanf("%d", &novoNo->fruta.codigo);

    printf("Digite o nome da fruta: ");
    scanf("%s", novoNo->fruta.nome);

    printf("Digite a quantidade disponível: ");
    scanf("%d", &novoNo->fruta.quantidade);

    printf("Digite o preço: ");
    scanf("%f", &novoNo->fruta.preco);

    novoNo->prox = lista;
    return novoNo;
}

int main()
{
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
            printf("Fruta cadastrada com sucesso!\n");
            break;
        case 2:
            // Aqui vai a função listar frutas, que ainda não foi implementada
            break;
        case 3:
            // Função buscar fruta
            break;
        case 4:
            // Função alterar fruta
            break;
        case 5:
            // Função excluir fruta
            break;
        case 6:
            // Função vender fruta
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
