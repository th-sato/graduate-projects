#Exercício 1
/*select distinct NomePais
from pais pa
where not exists
(select * from piloto pl
where pa.CodPais = pl.CodPais);*/

#Exercício 2
/*SELECT p.nomepil
FROM piloto p, pospilotoprova pp
WHERE p.codpil=pp.codpil
and pp.posicao=1
having (count(pp.codpil)) >  all
        (select count(codpil) 
         from pospilotoprova 
         where posicao=1 
         group by codpil);*/

#Exercício 3
/*SELECT nomeeq
FROM equipe 
where codeq = any (SELECT equipe.codeq 
              FROM piloto, equipe
              where piloto.codpais =equipe.codpais
              and piloto.codeq=equipe.codeq);*/

#Exercício 4
/*select p1.nomepil, p2.nomepil
from (amizade a inner join piloto p1 on a.codpiloto1 = p1.codpil)
inner join piloto p2 on a.codpiloto2 = p2.codpil;*/

#Exercício 5
/*select distinct p.nomepais
from (((equipe e join pais p using(codpais))
join piloto pl using (codpais))
join circuito c using (codpais))
join prova pr using (codcirc)
where pr.data>=20090101 and pr.data<=20091231;*/

#Exercício 6
/*select p.nomepil, count(pp.posicao)
from piloto p join pospilotoprova pp using (CodPil)
where pp.Posicao = 1
group by p.nomepil;*/

#Exercício 7
/*select c.codcirc, c.nomecir, count(p.codcirc)
from circuito c join prova p using(CodCirc)
where p.data>=20090101 and p.data<=20091231
group by c.nomecir
having count(p.codcirc) > 1;*/

#Exercício 8
/* SELECT nomepil from piloto where not exists
(select codcirc from prova where codcirc in
(select codcirc from circuito
where codpais in (select codpais from pais where nomepais='inglaterra'))
and not exists
(select codcirc from pospilotoprova as ppp
where ppp.codcirc=prova.codcirc
and ppp.data=prova.data
and ppp.codpil=piloto.codpil));*/

#Exercício 9


#Exercício 10

