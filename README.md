# Estruturas de Dados em C

Este repositório contém a atividade e o trabalho prático proposto na disciplina de Estruturas de Dados pelo professor Berg Carvalho, com foco em listas encadeadas e manipulação de estruturas de dados usando C.

> **Objetivo**: Demonstrar o uso de listas encadeadas, ponteiros e funções para manipulação de dados em C, reforçando habilidades essenciais para o desenvolvimento de estruturas de dados.

## Sumário

- [Descrição](#descrição)
- [Pré-requisitos](#pré-requisitos)
- [Funcionalidades](#funcionalidades)
- [Como Executar](#como-executar)
  - [Online GDB](#online-gdb)
  - [Localmente](#localmente)
- [Contribuição](#contribuição)

## Descrição

Este projeto contém a implementação de uma lista encadeada em C, permitindo operações fundamentais como **inserção**, **busca**, **exclusão** e **exibição** de nós. Há uma função especial para inserir elementos de forma ordenada, atendendo aos requisitos da atividade prática.

## Pré-requisitos

- Compilador C (por exemplo, gcc)
- Conhecimentos básicos em C e Git

## Funcionalidades

- **criarLista**: Inicializa uma lista vazia.
- **inserirLista**: Insere um novo elemento no início da lista.
- **inserirOrdenado**: Insere um elemento em ordem crescente.
- **exibirLista**: Exibe todos os elementos presentes na lista.
- **verificarVazia**: Verifica se a lista está vazia.
- **buscarLista**: Busca um elemento específico na lista.
- **excluirLista**: Exclui um elemento específico da lista.
- **liberarLista**: Libera toda a memória alocada para a lista.

## Como Executar

### Online GDB

1. Copie o código-fonte e cole em arquivos separados com os mesmos nomes (`main.c`, `mercado.c`).
2. Execute o código clicando em **RUN**.

### Localmente

1. Clone o repositório no seu computador.
2. Compile o código com o comando:
   ```bash
   gcc main.c mercado.c -o mercado
   ```
3. Execute o programa com:
   ```bash
   ./mercado
   ```

## Contribuição

Este projeto foi desenvolvido individualmente. Sugestões e melhorias são bem-vindas! Caso queira contribuir, fique à vontade para abrir um pull request.