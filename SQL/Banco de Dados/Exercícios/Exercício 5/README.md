### Rode o script para o seguinte esquema de um banco de dados:
* Pais(__CodPais__, NomePais) /*Tabela de países*/
* Equipe(__CodEq__, NomeEq, #CodPais) /*Tabela de equipes de fórmula 1*/
* Piloto(__CodPil__, NomePil, #CodEq, #CodPais) /*Tabela com os pilotos que participam do campeonato*/
* Circuito(__CodCirc__, NomeCirc, #CodPais) /*Tabela com os circuitos em que ocorrem as provas*/
* Prova (__#CodCirc__, __Data__, Tempo) /*Tabela com as provas*/
* PosPilotoProva(__#CodCirc__, __#Data__, __#CodPil__, Posicao) /*Tabela com as posições que cada piloto obteve em cada prova*/
* Amizade(__#CodPiloto1__, __#CodPiloto2__)

__1) Listar os nomes dos países que não existem pilotos (usar NOT EXISTS)__

_estados unidos_

_italia_

_franca_

_australia_

__2) Selecionar o nome do piloto que foi campeão (ficou em primeiro lugar) mais do que qualquer outro piloto. USE ALL__

_Lewis Hamilton_

__3) Selecionar o nome das equipes que possuem pelo menos um piloto que é do mesmo país que a equipe. USE ANY__

_McLaren_

__4) Listar o nome dos amigos de cada piloto; DICA: use 2x a tabela Piloto no FROM__ 

__SELECT ... FROM piloto p1, piloto p2, .. WHERE ...__

_Felipe Massa    |  Fernando Alonso_

_Kimi Raikkonen  |  Kovalainen_

_Lewis Hamiltton |  Nico Rosberg_

__5) Obter os países que tem equipes e pilotos e que foram sede de um circuito em 2009 (data>=20090101 e data<=20091231).__

_Inglaterra_

__6) Obter o nome de cada piloto e o número de vezes em que ele foi campeão.__

_Felipe Massa 1_

_Lewis Hamilton 2_

__7) Para cada circuito no qual em 2009 houve mais que uma prova obter o código do circuito, o nome do circuito e o número de provas.__

_3 Silverstone 2_

__8) Obter o nome de cada piloto, tal que, não exista prova realizada na Inglaterra da qual ele não tenha participado. (mesmo que: participou de todas as provas da Inglaterra).__

__USE NOT EXISTS:__
_Exemplo:_
_select * from tabelaA where not exists_

_(select campoA from tabelaB where campoB = valor)_

__9) Obter os nomes dos países que obedecem todos os requisitos abaixo:__
    * No país há ao menos uma equipe que tem um piloto que é do país em questão;
    * No país há ao menos um circuito no qual tenha ocorrido uma prova no ano de 2009 use a função year(data).

_Inglaterra_

__10) Obter uma tabela com três colunas: nome do país, nome de circuito e data da prova. A tabela deve conter uma linha para cada prova com duração de mais de 60 minutos no circuito em questão no país em questão. Países sem circuitos devem aparecer ficando as demais colunas vazias(NULL). Circuitos nos quais não ocorreram provas ou nos quais as provas não excederam 60 minutos devem aparecer também, com a data da prova vazia (NULL).__

_brasil Interlagos 2009-10-21_

_alemanha Nurburgring_

_inglaterra Silverstone_

_estados unidos_

_italia Monza_

_irlanda_

_franca_

_espanha Barcelona 2009-10-21_

_australia Melbourne_

