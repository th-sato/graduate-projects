# Atividade 6: Problemas clássicos em Sincronização

1. Considere um programa concorrente, utilizando C/PThreads, ou C/OpenMP ou ainda JavaThreads, onde existem duas categorias de processos/threads. Os processos da primeira categoria, denominados TPs, deverão produzir N números inteiros aleatórios (todos na faixa entre 1 e 10^8) e inseri-los em uma determinada fila. Os demais processos de outro tipo, denominados TCs, deverão retirar (se houver) dados da fila em comum e verificar se os mesmos são números primos.

> Caso os TCs recebam números negativos os mesmos deverão ser finalizados.

> Simule o funcionamento do sistema nas seguintes configurações:

> a) TP=1, TC=2, N=100

> b) TP=2, TC=4, N=100

> c) TP=4, TC=2, N=100

> Onde N representa a quantidade total de números gerados pelos TPs.

> _Observação:_ Considere que após a quantidade total de números aleatórios gerados for igual a N os TPs deverão emitir valores negativos para a quantidade exata de TCs, de forma a encerrá-los e também encerrar-se posteriormente.

> Demonstre em relatório o funcionamento correto do código desenvolvido para todos os casos requeridos.


2. Crie um programa em C com PThreads que implementem rotinas que fazem operações de Wait e Signal em um Semáforo Geral. Lembrando que a linguagem C apenas implementa, nativamente, semáforos binários (mutex). Assim, use mutex para implementar rotinas que fazem operações sobre semáforos gerais. Crie um exemplo de uso para Semaforos Gerais que ateste seu funcionamento através do uso das rotinas criadas.
