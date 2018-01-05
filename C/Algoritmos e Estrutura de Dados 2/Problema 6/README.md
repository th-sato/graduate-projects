# Problema 6: Organização por espalhamento

Em uma grande empresa é fundamental que as informações sejam organizadas para que a busca por informações seja feita de forma eficiente. Para organizar uma lista de clientes e quantidades de produtos pedidos a cada compra deste cliente, você teve a ideia de primeiro dividir os clientes em *m* diferentes grupos numerados de 0 a *m*-1. A atribuição de grupo se dá pela transformação do nome do cliente em um inteiro do intervalo [0, *m*-1] através da conversão da string de base 128 (ASCII) para um número de decimal e depois pela obtenção do resto da divisão desse número por *m*. Implemente um programa que organize os dados em grupos conforme a descrição acima e realize busca nessa base de dados.

__Entrada__

A primeira linha contém o valor de *m* (2 < *m* < 1.000.000). Cada uma das outras linhas da entrada inicia-se com o número da operação a ser realizada: 1 para inserção ou atualização de um registro, 2 para busca e 0 para encerrar o programa. A operação 1 é seguida de um nome simples de até 15 caracteres e um número inteiro correspondente a uma nova quantidade de produtos adquiridos pelo cliente. Caso esse nome ainda não tenha sido inserido anteriormente, você deve inserir este nome na base de dados. Caso contrário, adicione o novo número na lista de quantidades do nome encontrado. A operação 2 é seguida apenas do nome a ser buscado.

__Saída__

Para cada operação de busca, imprima duas linhas. A primeira linha deve conter todos os nomes, em ordem crescente (alfanumérica) e separados por espaços em branco, inclusos no mesmo grupo da pessoa buscada. A segunda linha deve conter a lista de números da pessoa buscada em ordem de inserção separados por espaços em branco. Caso o nome buscado não seja encontrado, imprima 0 na segunda linha.

| Exemplo de Entrada  | Exemplo de Saída |
| ------------------- | ---------------- |
| 3                   | Ari Ruy          |
| 1 Ruy 5             | 5                |
| 1 Lee 7             | Kim Lee Mao      |
| 1 Ari 8             | 7 5              |
| 1 Mao 6             | Ari Ruy Sam      |
| 1 Lee 5             | 8                |
| 2 Ruy               | Kim Lee Mao      |
| 1 Sam 7             | 6                |
| 1 Ruy 9             |                  |
| 1 Kim 8             | 0                |
| 2 Lee               | Kim Lee Mao      |
| 2 Ari               | 0                |
| 2 Mao               |                  |
| 2 Aab               |                  |
| 2 Mau               |                  |
| 0                   |                  |

| Exemplo de Entrada  |  Exemplo de Saída   |
| ------------------- | ------------------- |
| 7                   | Barbara Rui Tatiana |
| 1 Carlos 5          | 9                   |
| 1 Rui 9             | Barbara Rui Tatiana |
| 1 Barbara 7         | 9 5                 |
| 1 Vinicius 6        | Carlos              |
| 1 Tatiana 9         | 5                   |
| 1 Olavo 7           | Barbara Rui Tatiana |
| 1 Fabiane 6         | 7                   |
| 1 Tatiana 5         | Vinicius            |
| 2 Rui               | 6                   |
| 2 Tatiana           | Olavo               |
| 2 Carlos            | 7                   |
| 2 Barbara           | Fabiane             |
| 2 Vinicius          | 6                   |
| 2 Olavo             |                     |
| 2 Fabiane           |                     |
| 0                   |                     |
