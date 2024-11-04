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
No *alterarFruta(No *lista)
{
    int codigo;
    printf("Digite o código da fruta que deseja alterar: ");
    scanf("%d", &codigo);

    No *atual = lista;
    while (atual != NULL)
    {
        if (atual->fruta.codigo == codigo)
        {
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
No *buscarFruta(No *lista)
{
    // mesmo paranuê de encontrar pelo codigo da ultima função, só troquei os prints para imprimir as informações
    int codigo;
    printf("Digite o código da fruta que deseja buscar: ");
    scanf("%d", &codigo);

    No *atual = lista;
    while (atual != NULL)
    {
        if (atual->fruta.codigo == codigo)
        {
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

void excluirFruta(No **lista, int codigo)
{
    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL && atual->fruta.codigo != codigo)
    {
        anterior = atual;
        atual = atual->prox;
    }

    // verificar se a fruta não foi encontrada(se ela for null)
    if (atual == NULL)
    {
        printf("Erro: Fruta com código %d não encontrada!\n", codigo);
        return;
    }

    // verificar se a fruta é a primeira da lista(cabeça)
    if (anterior == NULL)
    {
        *lista = atual->prox;
    }

    // verificar se a fruta está em outro lugar, que não seja a cabeça(primeira)
    else
    {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Fruta de codigo %d excluída.", codigo);
}

int verificarFruta(No *lista, int codigo)
{
    No *atual = lista;

    // Percorre a lista em busca do código
    while (atual != NULL)
    {
        if (atual->fruta.codigo == codigo)
        {
            return 1; // Fruta encontrada
        }
        atual = atual->prox; // Move para o próximo nó
    }

    return 0; // Fruta não encontrada
}

void venderFruta(No *lista, int codigo, int quantidade)
{
    // Verificar o código da fruta na lista para garantir que ela existe
    // Verificar a quantidade disponível da fruta para garantir que a quantidade solicitada para venda está no estoque
    // Diminuir a quantidade da fruta no estoque após a venda
    // Registrar a venda em um arquivo vendas.txt com informações como o código da fruta, nome, quantidade vendida e valor total da venda

    // Procura a fruta pelo código
    No *atual = lista;
    while (atual != NULL)
    {
        if (atual->fruta.codigo == codigo)
        {
            // Verifica se a quantidade desejada está disponível
            if (atual->fruta.quantidade >= quantidade)
            {
                // Calcula o valor da venda
                float valorVenda = quantidade * atual->fruta.preco;

                // Diminui a quantidade no estoque
                atual->fruta.quantidade -= quantidade;

                // Abre o arquivo para registrar a venda
                FILE *arquivoVendas = fopen("vendas.txt", "a");
                if (arquivoVendas == NULL)
                {
                    printf("Erro ao abrir o arquivo de vendas.\n");
                    return;
                }

                // Escreve os detalhes da venda no arquivo
                fprintf(arquivoVendas, "Código: %d\n", atual->fruta.codigo);
                fprintf(arquivoVendas, "Nome: %s\n", atual->fruta.nome);
                fprintf(arquivoVendas, "Quantidade vendida: %d\n", quantidade);
                fprintf(arquivoVendas, "Valor total: R$%.2f\n", valorVenda);
                fprintf(arquivoVendas, "----------------------\n");

                // Fecha o arquivo
                fclose(arquivoVendas);

                printf("Venda realizada com sucesso!\n");
                printf("Quantidade restante de %s: %d\n", atual->fruta.nome, atual->fruta.quantidade);
            }
            else
            {
                printf("Quantidade insuficiente em estoque para a venda.\n");
            }
            return;
        }
        atual = atual->prox; // Move para o próximo nó
    }

    // Se o código não foi encontrado
    printf("Fruta com o código %d não encontrada.\n", codigo);
}

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
