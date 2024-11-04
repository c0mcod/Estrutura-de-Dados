// frutas.h
#ifndef FRUTAS_H
#define FRUTAS_H

typedef struct mercadoDeFrutas {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Fruta;

typedef struct No {
    Fruta fruta;
    struct No *prox;
} No;

// Funções para manipulação da lista e das frutas
No *criarNo(Fruta fruta);
No *cadastrarFruta(No *lista);
void exibirListaFruta(No *lista);
int codigoDuplicado(No *lista, int codigo);
No *buscarFruta(No *lista, int codigo);
No *alterarFruta(No *lista, int codigo);
void excluirFruta(No **lista, int codigo);
void venderFruta(No *lista, int codigo, int quantidade);

#endif
