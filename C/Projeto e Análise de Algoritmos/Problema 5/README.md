# Problema 5: Padrões em DNA

*Tempo Limite:* 0,5s (C/C++), 2s (Java)

Padrões em sequências de DNA são frequentemente encontrados nos genomas de diversos organismos. Um padrão interessante é a simetria em determinadas regiões do DNA. Esses padrões, em geral, são ligados a alguma funcionalidade como sítio de reconhecimento de enzima de restrição ou para formação de estruturas de haipin loop.

Porém, caso alguma mutação altere alguma base deste padrão em um dada indivíduo, esta sequência pode deixar de ter a mesma finalidade. Interessado na busca por regiões em sequências genômicas contendo esse tipo de padrões, um pesquisador pede a sua ajuda para que você escreva um programa que encontre tais regiões. Além de padrões presentes em sequências contíguas, ele pede para que você também procure por padrões em subsequências, ou seja, não nencessariamente contíguas.

Dada uma string S contendo a sequência a ser analisada e um conjunto de posições de S que possuem mutações conhecidas, a sua tarefa é determinar o tamanho da subsequência simétrica, ou seja, palíndrome, com o número máximo de mutações conhecidas. Caso existam múltiplas subsequências com o número máximo de mutações, imprima o tamanho da maior dessas subsequências.

__Entrada__

A entrada se inicia com uma linha contendo a string S de tamanho entre 1 e 2000 caracteres. Na segunda linha, é dado um inteiro N (0 <= N <= |S|) seguido de N posições de mutações conhecidas. As posições são números distintos entre 1 e |S|, inclusive.

__Saída__

Imprima um inteiro representando o tamanho do maior padrão simétrico com o número máximo de mutações como descrito acima.

| Exemplo de Entrada |
| ------------------ |
| GACACAT            |
| 0                  |

| Exemplo de Saída |
| ---------------- |
| 5                |

***

| Exemplo de Entrada |
| ------------------ |
| GATTACA            |
| 1 1                |

| Exemplo de Saída |
| ---------------- |
| 1                |

***

| Exemplo de Entrada |
| ------------------ |
| GATTACA            |
| 3 1 5 6            |

| Exemplo de Saída |
| ---------------- |
| 3                |

***

| Exemplo de Entrada |
| ------------------ |
| TATACTATA          |
| 2 5 9              |

| Exemplo de Saída |
| ---------------- |
| 7                |
