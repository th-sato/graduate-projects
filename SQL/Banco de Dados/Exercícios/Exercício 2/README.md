---
output:
  pdf_document: default
  html_document: default
---
### Copie os comandos em um editor de texto, ao final do exercício envie o documento contendo todos os comandos executados.


1. Rode o script para criação das tabelas.
    * Medico(cod, nome, telefone)
    * Especialidade(cod, nome)
    * Clinica(cod, nome, endereco)
    * Consulta(cod, data, hora, #especialidade_cod, #medico_cod, #clinica_cod)
    * MedicoEspecialidade(#medico_cod,#especialidade_cod)
    * EspecialidadeClinica(#especialidade_cod , #clinica_cod)
    * MedicoClinica(#medico_cod,#clinica_cod)

2. Rode o script de inserção dos dados.

3. Formule e executa as seguintes consultas. (USE ALIAS PARA O NOME DAS TABELAS)
    * Obter as especialidades do Dr Paulo;
    * Obter as datas das consultas do dr Arthur;
    * Selecione o nome do médico e o nome e endereço da clínica para todas as consultas que possuem especialidade ‘CLINICO GERAL’;
    * Selecione o nome e telefone dos médicos PEDIATRAS;
    * Selecione o nome e telefone dos médicos e o nome de suas respectivas especialidade;
    * Mostre o nome e o endereço das clínicas especializadas em ‘OFTALMOLOGIA’ ou ‘GINECOLOGIA’;
    * Mostre o nome e o endereço das clínicas que possuem consulta marcada para 30/03/2010;
    * Selecionar o nome dos médicos que trabalham no Barro Preto e são especialistas em ‘CLINICO GERAL’;
    * Recuperar nome dos médicos que atendem na Clínica Bem Estar;
    * Exiba o nome e endereço das clínicas onde o médico André trabalha.
