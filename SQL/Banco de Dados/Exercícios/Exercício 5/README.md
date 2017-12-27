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


