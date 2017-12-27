insert into Hotel (sigla, descrição) values ('SH', 'Sheraton');
insert into Hotel (sigla, descrição) values ('AL', 'Alfa');
insert into Hotel (sigla, descrição) values ('MN', 'Mundial');
insert into Hotel (sigla, descrição) values ('RM', 'Roma');
insert into Hotel (sigla, descrição) values ('MJ', 'Majestic');
insert into Hotel (sigla, descrição) values ('LS', 'Lisboa');

insert into Quarto (sigla, numero, NumCamas, Preco) values ('SH', 1, 2, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('SH', 2, 2, 20);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('SH', 3, 4, 20);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('SH', 4, 1, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('SH', 5, 2, null);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('SH', 6, 3, 15);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('SH', 7, 2, 15);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('SH', 8, 4, null);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('SH', 9, 1, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('SH', 10, 1, 5);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('AL', 1, 2, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('AL', 2, 4, null);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('AL', 3, 4, 20);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('AL', 4, 2, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('AL', 5, 2, null);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('AL', 6, 4, 15);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('AL', 7, 2, 15);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('AL', 8, 4, null);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 1, 2, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 2, 2, 20);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 3, 4, 26);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 4, 1, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 5, 3, null);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 6, 4, 15);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 7, 2, 15);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 8, 4, null);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 9, 1, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 10, 2, 8);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 11, 3, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MN', 12, 1, null);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('RM', 1, 2, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('RM', 2, 3, 25);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('RM', 3, 4, 20);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('RM', 4, 1, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('RM', 5, 2, null);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('RM', 6, 2, 20);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('RM', 7, 2, 15);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('RM', 8, 4, null);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('RM', 9, 1, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('RM', 10, 4, 13);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MJ', 1, 2, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MJ', 2, 3, 15);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MJ', 3, 4, 22);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('MJ', 4, 1, 10);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('LS', 1, 2, 12);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('LS', 2, 2, 20);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('LS', 3, 3, 16);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('LS', 4, 1, 14);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('LS', 5, 1, 20);
insert into Quarto (sigla, numero, NumCamas, Preco) values ('LS', 6, 4, 20);

insert into Cliente (numerocliente, nome) values (1,'Ana');
insert into Cliente (numerocliente, nome) values (2,'ISCTE');
insert into Cliente (numerocliente, nome) values (3,'Pedro');
insert into Cliente (numerocliente, nome) values (4,'ONU');
insert into Cliente (numerocliente, nome) values (5,'Luis');
insert into Cliente (numerocliente, nome) values (6,'NASA');
insert into Cliente (numerocliente, nome) values (7,'Carlos');
insert into Cliente (numerocliente, nome) values (8,'CE');
insert into Cliente (numerocliente, nome) values (9,'Sofia');
insert into Cliente (numerocliente, nome) values (10,'TAP');
insert into Cliente (numerocliente, nome) values (11,'Luisa');
insert into Cliente (numerocliente, nome) values (12,'Antonio');

insert into Organizacoes (Numerocliente, Contato, NPC) values (2, null, 1020);
insert into Organizacoes (Numerocliente, Contato, NPC) values (4, 'Evaristo', 2040);
insert into Organizacoes (Numerocliente, Contato, NPC) values (6, null, 1030);
insert into Organizacoes (Numerocliente, Contato, NPC) values (8, 'Joao', 1120);
insert into Organizacoes (Numerocliente, Contato, NPC) values (10, null, 1060);

insert into Individual (Numerocliente, BI) values (1, 589595);
insert into Individual (Numerocliente, BI) values (3, 585985);
insert into Individual (Numerocliente, BI) values (5, 375895);
insert into Individual (Numerocliente, BI) values (7, 836137);
insert into Individual (Numerocliente, BI) values (9, 767676);
insert into Individual (Numerocliente, BI) values (11, null);
insert into Individual (Numerocliente, BI) values (12, null);

insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (1,4,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (2,4,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (3,1,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (4,2,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (5,2,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (6,4,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (7,2,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (8,3,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (9,3,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (10,4,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (11,4,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (12,4,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (13,4,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (14,4,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (15,5,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (16,5,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (17,5,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (18,8,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (19,8,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (20,9,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (21,9,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (22,10,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (23,10,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (24,11,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (25,11,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (26,11,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (27,12,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (28,12,null, null);
insert into Reserva (numeroreserva, numerocliente, diaentrada, diasaida) values (29,12,null, null);


insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (1,'SH',1, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (1,'SH',3, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (2,'AL',4, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (2,'AL',6, null,2);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (3,'AL',1, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (4,'AL',2, null,2);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (5,'AL',7, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (6,'AL',8, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (7,'MN',1, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (8,'MN',2, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (9,'MN',7, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (10,'LS',6, null,2);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (11,'MN',3, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (12,'RM',1, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (13,'MJ',2, null,2);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (14,'RM',3, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (15,'RM',4, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (16,'RM',5, null,2);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (17,'RM',7, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (18,'RM',8, null,3);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (19,'RM',9, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (20,'RM',10, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (21,'MJ',1, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (22,'MJ',2, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (23,'MJ',3, null,2);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (24,'MJ',4, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (25,'LS',1, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (26,'LS',2, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (27,'LS',3, null,3);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (28, 'LS',4, null,2);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (29,'LS',5, null,1);
insert into Reserva_Quarto (numeroreserva, sigla, numero, camaextra, numpessoas) values (29,'LS',6, null,1);

insert into Fatura (numerofatura, numeroreserva, data, valor) values (1,1,null,100);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (2,3,null,120);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (3,5,null,100);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (4,6,null,120);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (5,8,null,112);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (6,10,null,70);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (7,12,null,80);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (8,13,null,90);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (9,14,null,112);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (10,16,null,124);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (11,17,null,102);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (12,20,null,70);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (13,21,null,12);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (14,25,null,120);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (15,27,null,100);
insert into Fatura (numerofatura, numeroreserva, data, valor) values (16,29,null,80);