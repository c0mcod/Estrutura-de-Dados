# Estruturas de Dados em C

Este repositório contém a atividade e o  trabalho prático proposto na disciplina de Estruturas de Dados pelo nosso professor Berg Carvalho, com foco em listas encadeadas e outras estruturas. 


* O objetivo deste trabalho prático é permitir que os alunos demonstrem suas habilidades
adquiridas ao longo do curso de estrutura de dados no uso de listas, ponteiros e funções.*

## Sumário

- [Descrição](#descrição)
- [Pré-requisitos](#pré-requisitos)
- [Funcionalidades](#funcionalidades)
- [Como Executar](#como-executar)
- [Exemplos de Uso](#exemplos-de-uso)
- [Contribuição](#contribuição)

## Descrição

Este projeto contém a implementação de uma lista encadeada em C, incluindo operações de inserção, busca, exclusão e exibição de nós. Há uma função específica para inserir elementos na lista em ordem crescente, que o nosso professor pediu para implementar.

## Pré-requisitos

- Compilador C (gcc ou outro)
- Conhecimentos básicos em C e Git

## Funcionalidades

- **criarLista**: inicializa uma lista vazia.
- **inserirLista**: insere um novo elemento no início da lista.
- **inserirOrdenado**: insere um elemento na posição correta para manter a lista ordenada.
- **exibirLista**: exibe todos os elementos da lista.
- **verificarVazia**: verifica se a lista está vazia.
- **buscarLista**: busca por um elemento específico na lista.
- **excluirLista**: exclui um elemento específico da lista.
- **liberarLista**: libera a memória alocada para a lista.

## Exemplos de Uso

```c
struct Node* lista = criarLista();
inserirOrdenado(&lista, 5);
inserirOrdenado(&lista, 3);
inserirOrdenado(&lista, 8);
exibirLista(lista); // Saída: 3 -> 5 -> 8 -> NULL
```
