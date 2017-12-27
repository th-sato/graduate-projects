
# 1) Listar o nome, BI e NPC para cada cliente Indivial e Organização (use UNION).
SELECT nome, bi as bi_npc FROM Cliente, Individual
where cliente.numerocliente = individual.numerocliente
union
SELECT nome, npc FROM Cliente, organizacoes
where cliente.numerocliente = organizacoes.numerocliente;

# 2) Listar o número de clientes individuais com reservas.
SELECT distinct Individual.numerocliente FROM Individual, reserva
where reserva.numerocliente = individual.numerocliente;

# 3) Listar para cada hotel o número de quartos.
select descrição, count(*) 
from hotel, quarto
where hotel.sigla = quarto.sigla
group by descrição;

# 4) Listar os hotéis que possui o maior número de quartos (use ALL).
select descrição 
from hotel, quarto
where hotel.sigla = quarto.sigla
group by descrição
having count(*) >= all ( select count(*) from hotel, quarto where hotel.sigla =    quarto.sigla group by descrição)

# 5) Listar para cada hotel, o numero de quartos livres
select descrição, count(*) from hotel, quarto
where hotel.sigla = quarto.sigla and not exists (select * from reserva_quarto where reserva_quarto.sigla = hotel.sigla and reserva_quarto.numero = quarto.numero)
group by designacao;

# 6) Listar os hoteis que possuem o maior número de quartos livres.
select Descrição, count(*) from hotel, quarto where hotel.sigla = quarto.sigla and not exists (select * from reserva_quarto where reserva_quarto.sigla = hotel.sigla and reserva_quarto.numero = quarto.numero) group by Descrição having count(*) >= all
( select count(*) from hotel, quarto where hotel.sigla = quarto.sigla and not exists (select * from reserva_quarto where reserva_quarto.sigla = hotel.sigla and reserva_quarto.numero = quarto.numero) group by Descrição);

# 7) Para cada nome de uma organização indicar o total de reservas existentes
select Nome, count(*) from Organizacoes, reserva, cliente
where reserva.numerocliente = Organizacoes.numerocliente and
cliente.numerocliente = Organizacoes.numerocliente
Group by nome;

# 8) Listar os hotéis que apenas têm reservas de um cliente, que  é uma organização
select distinct Descrição from hotel, reserva_quarto, reserva, organizacoes 
where hotel.sigla = reserva_quarto.sigla and reserva_quarto.numeroreserva =
reserva.numeroreserva and reserva.numerocliente = organizacoes.numerocliente
and 
not exists
(select * from reserva_quarto, reserva where
hotel.sigla = reserva_quarto.sigla and reserva_quarto.numeroreserva =
reserva.numeroreserva and reserva.numerocliente <>
organizacoes.numerocliente);

# 9) Listar o nome das organizações que têm reservas em todos os hotéis.
select nome from cliente, organizacoes where cliente.numerocliente = organizacoes.numerocliente and not exists 
(select * from hotel where
not exists
(select * from reserva_quarto, reserva where reserva_quarto.sigla =
hotel.sigla and reserva_quarto.numeroreserva = reserva.numeroreserva
and reserva.numerocliente = cliente.numerocliente));

# 10) Para cada  organização indicar o total de reservas existentes por hotel. Listar as organizações sem reserva também. 
select Nome, sigla, count(reserva.numeroreserva) from Organizacoes left join reserva on  (reserva.numerocliente = Organizacoes.numerocliente) left join  cliente  on cliente.numerocliente = Organizacoes.numerocliente  left join reserva_quarto on  reserva_quarto.numeroreserva = reserva.numeroreserva Group by nome, sigla;


