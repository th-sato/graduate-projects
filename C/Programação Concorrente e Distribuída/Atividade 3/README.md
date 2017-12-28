# Atividade 3: Métricas

__A partir da solução paralela para o problema de N-Body, desenvolvido no problema 2 da tarefa 2, faça as seguintes medidas:__

1. A partir da versão serial do código fornecido, meça a fração (percentual) de tempo que o código executa apenas tarefas sequenciais, ou seja, tempo decorrido para o trecho do código que _não_ é concorrente, e meça também a fração (percentual) de tempo que o código executa tarefas concorrentes.

2. construa uma tabela com as estimativas de speedup para execuções paralelas do código, a partir da fórmula da lei de Amdhal, para 1, 2, 4, 8, 16, 32 e 64 processadores

3. A partir das medidas de tempo em execuções paralelas efetuadas na mesma atividade 2 - problema 2, construa outras duas colunas da tabela iniciada no item b, contendo o speedup e eficiência paralela encontradas nas execuções com 1, 2 e 4 thredas.

4. Compare os valores teóricos esperados de Speedup, a partir da lei de Amdhal (item b), com os valores medidos (item c). Analise os resultados.

5. Modifique, a versão concorrente desenvolvida do código, alterando a função original: __double Random(void)__ para que a mesma possa ser executada concorrentemente. Descreva também a principal limitação encontrada na versão original da função que impede que a mesma possa ser executada concorrentemente.

_The function rand() is not reentrant or thread-safe, since it uses hidden state that is modified on each call. This might just be the seed value to be used by the next call, or it might be something more elaborate. In order to get reproducible behaviour in a threaded application, this state must be made explicit. The function  rand_r() is supplied with a pointer to an unsigned int, to be used as state. This is a very small amount of state, so this function will be a weak pseudo-random generator. Try  drand48_r(3) instead._

6. Refaça as medidas da tabela desenvolvida no item d com a nova versão do código. Implica em novas execuções paralelas da versão desenvolvida no item e.
