# Problema 2: Intercalação de vetores

*Tempo Limite:* 0,5s (C/C++), 2s (Java)

Considere um conjunto de K vetores ordenadas de números inteiros. Implemente uma solução eficiente para intercalar todos esses vetores e obter um único vetor ordenado de N números (o total de números nas K sequências é N). Para cada iteração i de intercalação, a ordenação deverá considerar o menor número de cada vetor para descobrir o i-ésimo (1 <= i <= N) menor número entre todas as sequências. Após encontrar o menor entre esses números, o menor número deve ser removido do seu vetor original e ser inserido no vetor final. Desta forma, o número seguinte desta sequência original será considerado como o menor número entre os números restantes deste vetor na próxima iteração. O seu programa deve imprimir o menor número de cada um dos vetores de entrada antes da intercalação do i-ésimo menor número. Imprima os números em ordem crescente.

*7 7 9 10 13 18 20*

*2 4 4*

*3 4 8 9*

*3 8 9 9 10*

*9 12 20 23*

No exemplo acima, temos 5 vetores ordenados. A primeira iteração do processo de intercalação compara os primeiros números dos vetores. Para i=1, o seu programa deve imprimir esses números em ordem crescente, ou seja, 2 3 3 7 9 para o exemplo acima. Após a remoção do número 2 do segundo vetor, teríamos ainda os seguintes elementos nos vetores:

*7 7 9 10 13 18 20*

*4 4*

*3 4 8 9*

*3 8 9 9 10*

*9 12 20 23*

Para i=2, o seu programa deve imprimir os primeiros números dos vetores ordenados após a remoção do menor (i-1 menores elementos) de todos os números, ou seja, a sequência ordenada a ser impressa seria 3 3 4 7 9.

__Entrada__

A primeira linha de um caso de teste contém os inteiros K (1 <= K <= 10.000) e i (1 <= i <= N <= 100.000). Cada uma das K próximas linhas apresenta um dos K vetores ordenados. Cada uma dessas linhas inicia-se com o tamanho de um dado vetor e em seguida é fornecida a sequência de números inteiros ordenados do vetor.

__Saída__

Seu programa deve imprimir uma linha contendo a lista dos menores números restantes dos vetores ordenados antes de intercalar o i-ésimo menor valor. Imprima um espaço em branco entre cada par de números.

| Exemplo de Entrada  |
| ------------------- |
| 5 1                 |
| 7 7 7 9 10 13 18 20 |
| 3 2 4 4             |
| 4 3 4 8 9           |
| 5 3 8 9 9 10        |
| 4 9 12 20 23        |

| Exemplo de Saída    |
| ------------------- |
| 2 3 3 7 9           |

***

|         Exemplo de Entrada          |
| ----------------------------------- |
| 5 4                                 |
| 3 126413 752631 946163              |
| 0                                   |
| 5 92683 456122 463803 687371 848812 |
| 1 404405                            |
| 1 951157                            |

|   Exemplo de Saída   |
| -------------------- |
| 456122 752631 951157 |
