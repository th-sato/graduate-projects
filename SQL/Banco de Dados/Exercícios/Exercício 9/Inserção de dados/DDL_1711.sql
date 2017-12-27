CREATE TABLE Cliente
(
	NumeroCliente 		integer NOT NULL,
	Nome  			text NULL,
	PRIMARY KEY (NumeroCliente)
)
;
CREATE TABLE Fatura
(
	NumeroFatura 		integer NOT NULL,
	NumeroReserva 		integer NOT NULL,
	Data  			timestamp NULL,
	Valor 			float NULL,
	PRIMARY KEY (NumeroFatura)
)
;
CREATE TABLE Hotel
(
	Sigla 			varchar(20) NOT NULL,
	Descrição     		varchar(20) NULL,
	PRIMARY KEY (Sigla)
)
;
CREATE TABLE Individual
(
	NumeroCliente 		integer NOT NULL,
	Bi    			integer NULL,
	PRIMARY KEY (NumeroCliente)
)
;
CREATE TABLE Organizacoes
(
	NumeroCliente 		integer NOT NULL,
	Contato      		text NULL,
	NPC   			integer NULL,
	PRIMARY KEY (NumeroCliente)
)
;
CREATE TABLE Quarto
(
	Sigla 			varchar(20) NOT NULL,
	Numero        		integer NOT NULL,
	NumCamas      		integer NULL,
	Preco 			float NULL,
	PRIMARY KEY (Sigla, Numero)
)
;
CREATE TABLE Reserva
(
	NumeroReserva 		integer NOT NULL,
	NumeroCliente 		integer NOT NULL,
	DiaEntrada    		timestamp NULL,
	DiaSaida      		timestamp NULL,
	PRIMARY KEY (NumeroReserva)
)
;
CREATE TABLE Reserva_Quarto
(
	NumeroReserva 		integer NOT NULL,
	Sigla 			varchar(20) NOT NULL,
	Numero        		integer NOT NULL,
	CamaExtra     		bit NULL,
	NumPessoas    		integer NULL,
	PRIMARY KEY (NumeroReserva, Sigla, Numero)
)
;


ALTER TABLE Fatura
	ADD FOREIGN KEY FK_FACTURA_PAGAMENTO_RESERVA (NumeroReserva) 
	REFERENCES Reserva (NumeroReserva) on update cascade on delete cascade
;

ALTER TABLE Individual
	ADD FOREIGN KEY FK_INDIVIDU_INDIVIDUA_CLIENTE (NumeroCliente) 
	REFERENCES Cliente (NumeroCliente) on update cascade on delete cascade
;

ALTER TABLE Organizacoes
	ADD FOREIGN KEY FK_ORGANIZA_CLIENTE_O_CLIENTE (NumeroCliente) 
	REFERENCES Cliente (NumeroCliente) on update cascade on delete cascade
;

ALTER TABLE Quarto
	ADD FOREIGN KEY FK_QUARTO_HOTELQUAR_HOTEL (Sigla) 
	REFERENCES Hotel (Sigla) on update cascade on delete cascade
;

ALTER TABLE Reserva
	ADD FOREIGN KEY FK_RESERVA_CLIENTERE_CLIENTE (NumeroCliente) 
	REFERENCES Cliente (NumeroCliente) on update cascade on delete cascade
;

ALTER TABLE Reserva_Quarto
	ADD FOREIGN KEY FK_RESERVA__RESERVA_Q_QUARTO (Sigla,Numero) 
	REFERENCES Quarto (Sigla,Numero) on update cascade on delete cascade
;

ALTER TABLE Reserva_Quarto
	ADD FOREIGN KEY FK_RESERVA__RESERVA_Q_RESERVA (NumeroReserva) 
	REFERENCES Reserva (NumeroReserva) on delete cascade on update cascade
;
