# Problema 5: Histórico de vencedores

Em diversos esportes, a cada premiação ou campeonato, novos campeões ou premiados entram para a lista de vencedores. Para permitir a organização de um histórico de premiações de uma modalidade de esporte, você deve implementar um sistema que armazena e organiza esse histórico de forma a permitir buscas por nome e atualizações eficientes, uma vez que esse histórico pode chegar a ficar bastante grande para certas modalidades. Para isso, você deve implementar um programa que insere os dados em uma árvore AVL ordenada por nome e que faça buscas e atualizações (inserções das datas de novos prêmios).

__Entrada__

Cada linha da entrada inicia-se com o número da operação a ser realizada: 1 para inserção ou atualização de um registro, 2 para busca e 0 para encerrar o programa. A operação 1 é seguida de um nome simples de até 15 caracteres e um número correspondente a um novo ano. Caso esse nome ainda não tenha sido inserido anteriormente, você deve inserir este nome em um novo nó na árvore AVL. Caso contrário, adicione o novo ano na lista de datas no nó do nome encontrado. A operação 2 é seguida apenas do nome a ser buscado.

__Saída__

Para cada operação de busca, imprima a altura do nó que armazena o nome buscado e a lista de anos registrados para esse nome em ordem de inserção separados por espaços em branco. Considere que a altura de um nó folha é 1. Caso o nome buscado não exista na árvore de busca, imprima 0.

| Exemplo de Entrada  | Exemplo de Saída |
| ------------------- | ---------------- |
| 1 Rivaldo 1999      | 1 1998 2000 2003 |
| 1 Ronaldo 1997      | 1 2009 2010      |
| 1 Zidane 1998       | 0                |
| 1 Ronaldo 2002      | 2 1997 2002 1996 |
| 1 Zidane 2000       | 1 1994           |
| 1 Ronaldinho 2004   |                  |
| 1 Zidane 2003       |                  |
| 2 Zidane            |                  |
| 1 Kaka 2007         |                  |
| 1 Messi 2009        |                  |
| 1 Messi 2010        |                  |
| 1 Ronaldinho 2005   |                  |
| 2 Messi             |                  |
| 1 Messi 2011        |                  |
| 2 Cristiano         |                  |
| 1 Cristiano 2008    |                  |
| 1 Cristiano 2013    |                  |
| 1 Messi 2012        |                  |
| 1 Ronaldo 1996      |                  |
| 2 Ronaldo           |                  |
| 1 Romario 1994      |                  |
| 1 Cristiano 2014    |                  |
| 2 Romario           |                  |
| 0                   |                  |

|  Exemplo de Entrada   | Exemplo de Saída |
| --------------------- | ---------------- |
| 1 Barcelona 2009      | 3 2000           |
| 1 Corinthians 2000    | 1 2009 2011      |
| 1 SaoPaulo 2005       | 1 2000 2012      |
| 1 Internacional 2006  | 4 2006           |
| 1 RealMadrid 2014     |                  |
| 2 Corinthians         |                  |
| 1 Milan 2007          |                  |
| 1 Barcelona 2011      |                  |
| 1 Corinthians 2012    |                  |
| 1 BayernMunich 2013   |                  |
| 2 Barcelona           |                  |
| 1 ManchesterU 2008    |                  |
| 1 Internazionale 2010 |                  |
| 2 Corinthians         |                  |
| 2 Internacional       |                  |
| 0                     |                  |
