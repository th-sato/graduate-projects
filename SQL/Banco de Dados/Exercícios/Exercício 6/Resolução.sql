#Exercício 1
/*create view piloto_circuito (n_piloto, n_circuito)
as select p.nomepil, c.nomecir
from piloto p, circuito c, pospilotoprova pp
where pp.codpil = p.codpil and pp.codcirc = c.codcirc;*/
#select distinct * from piloto_circuito;

#Exercício 2
/*create view piloto_prova (n_piloto, p_data, p_duracao, p_posicao)
as select p.nomepil, pr.data, pr.duracao, pp.posicao
from (piloto p left join pospilotoprova pp using (codpil))
left join prova pr using(codcirc);*/
#select * from piloto_prova;

#Exercício 3
/*create view piloto_dados (n_piloto, p_origem, n_equipe, p_equipe)
as select p.nomepil, pa.nomepais, e.nomeeq, pa2.nomepais
from (piloto p inner join pais pa using(codpais))
inner join (pais pa2 inner join equipe e using(codpais)) using(codeq);*/
#select * from piloto_dados;

#Exercício 4
/*create view equipe_sempiloto (n_equipe)
as select e.nomeeq
from equipe e
where not exists
(select e.nomeeq
from equipe e join piloto p using(codeq));*/
#select * from equipe_sempiloto;

#Exercício 5
/*select pc.n_piloto, count(pc.n_circuito)
from piloto_circuito pc
group by (pc.n_piloto);*/

#Exercício 6
/*select pd.n_piloto, pd.n_equipe
from piloto_dados pd;*/

#Exercício 7
/*select pd.n_piloto
from piloto_dados pd
where pd.p_origem = pd.p_equipe;*/

#Exercício 8
/*insert into piloto values
(10, 'Sebastian Vettel', 1, 1);*/
#select * from piloto_dados;
#Resultado:
/*'Felipe Massa', 'brasil', 'ferrari', 'italia'
'Kimi Raikkonen', 'irlanda', 'ferrari', 'italia'
'Kovalainen', 'irlanda', 'MCLaren', 'inglaterra'
'Lewis Hamiltton', 'inglaterra', 'MCLaren', 'inglaterra'
'Nico Rosberg', 'alemanha', 'Williams', 'inglaterra'
'Sebastian Vettel', 'brasil', 'ferrari', 'italia'*/
#A view piloto_dados foi atualizada com a inserção do novo piloto.

#Exercício 9
#É possível fazer um comando Insert ou Delete em uma view, porém não é recomendado.
#Ao modificar a view com comandos de inserção ou deleção, as tabelas originais
#não serão alteradas. Desta forma, haveria a necessidade de atualização nestas
#tabelas.