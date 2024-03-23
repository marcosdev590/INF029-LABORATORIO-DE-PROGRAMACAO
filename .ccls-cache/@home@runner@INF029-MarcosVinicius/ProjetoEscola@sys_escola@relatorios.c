//BIBLIOTECAS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//HEADERS
#include "validacoes.h"
#include "relatorios.h"

//DEFINE
#define FALHA_NA_SOLICITACAO -400
#define SUCESSO_NA_SOLICITACAO -200

// RELATÓRIOS

int listarPessoasPorSexo(Pessoa * listaPessoas, int * totalPessoas)
{
  //Lista todos os alunos ou professores em ordem de matrícula separando por sexo
  printf("\n****************************************\n");
  printf("**    RELATÓRIOS - LISTAR POR SEXO    **\n");
  printf("****************************************\n\n");
  printf("------------------------------------------------------------------------------------\n\n");

  if (totalPessoas == 0)
  {
    printf("NÃO HÁ PESSOAS CADASTRADAS.\n");
    printf("------------------------------------------------------------------------------------\n\n");
  }
  else
  {
    for (int i = 0; i < *totalPessoas; i++) 
    {
      if (listaPessoas[i].sexo == 'F')
      {
        printf("--- DO SEXO FEMININO ---\n");
        printf("MATRÍCULA: %d | NOME: %s | DATA DE NASCIMENTO: %02d/%02d/%04d | CPF: %s\n", listaPessoas[i].matricula, listaPessoas[i].nome, listaPessoas[i].dataNascimento.dia, listaPessoas[i].dataNascimento.mes, listaPessoas[i].dataNascimento.ano, listaPessoas[i].cpf);
    printf("------------------------------------------------------------------------------------\n");
      }
    }
    for (int i = 0; i < * totalPessoas; i++) 
    {
      if (listaPessoas[i].sexo == 'M')
      {
    printf("--- DO SEXO MASCULINO ---\n");
    printf("MATRÍCULA: %d | NOME: %s | DATA DE NASCIMENTO: %02d/%02d/%04d | CPF: %s\n", listaPessoas[i].matricula, listaPessoas[i].nome, listaPessoas[i].dataNascimento.dia, listaPessoas[i].dataNascimento.mes, listaPessoas[i].dataNascimento.ano, listaPessoas[i].cpf);
      printf("------------------------------------------------------------------------------------\n\n");
      }
    }
  }
  return SUCESSO_NA_SOLICITACAO;
}

int listarPessoasPorNome(Pessoa * listaPessoas, int * totalPessoas)
{
  // Lista todos os alunos ou professores em ordem alfabética por nome
  Pessoa copia[*totalPessoas];
  Pessoa auxiliar;
  int i, j, minimo;

  for(int k = 0; k < *totalPessoas; k++) copia[k] = listaPessoas[k];

  for(i = 0; i < (*totalPessoas - 1); i++)
  {
    minimo = i;
    for(j = (i + 1); j < *totalPessoas; j++)
    {
      if(strcmp(copia[j].nome, copia[minimo].nome) > 0) minimo = j;
    }
    if(i != minimo)
    {
      auxiliar = copia[i];
      copia[i] = copia[minimo];
      copia[minimo] = auxiliar;
    }
  }

  printf("*********************************************\n");
  printf("** LISTAGEM DE PESSOAS EM ORDEM ALFABETICA **\n");
  printf("*********************************************\n\n");
  printf("------------------------------------------------------------------------------------\n");

  if (totalPessoas == 0)
  {
    printf("NÃO HÁ PESSOAS CADASTRADAS.\n");
    printf("------------------------------------------------------------------------------------\n\n");
  }
  else
  {
    for (i = 0; i < *totalPessoas; i++) 
    {
      printf("MATRÍCULA: %d | NOME: %s | SEXO: %c | DATA DE NASCIMENTO: %02d/%02d/%04d | CPF: %s\n", copia[i].matricula, copia[i].nome, copia[i].sexo, copia[i].dataNascimento.dia, copia[i].dataNascimento.mes, copia[i].dataNascimento.ano, copia[i].cpf);
      printf("------------------------------------------------------------------------------------\n\n");
    }
  }

  return 0;
}

int listarPessoasPorAniversario(Pessoa * listaPessoas, int * totalPessoas)
{
  // Lista todos os alunos ou professores por data de nascimento
  Pessoa copia[*totalPessoas];
  Pessoa auxiliar;
  int i, j, minimo;

  for(int k = 0; k < *totalPessoas; k++) copia[k] = listaPessoas[k];

  for(i = 0; i < (*totalPessoas - 1); i++)
  {
    minimo = i;
    for(j = (i + 1); j < *totalPessoas; j++)
    {
      if(copia[j].dataNascimento.ano < copia[minimo].dataNascimento.ano || (copia[j].dataNascimento.ano == copia[minimo].dataNascimento.ano && copia[j].dataNascimento.mes < copia[minimo].dataNascimento.mes) || (copia[j].dataNascimento.ano == copia[minimo].dataNascimento.ano && copia[j].dataNascimento.mes == copia[minimo].dataNascimento.mes && copia[j].dataNascimento.dia < copia[minimo].dataNascimento.dia)) minimo = j;
    }
    if(i != minimo)
    {
      auxiliar = copia[i];
      copia[i] = copia[minimo];
      copia[minimo] = auxiliar;
    }
  }

  printf("****************************************\n");
  printf("**     LISTAGEM DE PESSOAS POR DATA   **\n");
  printf("****************************************\n\n");
  printf("------------------------------------------------------------------------------------\n");

  if (totalPessoas == 0)
  {
    printf("NÃO HÁ PESSOAS CADASTRADAS.\n");
    printf("------------------------------------------------------------------------------------\n\n");
  }
  else
  {
    for (int i = 0; i < *totalPessoas; i++) 
    {
      printf("MATRÍCULA: %d | NOME: %s | SEXO: %c | DATA DE NASCIMENTO: %02d/%02d/%04d | CPF: %s\n", copia[i].matricula, copia[i].nome, copia[i].sexo, copia[i].dataNascimento.dia, copia[i].dataNascimento.mes, copia[i].dataNascimento.ano, copia[i].cpf);
      printf("------------------------------------------------------------------------------------\n\n");
    }
  }

  return 0;
}

int listarAniversariantesDoMes(Pessoa * listaAlunos, Pessoa * listaProfessores, int * totalAlunos, int * totalProfessores)
{//  Lista todos os alunos e professores cujo mês da data de nascimento é igual ao do mês de execução do código
  int totalPessoas = *totalAlunos + *totalProfessores;
  Pessoa listaPessoas[totalPessoas];
  memcpy(listaPessoas, listaAlunos, *totalAlunos * sizeof(Pessoa));
  memcpy(listaPessoas +(sizeof(*listaAlunos)/sizeof(Pessoa)), listaProfessores, *totalProfessores * sizeof(Pessoa));
  int mes;
  
  printf("\n****************************************\n");
  printf("**       ANIVERSARIANTES DO MES       **\n");
  printf("****************************************\n\n");
  printf("Deseja Listar Aniversariantes de qual mês? (1-12): ");
  scanf("%d", &mes);
  
  printf("------------------------------------------------------------------------------------\n\n");
  
  for(int i = 0; i < totalPessoas; i++)
  {
    if(listaPessoas[i].dataNascimento.mes == mes) printf("NOME: %s | DATA NASCIMENTO: %02d/%02d/%04d\n", listaPessoas[i].nome, listaPessoas[i].dataNascimento.dia, listaPessoas[i].dataNascimento.mes, listaPessoas[i].dataNascimento.ano);
  }
  
	return 0;
}

int buscarPessoas(Pessoa * listaPessoas, int totalPessoas)
{ //Lista todas as pessoas a partir de uma string de busca de no mínimo três letras
  char busca[50];
  int found = 0;
  int slen[totalPessoas];
  int len_busca;

  printf("\n****************************************\n");
  printf("**           BUSCAR PESSOAS           **\n");
  printf("****************************************\n\n");
  printf("Digite pelo menos 3 letras consecutivas para busca: ");
  
  fgets(busca, 50, stdin);
  len_busca = strlen(busca);
  
  for(int i = 0; i < totalPessoas; i++) slen[i] = strlen(listaPessoas[i].nome);

  for(int i = 0; i < totalPessoas; i++)
  {
    if( slen[i] >= len_busca )
    {
        for(int u = 0; u < totalPessoas; u++)
        {
          for(int s = 0, t = 0; s < slen[i]; s++)
            do{

                if( listaPessoas[u].nome[s] == busca[t] )
                {
                    if( ++found == len_busca ) printf("MATRICULA: %d | NOME: %s", listaPessoas[u].matricula, listaPessoas[u].nome);
                    s++;
                    t++;
                }
                else { s -= found; found=0; t=0; }

              }while(found);
        }
        printf("Termo não encontrado em nenhum dos nomes cadastrados. Tente novamente!");
    }
    else printf("O tamanho do termo buscado é maior que o dos nomes cadastrados. Tente novamente!");
  }
  
	return 0;
}

int listarAlunosSubmatriculados(Pessoa * listaPessoas, int * totalPessoas) 
{
  //Lista todos os alunos matriculados em menos de três disciplinas
  printf("****************************************\n");
  printf("** LISTAGEM DE ALUNOS SUBMATRICULADOS **\n");
  printf("****************************************\n\n");
  printf("------------------------------------------------------------------------------------\n");

  if (*totalPessoas == 0)
  {
    printf("NÃO HÁ PESSOAS CADASTRADAS.\n");
    printf("------------------------------------------------------------------------------------\n\n");
  }
  else
  {
    for (int i = 0; i < *totalPessoas && listaPessoas[i].qtdDisciplinasMatriculadas < 3; i++) 
    {
      printf("MATRÍCULA: %d | NOME: %s | SEXO: %c | DATA DE NASCIMENTO: %02d/%02d/%04d | CPF: %s\n", listaPessoas[i].matricula, listaPessoas[i].nome, listaPessoas[i].sexo, listaPessoas[i].dataNascimento.dia, listaPessoas[i].dataNascimento.mes, listaPessoas[i].dataNascimento.ano, listaPessoas[i].cpf);
      printf("------------------------------------------------------------------------------------\n");
    }
    printf("\n");
  }  
	return 0;
}

int listarDisciplinasSuperpopuladas(Disciplina * listaDisciplinas, int * totalDisciplinas, int limiteAlunosDisciplina) 
{
  //Lista todas as disciplinas com mais de 40 alunos, incluindo o nome do professor responsável
  printf("****************************************\n");
  printf("**   LISTAGEM DE DISCIPLINAS LOTADAS  **\n");
  printf("****************************************\n\n");
  printf("------------------------------------------------------------------------------------\n");

  if (*totalDisciplinas == 0)
  {
    printf("NÃO HÁ DISCIPLINAS CADASTRADAS.\n");
    printf("------------------------------------------------------------------------------------\n\n");
  }
  else
  {
    for(int i = 0; i < *totalDisciplinas && listaDisciplinas[i].qtdAlunosCadastrados > limiteAlunosDisciplina; i++){
      printf("%s - %s | SEMESTRE: %s | PROFESSOR: %s\n", listaDisciplinas[i].codigo, listaDisciplinas[i].nome, "2024.1", listaDisciplinas[i].professor->nome); //IMPLEMENTAÇÃO DA IMPRESSÃO DAS DISCIPLINAS
    printf("------------------------------------------------------------------------------------\n");
  }
  printf("\n");
  }
}