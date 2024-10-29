# Implementação de Lista Encadeada em C

## 1. Declarações de Bibliotecas

```c
#include <stdio.h>
#include <stdlib.h>
```
- **`#include <stdio.h>`**: Inclui a biblioteca padrão de entrada e saída, permitindo o uso de funções como `printf` e `fprintf`.
- **`#include <stdlib.h>`**: Inclui a biblioteca padrão de funções utilitárias, como `malloc` (para alocar memória) e `exit`.

## 2. Definindo a Estrutura `Node`

```c
struct Node {
    int data;
    struct Node* next;
};
```
- **`struct Node`**: Declara uma estrutura chamada `Node`, que representa cada elemento (nó) da lista.
  - **`int data`**: Um campo de dados, que armazena o valor de cada nó.
  - **`struct Node* next`**: Um ponteiro para o próximo nó na lista.

## 3. Função `criarLista`

```c
struct Node* criarLista() {
    return NULL;
}
```
- **`criarLista`**: Inicializa a lista encadeada, retornando um ponteiro `NULL`, que indica uma lista vazia.

## 4. Função `inserirLista`

```c
void inserirLista(struct Node** head, int valor) {
    struct Node* novoNode = (struct Node*) malloc(sizeof(struct Node));
    if (novoNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória.
");
        exit(EXIT_FAILURE);
    }
    novoNode->data = valor;
    novoNode->next = *head;
    *head = novoNode;
}
```
- **Parâmetros**:
  - **`struct Node** head`**: Um ponteiro duplo para o primeiro nó da lista.
  - **`int valor`**: O valor a ser inserido no novo nó.
- **`malloc(sizeof(struct Node))`**: Aloca memória para o novo nó.
- **Inserção na Lista**: Atualiza o ponteiro `head` para apontar para o novo nó.

## 5. Função `exibirLista`

```c
void exibirLista(struct Node* head) {
    struct Node* atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->data);
        atual = atual->next;
    }
    printf("NULL
");
}
```
- **`exibirLista`**: Exibe os valores de todos os nós na lista encadeada.

## 6. Função `verificarVazia`

```c
int verificarVazia(struct Node* head) {
    return head == NULL;
}
```
- **`verificarVazia`**: Retorna `1` (verdadeiro) se a lista estiver vazia (`head == NULL`).

## 7. Função `buscarLista`

```c
struct Node* buscarLista(struct Node* head, int data) {
    struct Node* atual = head;
    while (atual != NULL) {
        if (atual->data == data) {
            return atual;
        }
        atual = atual->next;
    }
    return NULL;
}
```
- **`buscarLista`**: Procura um nó com um valor específico (`data`) e retorna um ponteiro para ele se encontrado.

## 8. Função `excluirLista`

```c
void excluirLista(struct Node** head, int data) {
    struct Node* atual = *head;
    struct Node* anterior = NULL;

    while (atual != NULL && atual->data != data) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL) {
        printf("Elemento não encontrado na lista.
");
        return;
    }

    if (anterior == NULL) {
        *head = atual->next;
    } else {
        anterior->next = atual->next;
    }
    free(atual);
}
```
- **`excluirLista`**: Remove o primeiro nó que contém o valor `data`.

## 9. Função `liberarLista`

```c
void liberarLista(struct Node** head) {
    struct Node* atual = *head;
    struct Node* proximo;

    while (atual != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    *head = NULL;
}
```
- **`liberarLista`**: Libera todos os nós da lista e redefine `head` para `NULL`.

## 10. Função `inserirOrdenado`

```c
void inserirOrdenado(struct Node** head, int data) {
    struct Node* novoNode = (struct Node*) malloc(sizeof(struct Node));
    if (novoNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória.
");
        exit(EXIT_FAILURE);
    }
    novoNode->data = data;

    if (*head == NULL || (*head)->data >= data) {
        novoNode->next = *head;
        *head = novoNode;
    } else {
        struct Node* atual = *head;
        while (atual->next != NULL && atual->next->data < data) {
            atual = atual->next;
        }
        novoNode->next = atual->next;
        atual->next = novoNode;
    }
}
```
- **`inserirOrdenado`**: Insere um nó na lista de forma ordenada (ordem crescente).
