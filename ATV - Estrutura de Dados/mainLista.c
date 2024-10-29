#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* criarLista() {
    return NULL;
}

void inserirLista(struct Node** head, int valor) {
    struct Node* novoNode = (struct Node*) malloc(sizeof(struct Node));
    if (novoNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novoNode->data = valor;
    novoNode->next = *head;
    *head = novoNode;
}

void exibirLista(struct Node* head) {
    struct Node* atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->data);
        atual = atual->next;
    }
    printf("NULL\n");
}

int verificarVazia(struct Node* head) {
    return head == NULL;
}

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

void excluirLista(struct Node** head, int data) {
    struct Node* atual = *head;
    struct Node* anterior = NULL;

    while (atual != NULL && atual->data != data) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL) {
        printf("Elemento não encontrado na lista.\n");
        return;
    }

    if (anterior == NULL) {
        *head = atual->next;
    } else {
        anterior->next = atual->next;
    }
    free(atual);
}

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

void inserirOrdenado(struct Node** head, int data) {
    struct Node* novoNode = (struct Node*) malloc(sizeof(struct Node));
    if (novoNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
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
