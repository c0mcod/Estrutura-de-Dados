# Estruturas de Dados em C

Este repositório contém a atividade e o trabalho prático proposto na disciplina de Estruturas de Dados pelo professor Berg Carvalho, com foco em listas encadeadas, manipulação de dados heterogêneos e operações dinâmicas com ponteiros em C.

## Sumário

- [Descrição](#descrição)
- [Pré-requisitos](#pré-requisitos)
- [Funcionalidades](#funcionalidades)
- [Como Executar](#como-executar)
  - [Online GDB](#online-gdb)
  - [Localmente](#localmente)
- [Contribuição](#contribuição)

## Descrição

Este projeto é dividido em duas partes: **atividade** e **trabalho prático**.

1. **Atividade**: Implementação de uma lista encadeada em C, com operações básicas como inserção, busca, exclusão, exibição e inserção ordenada.

2. **Trabalho Prático - Mercado de Frutas**: 
   Um programa em C que simula um pequeno mercado de frutas. As frutas são representadas como estruturas heterogêneas contendo:
   - **Código**: Identificador único para cada fruta.
   - **Nome**: Nome da fruta.
   - **Quantidade**: Quantidade em estoque.
   - **Preço**: Preço unitário da fruta.

   ### Funcionalidades específicas do trabalho prático:
   - **Cadastrar Fruta**: Cadastra uma nova fruta na lista.
   - **Listar Frutas**: Exibe todas as frutas cadastradas com seus respectivos dados.
   - **Buscar Fruta**: Busca uma fruta pelo código e exibe seus dados.
   - **Alterar Fruta**: Permite modificar os dados de uma fruta cadastrada.
   - **Excluir Fruta**: Exclui uma fruta pelo código, desde que o estoque esteja vazio.
   - **Vender Fruta**: Realiza a venda de uma fruta, ajustando o estoque e registrando a venda em um arquivo de texto (`vendas.txt`).

## Requisitos

- As frutas são representadas por estruturas heterogêneas.
- Os registros das frutas são alocados dinamicamente e armazenados em uma lista encadeada.
- O programa deve ser modular, utilizando funções para cada operação.
- Códigos de frutas duplicados não são permitidos no cadastro.
- A venda de frutas deve respeitar a quantidade disponível em estoque.
- As vendas devem ser registradas em um arquivo (`vendas.txt`), incluindo detalhes como o código, nome da fruta, quantidade vendida e valor total.

## Pré-requisitos

- Compilador C (como `gcc`)
- Conhecimentos básicos em C e Git

## Funcionalidades da Atividade

- **criarLista**: Inicializa uma lista vazia.
- **inserirLista**: Insere um novo elemento no início da lista.
- **inserirOrdenado**: Insere um elemento na posição correta para manter a lista ordenada.
- **exibirLista**: Exibe todos os elementos da lista.
- **verificarVazia**: Verifica se a lista está vazia.
- **buscarLista**: Busca um elemento específico na lista.
- **excluirLista**: Exclui um elemento específico da lista.
- **liberarLista**: Libera toda a memória alocada para a lista.

## Como Executar

### Online GDB

1. Copie o código-fonte e cole em arquivos separados com os mesmos nomes (`main.c`, `mercado.c`).
2. Execute o código clicando em **RUN**.

### Localmente

1. Clone o repositório no seu computador:
   ```bash
   git clone https://github.com/c0mcod/Estrutura-de-Dados
   ```
2. Compile o código com o comando:
   ```bash
   gcc main.c mercado.c -o mercado
   ```
3. Execute o programa com:
   ```bash
   ./mercado
   ```

## Contribuição

Este projeto foi desenvolvido individualmente, mas sugestões e melhorias são bem-vindas! Caso queira contribuir, fique à vontade para abrir um pull request.