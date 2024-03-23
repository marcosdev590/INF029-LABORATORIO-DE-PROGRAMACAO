//HEADERS
#include "structs.h"

#ifndef RELATORIOS_H
#define RELATORIOS_H
//PROTÓTIPOS

int listarPessoasPorSexo(Pessoa * listaPessoas, int * totalPessoas); //Lista todos os alunos ou professores em ordem de matrícula separando por sexo

int listarPessoasPorNome(Pessoa * listaPessoas, int * totalPessoas); // Lista todos os alunos ou professores em ordem alfabética por nome

int listarPessoasPorAniversario(Pessoa * listaPessoa, int * totalPessoas); // Lista todos os alunos ou professores por data de nascimento

int listarAniversariantesDoMes(Pessoa * listaAlunos, Pessoa * listaProfessores, int * totalAlunos, int * totalProfessores); //  Lista todos os alunos e professores cujo mês da data de nascimento é igual ao do mês de execução do código

int buscarPessoas(); //Lista todas as pessoas a partir de uma string de busca de no mínimo três letras

int listarAlunosSubmatriculados(Pessoa * listaAlunos, int * totalAlunos); //Lista todos os alunos matriculados em menos de três disciplinas

int listarDisciplinasSuperpopuladas(Disciplina * listaDisciplinas, int * totalDisciplinas, int limiteAlunosDisciplina); //Lista todas as disciplinas com mais de 40 alunos, incluindo o nome do professor responsável

#endif