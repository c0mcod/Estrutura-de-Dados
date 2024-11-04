// frutas.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frutas.h"

No *criarNo(Fruta fruta) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo) {
        novoNo->fruta = fruta;
        novoNo->prox = NULL;
    }
    return novoNo;
}

int codigoDuplicado(No *lista, int codigo) {
    No *atual = lista;
    while (atual != NULL) {
        if (atual->fruta.codigo == codigo) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

No *cadastrarFruta(No *lista) {
    Fruta novaFruta;
    printf("Digite o código da fruta: ");
    scanf("%d", &novaFruta.codigo);

    if (codigoDuplicado(lista, novaFruta.codigo)) {
        printf("Código duplicado! Não é possível cadastrar.\n");
        return lista;
    }

    printf("Digite o nome da fruta: ");
    scanf(" %[^\n]s", novaFruta.nome);
    printf("Digite a quantidade: ");
    scanf("%d", &novaFruta.quantidade);
    printf("Digite o preço: ");
    scanf("%f", &novaFruta.preco);

    No *novoNo = criarNo(novaFruta);
    novoNo->prox = lista;
    return novoNo;
}

void exibirListaFruta(No *lista) {
    if (lista == NULL) {
        printf("Lista de frutas está vazia.\n");
        return;
    }
    No *atual = lista;
    printf("\n--- Lista de Frutas ---\n");
    while (atual != NULL) {
        printf("Código: %d, Nome: %s, Quantidade: %d, Preço: R$%.2f\n",
               atual->fruta.codigo, atual->fruta.nome,
               atual->fruta.quantidade, atual->fruta.preco);
        atual = atual->prox;
    }
}

No *buscarFruta(No *lista, int codigo) {
    No *atual = lista;
    while (atual != NULL) {
        if (atual->fruta.codigo == codigo) {
            return atual;
        }
        atual = atual->prox;
    }
    printf("Fruta não encontrada.\n");
    return NULL;
}

No *alterarFruta(No *lista, int codigo) {
    No *atual = buscarFruta(lista, codigo);
    if (atual) {
        printf("Digite o novo nome da fruta: ");
        scanf(" %[^\n]s", atual->fruta.nome);
        printf("Digite a nova quantidade: ");
        scanf("%d", &atual->fruta.quantidade);
        printf("Digite o novo preço: ");
        scanf("%f", &atual->fruta.preco);
        printf("Fruta alterada com sucesso!\n");
    }
    return lista;
}

void excluirFruta(No **lista, int codigo) {
    No *atual = *lista, *anterior = NULL;
    while (atual != NULL && atual->fruta.codigo != codigo) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Fruta não encontrada.\n");
        return;
    }
    if (anterior == NULL) {
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    free(atual);
    printf("Fruta excluída com sucesso!\n");
}

void venderFruta(No *lista, int codigo, int quantidade) {
    No *atual = buscarFruta(lista, codigo);
    if (atual && atual->fruta.quantidade >= quantidade) {
        atual->fruta.quantidade -= quantidade;
        float valorVenda = quantidade * atual->fruta.preco;

        FILE *arquivoVendas = fopen("vendas.txt", "a");
        if (arquivoVendas == NULL) {
            printf("Erro ao abrir o arquivo de vendas.\n");
            return;
        }
        fprintf(arquivoVendas, "Código: %d, Nome: %s, Quantidade vendida: %d, Valor total: R$%.2f\n",
                atual->fruta.codigo, atual->fruta.nome, quantidade, valorVenda);
        fclose(arquivoVendas);

        printf("Venda realizada! Quantidade restante: %d\n", atual->fruta.quantidade);
    } else {
        printf("Quantidade insuficiente ou fruta não encontrada.\n");
    }
}
