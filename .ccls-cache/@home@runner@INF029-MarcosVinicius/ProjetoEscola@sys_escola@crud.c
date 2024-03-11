//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//HEADERS
#include "crud.h"

//DEFINE
#define FALHA_NA_SOLICITACAO 400
#define SUCESSO_NA_SOLICITACAO 200
#define TAMANHO_NOME 50
#define TAMANHO_CPF 15

// CREATE

int cadastroPessoa(Pessoa * listaPessoas, int limitePessoas, int * totalPessoas) //Cadastra um aluno ou professor, recebendo sua matrícula, nome, sexo, data de nascimento e CPF. Chama uma função para validar os dados antes de gravar no array correspondente.
{
    //Declara variáveis locais para validação
    int matricula;
    char nome[50];
    char sexo;
    int diaAniversario, mesAniversario, anoAniversario;
    char cpf[15];

    // Verifica se o array está cheio
    if (*totalPessoas >= limitePessoas) {
        printf("LIMITE DE CADASTROS ATINGIDO. NÃO É POSSÍVEL REALIZAR NOVOS CADASTROS.\n");
        return FALHA_NA_SOLICITACAO;
    }

    // Solicita as informações da pessoa e valida antes de salvar no array
    printf("****************************************\n");
    printf("**              CADASTRO              **\n");
    printf("****************************************\n\n");
    printf("MATRÍCULA: ");
    scanf("%d", &matricula);
    
    printf("NOME: ");
    while ((getchar()) != '\n');
    fgets(nome, TAMANHO_NOME, stdin);
    
    printf("SEXO: ");
    scanf(" %c", &sexo);

    printf("DIA DA DATA DE NASCIMENTO (FORMATO DD): ");
    scanf("%d", &diaAniversario);

    printf("MÊS DA DATA DE NASCIMENTO (FORMATO MM): ");
    scanf("%d", &mesAniversario);

    printf("ANO DA DATA DE NASCIMENTO (FORMATO AAAA): ");
    scanf("%d", &anoAniversario);

    printf("CPF: ");
    while ((getchar()) != '\n');
    fgets(cpf, TAMANHO_CPF, stdin);

    listaPessoas[*totalPessoas].matricula = validarMatricula(matricula);
    strcpy(listaPessoas[*totalPessoas].nome, validarNome(nome));
    listaPessoas[*totalPessoas].sexo = validarSexo(sexo);
    listaPessoas[*totalPessoas].dataNascimento = validarAniversario(diaAniversario, mesAniversario, anoAniversario);
    strcpy(listaPessoas[*totalPessoas].cpf, validarCPF(cpf));

    (*totalPessoas)++; // Incrementa o total de alunos ou professores cadastrados

    return SUCESSO_NA_SOLICITACAO;
}

int cadastroDisciplina() // Cadastra uma disciplina, recebendo seu nome, código, semestre e professor responsável
{
    return SUCESSO_NA_SOLICITACAO;
}

// READ
void listarPessoas(Pessoa * listaPessoas, int * totalPessoas) // Lista o array de alunos ou professores, informando todos os dados das pessoas por linhas, separando os atributos com um |
{
    printf("****************************************\n");
    printf("**         LISTAGEM DE PESSOAS        **\n");
    printf("****************************************\n\n");

    printf("------------------------------------------------------------------------------------\n");
    if (*totalPessoas == 0)
    {
        printf("NÃO HÁ PESSOAS CADASTRADAS.\n");
      printf("------------------------------------------------------------------------------------\n");
    }
    else
    {
        for (int i = 0; i < *totalPessoas; i++) 
        {
            printf("MATRÍCULA: %09d | NOME: %s | SEXO: %c | DATA DE NASCIMENTO: %02d/%02d/%04d | CPF: %s |\n", listaPessoas[i].matricula, listaPessoas[i].nome, listaPessoas[i].sexo, listaPessoas[i].dataNascimento.dia, listaPessoas[i].dataNascimento.mes, listaPessoas[i].dataNascimento.ano, listaPessoas[i].cpf);
            printf("------------------------------------------------------------------------------------\n");
        }
    }  
}

void listarDisciplinas() //Lista o array de disciplinas, informando todos os dados por linhas, separando os atributos com um |
{
    return 0;
}

// UPDATE

int atualizacaoPessoa(Pessoa * listaPessoas, int * totalPessoas) //Atualiza um aluno ou professor, recebendo sua matrícula, nome, sexo, data de nascimento e CPF. Chama uma função para validar os dados antes de gravar no array correspondente.
{
	bool achou = false;
	int matricula;
	printf("DIGITE A MATRÍCULA DO CADASTRO A SER ATUALIZADO: ");
	scanf("%d", &matricula);

	for (int i = 0; i < *totalPessoas; i++)
	{
		if (matricula == listaPessoas[i].matricula)
		{
			scanf("%d", &listaPessoas[i].matricula);
			achou = true;
			break;
		}
	}

	if (achou) printf("ALUNO EXCLUÍDO COM SUCESSO\n");
	else printf("MATRÍCULA INEXISTENTE\n");
	return 0;
}

int atualizacaoDisciplina() // Atualiza uma disciplina, recebendo seu nome, código, semestre e professor responsável
{
    return 0;
}

// DELETE

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

	if (achou) printf("ALUNO EXCLUÍDO COM SUCESSO\n");
	else printf("MATRÍCULA INEXISTENTE\n");
    return 0;
}

int exclusaoDisciplina() // Exclui uma disciplina, recebendo seu código e reorganizando o array correspondente após apagar os dados
{
    return 0;
}

// RELATÓRIOS

int listarDisciplina() //Lista uma disciplina e seus dados, incluindo os alunos matriculados
{
    return 0;
}

int listarPessoasPorSexo() //Lista todos os alunos ou professores em ordem de matrícula separando por sexo
{
    return 0;
}

int listarPessoasPorNome() // Lista todos os alunos ou professores em ordem alfabética por nome
{
    return 0;
}

int listarPessoasPorAniversario() // Lista todos os alunos ou professores por data de nascimento
{
    return 0;
}

int listarAniversariantesDoMes() //  Lista todos os alunos e professores cujo mês da data de nascimento é igual ao do mês de execução do código
{
    return 0;
}

int buscarPessoas() //Lista todas as pessoas a partir de uma string de busca de no mínimo três letras
{
    return 0;
}

int listarAlunosSubmatriculados() //Lista todos os alunos matriculados em menos de três disciplinas
{
    return 0;
}

int listarDisciplinasSuperpopuladas() //Lista todas as disciplinas com mais de 40 alunos, incluindo o nome do professor responsável
{
    return 0;
}