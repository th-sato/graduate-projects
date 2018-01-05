#Exercício 1
/*select m.nome, count(mc.clinica_cod)
from MedicoClinica mc, Medico m
where m.cod = mc.medico_cod
group by mc.medico_cod
order by m.nome;*/

#Exercício 2
/*select m.nome
from MedicoEspecialidade me, Medico m
where m.cod = me.medico_cod
group by m.nome
having count(me.especialidade_cod) = 2;*/

#Exercício 3
/*select c.nome
from Clinica c, Consulta ct
where c.cod = ct.clinica_cod
group by c.nome
having hour(avg(ct.hora)) > 20;*/

#Exercício 4
/*select c.nome, e.nome
from Clinica c, Especialidade e, EspecialidadeClinica ec
where ec.clinica_cod = c.cod and ec.especialidade_cod = e.cod
order by c.nome;*/

#Exercício 5
/*select c.nome, count(ec.especialidade_cod)
from Clinica c, EspecialidadeClinica ec
where c.cod = ec.clinica_cod
group by c.nome;*/

#Exercício 6
/*select nome
from Clinica
where cod
in
(select clinica_cod
from MedicoClinica
where medico_cod
in
(select cod
from Medico
where nome = 'Arthur'));*/

#Exercício 7
/*select nome
from Especialidade
where cod
in
(select especialidade_cod
from MedicoEspecialidade
where medico_cod
in
(select cod
from Medico
where nome = 'Andre'));*/

#Exercício 8
/*select nome
from Medico
where cod
in
(select medico_cod
from Consulta
where hora
in
(select max(hora)
from Consulta));*/

#Exercício 9
/*delete from MedicoClinica where medico_cod = 10;

select nome
from Medico
where cod
not in
(select medico_cod
from MedicoClinica);*/

