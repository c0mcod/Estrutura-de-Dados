// Isso aqui é uma anotação que eu colei das instruções que foram passadas pelo o professor para eu não ter que alterar de aba a todo momento

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

// Algo que foi beem analisado durante uma revisão com o professor foi o caso do ponteiro de ponteiro no caso de excluir a fruta, uma breve explicação:
// o "**" da função pode remover a primeira fruta e mudar a "head" da lista, ou pode remover uma fruta no meio da lista, ajustando quem está antes dela para que ignore a fruta removida.
// é uma referência ao ponteiro head original, que aponta para o primeiro nó da lista.
// Com "**head", a função tem acesso ao ponteiro original e pode modificar a posição para onde ele aponta, afetando o ponteiro head fora da função.

// -------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aqui é os protótipos de função(ou assinaturas) 
typedef struct No No;
No *criarLista();
No *cadastrarFruta(No *lista);
void exibirListaFruta(No *lista);
No *alterarFruta(No *lista);
No *buscarFruta(No *lista);
void excluirFruta(No **lista, int codigo);
void venderFruta(No *lista, int codigo, int quantidade);

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
// Aqui vai aplicar dentro do if a função que eu criei acima pra ver se o codigo já existe ou não
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
        atual = atual->prox; // Move para o próximo nó(mesma coisa que rolou em algumas funções anteriores)
    }

    return 0; 
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
                // o "a" ali dps do "vendas.txt" é pra acrescentar sem apagar os outros, é modo de abertura do arquivo
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