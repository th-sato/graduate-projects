#Exercício 1
/*create table Departamento
(Dnum int not null,
Nome varchar(20) not null,
TotalSal int not null,
primary key (Dnum)
);

create table Empregado
(ID int not null,
Nome varchar(20) not null,
Salario int not null,
Dnum int not null,
primary key (ID),
foreign key (Dnum) references Departamento (Dnum)
);*/

#Exercício 2
/*insert into Departamento values (1, 'Departamento1', 5000);
insert into Departamento values (2, 'Departamento2', 4000);
insert into Empregado values (1, 'Thiago', 5000, 1);
insert into Empregado values (2, 'Sato', 4000, 2);*/

#Exercício 3
/*create trigger trg_empregado_insert after insert on Empregado
for each row
update Departamento set TotalSal = TotalSal + NEW.Salario
where Dnum = NEW.Dnum;*/
#insert into Empregado values (3, 'Hideki', 3000, 1);
#select * from Departamento;

#Exercicio 4
/*create trigger trg_empregado_update after update on Empregado
for each row
update Departamento set TotalSal = TotalSal + new.Salario - old.Salario
where Dnum = NEW.Dnum;*/
#update Empregado set Salario = 5000 where id = 3;
#select * from Departamento;

#Exercicio 5
/*create trigger trg_empregado_alter_depto after update on Empregado
for each row
begin
update Departamento set TotalSal = TotalSal + new.Salario
where Dnum = new.Dnum;
update Departamento set TotalSal = TotalSal - old.Salario
where Dnum = old.Dnum;
end;*/
