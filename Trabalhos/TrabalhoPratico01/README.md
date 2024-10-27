# Trabalho Prático 01 - Funções para Árvores Binárias

| Academico:    | [José A. Q. C. Gomes <code>@JoseComparotto</code>](https://github.com/JoseComparotto) | RA: 398439413098 |
| ------------- | ------------------------------------------------------------------------------------- | :--------------: |
| Curso:        | Ciência da Computação                                                                 | Noturno          |
| Professora:   | Noiza Waltrick Trindade                                                               |                  |
| Disciplina:   | Algoritmos e Estrutura de Dados Avançados                                             | 2024.2 - Turma A |
| Universidade: | Anhanguera-Uniderp - Matriz                                                           | Campo Grande, MS |
| Atividade     | [Trabalho Prático 01 - Funções para Árvores Binárias](./docs/EDA%20-%20Trabalho%20Pratico%2001.pdf) | Data: 27/10/2024 |

## Objetivo

Neste trabalho, vocês deverão implementar quatro funções para manipulação e
consulta de uma árvore binária de busca (ABB). O foco será em operações de
consulta e percursos (em diferentes ordens) em uma árvore binária, além da
implementação de uma função que imprime os elementos da árvore por nível.

## Funções a serem implementadas:

### 1. Consulta

```c
int consulta_ArvBin(ArvBin *raiz, int valor);
```

**Objetivo:** Esta função deve procurar um valor na árvore binária de busca.

**Descrição:** A função recebe como parâmetros o ponteiro para a raiz da
árvore e o valor que será buscado. Ela deve percorrer a árvore de maneira
eficiente (de acordo com as propriedades da ABB) e retornar 1 se o valor
for encontrado ou 0 caso o valor não exista na árvore.

#### Resposta

https://github.com/JoseComparotto/aeda/blob/eee5f169685811f13e63393cb08ca2f827bba9b0/Trabalhos/TrabalhoPratico01/src/ArvoreBinaria.c#L228-L241

### 2. Impressão em Pré-Ordem

```c
void preOrdem_ArvBin(ArvBin *raiz);
```

**Objetivo:** Esta função deve realizar o percurso pré-ordem na árvore e
imprimir os valores dos nós.

**Descrição:** No percurso pré-ordem, a visitação dos nós segue a ordem:
1. Visita o nó atual (raiz da subárvore).
2. Percorre a subárvore esquerda.
3. Percorre a subárvore direita.

#### Resposta

https://github.com/JoseComparotto/aeda/blob/eee5f169685811f13e63393cb08ca2f827bba9b0/Trabalhos/TrabalhoPratico01/src/ArvoreBinaria.c#L208-L216

### 3. Impressão em Pós-Ordem

```c
void posOrdem_ArvBin(ArvBin *raiz);
```

**Objetivo:** Esta função deve realizar o percurso pós-ordem na árvore e imprimir os valores dos nós.

**Descrição:** No percurso pós-ordem, a visitação dos nós segue a ordem:
1. Percorre a subárvore esquerda.
2. Percorre a subárvore direita.
3. Visita o nó atual (raiz da subárvore).

#### Resposta

https://github.com/JoseComparotto/aeda/blob/eee5f169685811f13e63393cb08ca2f827bba9b0/Trabalhos/TrabalhoPratico01/src/ArvoreBinaria.c#L218-L226

### 4. Impressão Por Nível

```c
void imprimePorNivel_ArvBin(ArvBin *raiz);
```

**Objetivo:** Esta função deve imprimir os valores dos nós **por nível** na árvore binária.

**Descrição:** A ideia é visitar a árvore nível por nível, começando pela raiz. Este é um exemplo de percurso em **largura** (ou *breadth-first*).
A função deve imprimir os nós da árvore organizados por nível. Por exemplo, primeiro o nó raiz, depois os filhos da raiz, depois os netos, e assim por diante.

#### Resposta

Parte 1 - Gerar matriz por nível

https://github.com/JoseComparotto/aeda/blob/eee5f169685811f13e63393cb08ca2f827bba9b0/Trabalhos/TrabalhoPratico01/src/ArvoreBinaria.c#L254-L311

Parte 2 - Imprimir níveis

https://github.com/JoseComparotto/aeda/blob/eee5f169685811f13e63393cb08ca2f827bba9b0/Trabalhos/TrabalhoPratico01/src/ArvoreBinaria.c#L313-L355
