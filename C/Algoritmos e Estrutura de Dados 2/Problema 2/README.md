# Problema 2: Particionando e ordenando

O Quicksort é um algoritmo considerado muito rápido para a maioria das situações. Um dos fatores que influencia a sua eficiência é a escolha do pivô do algoritmo de particionamento.

Considere o algoritmo do Quicksort, em que o pivô escolhido é sempre o último elemento do intervalo considerado do vetor, e calcule a quantidade de vezes que a função PARTITION é chamada até que a entrada se torne ordenada.

Você deve implementar um programa que leia da entrada um conjunto de nomes com até 15 caracteres cada e que ordene-os de forma alfabética. Você deverá converter todas as letras maiúsculas para letras minúsculas antes de realizar a ordenação. Após a ordenação, você deve imprimir uma região indicada da lista ordenada com os nomes em letras minúsculas.

__Entrada__

A primeira linha da entrada contém o número *N* (2 ≤ N ≤ 100.000) de nomes a serem ordenados. Nas próximas *N* linhas são apresentados os nomes, um nome em cada linha. A linha seguinte contém dois números *P* (1 ≤ P ≤ N) da posição do primeiro nome a ser impresso e o número *M* (1 ≤ M ≤ N-P+1) de números a partir do *P*-éssimo nome.

__Saída__

Na primeira linha da saída, imprima o número de vezes que a função PARTITION é executada. Nas próximas *M* linhas, imprima os M nomes presentes a partir da *P*-éssima posição da lista ordenada, um nome a cada linha.

| Exemplo de Entrada  | Exemplo de Saída |
| ------------------- | ---------------- |
| 5                   | 3                |
| Daniel              | ana              |
| Ana                 | daniel           |
| Jose                | joao             |
| Silvia              | jose             |
| Joao                | silvia           |
| 1 5                 |                  |

| Exemplo de Entrada  | Exemplo de Saída |
| ------------------- | ---------------- |
| 10                  | 6                |
| Zurich              | aaaaa            |
| Zu                  | hu               |
| Wu                  | wei              |
| Hu                  | woo              |
| Zukemberg           | wu               |
| Wei                 | zoo              |
| Woo                 | zu               |
| Zoo                 | zukemberg        |
| Zuu                 | zurich           |
| aaaaa               | zuu              |
| 1 10                |                  |

| Exemplo de Entrada  | Exemplo de Saída |
| ------------------- | ---------------- |
| 10                  | 7                |
| USA                 | iran             |
| brazil              | iraq             |
| zimbabwe            | ukraine          |
| Burundi             | usa              |
| Iraq                | vietnam          |
| Vietnam             |                  |
| Greece              |                  |
| bhutan              |                  |
| Iran                |                  |
| Ukraine             |                  |
| 5 5                 |                  |
