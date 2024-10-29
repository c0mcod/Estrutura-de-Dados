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


typedef struct No // Construção padrão de uma lista, um dado do tipo da struct ponteiro para o próximo nó
{
    // a váriavel "fruta" é do tipo da estrutura anterior que permite que cada nó(dessa estrutura No) possa ter todos os dados de uma fruta nesse mercado
    Fruta fruta;
    struct No *prox;
} No;


No *criarNo(Fruta fruta)// Função para criar o primeiro nó
{
    No *novoNo = (No *)malloc(sizeof(No));

    if (novoNo)
    {
    // novoNo->frut significa: "vá até o ponteiro novoNo, acesse o que ele está apontando (a estrutura em si), e então acesse o membro frut dessa estrutura."
        novoNo->fruta = fruta;
        novoNo->prox = NULL;
    }
    return novoNo;
}

// Função para criar a lista
struct No *criarLista()
{
    return NULL;
}

struct No *cadastrarFruta(struct No *lista){
    struct No*novoNo = (struct No *) malloc(sizeof(struct No));
    if (novoNo == NULL){
        printf("Não foi possível alocar memoria para a nova fruta.\n");
        return lista;
    }
    printf("Digite o código da fruta: ");
    scanf("%d", &novoNo->fruta.codigo);

    printf("digite o nome da fruta: ");
    scanf("%d", &novoNo -> fruta.nome);

    printf("Digite a quantidade disponivel: ");
    scanf("%d", &novoNo -> fruta.quantidade);

    printf("Digite o preço: ");
    scanf("%f", &novoNo->fruta.preco);

    novoNo -> prox = lista;
    return novoNo;
}

int main() {
    struct No *listaFrutas = criarLista();
    int op;
    int valor;
    do {
        exibirMenu();
        scanf("%d", &op);
        switch(op) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(op != 7);

    return 0;
}
