1. Desenvolva programas concorrentes em C/PThreads e Java, ambos utilizando-se de semáforos, para calcular o Produto Escalar entre 2 vetores (do tipo double) de tamanho N:

> _PE = A1*B1 + A2*B2 + ... + AN*BN_

> Os vetores devem ser preenchidos aleatoriamente e sua alocação e preenchimento não deverão influenciar as medidas de desempenho.

> O algoritmo deve ser implementado da seguinte forma: cada thread deve calcular valores parciais, sendo que a totalização deve ocorrer ao final do cálculo, ainda dentro das threads, em uma seção crítica controlada por semáforo, a qual atualiza uma variável global.

> Faça um gráfico com o Speed-up e a eficiência obtido considerando N com tamanho de 10^5 e 10^7, e o número de threads de 1, 2, 4 e 8.

2. Faça o mesmo que o exercício 1 com um programa em OpenMP usando:
    * seção crítica (#pragma omp critical) para controlar a totalização dos resultados parciais em uma variável global;
    * redução (reduction (...)).

> Faça um gráfico com o Speed-up e a eficiência obtido de ambos.

3. Considere dois processos concorrentes:

|    P1    |    P2    |
|----------|----------|
| Print(C) | Print(A) |
| Print(E) | Print(R) |
|          | Print(O) |

> Faça os seguintes exercícios:

> a) Crie um pseudo-código que utilize semáforos para que seja possível imprimir a sequência: ACERO ou ACREO. Obs: Não se esqueça de determinar o(s) valor(es) inicial(is) do(s) semáforo(s).

> b) Mostre, através de um diagrama de estados ou descrição tabular, que o código funciona como especificado no item a.

> c) Implemente o programa em liguagem C/PThreads ou Java que faça o que o pseudo-código determine.

4. Crie um programa multi-threads com Java que modifique o exercício 1, de forma a usar um código monitor para resolver o mesmo problema. Desta forma, deve-se usar um método contendo a palavra reservada "synchronized", para atualizar o valor do produto escalar após o cálculo dos valores parciais obtidos pelas threads. Faça um gráfico com o Speed-up e a eficiência obtido. Teste com os mesmos parâmetros estabelecidos no exercício original.

5. A partir do seguinte programa exemplo disponível no Moodle: "Exemplo de variável de condição em C com PThreads", o qual demonstra o uso de um código com semáforos e variáveis de condição em C/PThreads, faça um programa similar usando linguagem Java utilizando os seguintes recursos de controle de fluxo de execução de threads:
    * Trava (lock()) e variável de condição;
    * Código Monitor (método com cláusula sychronized) e variável de condição.

> Mostre saídas provando que o código funciona.

> Observação: no caso do item (b) deve-se ter o mesmo código monitor rodando procedimentos distintos de acordo com a identificação da Thread.
