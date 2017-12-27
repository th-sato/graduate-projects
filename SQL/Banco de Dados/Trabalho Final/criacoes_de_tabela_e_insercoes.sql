CREATE TABLE User(
	id int NOT NULL,
	email varchar(20) NOT NULL,
	name varchar(45) NOT NULL,
	password varchar(45) NOT NULL,
	cpf varchar(11) NOT NULL,
	address varchar(100) NOT NULL,
	city varchar(45) NOT NULL,
	postcode varchar(45) NOT NULL,
	phone varchar(13) NOT NULL,
	state varchar(2) NOT NULL,
	birthday DATE NOT NULL,
	PRIMARY KEY (id)
);

INSERT INTO User (id, email, name, password, cpf, address, city, postcode, phone, state, birthday) VALUES (1, 'thomas@wheretocoupon.com', 'Thomas William', '123456', '67663332350', 'Rua dos abestados 344', 'SJC', '12334234', '1234567878', 'SP', '1990-08-05');

INSERT INTO User (id, email, name, password, cpf, address, city, postcode, phone, state, birthday) VALUES (2, 'ruzzon@wheretocoupon.com', 'Tiago Ruzzon', '4535553', '15234447545', 'Rua das torneiras 433', 'SJC', '12334234', '9884545432', 'SP', '1997-11-09');

INSERT INTO User (id, email, name, password, cpf, address, city, postcode, phone, state, birthday) VALUES (3, 'thiago@wheretocoupon.com', 'Thiago Sato', 'hghytt', '73807962670', 'Rua das tulipas 79', 'SJC', '12453466', '985864786', 'SP', '1996-06-06');

INSERT INTO User (id, email, name, password, cpf, address, city, postcode, phone, state, birthday) VALUES (4, 'jose@wheretocoupon.com', 'José Jailson', '767567', '47563128379', 'Rua jailson mendes 66', 'SJC', '12435456', '1243534566', 'SP', '1992-10-18');

INSERT INTO User (id, email, name, password, cpf, address, city, postcode, phone, state, birthday) VALUES (5, 'caio@hotmail.com', 'Caio Henrique', '4535654', '82571887947', 'Rua dos vagabundos', 'SJC', '12434345', '9554735637', 'SP', '1997-12-20');

INSERT INTO User (id, email, name, password, cpf, address, city, postcode, phone, state, birthday) VALUES (6, 'monteiro@gmail.com', 'Henrique Monteiro', '7567567', '84671199262', 'Rua dos frangos', 'SJC', '12897867', '12876763332', 'SP', '1991-06-30');

INSERT INTO User (id, email, name, password, cpf, address, city, postcode, phone, state, birthday) VALUES (7, 'paulo@hotmai.com', 'Paulo Gustavo', '987654', '68483525003', 'Av andromeda', 'SJC', '12456343', '123456765', 'SP', '1956-10-10');

INSERT INTO User (id, email, name, password, cpf, address, city, postcode, phone, state, birthday) VALUES (8, 'leduino@unifesp.br', 'Leduino', '8765456', '65623486843', 'Rua dos varzeas', 'São Paulo', '124344345', '1244534534', 'SP', '1970-02-30');

INSERT INTO User (id, email, name, password, cpf, address, city, postcode, phone, state, birthday) VALUES (9, 'joao@gmail.com', 'João
Varzea', '7658r9e', '97583558646', 'Rua dos varzeas', 'São Paulo', '765434553', '876543232', 'SP', '1996-06-20');

INSERT INTO User (id, email, name, password, cpf, address, city, postcode, phone, state, birthday) VALUES (10, 'wilson@hotmail.com', 'Wilson
Baitola', 'fhgfieuu', '74865737766', 'Rua traficantes', 'São Paulo', '765884754', '675493875', 'SP', '1994-01-20');

#===============================================================================================

CREATE TABLE Category(
    id  int NOT NULL,
    category varchar(45) NOT NULL,
    PRIMARY KEY (id)
);

INSERT INTO Category (id, category) VALUES (1, 'Alimentícia');
INSERT INTO Category (id, category) VALUES (2, 'Sex Shop');
INSERT INTO Category (id, category) VALUES (3, 'Cosméticos');
INSERT INTO Category (id, category) VALUES (4, 'Bar');
INSERT INTO Category (id, category) VALUES (5, 'Informáticas');
INSERT INTO Category (id, category) VALUES (6, 'Limpeza');
INSERT INTO Category (id, category) VALUES (7, 'Papelaria e Presentes');
INSERT INTO Category (id, category) VALUES (8, 'Pastelaria');
INSERT INTO Category (id, category) VALUES (9, 'Pizzaria');
INSERT INTO Category (id, category) VALUES (10, 'Farmácia');

#===============================================================================================

CREATE TABLE Preferencia(
    id  int NOT NULL,
    category_id int NOT NULL,
    user_id int NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (category_id) REFERENCES Category(id),
    FOREIGN KEY (user_id) REFERENCES User(id)
);

INSERT INTO Preferencia (id, category_id, user_id) VALUES (1, 2, 1);
INSERT INTO Preferencia (id, category_id, user_id) VALUES (2, 4, 4);
INSERT INTO Preferencia (id, category_id, user_id) VALUES (3, 5, 5);
INSERT INTO Preferencia (id, category_id, user_id) VALUES (4, 1, 6);
INSERT INTO Preferencia (id, category_id, user_id) VALUES (5, 6, 9);
INSERT INTO Preferencia (id, category_id, user_id) VALUES (6, 7, 10);
INSERT INTO Preferencia (id, category_id, user_id) VALUES (7, 8, 4);
INSERT INTO Preferencia (id, category_id, user_id) VALUES (8, 3, 8);
INSERT INTO Preferencia (id, category_id, user_id) VALUES (9, 10, 3);
INSERT INTO Preferencia (id, category_id, user_id) VALUES (10, 9, 2);

#===============================================================================================

CREATE TABLE Store(
	id int NOT NULL,
	cnpj varchar(45) NOT NULL,
	email varchar(45) NOT NULL,
	companyname varchar(100) NOT NULL,
	password varchar(45) NOT NULL,
	tradingname varchar(45) NOT NULL,
	brand varchar(45) NOT NULL,
	address varchar(100) NOT NULL,
	city varchar(45) NOT NULL,
	postcode varchar(45) NOT NULL,
	phone varchar(13) NOT NULL,
	state varchar(2) NOT NULL,
	lat varchar(20) NOT NULL,
	lon varchar(20) NOT NULL,
	imglogo MEDIUMBLOB,
	category_id int NOT NULL,
	PRIMARY KEY (id),
	FOREIGN KEY (category_id) REFERENCES Category(id)
);

INSERT INTO Store (id, cnpj, email, companyname, password, tradingname, brand, address, city, postcode, phone, state, lat, lon, category_id, imglogo) VALUES (1, '96288645000140', 'pasteldeflango@flango.com.br', 'Empresa Ramos Pastelaria', '123245', 'Pastel de Flango', 'Flango do Chinês','Rua da China','Caxambu','12343433','343243222','MG','40.7143528', '-74.0059731', 8, NULL);

INSERT INTO Store (id, cnpj, email, companyname, password, tradingname, brand, address, city, postcode, phone, state, lat, lon, category_id, imglogo) VALUES (2, '54212361000120', 'contato@extra.com.br', 'Grupo empresarial de Verejo ', 'facil123', 'Extra - Supermercado', 'Extra','Rua da pelotas, 3434','Rio de Janeiro','12343433','987847324','RJ','26.59227383', '-80.57927894', 1, NULL);

INSERT INTO Store (id, cnpj, email, companyname, password, tradingname, brand, address, city, postcode, phone, state, lat, lon, category_id, imglogo) VALUES (3, '67717431000144', 'belaflor@restaurante.com.br', 'Restaurante Bela Flor', 'belafdd', 'Bela Flor', 'Belinha e florzinha','Rua Cambuí','Natal','65434222','987332321','NR','-8.40716816', '-55.546873', 1, NULL);

INSERT INTO Store (id, cnpj, email, companyname, password, tradingname, brand, address, city, postcode, phone, state, lat, lon, category_id, imglogo) VALUES (4, '05208538000100', 'sexyshop@belasexy.com.br', 'BELA SEXY SHOP', '123245', 'BellaSexy Lingerie e Sex Shop', 'Marca Sexy','Rua do sexo','Itápolis','54534324','(16)32621295','MG','-22.91792294', '-45.3515605', 2, NULL);

INSERT INTO Store (id, cnpj, email, companyname, password, tradingname, brand, address, city, postcode, phone, state, lat, lon, category_id, imglogo) VALUES (5, '82630303000152', 'adega@adega.com.br', 'BAR DO JOSÉ', '123245', 'Adega Aliança do Sul', 'Marca Adega Bar','Av. da cachaça','Araraquara','948574433','(16)33373123','MG','-24.84656535', '-56.86523237', 4, NULL);

INSERT INTO Store (id, cnpj, email, companyname, password, tradingname, brand, address, city, postcode, phone, state, lat, lon, category_id, imglogo) VALUES (6, '54448385000183', 'info@info.com.br', 'Empresa Ramos Informáticas', 'info123', 'Actual TI', 'Marca Actual TI','Rua dos nerds','Araraquara','87654334','(16)33571553','SP','-27.3717673', '-50.88866987', 5, NULL);

INSERT INTO Store (id, cnpj, email, companyname, password, tradingname, brand, address, city, postcode, phone, state, lat, lon, category_id, imglogo) VALUES (7, '93318274000104', 'belacapri@pizzaria.com.br', 'Empresa Ramos Pizzaria', '8973894dd', 'Bella Capri', 'Marca Bella Capri','Rua das pizzas','Joao em Vile','12343433','(16)33366650','SC','-7.53676432', '-37.265623', 9, NULL);

INSERT INTO Store (id, cnpj, email, companyname, password, tradingname, brand, address, city, postcode, phone, state, lat, lon, category_id, imglogo) VALUES (8, '64110276000105', 'agualimpa@limpeza.com.br', 'Empresa Ramos Limpeza', 'aguinha', 'Água Limpa', 'Marca Água Limpa','Rua dos limpos','Limpa Tudo','64568765','(16)32524845','RS','-2.02106512', '-49.39452925', 6, NULL);

INSERT INTO Store (id, cnpj, email, companyname, password, tradingname, brand, address, city, postcode, phone, state, lat, lon, category_id, imglogo) VALUES (9, '64110276000105', 'agendaescolar@agendaescolar.com.br', 'Empresa Ramos Papelaria e Presentes', '973983e', 'Agenda Escolar', 'Marca Agenda Escolar','Rua dos estudantes','Mogi das Cruzes','64568765','(16)32524845','SP','-2.02106512', '-49.39452925', 7, NULL);

INSERT INTO Store (id, cnpj, email, companyname, password, tradingname, brand, address, city, postcode, phone, state, lat, lon, category_id, imglogo) VALUES (10, '64110276000105', 'centralfarma@farmacia.com.br', 'Empresa Ramos Farmácia', 'aguinha', 'Centralfarma', 'Marca Centralfarma','Rua dos doentes','Pitanguinha','senha','(16)32536289','AM','-2.02106512', '-49.39452925', 10, NULL);

#===============================================================================================

CREATE TABLE Type(
	id  int NOT NULL,
	type varchar(45) NOT NULL,
	PRIMARY KEY (id)
);

INSERT INTO Type (id, type) VALUES (1, 'Desconto Valor Bruto');
INSERT INTO Type (id, type) VALUES (2, 'Desconto Porcentagem');
INSERT INTO Type (id, type) VALUES (3, 'Desconto por quantidade');

#===============================================================================================

CREATE TABLE Coupon(
	id int NOT NULL,
	lat varchar(20) NOT NULL,
	lon varchar(20) NOT NULL,
	value float NOT NULL,
	description varchar(1000) NOT NULL,
	datetocollect DATETIME NOT NULL,
	datetoredeem DATETIME NOT NULL,
	radius INT NOT NULL,
	title varchar(45) NOT NULL,
	img MEDIUMBLOB,
	real_value FLOAT NOT NULL,
	numavalable INT NOT NULL,
	type_id int NOT NULL,
	store_id int NOT NULL,
	PRIMARY KEY (id),
	FOREIGN KEY (type_id) REFERENCES Type(id),
	FOREIGN KEY (store_id) REFERENCES Store(id)
);

INSERT INTO Coupon (id, lat, lon, value, description, datetocollect, datetoredeem, radius, title, img, real_value, numavalable, type_id, store_id) VALUES (1, '-6.92642685', '-62.66601362', 32.00, 'Cupom de desconte em todo o site extra', '2016-02-06 19:30:13', '2016-02-06 20:30:13', 60, 'Vale tudo', NULL, 0, 100, 1, 2);
INSERT INTO Coupon (id, lat, lon, value, description, datetocollect, datetoredeem, radius, title, img, real_value, numavalable, type_id, store_id) VALUES (2, '40.77677839', '-73.08312154', 2.50, 'Compre 1 pastel leve 2', '2016-03-08 00:30:13', '2016-03-09 01:30:13', 100, 'Vale Pastel', NULL, 5.00, 20, 3, 1);
INSERT INTO Coupon (id, lat, lon, value, description, datetocollect, datetoredeem, radius, title, img, real_value, numavalable, type_id, store_id) VALUES (3, '42.84816282', '-71.15502095', 12.00, '50% de desconto no self service', '2016-03-20 20:15:59', '2016-03-20 21:05:00', 70, '50% self service', NULL, 24.00, 50, 2, 3);
INSERT INTO Coupon (id, lat, lon, value, description, datetocollect, datetoredeem, radius, title, img, real_value, numavalable, type_id, store_id) VALUES (4, '45.66433243', '-77.2469399', 40.00, 'Compre um borrachão e leve 2', '2016-04-21 06:33:33', '2016-04-21 16:23:10', 50, 'Vale um borrachão', NULL, 20.00, 60, 3, 4);
INSERT INTO Coupon (id, lat, lon, value, description, datetocollect, datetoredeem, radius, title, img, real_value, numavalable, type_id, store_id) VALUES (5, '45.67968615', '-84.83299947', 24.00, 'Cupom de desconte em todo o bar', '2016-04-11 08:41:12', '2016-04-11 14:11:15', 45, 'Vale uma cachaça', NULL, 0, 55, 1, 5);
INSERT INTO Coupon (id, lat, lon, value, description, datetocollect, datetoredeem, radius, title, img, real_value, numavalable, type_id, store_id) VALUES (6, '46.01640245', '-85.65697408', 150.00, 'Cupom de desconte nos notebook samsung', '2016-04-30 10:56:15', '2016-04-30 14:56:15', 65, 'Vale notebook', NULL, 0, 150, 1, 6);
INSERT INTO Coupon (id, lat, lon, value, description, datetocollect, datetoredeem, radius, title, img, real_value, numavalable, type_id, store_id) VALUES (7, '46.45335787', '-86.12389302', 500.00, 'compre uma pizza e leve 5', '2016-05-05 15:36:18', '2016-05-05 16:36:18', 40, 'Vale 5 pizza', NULL, 500.02, 5, 3, 7);
INSERT INTO Coupon (id, lat, lon, value, description, datetocollect, datetoredeem, radius, title, img, real_value, numavalable, type_id, store_id) VALUES (8, '37.03805774', '-97.4837563', 32.00, 'Cupom de desconte em todo o site', '2016-05-18 18:18:18', '2016-05-18 19:19:19', 80, 'Vale tudo', NULL, 0, 80, 1, 8);
INSERT INTO Coupon (id, lat, lon, value, description, datetocollect, datetoredeem, radius, title, img, real_value, numavalable, type_id, store_id) VALUES (9, '29.32517678', '-101.43883443', 150.00, 'Desconto nas limpezas acima de R$150,00', '2016-05-25 00:14:39', '2016-05-25 02:07:08', 200, 'Vale Limpeza', NULL, 20.00, 65, 2, 9);
INSERT INTO Coupon (id, lat, lon, value, description, datetocollect, datetoredeem, radius, title, img, real_value, numavalable, type_id, store_id) VALUES (10, '23.62487441', '-102.09801412', 100.00, 'Ganha um genérico gratis', '2016-05-30 05:14:39', '2016-05-30 10:08:15', 300, 'Vale um genérico', NULL, 150.00, 54, 3, 10);

#===============================================================================================

CREATE TABLE History(
	coupon_id int NOT NULL,
	user_id int NOT NULL,
	date_hours DATETIME NOT NULL,
	lat varchar(20) NOT NULL,
	lon varchar(20) NOT NULL,
	status INT NOT NULL,
	PRIMARY KEY (coupon_id, user_id),
	FOREIGN KEY (coupon_id) REFERENCES Coupon(id)
);

INSERT INTO History (coupon_id, user_id, date_hours, lat, lon, status) VALUES (1, 2, '2016-06-20 10:14:39', '4.19355193', '-73.53356099', 0);
INSERT INTO History (coupon_id, user_id, date_hours, lat, lon, status) VALUES (2, 1, '2016-06-20 10:14:39', '-4.23633376', '34.39612651', 0);
INSERT INTO History (coupon_id, user_id, date_hours, lat, lon, status) VALUES (3, 3, '2016-06-20 10:14:39', '-22.28861182', '19.63050151', 0);
INSERT INTO History (coupon_id, user_id, date_hours, lat, lon, status) VALUES (4, 5, '2016-06-20 10:14:39', '-16.31963682', '36.85706401', 0);
INSERT INTO History (coupon_id, user_id, date_hours, lat, lon, status) VALUES (5, 8, '2016-06-20 10:14:39', '-16.99325459', '-61.58043599', 0);
INSERT INTO History (coupon_id, user_id, date_hours, lat, lon, status) VALUES (6, 9, '2016-06-20 10:14:39', '36.29784029', '62.87268901', 0);
INSERT INTO History (coupon_id, user_id, date_hours, lat, lon, status) VALUES (7, 6, '2016-06-20 10:14:39', '52.89596461', '31.23206401', 0);
INSERT INTO History (coupon_id, user_id, date_hours, lat, lon, status) VALUES (8, 10, '2016-06-20 10:14:39', '75.22519849', '-42.94762349', 0);
INSERT INTO History (coupon_id, user_id, date_hours, lat, lon, status) VALUES (9, 4, '2016-06-20 10:14:39', '76.26360242', '-28.18199849', 0);
INSERT INTO History (coupon_id, user_id, date_hours, lat, lon, status) VALUES (10, 7, '2016-06-20 10:14:39', '64.46354907', '-96.03356099', 0);

#===============================================================================================

CREATE TABLE Employers(
	id int NOT NULL,
	email varchar(45) NOT NULL,
	name varchar(45) NOT NULL,
	password varchar(45) NOT NULL,
	cpf varchar(11) NOT NULL,
	address varchar(100) NOT NULL,
	city varchar(45) NOT NULL,
	postcode varchar(45) NOT NULL,
	phone varchar(13) NOT NULL,
	state varchar(2) NOT NULL,
	birthday varchar(45) NOT NULL,
	store_id int NOT NULL,
	PRIMARY KEY (id),
	FOREIGN KEY (store_id) REFERENCES Store(id)

);

INSERT INTO Employers (id, email, name, password, cpf, address, city, postcode, phone, state, birthday, store_id) VALUES (1, 'robson@flango.com.br', 'Robson Eitas', '123456', '82771233614', 'Rua Soldado Apolinário dos Reis', 'Vitória', '29010-510', '1234567878', 'ES', '1990-08-05', 1);
INSERT INTO Employers (id, email, name, password, cpf, address, city, postcode, phone, state, birthday, store_id) VALUES (2, 'micael@extra.com.br', 'Micael Viera', '4535553', '66105694440', 'Rua Alexandre Sesso', 'Lins', '16406-076', '894758974', 'SP', '1997-11-09',2);
INSERT INTO Employers (id, email, name, password, cpf, address, city, postcode, phone, state, birthday, store_id) VALUES (3, 'matheus@restaurante.com', 'Matheus Santos', '983743fhds3', '74781806201', 'Rua Donato Pássaro 79', 'Itapetininga', '18203-440', '486988947', 'SP', '1996-06-06', 3);
INSERT INTO Employers (id, email, name, password, cpf, address, city, postcode, phone, state, birthday, store_id) VALUES (4, 'isabela@belasexy.com.br', 'Isabela Castro', 'gadora', '25556357773', 'Rua das Figueiras 66', 'Santo André', '09080-371', '984847433', 'SP', '1992-10-18', 4);
INSERT INTO Employers (id, email, name, password, cpf, address, city, postcode, phone, state, birthday, store_id) VALUES (5, 'marcos@adega.com', 'Marcos Castro', '4535654', '85646924901', 'Beco Catarino', 'Beco Catarino', '30240-324', '98765546', 'MG', '1997-12-20', 5);
INSERT INTO Employers (id, email, name, password, cpf, address, city, postcode, phone, state, birthday, store_id) VALUES (6, 'monteiro@gmail.com', 'Henrique Monteiro', '7567567', '75465386886', 'Rua dos frangos', 'Santa Luzia', '12897867', '12876763332', 'MG', '1991-06-30', 6);
INSERT INTO Employers (id, email, name, password, cpf, address, city, postcode, phone, state, birthday, store_id) VALUES (7, 'jacinto@pizzaria.com', 'Jacinto Cabeção', '498573', '16532576280', 'Rua Valmor Schütz', 'Palhoça', '88135-247', '984738957', 'SC', '1956-10-10', 7);
INSERT INTO Employers (id, email, name, password, cpf, address, city, postcode, phone, state, birthday, store_id) VALUES (8, 'carlos@limpeza.com.br', 'Carlos Pinto', '8765456', '28366758451', 'Rua São Paulo', 'Porto Alegre', '91550-070', '1244534534', 'SP', '1970-02-30', 8);
INSERT INTO Employers (id, email, name, password, cpf, address, city, postcode, phone, state, birthday, store_id) VALUES (9, 'juliana@agendaescolar.com.br', 'Juliana Lindomar', '7658r9e', '32417599112', 'Rua das Andorinhas', 'São José do Rio Preto', '15048-432', '4895734382', 'SP', '1996-06-20', 9);
INSERT INTO Employers (id, email, name, password, cpf, address, city, postcode, phone, state, birthday, store_id) VALUES (10, 'ramires@farmacia.com.br', 'Ramires Josney', 'ioure', '59759113112', 'Rua 16', 'Manaus', '69038-287', '98274543', 'AM', '1994-01-20', 10);

#===============================================================================================

CREATE TABLE Preferencia_Loja(
    id  int NOT NULL,
	store_id int NOT NULL,
    user_id int NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (store_id) REFERENCES Store(id),
    FOREIGN KEY (user_id) REFERENCES User(id)
);


INSERT INTO Preferencia_Loja (id, store_id, user_id) VALUES (1, 2, 1);
INSERT INTO Preferencia_Loja (id, store_id, user_id) VALUES (2, 4, 4);
INSERT INTO Preferencia_Loja (id, store_id, user_id) VALUES (3, 5, 5);
INSERT INTO Preferencia_Loja (id, store_id, user_id) VALUES (4, 1, 6);
INSERT INTO Preferencia_Loja (id, store_id, user_id) VALUES (5, 6, 9);
INSERT INTO Preferencia_Loja (id, store_id, user_id) VALUES (6, 7, 10);
INSERT INTO Preferencia_Loja (id, store_id, user_id) VALUES (7, 8, 4);
INSERT INTO Preferencia_Loja (id, store_id, user_id) VALUES (8, 3, 8);
INSERT INTO Preferencia_Loja (id, store_id, user_id) VALUES (9, 10, 3);
INSERT INTO Preferencia_Loja (id, store_id, user_id) VALUES (10, 9, 2);