#Exercício 1
/*
INSERT INTO Clinica
VALUES (11, 'Hospital das Clínicas', 'Cerqueira César');

INSERT INTO Clinica
VALUES (12, 'Medsel Clínica Médica', 'Centro');*/

#Exercício 2
/*select c.nome, e.nome
from (Clinica c inner join EspecialidadeClinica ec on c.cod = ec.clinica_cod)
inner join Especialidade e on ec.especialidade_cod = e.cod;*/

#Exercício 3
/*select c.nome, e.nome
from (Clinica c left outer join EspecialidadeClinica ec on c.cod = ec.clinica_cod)
left outer join Especialidade e on ec.especialidade_cod = e.cod
order by c.nome, e.nome;*/

#Exercício 4
/*select m.nome, c.data, c.hora
from Medico m left join Consulta c on c.medico_cod = m.cod;*/

#Exercício 5
/*select m.nome, count(c.medico_cod)
from Medico m inner join Consulta c on m.cod = c.medico_cod
group by m.nome;*/

#Exercício 6
/*select m.nome, count(c.medico_cod)
from Medico m left join Consulta c on m.cod = c.medico_cod
group by m.nome;*/

#Exercício 7
/*select c.nome, m.nome
from (Clinica c left join MedicoClinica mc on c.cod = mc.clinica_cod)
left join Medico m on m.cod = mc.medico_cod
order by c.nome, m.nome;*/
