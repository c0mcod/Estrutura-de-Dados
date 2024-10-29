#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *criarLista()
{
    return NULL;
}

void inserirLista(struct Node **head, int valor)
{
    struct Node *novoNode = (struct Node *)malloc(sizeof(struct Node));

    // esse if é apenas para informar se a alocação foi bem sucedida.
    if (novoNode == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    // atribui "valor" no campo data da struct(o valor que vai ser adicionado na lista)
    novoNode->data = valor;

    // novoNode vai apontar pro que o head estava apontando, no caso, o antigo 1° nó
    // o novo node agora tá apontando pro antigo, o que mantem a conexão, e logo fazemos o head apontar pro novoNode
    novoNode->next = *head;
    // Head atualizado apontando para o novo 1° nó(transcendi quando entendi essa lógica kkk)
    *head = novoNode;
}

void exibirLista(struct Node *head)
{
    struct Node *atual = head;
    // a variavel do tipo struct Node vai pegar a 1° posição que é oq o head tá apontando(tipo em array quando diz [1] | head = [1])
    // enquanto não for diferente de NULL, que é para aonde o ultimo elemento aponta, a iteração continua
    while (atual != NULL)
    {
        printf("%d -> ", atual->data);

        // Para passar para o próximo elemento da lista
        atual = atual->next;
    }
    // confirmação para o usuário
    printf("NULL\n");
}

int verificarVazia(struct Node *head)
{
    // confirmação básica para saber se está vázia, se o head apontar apontar pra NUll, não tem nada
    // 1 vazia(verdadeiro) e 0 pelo menos um nó(falso)
    return head == NULL;
}

struct Node *buscarLista(struct Node *head, int data)
{
    // essa função é um pouco confusa, mas funciona assim:

    // enquanto não for NULL, ele vai verificar se o valor do nó atual é igual ao valor
    // que estamos procurando, se for igual, ele retorna o nó atual, se não for
    // ele vai para o próximo nó, até encontrar o que estamos procurando ou até o final
    struct Node *atual = head;
    while (atual != NULL)
    {
        if (atual->data == data)
        {
            return atual;
        }
        // se não for igual, ele vai para o próximo nó
        atual = atual->next;
    }
    return NULL;
}

void excluirLista(struct Node **head, int data)
{
    // atual começa a partir do 1° elemento da lista, aonde head aponta
    struct Node *atual = *head;
    // anterior é definido como NULL pq não há nada antes do 1° elemento
    struct Node *anterior = NULL;

    // enquanto o atual for diferente de NULL e for diferente de data(valor a ser buscado), irá continuar a busca
    while (atual != NULL && atual->data != data)
    {
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL)
    {
        printf("Elemento não encontrado na lista.\n");
        return;
    }

    // O que foi feito é que, o 'anterior' irá "pular" para o next do que o atual aponta, fazendo perder a conexão com o número que queremos remover
    if (anterior == NULL)
    {
        *head = atual->next;
    }
    else
    {
        anterior->next = atual->next;
    }
    free(atual);
}

void liberarLista(struct Node **head)
{
    // aqui é bem interessante e simples
    struct Node *atual = *head;
    struct Node *proximo;
    // enquanto atual não for NULL, ainda tem elementos na lista para liberar
    while (atual != NULL)
    {
        // a referencia do proximo nó depois do atual é guardada para continuar seguindo
        proximo = atual->next;
        // FREE para limpar a memoria
        free(atual);
        // atual irá para o próximo nó repetir o processor
        atual = proximo;
    }
    // Head foi definido como NULL para indicar que a lista está vazia
    *head = NULL;
}

void inserirOrdenado(struct Node **head, int data)
{
    struct Node *novoNode = (struct Node *)malloc(sizeof(struct Node));
    if (novoNode == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novoNode->data = data;
    // Se a lista está vazia (*head == NULL)
    // ou o valor do primeiro nó ((*head)->data) é maior ou igual ao novo valor (data),
    // o novo nó deve ser inserido no início da lista.
    if (*head == NULL || (*head)->data >= data)
    {
        // ponteiro next do novoNode para o inicio do head
        novoNode->next = *head;
        // head definindo como o começo o novoNode, fazendo dele o primeiro nó da lista
        *head = novoNode;

        // se o nó que o usuario for inserir for diferente de NULL e o valor do próximo nó for menor doq foi inserido, a função continuará andando
    }
    else
    {
        struct Node *atual = *head;

        while (atual->next != NULL && atual->next->data < data)
        {
            atual = atual->next;
        }
        // aqui o atual funciona como um batedor, ele aponta para o próximo nó depois, para o atual linkar com o que ele aponta
        // pegando a posição sem perder a conexão com o anterior, que está apontado por atual
        novoNode->next = atual->next;
        atual->next = novoNode;
    }
}

int main()
{
    struct Node *lista = criarLista();
    inserirOrdenado(&lista, 1);
    inserirOrdenado(&lista, 2);
    inserirOrdenado(&lista, 4);
    inserirOrdenado(&lista, 5);
    exibirLista(lista); // Saída: 3 -> 5 -> 8 -> NULL
    inserirOrdenado(&lista, 3);
    exibirLista(lista);

    return 0;
}
