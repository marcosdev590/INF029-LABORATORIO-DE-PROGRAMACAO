//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//DEFINE
#define FALHA_NA_SOLICITACAO -400
#define SUCESSO_NA_SOLICITACAO -200
#define ENCERRAR_INT 0
#define ENCERRAR_STR "0"
#define ENCERRAR_CHR '0'
#define MAX_TAM_STR 50
#define MAX_TAM_CPF 15
#define MAX_TAM_DSC 7
#define LIMITE_ALUNOS_DISCIPLINA 40

//HEADERS
#include "menus.h"
#include "disciplina.h"

//CREATE
int cadastroDisciplina(Pessoa * listaProfessor, int * totalProfessor ,Disciplina * listaDisciplinas, int * totalDisciplinas, int limiteDisciplinas) // Cadastra uma disciplina, recebendo seu nome, código, semestre e professor responsável
{
	//Declara variáveis locais para validação
	int matricula, posicaoCerta;
	bool achou;
	char nome[MAX_TAM_STR];
	char codigo[MAX_TAM_DSC];
	Pessoa * professorResponsavel;
	Pessoa listaAlunosMatriculados[LIMITE_ALUNOS_DISCIPLINA];

	// Verifica se o array está cheio
	if (*totalDisciplinas >= limiteDisciplinas) {
		printf("LIMITE DE CADASTROS ATINGIDO. NÃO É POSSÍVEL REALIZAR NOVOS CADASTROS.\n");
		return FALHA_NA_SOLICITACAO;
	}

	// Solicita as informações da disciplina e valida antes de salvar no array
	printf("****************************************\n");
	printf("**              CADASTRO              **\n");
	printf("****************************************\n\n");
	printf("PARA SAIR A QUALQUER MOMENTO, DIGITE 0\n\n");

	printf("NOME: ");
	while ((getchar()) != '\n');
	validarNome(nome);
	if (strcmp(nome, ENCERRAR_STR) == 0) return FALHA_NA_SOLICITACAO;

	printf("CÓDIGO: ");
	validarCodigoDisciplina(codigo);
	if (strcmp(codigo, ENCERRAR_STR) == 0) return FALHA_NA_SOLICITACAO;

	printf("MATRÍCULA DO PROFESSOR RESPONSÁVEL: ");
	posicaoCerta = buscarPessoa(&achou, listaProfessor, totalProfessor);
	professorResponsavel = &listaProfessor[posicaoCerta];

	strcpy(listaDisciplinas[*totalDisciplinas].nome, nome);
	strcpy(listaDisciplinas[*totalDisciplinas].codigo, codigo);
	listaDisciplinas[*totalDisciplinas].professor = professorResponsavel;
	listaDisciplinas[*totalDisciplinas].qtdAlunosCadastrados = 0;

	(*totalDisciplinas)++;

	return SUCESSO_NA_SOLICITACAO;
}

//READ

int listarDisciplina(Disciplina * listaDisciplinas, int * totalDisciplinas) //Lista uma disciplina e seus dados, incluindo os alunos matriculados
{
	int posicaoCerta;
	bool achou = false;
	
	if (*totalDisciplinas == 0)
	{
		printf("------------------------------------------------------------------------------------\n");
		printf("NÃO HÁ DISCIPLINAS CADASTRADAS.\n");
		printf("------------------------------------------------------------------------------------\n\n");
	}
	else
	{
		printf("DIGITE O CÓDIGO DA DISCIPLINA: \n");
		
		while ((getchar()) != '\n');
		posicaoCerta = buscarDisciplina(&achou, listaDisciplinas, totalDisciplinas);

		while (!achou)
		{
			printf("CÓDIGO NÃO ENCONTRADO!!!!! DIGITE NOVAMENTE: ");
			posicaoCerta = buscarDisciplina(&achou, listaDisciplinas, totalDisciplinas);
			if (achou || posicaoCerta == FALHA_NA_SOLICITACAO) break;
		}
		if (posicaoCerta == FALHA_NA_SOLICITACAO) return FALHA_NA_SOLICITACAO;
		
		printf("------------------------------------------------------------------------------------\n");
		printf("%s - %s | SEMESTRE: %s | PROFESSOR: %s\n", listaDisciplinas[posicaoCerta].codigo, listaDisciplinas[posicaoCerta].nome, "2024.1", listaDisciplinas[posicaoCerta].professor->nome);
		
		if (listaDisciplinas[posicaoCerta].qtdAlunosCadastrados == 0)
		{
			printf("\n****************************************\n");
			printf("**     NÃO HÁ ALUNOS MATRICULADOS     **\n");
			printf("****************************************\n\n");
		}
		else
		{
			printf("****************************************\n");
			printf("**         ALUNOS MATRICULADOS        **\n");
			printf("****************************************\n\n");

			for(int i = 0; i < listaDisciplinas[posicaoCerta].qtdAlunosCadastrados; i++)
			{
				printf("MATRÍCULA: %d | NOME: %s | SEXO: %c | DATA DE NASCIMENTO: %02d/%02d/%04d | CPF: %s\n", 
				listaDisciplinas[posicaoCerta].alunos[i]->matricula,
				listaDisciplinas[posicaoCerta].alunos[i]->nome,
				listaDisciplinas[posicaoCerta].alunos[i]->sexo,
				listaDisciplinas[posicaoCerta].alunos[i]->dataNascimento.dia,
				listaDisciplinas[posicaoCerta].alunos[i]->dataNascimento.mes,
				listaDisciplinas[posicaoCerta].alunos[i]->dataNascimento.ano,
				listaDisciplinas[posicaoCerta].alunos[i]->cpf);
				printf("------------------------------------------------------------------------------------\n");
			}
		}
		
	}
		printf("\n");
	return SUCESSO_NA_SOLICITACAO;
}

void listarDisciplinas(Disciplina * listaDisciplinas, int * totalDisciplinas) //Lista o array de disciplinas, informando todos os dados por linhas, separando os atributos com um |
{ 
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
	  	printf("%s - %s | SEMESTRE: %s | PROFESSOR: %s\n", listaDisciplinas[i].codigo, listaDisciplinas[i].nome, "2024.1", listaDisciplinas[i].professor->nome); //IMPLEMENTAÇÃO DA IMPRESSÃO DAS DISCIPLINAS
		printf("------------------------------------------------------------------------------------\n");
	}
	printf("\n");
  }
}

//UPDATE
int atualizacaoDisciplina(Disciplina * listaDisciplinas, int * totalDisciplinas, Pessoa * listaAlunos, int * totalAlunos,  Pessoa * listaProfessores, int * totalProfessores) // Atualiza uma disciplina, recebendo seu nome, código, semestre e professor responsável
{
	bool achou = false;
	char nome[MAX_TAM_STR], codigo[MAX_TAM_DSC]; //Declarados aqui para não ter que incluir o define do tamanho no arquivo de menus
	int posicaoCerta;

	printf("\n****************************************\n");
	printf("**             ATUALIZAÇÃO            **\n");
	printf("****************************************\n\n");
	printf("PARA SAIR A QUALQUER MOMENTO, DIGITE 0\n\n");
	printf("DIGITE A MATRÍCULA DO CADASTRO A SER ATUALIZADO: ");

	while ((getchar()) != '\n');
	posicaoCerta = buscarDisciplina(&achou, listaDisciplinas, totalDisciplinas);
	
	while (!achou)
	{
		printf("CÓDIGO NÃO ENCONTRADO!!!!! DIGITE NOVAMENTE: ");
		posicaoCerta = buscarDisciplina(&achou, listaDisciplinas, totalDisciplinas);
		if (achou || posicaoCerta == FALHA_NA_SOLICITACAO) break;
	}
	if (posicaoCerta == FALHA_NA_SOLICITACAO) return FALHA_NA_SOLICITACAO;

	loopAtualizarDisciplina(listaDisciplinas, listaAlunos, listaProfessores, nome, codigo, totalAlunos, totalProfessores, &posicaoCerta, LIMITE_ALUNOS_DISCIPLINA);
	
	return SUCESSO_NA_SOLICITACAO;
}

//DELETE
int exclusaoDisciplina(Disciplina * listaDisciplinas, int * totalDisciplinas) // Exclui uma disciplina, recebendo seu código e reorganizando o array correspondente após apagar os dados
{
	bool achou = false;
	char codigo[MAX_TAM_DSC];
	printf("DIGITE O CÓDIGO DA DISCIPLINA A SER EXCLUÍDA: ");
	while ((getchar()) != '\n');
	fgets(codigo, MAX_TAM_DSC, stdin);
  codigo[strcspn(codigo, "\n")] = '\0';

	for (int i = 0; i < *totalDisciplinas; i++)
	{
		if (strcmp(codigo, listaDisciplinas[i].codigo))
		{
			for (int j = i; j < *totalDisciplinas - 1; j++)
			{
				strcpy(listaDisciplinas[j].nome, listaDisciplinas[j+1].nome);
				strcpy(listaDisciplinas[j].codigo, listaDisciplinas[j+1].codigo);
				listaDisciplinas[j].professor = listaDisciplinas[j+1].professor;
			}
			(*totalDisciplinas)--;
			achou = true;
			break;
		}
	}

	if (achou) return SUCESSO_NA_SOLICITACAO;
	else 
	{
		printf("CÓDIGO INEXISTENTE!!!!! ");
		return exclusaoDisciplina(listaDisciplinas, totalDisciplinas);
	}
}