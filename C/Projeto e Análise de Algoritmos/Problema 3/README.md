# Problema 3: Vigilância

*Tempo Limite:* 0,5s (C/C++), 2s (Java)

A cidade de Nova York atrai mais de 50 milhões de visitantes anualmente, o que mantém o comércio da cidade sempre aquecido e por isso o turismo traz diversos benefícios econômicos para a cidade. Para manter a cidade atrativa para futuros turistas, o prefeito de Nova York pretende ampliar o seu sistema de vigilância implantando pequenas guaritas para garantir mais segurança e aumentar o número de visitantes. Como Manhattan contém os principais atrativos da cidade, então inicialmente as guaritas serão implantadas em uma parte central de Manhattan. Devido ao formato de grade das ruas de Manhattan, uma guarita colocada em uma intersecção pode cobrir ambas as ruas por completo. As posições escolhidas para receber guaritas deverão garantir que todas as ruas de uma dada região sejam cobertas pelo sistema de vigilância.

Dado um conjunto de M intersecções de maior interesse, onde obrigatoriamente terão guaritas implantadas, a prefeitura de Nova York gostaria que você listasse todos possíveis lugares para se implantar um número mínimo de guaritas de forma a garantir a cobertura total de uma dada região de Manhattan.

A região a ser considerada para a implantação do sistema de vigilância é um conjunto de N x N ruas. Exemplo: seja uma região de 4x4 ruas, sendo a intersecção (x,y) dada pela localização da linha x e da coluna y. Caso o conjunto de pontos de interesse seja (1,4) e (4,1), então haveriam, portanto, duas possibilidades de se posicionar as outras duas guaritas: i) (2,2) e (3,3); e ii) (3,2) e (2,3). A sua tarefa é implementar um programa eficiente que liste todas as possibilidades para implantação das guaritas.

__Entrada__

A primeira linha de um caso de teste contém os inteiros N (1 < N <= 10) e M (1 <= M <= N). Cada uma das próximas M linhas apresenta as coordenadas x e y, separados por um espaço em branco, de um ponto de interesse a receber uma guarita obrigatoriamente, sendo x a linha e y a coluna do ponto de interesse. É garantido que não existirá sobreposição entre as coberturas dos pontos de interesse em cada caso, ou seja, não haverá um par de pontos que cubram uma mesma linha ou a uma mesma coluna.


__Saída__

Seu programa deve imprimir uma sequência de combinações para localização das guaritas. Para cada combinação, imprima uma linha com *N* números com as coordenadas das linhas de cada guarita, sendo que o primeiro número representa a linha em que a guarita da coluna 1 será implantada, o segundo número representa a linha em que a guarita da coluna 2 será colocada, e assim por diante. As linhas deverão ser impressas em ordem lexicográfica.

| Exemplo de Entrada | Exemplo de Saída |
| ------------------ | ---------------- |
| 3 1                | 1 2 3            |
| 2 2                | 3 2 1            |


| Exemplo de Entrada | Exemplo de Saída |
| ------------------ | ---------------- |
| 4 2                | 4 2 3 1          |
| 1 4                | 4 3 2 1          |
| 4 1                |                  |

| Exemplo de Entrada | Exemplo de Saída |
| ------------------ | ---------------- |
| 5 3                | 1 2 4 3 5        |
| 1 1                | 1 2 5 3 4        |
| 2 2                |                  |
| 3 4                |                  |


| Exemplo de Entrada | Exemplo de Saída |
| ------------------ | ---------------- |
| 8 5                | 1 2 4 5 3 7 6 8  |
| 1 1                | 1 2 8 5 3 7 6 4  |
| 3 5                | 1 4 2 5 3 7 6 8  |
| 5 4                | 1 4 8 5 3 7 6 2  |
| 7 6                | 1 8 2 5 3 7 6 4  |
| 6 7                | 1 8 4 5 3 7 6 2  |
