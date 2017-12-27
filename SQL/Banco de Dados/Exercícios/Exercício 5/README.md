### Rode o script para o seguinte esquema de um banco de dados:
* Pais(__CodPais__, NomePais) /* Tabela de países */
* Equipe(__CodEq__, NomeEq, #CodPais) /* Tabela de equipes de fórmula 1 */
* Piloto(__CodPil__, NomePil, #CodEq, #CodPais) /* Tabela com os pilotos que participam do campeonato */
* Circuito(__CodCirc__, NomeCirc, #CodPais) /* Tabela com os circuitos em que ocorrem as provas */
* Prova (__#CodCirc__, __Data__, Tempo) /* Tabela com as provas */
* PosPilotoProva(__#CodCirc__, __#Data__, __#CodPil__, Posicao) /* Tabela com as posições que cada piloto obteve em cada prova */
* Amizade(__#CodPiloto1__, __#CodPiloto2__)

__1) Listar os nomes dos países que não existem pilotos (usar NOT EXISTS)__

_estados unidos

italia

franca

australia_
