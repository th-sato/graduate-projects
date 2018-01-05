#Exercício 1
/*CREATE TABLE Paciente
(ID int,
nome varchar(20),
cidade varchar(20),
doenca varchar(20),
primary key (ID));*/

#Exercício 2
/*INSERT INTO Paciente
values (1, 'joao', 'sjc', 'gripe'), (2, 'maria', 'taubate', 'sarampo');*/
#select * from Paciente;

#Exercício 3
/*DELIMITER $$
create procedure qtd_pacientes (out quantidade int)
begin
	select count(*) into quantidade from Paciente;
end $$
DELIMITER ;

call qtd_pacientes (@qtd_paciente);
select @qtd_paciente;*/

#Exercício 4
/*DELIMITER $$
create procedure inserir_pacientes_20 ()
begin
	declare cont int;
    declare nome varchar(20);
    declare cidade varchar(20);
    declare doenca varchar(20);
    set cont = 3;
    set nome = 'nome';
    set cidade = 'sjc';
    set doenca = 'dengue';
    while (cont <= 22) do
		insert into Paciente values (cont, nome, cidade, doenca);
        set cont = cont + 1;
    end while;
end $$
DELIMITER ;

call inserir_pacientes_20();
select * from Paciente;*/

#Exercício 5
/*DELIMITER $$
create procedure inserir_pacientes_1000 ()
begin
	declare cont int;
    declare nome varchar(20);
    declare cidade varchar(20);
    declare doenca varchar(20);
    set cont = 23;
    set nome = 'name';
    while (cont <= 1000) do
		if (cont <= 100) then
			set cidade = 'jacarei';
            set doenca = 'pneumonia';
		elseif (cont <= 500) then 
			set cidade = 'taubate';
            set doenca = 'sarampo';
		elseif (cont <= 700) then
			set cidade = 'cacapava';
            set doenca = 'catapora';
        elseif (cont <= 900) then
			set cidade = 'guaratingueta';
            set doenca = 'sinusite';
		else
			set cidade = 'pindamonhagaba';
            set doenca = 'cachumba';
		end if;
		insert into Paciente values (cont, nome, cidade, doenca);
        set cont = cont + 1;
    end while;
end $$
DELIMITER ;*/

#call inserir_pacientes_1000 ();

#select * from Paciente;