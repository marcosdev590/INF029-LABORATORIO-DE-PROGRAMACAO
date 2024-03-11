//HEADERS 
#include "menus.h"

//DEFINE
#define TAM_MAX_ALUNOS 3
#define TAM_MAX_PROFESSORES 3

int main()
{
    //DECLARAÇÃO DOS VETORES E QUANTIDADE INICIAL DE ALUNOS E PROFESSORES
    Pessoa listaAlunos[TAM_MAX_ALUNOS];
    Pessoa listaProfessores[TAM_MAX_PROFESSORES];
    int totalAlunos = 0;
    int totalProfessores = 0;
  
    //INICIALIZA O MENU PRINCIPAL
    boasVindas();
    loopMenuPrincipal(listaAlunos, TAM_MAX_ALUNOS, &totalAlunos, listaProfessores, TAM_MAX_PROFESSORES, &totalProfessores);

    return 0;
}