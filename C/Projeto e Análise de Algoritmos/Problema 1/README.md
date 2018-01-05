# Problema 2: Cinema lucrativo

*Tempo Limite:* 1s (C/C++), 4s (Java)

Um novo filme está sendo lançado para exibição nos cinemas. Por questões de contrato com a distribuidora do filme no país, para se exibir este filme em seu cinema, Christopher terá que pagar uma taxa *C* para cada dia em que colocar o filme em exibição. Como Christopher é um empresário bastante esperto, ele consegue estimar, a partir de dados de exibições passadas, quase precisamente a quantidade de clientes que terá a cada dia, portanto ele também consegue calcular quanto de receita ele conguiria a cada um desses dias.

Por exemplo, caso o custo para exibição seja R$200 por dia e as receitas previstas para 6 dias sejam R$180, R$350, R$60, R$800, R$150 e R$210 consecutivamente, então o lucro máximo que Christopher poderia obter seria exibindo o filme durante três dias, do segundo ao quarto dia, obtendo o lucro de R$610.

Você deve escrever um programa que determine o lucro máximo que Christopher consegue obter de acordo com o custo de exibição e com as previsões de receitas para cada dia. Note que, caso Christopher estime uma receita menor do que o custo para exibir o filme, o lucro máximo seria obtido ao não se exibir o filme, portanto o lucro máximo seria de R$0.

__Entrada__

A primeira linha de um caso de teste contém o inteiro N (1 <= N <= 100.000) que representa o número de dias que Christopher poderá decidir sobre a exibição do filme. A segunda linha contém um inteiro *C* (1 <= C < 1000), que representa a taxa a ser paga para cada dia em que o filme ficou em exibição. Nas próximas *N* linhas, cada linha i (1 <= i <= N) terá um valor *Ri* com o valor da receita prevista para cada dia *i*.

__Saída__

Seu programa deve imprimir uma linha com o valor do lucro máximo que Christopher pode obter para cada caso.

| Exemplo de Entrada  | Exemplo de Saída |
| ------------------- | ---------------- |
| 6                   | 610              |
| 200                 |                  |
| 180                 |                  |
| 350                 |                  |
| 60                  |                  |
| 800                 |                  |
| 150                 |                  |
| 210                 |                  |

| Exemplo de Entrada  | Exemplo de Saída |
| ------------------- | ---------------- |
| 4                   | 0                |
| 40                  |                  |
| 30                  |                  |
| 20                  |                  |
| 10                  |                  |
| 38                  |                  |
