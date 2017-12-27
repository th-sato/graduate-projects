#Base de Dados - Produção Cinematográfica
1. Criar a base de dados apresentada a seguir. Os atributos sublinhados representam a chave
primária.
    * ATOR(__coda__, nomeart, nomereal, nacionalidade, sexo, idade, indicacoesoscar, oscar)
    * FILME(__codf__, nome, ano, orcamento, tempo)
    * PERSONAGEM(__coda__, __codf__, personagem, cache)

2. Inserir os seguintes dados:

__ATOR__

| coda |     nomeart    |    nomereal   | nacionalidade | sexo | idade | Indicações ao Oscar | Oscar |
|------|----------------|---------------|---------------|------|-------|---------------------|-------|
|  1   | DemiMoore      | MariadaSilva  | USA           | f    | 32    | 0                   | 0     |
|  2   | BradPitt       | JoaoPaulo     | USA           | f    | 28    | 1                   | 0     |
|  3   | DustinHoffman  | DustinHoffman | USA           | f    | 36    | 2                   | 0     |
|  4   | JessicaLange   | JessicaLange  | USA           | f    | 42    | 4                   | 2     |
|  5   | SoniaBraga     | SoniaBraga    | Brasil        | f    | 45    | 0                   | 0     |

__FILME__

| codf |      nome       | ano  | orçamento | tempo |
|------|-----------------|------|-----------|-------|
| 1    | AJurada         | 1996 | 1000000   | 18    |
| 2    | ALetraEscarlate | 1995 | 10000000  | 24    |
| 3    | Seven           | 1995 | 1500000   | 20    |
| 4    | Tootsie         | 1982 | 50000     | 16    |
| 5    | Tieta           | 1995 | 200000    | 18    |

__PERSONAGEM__

| coda | codf | personagem | cache |
|------|------|------------|-------|
| 1    | 1    | Mary       | 3.000 |
| 1    | 2    | Sandy      | 5.000 |
| 2    | 3    | John       | 5.000 |
| 3    | 4    | Mary       | 1.000 |
| 4    | 4    | Tootsie    | 2.000 |
| 5    | 5    | Tieta      | 500   |


##Consultas
1. Os dados de todas as atrizes;
2. O nome, nacionalidade e sexo dos artistas;
3. O nome e o número de oscars indicados ou recebidos;
4. O código dos filmes onde houve pelo menos um artista com cachê não maior que 3000;
5. O nome dos personagens desempenhados por Demi Moore;
6. O nome dos filmes desempenhados por Demi Moore;
7. O nome artístico completo de todas as atrizes chamadas Jessica;
8. O nome artístico dos artistas entre 30 e 40 anos;
9. O nome dos artistas que tem duas indicações a mais que oscar ganhos;
10. O nome de todos os artistas em ordem alfabética;
11. A lista das atrizes por ordem de idade (iniciando pelos mais velhos), e dentro da idade, ordenada alfabéticamente;
12. O nome artítisico e nacionalidade de todas as pessoas envolvidas em filmes (artistas e diretores);
13. Idade do artista mais velho, a idade do artista mais novo, a média de idade dos artistas;
14. As faixas de idade das atrizes;
15. O número de atrizes;
16. A soma das idades dos atores;
17. O nome do artista e o número de filmes em que participou;
18. Para cada ator que ganhou pelo menos um oscar, o ano de seu filme mais antigo e do mais novo;
19. Para cada filme, o nome do filme, média de cachês pagos por filme, cachê mais alto, cachê mais baixo, e total dos cachês pagos;
20. O nome do artista e o número de filmes em que participou, para todo artista que participou de no mínimo 2 filmes;
21. O número de caches distintos maiores do que 2000 pagos em cada filme, para todo filme onde a soma dos cachês destes artistas foi superior a 8000.
