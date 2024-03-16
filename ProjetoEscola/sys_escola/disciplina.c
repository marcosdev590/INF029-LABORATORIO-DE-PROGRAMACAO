//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//DEFINE
#define FALHA_NA_SOLICITACAO 400
#define SUCESSO_NA_SOLICITACAO 200
#define ENCERRAR_INT 0
#define ENCERRAR_STR "0"
#define ENCERRAR_CHR '0'
#define MAX_TAM_STR 50
#define MAX_TAM_CPF 15
#define MAX_TAM_DSC 7

//HEADERS
#include "disciplina.h"

//CREATE
int cadastroDisciplina(Pessoa * listaDisciplinas, int limiteDisciplinas, int * totalDisciplinas) // Cadastra uma disciplina, recebendo seu nome, código, semestre e professor responsável
{
	//Declara variáveis locais para validação
	int matricula;
	char nome[MAX_TAM_STR];
	char codigo[MAX_TAM_DSC];
	Pessoa professorResponsavel;

	return SUCESSO_NA_SOLICITACAO;
}

//READ
void listarDisciplinas(Disciplina * listaDisciplinas, int * totalDisciplinas) { //Lista o array de disciplinas, informando todos os dados por linhas, separando os atributos com um |
  printf("****************************************\n");
  printf("**       LISTAGEM DE DISCIPLINAS      **\n");
  printf("****************************************\n\n");
  printf("------------------------------------------------------------------------------------\n");

  if (*totalDisciplinas == 0)
  {
	  printf("NÃO HÁ DISCIPLINAS CADASTRADAS.\n");
	printf("------------------------------------------------------------------------------------\n\n");
  }
  else
  {
	for(int i = 0; i < *totalDisciplinas; i++){
	  printf("MATRICULA: %d | NOME: %s | SEMESTRE: %s | PROFESSOR: %s\n"); //IMPLEMENTAÇÃO DA IMPRESSÃO DAS DISCIPLINAS
	}
  }
}

//UPDATE
int atualizacaoDisciplina() // Atualiza uma disciplina, recebendo seu nome, código, semestre e professor responsável
{
	return 0;
}

//DELETE
int exclusaoDisciplina() // Exclui uma disciplina, recebendo seu código e reorganizando o array correspondente após apagar os dados
{
	return 0;
}