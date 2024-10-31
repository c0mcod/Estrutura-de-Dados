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

// Função para criar um nó com a fruta
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

// Função para verificar duplicação de código
int codigoDuplicado(No *lista, int codigo)
{
    No *atual = lista;
    while (atual != NULL)
    {
        if (atual->fruta.codigo == codigo)
        {
            return 1; // Código já existe
        }
        atual = atual->prox;
    }
    return 0;
}

// Função para cadastrar uma nova fruta
No *cadastrarFruta(No *lista)
{
    Fruta frutaNova;

    printf("Digite o código da fruta: ");
    scanf("%d", &frutaNova.codigo);

    if (codigoDuplicado(lista, frutaNova.codigo))
    {
        printf("Erro: Código já cadastrado!\n");
        return lista;
    }

    printf("Digite o nome da fruta: ");
    scanf("%s", frutaNova.nome);

    printf("Digite a quantidade disponível: ");
    scanf("%d", &frutaNova.quantidade);

    printf("Digite o preço: ");
    scanf("%f", &frutaNova.preco);

    No *novoNo = criarNo(frutaNova);
    novoNo->prox = lista;
    return novoNo;
}

// Função para exibir a lista de frutas cadastradas
void exibirListaFruta(No *lista)
{
    // verificação para saber se a lista está vazia
    if (lista == NULL)
    {
        printf("Lista de frutas está vazia.\n");
        return;
    }

    No *atual = lista;
    printf("\n-------------------- Lista de Frutas --------------------\n");

    while (atual != NULL)
    {
        printf("Código: %d\n", atual->fruta.codigo);
        printf("Nome: %s\n", atual->fruta.nome);
        printf("Quantidade: %d\n", atual->fruta.quantidade);
        printf("Preço: R$%.2f\n\n", atual->fruta.preco);
        printf("--------------------\n\n");
        // se atual não for null(oq significa que ela não é a ultima e que tem um próximo nó) ela irá percorer cada informação da struct Fruta
        // depois o atual vai apontar para o próximo nó(fruta da lista)
        atual = atual->prox;
    }
}

// Função para alterar os dados de uma fruta
No *alterarFruta(No *lista) {
    int codigo;
    printf("Digite o código da fruta que deseja alterar: ");
    scanf("%d", &codigo);

    No *atual = lista;
    while (atual != NULL) {
        if (atual->fruta.codigo == codigo) {
            // se a fruta for encontrada pelo codigo, novos dados serão solicitados para o usuário
            printf("Fruta encontrada! Digite os novos dados:\n");
            // mesma coisa do de cadastramento, alterando diretamente no campo da struct
            printf("Novo nome da fruta: ");
            scanf("%s", atual->fruta.nome);

            printf("Nova quantidade disponível: ");
            scanf("%d", &atual->fruta.quantidade);

            printf("Novo preço: ");
            scanf("%f", &atual->fruta.preco);

            printf("Dados da fruta alterados com sucesso!\n");
            return lista; // Retorna a lista inalterada
        }
        atual = atual->prox; // Avança para o próximo nó
    }

    printf("Erro: Fruta com código %d não encontrada!\n", codigo);
    return lista; // Retorna a lista inalterada
}

// Função para buscar uma fruta pelo código
No *buscarFruta(No *lista) {
    int codigo;
    printf("Digite o código da fruta que deseja buscar: ");
    scanf("%d", &codigo);

    No *atual = lista;
    while (atual != NULL) {
        if (atual->fruta.codigo == codigo) {
            printf("Fruta encontrada!\n\n");
            printf("Nome da fruta: %s\n", atual->fruta.nome);
            printf("Quantidade disponível: %d\n", atual->fruta.quantidade);
            printf("Preço: R$%.2f\n", atual->fruta.preco);
            return lista;
        }
        atual = atual->prox; // Avança para o próximo nó
    }

    printf("Erro: Fruta com código %d não encontrada!\n", codigo);
    return lista;
}

int main() {
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
            exibirListaFruta(listaFrutas);
            break;
        case 3:
            listaFrutas = buscarFruta(listaFrutas);
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
