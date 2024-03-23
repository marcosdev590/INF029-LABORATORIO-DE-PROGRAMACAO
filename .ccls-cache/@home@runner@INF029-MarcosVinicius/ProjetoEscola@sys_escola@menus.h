//HEADERS 
#include "pessoa.h"
#include "disciplina.h"
#include "structs.h"

#ifndef MENUS_H
#define MENUS_H
//PROTÓTIPOS
int opcaoMenuAlunos();
void loopMenuAlunos(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos);

int opcaoMenuProfessores();
void loopMenuProfessores(Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores);

int opcaoMenuDisciplinas();
void loopMenuDisciplinas(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores, Disciplina * listaDisciplinas, int * totalDisciplinas, int TAM_MAX_DISCIPLINAS);

int opcaoMenuRelatorios();
void loopMenuRelatorios(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores, Disciplina * listaDisciplinas, int TAM_MAX_DISCIPLINAS, int * totalDisciplinas, int limiteAlunosDisciplina);

int opcaoMenuPrincipal();
void loopMenuPrincipal(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores, Disciplina * listaDisciplinas, int TAM_MAX_DISCIPLINAS, int * totalDisciplinas);

int opcaoAtualizarPessoa();
void loopAtualizarPessoa(Pessoa * listaPessoas, char nome[], char sexo, Data aniversario, char cpf[], int * posicaoCerta);

int opcaoAtualizarDisciplina();
void loopAtualizarDisciplina(Disciplina * listaDisciplinas, Pessoa * listaAlunos, Pessoa * listaProfessores, char nome[], char codigo[], int * totalProfessores, int * totalAlunos, int * posicaoCertaDisciplina, int limiteAlunosDisciplina);
#endif