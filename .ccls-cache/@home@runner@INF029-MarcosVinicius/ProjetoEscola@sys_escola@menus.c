//BIBLIOTECAS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//HEADERS 
#include "menus.h"
#include "relatorios.h"

//DEFINE
#define FALHA_NA_SOLICITACAO -400
#define SUCESSO_NA_SOLICITACAO -200
#define LIMITE_ALUNOS_DISCIPLINA 40

int opcaoMenuAlunos() //CAPTURA A ESCOLHA DO MENU ATUAL E RETORNA PARA A FUNÇÃO DE LOOP QUE A CHAMO
{
    int opcao;
    printf("\n****************************************\n");
    printf("**           MENU DE ALUNOS           **\n");
    printf("****************************************\n\n");
    printf("****************************************\n");
    printf("**       DIGITE A OPÇÃO DESEJADA      **\n");
    printf("****************************************\n\n");
    printf("0 - VOLTAR\n");
    printf("1 - CADASTRAR\n");
    printf("2 - LISTAR\n");
    printf("3 - ATUALIZAR\n");
    printf("4 - EXCLUIR\n");

    printf("\nDIGITE A OPÇÃO DESEJADA: ");
    scanf("%d", &opcao);

    return opcao;   
}

void loopMenuAlunos(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos)
{
    //CRIAÇÃO DE VARIÁVEIS
    int opcao, codigo;
    bool sair = false;

    while (!sair)
    {
        opcao = opcaoMenuAlunos();
        switch (opcao)
        {
        case 0:
            sair = true;
            break;

        case 1:
			codigo = cadastroPessoa(listaAlunos, TAM_MAX_ALUNOS, totalAlunos);
			if (codigo == SUCESSO_NA_SOLICITACAO) printf("\nCADASTRO DE ALUNO REALIZADO COM SUCESSO\n\n");
			else if (codigo == FALHA_NA_SOLICITACAO) printf("\nCADASTRO DE ALUNO CANCELADO COM SUCESSO\n\n");
            break;

        case 2:
            listarPessoas(listaAlunos, totalAlunos);
            break;

        case 3:
            atualizacaoPessoa(listaAlunos, totalAlunos);
			if (codigo == SUCESSO_NA_SOLICITACAO) printf("\nATUALIZAÇÃO DE ALUNO REALIZADA COM SUCESSO\n\n");
			else if (codigo == FALHA_NA_SOLICITACAO) printf("\nATUALIZAÇÃO DE ALUNO CANCELADA COM SUCESSO\n\n");
            break;

        case 4:
            exclusaoPessoa(listaAlunos, totalAlunos);
			if (codigo == SUCESSO_NA_SOLICITACAO) printf("\nEXCLUSÃO DE ALUNO REALIZADA COM SUCESSO\n\n");
			else if (codigo == FALHA_NA_SOLICITACAO) printf("\nEXCLUSÃO DE ALUNO CANCELADA COM SUCESSO\n\n");
            break;

        default:
            printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
        }
    }
}

int opcaoMenuProfessores() //CAPTURA A ESCOLHA DO MENU ATUAL E RETORNA PARA A FUNÇÃO DE LOOP QUE A CHAMO
{
    int opcao;
    printf("\n****************************************\n");
    printf("**         MENU DE PROFESSORES        **\n");
    printf("****************************************\n\n");
    printf("****************************************\n");
    printf("**       DIGITE A OPÇÃO DESEJADA      **\n");
    printf("****************************************\n\n");
    printf("0 - VOLTAR\n");
    printf("1 - CADASTRAR\n");
    printf("2 - LISTAR\n");
    printf("3 - ATUALIZAR\n");
    printf("4 - EXCLUIR\n");

    printf("\nDIGITE A OPÇÃO DESEJADA: ");
    scanf("%d", &opcao);

    return opcao;
}

void loopMenuProfessores(Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores)
{
    //CRIAÇÃO DE VARIÁVEIS
    int opcao, codigo;
    bool sair = false;

    while (!sair)
    {
        opcao = opcaoMenuProfessores();
        switch (opcao)
        {
        case 0:
            sair = true;
            break;

        case 1:
            codigo = cadastroPessoa(listaProfessores, TAM_MAX_PROFESSORES, totalProfessores);
			if (codigo == SUCESSO_NA_SOLICITACAO) printf("\nCADASTRO DE PROFESSOR REALIZADO COM SUCESSO\n\n");
			else if (codigo == FALHA_NA_SOLICITACAO) printf("\nCADASTRO DE PROFESSOR CANCELADO OU FALHOU\n\n");
            break;

        case 2:
            listarPessoas(listaProfessores, totalProfessores);
            break;

        case 3:
            atualizacaoPessoa(listaProfessores, totalProfessores);
			if (codigo == SUCESSO_NA_SOLICITACAO) printf("\nATUALIZAÇÃO DE PROFESSOR REALIZADA COM SUCESSO\n\n");
			else if (codigo == FALHA_NA_SOLICITACAO) printf("\nATUALIZAÇÃO DE PROFESSOR CANCELADA COM SUCESSO\n\n");
            break;

        case 4:
            exclusaoPessoa(listaProfessores, totalProfessores);
			if (codigo == SUCESSO_NA_SOLICITACAO) printf("\nEXCLUSÃO DE PROFESSOR REALIZADA COM SUCESSO\n\n");
			else if (codigo == FALHA_NA_SOLICITACAO) printf("\nEXCLUSÃO DE PROFESSOR CANCELADA COM SUCESSO\n\n");
            break;

        default:
            printf("\nOPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
        }
    }
}

int opcaoMenuDisciplinas() //CAPTURA A ESCOLHA DO MENU ATUAL E RETORNA PARA A FUNÇÃO DE LOOP QUE A CHAMO
{
    int opcao;
    printf("\n****************************************\n");
    printf("**         MENU DE DISCIPLINAS        **\n");
    printf("****************************************\n\n");
    printf("****************************************\n");
    printf("**       DIGITE A OPÇÃO DESEJADA      **\n");
    printf("****************************************\n\n");
    printf("0 - VOLTAR\n");
    printf("1 - CADASTRAR\n");
	printf("2 - LISTAR ALUNOS DE UMA DISCIPLINA\n");
    printf("3 - LISTAR DISCIPLINAS\n");
    printf("4 - ATUALIZAR\n");
    printf("5 - EXCLUIR\n");

    printf("\nDIGITE A OPÇÃO DESEJADA: ");
    scanf("%d", &opcao);

    return opcao;
}

void loopMenuDisciplinas(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores, Disciplina * listaDisciplinas, int * totalDisciplinas, int TAM_MAX_DISCIPLINAS)
{
    //CRIAÇÃO DE VARIÁVEIS
    int opcao;
    bool sair = false;

    while (!sair)
    {
        opcao = opcaoMenuDisciplinas();
        switch (opcao)
        {
        case 0:
            sair = true;
            break;

        case 1:
            cadastroDisciplina(listaProfessores, totalProfessores, listaDisciplinas, totalDisciplinas, TAM_MAX_DISCIPLINAS);
            break;

			case 2:
			listarDisciplina(listaDisciplinas, totalDisciplinas);
			break;

        case 3:
        	listarDisciplinas(listaDisciplinas, totalDisciplinas);
            break;

        case 4:
            atualizacaoDisciplina(listaDisciplinas, totalDisciplinas, listaAlunos, totalAlunos, listaProfessores, totalProfessores);
            break;

        case 5:
            exclusaoDisciplina(listaDisciplinas, totalDisciplinas);
            break;

        default:
            printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
        }
    }
}

int opcaoMenuRelatorios() //CAPTURA A ESCOLHA DO MENU ATUAL E RETORNA PARA A FUNÇÃO DE LOOP QUE A CHAMO
{
    int opcao;
    printf("\n****************************************\n");
    printf("**      MENU DE RELATÓRIOS GERAIS     **\n");
    printf("****************************************\n\n");
    printf("****************************************\n");
    printf("**       DIGITE A OPÇÃO DESEJADA      **\n");
    printf("****************************************\n\n");
    printf("0 - VOLTAR\n");
    printf("1 - LISTAR TODOS OS ALUNOS\n"); 
    printf("2 - LISTAR ALUNOS ALFABETICAMENTE\n"); 
    printf("3 - LISTAR ALUNOS POR SEXO \n"); 
    printf("4 - LISTAR ALUNOS POR DATA DE NASCIMENTO\n"); 
    printf("5 - LISTAR TODOS OS PROFESSORES\n");
    printf("6 - LISTAR PROFESSORES ALFABETICAMENTE\n"); 
    printf("7 - LISTAR PROFESSORES POR SEXO \n"); 
    printf("8 - LISTAR PROFESSORES POR DATA DE NASCIMENTO\n"); 
    printf("9 - LISTAR ANIVERSARIANTES DO MES\n");
    printf("10 - LISTAR DISCIPLINAS\n");
    printf("11 - LISTAR TURMAS SUPERPOPULADAS\n");
    printf("12 - LISTAR ALUNOS SUB-MATRICULADOS\n");

    printf("\nDIGITE A OPÇÃO DESEJADA: ");
    scanf("%d", &opcao);

    return opcao;
}

void loopMenuRelatorios(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores, Disciplina * listaDisciplinas, int TAM_MAX_DISCIPLINAS, int * totalDisciplinas, int limiteAlunosDisciplina)
{
    //CRIAÇÃO DE VARIÁVEIS
    int opcao;
    bool sair = false;

    while (!sair)
    {
        opcao = opcaoMenuRelatorios();
        switch (opcao)
        {
        case 0:
            sair = true;
            break;

        case 1:
            listarPessoas(listaAlunos, totalAlunos);
            break;

        case 2:
            listarPessoasPorNome(listaAlunos, totalAlunos);
            break;

        case 3:
            listarPessoasPorSexo(listaAlunos, totalAlunos);
            break;

        case 4:
            listarPessoasPorAniversario(listaAlunos, totalAlunos);
            break;

        case 5:
            listarPessoas(listaProfessores, totalProfessores);
            break;

        case 6:
            listarPessoasPorNome(listaProfessores, totalAlunos);
            break;

        case 7:
            listarPessoasPorSexo(listaProfessores, totalProfessores);
            break;

        case 8:
            listarPessoasPorAniversario(listaProfessores, totalProfessores);
            break;

        case 9:
            listarAniversariantesDoMes(listaAlunos, listaProfessores, totalAlunos, totalProfessores);
          break;

        case 10:
            listarDisciplinas(listaDisciplinas, totalDisciplinas);
            break;

        case 11:
            listarDisciplinasSuperpopuladas(listaDisciplinas, totalDisciplinas, limiteAlunosDisciplina);
            break;

          case 12:
            listarAlunosSubmatriculados(listaAlunos, totalAlunos);
            break;
          
        default:
            printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
        }
    }
}

int opcaoMenuPrincipal() //CAPTURA A ESCOLHA DO MENU ATUAL E RETORNA PARA A FUNÇÃO DE LOOP QUE A CHAMO
{
    int opcao;
    printf("\n****************************************\n");
    printf("**           MENU PRINCIPAL           **\n");
    printf("****************************************\n\n");
    printf("****************************************\n");
    printf("**       DIGITE A OPÇÃO DESEJADA      **\n");
    printf("****************************************\n\n");
    printf("0 - SAIR\n");
    printf("1 - ALUNOS\n");
    printf("2 - PROFESSORES\n");
    printf("3 - DISCIPLINAS\n");
    printf("4 - RELATÓRIOS\n");

    printf("\nDIGITE A OPÇÃO DESEJADA: ");
    scanf("%d", &opcao);

    return opcao;
}

void loopMenuPrincipal(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores, Disciplina * listaDisciplinas, int TAM_MAX_DISCIPLINAS, int * totalDisciplinas)
{
    //CRIAÇÃO DE VARIÁVEIS
    int opcao;
    bool sair = false;

    while (!sair)
    {
        opcao = opcaoMenuPrincipal();
        switch (opcao)
        {
        case 0:
            printf("SAINDO DO SISTEMA...........\n");
            sair = true;
            break;

        case 1:
            loopMenuAlunos(listaAlunos, TAM_MAX_ALUNOS, totalAlunos);
            break;

        case 2:
            loopMenuProfessores(listaProfessores, TAM_MAX_PROFESSORES, totalProfessores);
            break;

        case 3:
            loopMenuDisciplinas(listaAlunos, TAM_MAX_ALUNOS, totalAlunos, listaProfessores, TAM_MAX_PROFESSORES, totalProfessores, listaDisciplinas, totalDisciplinas, TAM_MAX_DISCIPLINAS);
            break;

        case 4:
            loopMenuRelatorios(listaAlunos, TAM_MAX_ALUNOS, totalAlunos, listaProfessores, TAM_MAX_PROFESSORES, totalProfessores, listaDisciplinas, TAM_MAX_DISCIPLINAS, totalDisciplinas, LIMITE_ALUNOS_DISCIPLINA);
            break;

        default:
            printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
        }
    }
}

int opcaoAtualizarPessoa() //CAPTURA A ESCOLHA DO MENU ATUAL E RETORNA PARA A FUNÇÃO DE LOOP QUE A CHAMO
{
	int opcao;
	printf("\n****************************************\n");
	printf("**       DIGITE A OPÇÃO DESEJADA      **\n");
	printf("****************************************\n\n");
	printf("0 - SAIR\n");
	printf("1 - ATUALIZAR NOME\n");
	printf("2 - ATUALIZAR SEXO\n");
	printf("3 - ATUALIZAR DATA DE NASCIMENTO\n");
	printf("4 - ATUALIZAR CPF\n");

	printf("\nDIGITE A OPÇÃO DESEJADA: ");
	scanf("%d", &opcao);

	return opcao;
}

void loopAtualizarPessoa(Pessoa * listaPessoas, char nome[], char sexo, Data aniversario, char cpf[], int * posicaoCerta)
{
	//CRIAÇÃO DE VARIÁVEIS
	int opcao;
	bool sair = false;

	while (!sair)
	{
		opcao = opcaoAtualizarPessoa();
		switch (opcao)
		{
		case 0:
			sair = true;
			break;

		case 1:
			printf("NOME: ");
			while ((getchar()) != '\n');
			validarNome(nome);
			strcpy(listaPessoas[*posicaoCerta].nome, nome);
			break;

		case 2:
			printf("SEXO (M/F): ");
			while ((getchar()) != '\n');
			sexo = validarSexo();
			listaPessoas[*posicaoCerta].sexo = sexo;
			break;

		case 3:
			aniversario = validarAniversario();
			listaPessoas[*posicaoCerta].dataNascimento = aniversario;
			break;

		case 4:
			printf("CPF: ");
			while ((getchar()) != '\n');
			validarCPF(cpf);
			strcpy(listaPessoas[*posicaoCerta].cpf, cpf);
			break;

		default:
			printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
		}
	}
}

int opcaoAtualizarDisciplina() //CAPTURA A ESCOLHA DO MENU ATUAL E RETORNA PARA A FUNÇÃO DE LOOP QUE A CHAMO
{
	int opcao;
	printf("\n****************************************\n");
	printf("**       DIGITE A OPÇÃO DESEJADA      **\n");
	printf("****************************************\n\n");
	printf("0 - SAIR\n");
	printf("1 - ATUALIZAR NOME\n");
	printf("2 - ATUALIZAR CODIGO\n");
	printf("3 - ATUALIZAR PROFESSOR RESPONSÁVEL\n");
	printf("4 - ATUALIZAR SEMESTRE\n");
	printf("5 - ADICIONAR ALUNOS\n");
	printf("6 - REMOVER ALUNOS\n");

	printf("\nDIGITE A OPÇÃO DESEJADA: ");
	scanf("%d", &opcao);

	return opcao;
}

void loopAtualizarDisciplina(Disciplina * listaDisciplinas, Pessoa * listaAlunos, Pessoa * listaProfessores, char nome[], char codigo[], int * totalProfessores, int * totalAlunos, int * posicaoCertaDisciplina, int limiteAlunosDisciplina)
{
	//CRIAÇÃO DE VARIÁVEIS
	int opcao, posicaoCertaProfessor, posicaoCertaAluno, qtdAlunosCadastrados;
	bool sair = false, achou = false;
	anoSemestre semestre;

	while (!sair)
	{
		opcao = opcaoAtualizarDisciplina();
		switch (opcao)
		{
			case 0:
				sair = true;
				break;
	
			case 1:
				printf("NOME: ");
				while ((getchar()) != '\n');
				validarNome(nome);
				strcpy(listaDisciplinas[*posicaoCertaDisciplina].nome, nome);
				break;
	
			case 2:
				printf("CODIGO: ");
				while ((getchar()) != '\n');
				validarCodigoDisciplina(codigo);
				strcpy(listaDisciplinas[*posicaoCertaDisciplina].codigo, codigo);
				break;
	
			case 3:
				printf("MATRÍCULA DO PROFESSOR RESPONSÁVEL: ");
				posicaoCertaProfessor = buscarPessoa(&achou, listaProfessores, totalProfessores);
					listaDisciplinas[*posicaoCertaDisciplina].professor = &listaProfessores[posicaoCertaProfessor];
				break;
	
			case 4:
				
				break;
	
			case 5:
				qtdAlunosCadastrados = listaDisciplinas[*posicaoCertaDisciplina].qtdAlunosCadastrados;
				
				if (qtdAlunosCadastrados == limiteAlunosDisciplina)
				{
					printf("A QUANTIDADE DE ALUNOS JÁ ESTÁ NO LIMITE DE VAGAS OFERTADAS!!!!\n");
				}
				
				printf("MATRÍCULA DO ALUNO A SER ADICIONADO: ");
				posicaoCertaAluno = buscarPessoa(&achou, listaAlunos, totalAlunos);
		
				listaDisciplinas[*posicaoCertaDisciplina].alunos[qtdAlunosCadastrados] = &listaAlunos[posicaoCertaAluno];
        listaAlunos[posicaoCertaAluno].qtdDisciplinasMatriculadas++;
				(listaDisciplinas[*posicaoCertaDisciplina].qtdAlunosCadastrados)++;
				break;
	
			case 6:
				qtdAlunosCadastrados = listaDisciplinas[*posicaoCertaDisciplina].qtdAlunosCadastrados;
					
				printf("MATRÍCULA DO ALUNO A SER REMOVIDO: ");
				posicaoCertaAluno = buscarPessoa(&achou, listaAlunos, totalAlunos);
        listaAlunos[posicaoCertaAluno].qtdDisciplinasMatriculadas--;

				for (int i = 0; i < qtdAlunosCadastrados; i++)
				{
					if (listaDisciplinas[*posicaoCertaDisciplina].alunos[i]->matricula == listaAlunos[posicaoCertaAluno].matricula)
					{
						for (int j = i; j < qtdAlunosCadastrados - 1; j++)
						{
							listaDisciplinas[*posicaoCertaDisciplina].alunos[j] = listaDisciplinas[*posicaoCertaDisciplina].alunos[j+1];
						}
						(listaDisciplinas[*posicaoCertaDisciplina].qtdAlunosCadastrados)--;
						break;
					}
				}
				break;
	
			default:
				printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
		}
	}
}