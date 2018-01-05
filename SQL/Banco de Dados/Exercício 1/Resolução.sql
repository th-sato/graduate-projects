
/*set sql_safe_updates = 0;

CREATE TABLE ATOR (
coda int,
nomeart varchar(20) NOT NULL,
nomereal varchar(20) NOT NULL,
nacionalidade varchar(20) NOT NULL,
sexo varchar(10) NOT NULL,
idade int NOT NULL,
indicacoesoscar int NOT NULL,
oscar int NOT NULL,
primary key (coda));

CREATE TABLE FILME(
codf int,
nome varchar(20) NOT NULL,
ano varchar(4) NOT NULL,
orcamento int NOT NULL,
tempo int NOT NULL,
primary key(codf));

CREATE TABLE PERSONAGEM (
coda int,
codf int,
personagem varchar(20) NOT NULL,
cache int NOT NULL,
primary key(coda, codf),
foreign key (coda) references ATOR (coda),
foreign key (codf) references FILME (codf));

insert into ATOR values (1, 'DemiMoore', 'MariadaSilva', 'USA','f', 32, 0,0);
insert into ATOR values (2, 'BradPitt', 'JoaoPaulo', 'USA','f', 28, 1,0);
insert into ATOR values (3, 'DustinHoffman', 'DustinHoffman', 'USA','f', 36, 2,0);
insert into ATOR values (4, 'JessicaLange', 'JessicaLange', 'USA','f', 42, 4,2);
insert into ATOR values (5, 'SoniaBraga', 'SoniaBraga', 'Brasil','f', 45, 0,0);

insert into FILME values (1, 'Ajurada', '1996',  1000000, 18);
insert into FILME values (2, 'ALetraEscarlate', '1995', 10000000, 24);
insert into FILME values (3, 'Seven', '1995', 1500000, 20);
insert into FILME values (4, 'Tootsie', '1982', 50000, 16);
insert into FILME values (5, 'Tieta', '1995', 200000, 18);

insert into PERSONAGEM values (1, 1, 'Mary', 3000);
insert into PERSONAGEM values (1, 2, 'Sandy', 5000);
insert into PERSONAGEM values (2, 3, 'John', 5000);
insert into PERSONAGEM values (3, 4, 'Mary', 1000);
insert into PERSONAGEM values (4, 4, 'Tootsie', 2000);
insert into PERSONAGEM values (5, 5, 'Tieta', 500);*/

#Exercício 1
#select * from ATOR where sexo = 'f';

#Exercício 2
#select nomeart, nacionalidade, sexo from ATOR;

#Exercício 3
#select nomeart, indicacoesoscar, oscar from ATOR;

#Exercício 4
#select codf from PERSONAGEM where cache > 3000;

#Exercício 5
#select p.personagem from PERSONAGEM p, ATOR a where nomeart = "DemiMoore" and p.coda = a.coda;

#Exercício 6
#select f.nome from ATOR a, FILME f, PERSONAGEM p where nomeart = "DemiMoore"
#and p.coda = a.coda and p.codf = f.codf;

#Exercício 7
#select nomeart from ATOR where nomereal like 'Jessica%';

#Exercício 8
#select nomeart from ATOR where 30 < idade and idade < 40;
#select nomeart from ATOR where idade between 30 and 40;

#Exercício 9
#select nomeart from ATOR where (indicacoesoscar - oscar) >= 2;

#Exercício 10
#select nomeart from ATOR order by nomeart;

#Exercício 11
#select * from ATOR order by idade DESC, nomeart;

#Exercício 12
#select distinct a.nomeart, a.nacionalidade from ATOR a, PERSONAGEM p, FILME f
#where p.coda = a.coda and p.codf = f.codf;

#Exercício 13
#select max(idade) from ATOR;
#select min(idade) from ATOR;
#select avg(idade) from ATOR;

#Exercício 14
#select max(idade) from ATOR where sexo = 'f';
#select min(idade) from ATOR where sexo = 'f';

#Exercíco 15
#select count(*) from ATOR where sexo ='f';

#Exercício 16
#select sum(idade) from ATOR;

#Exercício 17
#select a.nomeart, count(p.codf) from ATOR a, PERSONAGEM p, FILME f
#where a.coda = p.coda and p.codf = f.codf
#group by nomeart;

#Exercício 18
#select a.nomeart, min(f.ano), max(f.ano)
#from ATOR a, FILME f, PERSONAGEM p
#where a.coda = p.coda and p.codf = f.codf and a.oscar>=1
#group by a.nomeart;

#Exercício 19
#select f.nome, avg(p.cache), max(p.cache), min(p.cache), sum(p.cache)
#from FILME f, PERSONAGEM p
#where p.codf = f.codf
#group by f.nome;

#Exercício 20
#select a.nomeart, count(p.codf)
#from ATOR a, PERSONAGEM p
#where a.coda = p.coda
#group by a.nomeart
#having count(p.codf)>=2;

#Exercício 21
#select count(distinct p.codf)
#from PERSONAGEM p, FILME f
#where f.codf = p.codf and p.cache > 2000
#group by p.codf
#having sum(cache) > 8000;
