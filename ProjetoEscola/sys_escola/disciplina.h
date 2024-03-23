//HEADERS
#include "structs.h"
#include "validacoes.h"

#ifndef DISCIPLINA_H
#define DISCIPLINA_H
//PROTÓTIPOS
int cadastroDisciplina(Pessoa * listaProfessor, int * totalProfessor ,Disciplina * listaDisciplinas, int * totalDisciplinas, int limiteDisciplinas);
int listarDisciplina(Disciplina * listaDisciplinas, int * totalDisciplinas);
void listarDisciplinas(Disciplina * listaDisciplinas, int * totalDisciplinas);
int atualizacaoDisciplina(Disciplina * listaDisciplinas, int * totalDisciplinas, Pessoa * listaAlunos, int * totalAlunos,  Pessoa * listaProfessores, int * totalProfessores);
int exclusaoDisciplina(Disciplina * listaDisciplinas, int * totalDisciplinas);
#endif