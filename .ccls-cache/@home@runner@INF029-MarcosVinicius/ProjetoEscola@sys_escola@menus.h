//HEADERS 
#include "pessoa.h"
#include "disciplina.h"
#include "relatorios.h"
#include "structs.h"

//PROTÓTIPOS
int opcaoMenuAlunos();
void loopMenuAlunos(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos);

int opcaoMenuProfessores();
void loopMenuProfessores(Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores);

int opcaoMenuDisciplinas();
void loopMenuDisciplinas(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores);

int opcaoMenuRelatorios();
void loopMenuRelatorios(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores, Disciplina * listaDisciplinas, int TAM_MAX_DISCIPLINAS, int * totalDisciplinas);

int opcaoMenuPrincipal();
void loopMenuPrincipal(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores, Disciplina * listaDisciplinas, int TAM_MAX_DISCIPLINAS, int * totalDisciplinas);