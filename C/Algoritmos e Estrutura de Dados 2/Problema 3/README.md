# Problema 3: Regra do Tapetão

*Tempo Limite:* 1s (C/C++), 2s (Java)

A confederação nacional de futebol estava estudando meios para aumentar a sua arrecadação e também evitar que grandes times sejam rebaixados para a segunda divisão. O novo presidente da confederação teve uma grande ideia para resolver esses problemas e por isso criou novas regras para o seu campeonato nacional de futebol. As regras básicas de pontuação permanecem inalteradas, sendo três pontos dados ao time que vence um jogo, e nenhum para o time que perde. Se um jogo termina empatado, cada time recebe um ponto.

Pelas novas regras, o campeonato nacional é dividido em 2 fases, sendo que apenas os times com as maiores pontuações são classificados para a segunda fase. Porém, após a primeira fase, os times podem comprar gols adicionais e alterar os resultados de algumas partidas.

O presidente de um time muito popular possui orçamento para comprar até *G* gols. Seja uma lista de resultados de *N* partidas da primeira fase, a sua tarefa é calcular o número máximo de pontos que o seu time pode alcançar com a compra de *G* gols, supondo que os outros times não comprarão nenhum gol.

__Entrada__

A primeira linha da entrada contém dois inteiros N (0 < N <= 10^5 ) e G (0 <= G <= 10^6), representado o número de partidas jogadas e número de gols que o time pode comprar, respectivamente. Cada uma das próximas N linhas contém o resultado de uma partida com dois inteiros *S* e *R* (0 <= S,R <= 100), indicando respectivamente a quantidade de gols que o time marcou e sofreu antes da compra de gols.

__Saída__

Imprima uma linha o número máximo de pontos que o seu time pode obter após a compra dos gols.

| Exemplo de Entrada  | Exemplo de Saída |
| ------------------- | ---------------- |
| 2 1                 | 4                |
| 1 1                 |                  |
| 1 1                 |                  |


| Exemplo de Entrada  | Exemplo de Saída |
| ------------------- | ---------------- |
| 3 2                 | 6                |
| 1 3                 |                  |
| 3 1                 |                  |
| 2 2                 |                  |

| Exemplo de Entrada  | Exemplo de Saída |
| ------------------- | ---------------- |
| 4 10                | 12               |
| 1 1                 |                  |
| 2 2                 |                  |
| 1 3                 |                  |
| 0 4                 |                  |
