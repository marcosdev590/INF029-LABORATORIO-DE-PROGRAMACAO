//BIBLIOTECAS
#include <stdio.h>
#include <stdbool.h>

//HEADERS 
#include "menus.h"

void boasVindas()
{
    printf("****************************************\n");
    printf("**      BEM VINDOS AO SYS_ESCOLA      **\n");
    printf("****************************************\n\n");
}

int opcaoMenuAlunos()
{
    int opcao;
    printf("****************************************\n");
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
    int opcao;
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
            cadastroPessoa(listaAlunos, TAM_MAX_ALUNOS, totalAlunos);
            break;

        case 2:
            listarPessoas(listaAlunos, totalAlunos);
            break;

        case 3:
            atualizacaoPessoa(listaAlunos, totalAlunos);
            break;

        case 4:
            exclusaoPessoa(listaAlunos, totalAlunos);
            break;

        default:
            printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
        }
    }
}

int opcaoMenuProfessores()
{
    int opcao;
    printf("****************************************\n");
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
    int opcao;
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
            cadastroPessoa(listaProfessores, TAM_MAX_PROFESSORES, totalProfessores);
            break;

        case 2:
            listarPessoas(listaProfessores, totalProfessores);
            break;

        case 3:
            atualizacaoPessoa(listaProfessores, totalProfessores);
            break;

        case 4:
            exclusaoPessoa(listaProfessores, totalProfessores);
            break;

        default:
            printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
        }
    }
}

int opcaoMenuDisciplinas()
{
    int opcao;
    printf("****************************************\n");
    printf("**         MENU DE DISCIPLINAS        **\n");
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

void loopMenuDisciplinas(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores)
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
            cadastroDisciplina();
            break;

        case 2:
            listarDisciplinas();
            break;

        case 3:
            atualizacaoDisciplina();
            break;

        case 4:
            exclusaoDisciplina();
            break;

        default:
            printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
        }
    }
}

int opcaoMenuRelatorios()
{
    int opcao;
    printf("****************************************\n");
    printf("**      MENU DE RELATÓRIOS GERAIS     **\n");
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

void loopMenuRelatorios(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores)
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
            //cadastroPessoa();
            break;

        case 2:
            //listarPessoas();
            break;

        case 3:
            //atualizacaoPessoa();
            break;

        case 4:
            //exclusaoPessoa();
            break;

        default:
            printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
        }
    }
}

int opcaoMenuPrincipal()
{
    int opcao;
    printf("****************************************\n");
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

void loopMenuPrincipal(Pessoa * listaAlunos, int TAM_MAX_ALUNOS, int * totalAlunos, Pessoa * listaProfessores, int TAM_MAX_PROFESSORES, int * totalProfessores)
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
            loopMenuDisciplinas(listaAlunos, TAM_MAX_ALUNOS, totalAlunos, listaProfessores, TAM_MAX_PROFESSORES, totalProfessores);
            break;

        case 4:
            loopMenuRelatorios(listaAlunos, TAM_MAX_ALUNOS, totalAlunos, listaProfessores, TAM_MAX_PROFESSORES, totalProfessores);
            break;

        default:
            printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA NOVAMENTE!\n");
        }
    }
}