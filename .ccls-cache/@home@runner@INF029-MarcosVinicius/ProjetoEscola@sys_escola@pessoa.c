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

//HEADERS
#include "menus.h"
#include "pessoa.h"

//CREATE
int cadastroPessoa(Pessoa * listaPessoas, int limitePessoas, int * totalPessoas) //Cadastra um aluno ou professor, recebendo sua matrícula, nome, sexo, data de nascimento e CPF. Chama uma função para validar os dados antes de gravar no array correspondente.
{
	//Declara variáveis locais para validação
	int matricula;
	char nome[MAX_TAM_STR];
	char sexo;
	Data aniversario;
	int diaAniversario, mesAniversario, anoAniversario;
	char cpf[MAX_TAM_CPF];

	// Verifica se o array está cheio
	if (*totalPessoas >= limitePessoas) {
		printf("LIMITE DE CADASTROS ATINGIDO. NÃO É POSSÍVEL REALIZAR NOVOS CADASTROS.\n");
		return FALHA_NA_SOLICITACAO;
	}

	// Solicita as informações da pessoa e valida antes de salvar no array
	printf("****************************************\n");
	printf("**              CADASTRO              **\n");
	printf("****************************************\n\n");
	printf("PARA SAIR A QUALQUER MOMENTO, DIGITE 0\n\n");

	matricula = validarMatricula(listaPessoas, totalPessoas);

	printf("NOME: ");
	while ((getchar()) != '\n');
	validarNome(nome);
	if (strcmp(nome, ENCERRAR_STR) == 0) return FALHA_NA_SOLICITACAO;

	printf("SEXO (M/F): ");
	sexo = validarSexo();
	if (sexo == ENCERRAR_CHR) return FALHA_NA_SOLICITACAO;

	aniversario = validarAniversario();
	if (aniversario.dia == ENCERRAR_INT || aniversario.mes == ENCERRAR_INT || aniversario.ano == ENCERRAR_INT) return FALHA_NA_SOLICITACAO;

	printf("CPF: ");
	while ((getchar()) != '\n');
	validarCPF(cpf);
	if (strcmp(cpf, ENCERRAR_STR) == 0) return FALHA_NA_SOLICITACAO;

	listaPessoas[*totalPessoas].matricula = matricula;
	strcpy(listaPessoas[*totalPessoas].nome, nome);
	listaPessoas[*totalPessoas].sexo = sexo;
	listaPessoas[*totalPessoas].dataNascimento = aniversario;
	strcpy(listaPessoas[*totalPessoas].cpf, cpf);
  listaPessoas[*totalPessoas].qtdDisciplinasMatriculadas = 0;
	
	(*totalPessoas)++; // Incrementa o total de alunos ou professores cadastrados

	return SUCESSO_NA_SOLICITACAO;
}

//READ
void listarPessoas(Pessoa * listaPessoas, int * totalPessoas) // Lista o array de alunos ou professores, informando todos os dados das pessoas por linhas, separando os atributos com um |
{
	printf("****************************************\n");
	printf("**         LISTAGEM DE PESSOAS        **\n");
	printf("****************************************\n\n");
	printf("------------------------------------------------------------------------------------\n");

	if (*totalPessoas == 0)
	{
		printf("NÃO HÁ PESSOAS CADASTRADAS.\n");
	  printf("------------------------------------------------------------------------------------\n\n");
	}
	else
	{
		for (int i = 0; i < *totalPessoas; i++) 
		{
			printf("MATRÍCULA: %d | NOME: %s | SEXO: %c | DATA DE NASCIMENTO: %02d/%02d/%04d | CPF: %s\n", listaPessoas[i].matricula, listaPessoas[i].nome, listaPessoas[i].sexo, listaPessoas[i].dataNascimento.dia, listaPessoas[i].dataNascimento.mes, listaPessoas[i].dataNascimento.ano, listaPessoas[i].cpf);
			printf("------------------------------------------------------------------------------------\n");
		}
		printf("\n");
	}  
}

//UPDATE
int atualizacaoPessoa(Pessoa * listaPessoas, int * totalPessoas) //Atualiza um aluno ou professor, recebendo sua matrícula e atualizando a mesma, além de nome, sexo, data de nascimento e CPF. Chama uma função para validar os dados antes de gravar no array correspondente.
{
	bool achou = false;
	int posicaoCerta, novaMatricula, diaAniversario, mesAniversario, anoAniversario;
	char novoSexo, novoNome[MAX_TAM_STR], novoCpf[MAX_TAM_CPF];
	Data novoAniversario;
	
	printf("\n****************************************\n");
	printf("**             ATUALIZAÇÃO            **\n");
	printf("****************************************\n\n");
	printf("PARA SAIR A QUALQUER MOMENTO, DIGITE 0\n\n");
	printf("DIGITE A MATRÍCULA DO CADASTRO A SER ATUALIZADO: ");

	posicaoCerta = buscarPessoa(&achou, listaPessoas, totalPessoas);
	
	if (posicaoCerta == FALHA_NA_SOLICITACAO) return FALHA_NA_SOLICITACAO;
	else if (!achou)
	{
		printf("MATRÍCULA NÃO ENCONTRADA!!!!! DIGITE NOVAMENTE: ");
		posicaoCerta = buscarPessoa(&achou, listaPessoas, totalPessoas);
	}

	loopAtualizarPessoa(listaPessoas, novoNome, novoSexo, novoAniversario, novoCpf, &posicaoCerta);
		
	return SUCESSO_NA_SOLICITACAO;
}

//DELETE
int exclusaoPessoa(Pessoa * listaPessoas, int * totalPessoas) //Exclui o cadastro de um aluno ou professor, recebendo sua matrícula e reorganizando o array correspondente após apagar os dados
{
	bool achou = false;
	int matricula;
	printf("DIGITE A MATRÍCULA DO CADASTRO A SER EXCLUÍDO: ");
	scanf("%d", &matricula);

	for (int i = 0; i < *totalPessoas; i++)
	{
		if (matricula == listaPessoas[i].matricula)
		{
			for (int j = i; j < *totalPessoas - 1; j++)
			{
				listaPessoas[j].matricula = listaPessoas[j+1].matricula;
				strcpy(listaPessoas[j].nome, listaPessoas[j+1].nome);
				listaPessoas[j].sexo = listaPessoas[j+1].sexo;
				listaPessoas[j].dataNascimento = listaPessoas[j+1].dataNascimento;
				strcpy(listaPessoas[j].cpf, listaPessoas[j+1].cpf);
			}
			(*totalPessoas)--;
			achou = true;
			break;
		}
	}

	if (achou) return SUCESSO_NA_SOLICITACAO;
	else 
	{
		printf("MATRÍCULA INEXISTENTE!!!!! ");
		return exclusaoPessoa(listaPessoas, totalPessoas);
	}	
}