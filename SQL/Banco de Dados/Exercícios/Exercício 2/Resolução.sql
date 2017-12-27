#Exercício 1
/*select e.nome 
from Especialidade e, MedicoEspecialidade me, Medico m
where me.medico_cod = m.cod and me.especialidade_cod = e.cod and m.nome = 'Paulo';
*/

#Exercício 2
/*select distinct c.data
from Consulta c, Medico m
where c.medico_cod = m.cod and m.nome = 'Arthur';
*/

#Exercício 3
/*select m.nome, c.nome, c.endereco
from Medico m, Clinica c, Especialidade e, MedicoEspecialidade me, EspecialidadeClinica ec
where m.cod = me.medico_cod and e.cod = me.especialidade_cod and
ec.especialidade_cod = me.especialidade_cod and c.cod = ec.clinica_cod and 
e.nome = 'CLINICO GERAL';
*/

#Exercício 4
/*select m.nome, m.telefone
from Medico m, Especialidade e, MedicoEspecialidade me
where m.cod = me.medico_cod and e.cod = me.especialidade_cod and e.nome = 'PEDIATRIA';
*/

#Exercício 5
/*select m.nome, m.telefone, e.nome
from Medico m, Especialidade e, MedicoEspecialidade me
where m.cod = me.medico_cod and e.cod = me.especialidade_cod;
*/

#Exercício 6
/*select c.nome, c.endereco
from Clinica c, Especialidade e, EspecialidadeClinica ec
where c.cod = ec.clinica_cod and e.cod = ec.especialidade_cod
and (e.nome = 'OFTALMOLOGIA' or e.nome = 'GINECOLOGIA');*/

#Exercício 7
/*select c.nome, c.endereco
from Clinica c, Consulta ct
where c.cod = ct.clinica_cod and ct.data = '2010-03-30';
*/

#Exercício 8
/*select m.nome
from Medico m, Clinica c, Especialidade e,
MedicoEspecialidade me, MedicoClinica mc
where m.cod = me.medico_cod and e.cod = me.especialidade_cod and
c.cod = mc.clinica_cod and me.medico_cod = mc.medico_cod and
c.endereco = 'barro preto' and e.nome = 'CLiNiCO GERAL';*/

#Exercício 9
/*select m.nome
from Medico m, Clinica c, MedicoClinica mc
where m.cod = mc.medico_cod and c.cod = mc.clinica_cod and c.nome = 'clinica bem estar'
*/

#Exercício 10
/*select c.nome, c.endereco
from Clinica c, Medico m, MedicoClinica mc
where m.cod = mc.medico_cod and c.cod = mc.clinica_cod and m.nome = 'Andre';
*/