//BIBLIOTECAS
#include <stdio.h>

//HEADERS 
#include "menus.h"

//DEFINE
#define TAM_MAX_ALUNOS 3
#define TAM_MAX_PROFESSORES 3
#define TAM_MAX_DISCIPLINAS 3

void main()
{
    //DECLARAÇÃO DAS LISTAS INICIAIS DE ALUNOS, PROFESSORES E DICIPLINAS E QUANTIDADE INICIAL DE ALUNOS E PROFESSORES
    Pessoa listaAlunos[TAM_MAX_ALUNOS];
    Pessoa listaProfessores[TAM_MAX_PROFESSORES];
	Disciplina listaDisciplinas[TAM_MAX_DISCIPLINAS];
    int totalAlunos = 0;
    int totalProfessores = 0;
	int totalDisciplinas = 0;
  
    //INICIALIZA O MENU PRINCIPAL
	printf("****************************************\n");
	printf("**      BEM VINDOS AO SYS_ESCOLA      **\n");
	printf("****************************************\n");
    loopMenuPrincipal(listaAlunos, TAM_MAX_ALUNOS, &totalAlunos, listaProfessores, TAM_MAX_PROFESSORES, &totalProfessores, listaDisciplinas, TAM_MAX_DISCIPLINAS, &totalDisciplinas);
}