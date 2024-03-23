//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

//HEADERS
#include "validacoes.h"

//DEFINE
#define FALHA_NA_SOLICITACAO -400
#define ENCERRAR_INT 0
#define ENCERRAR_STR "0"
#define ENCERRAR_CHR '0'
#define MAX_TAM_STR 50
#define MAX_TAM_CPF 15
#define MAX_TAM_DSC 7
#define MAX_TAM_CHR 0

int validarMatricula(Pessoa * listaPessoas, int * totalPessoas) //FINALIZADO
{
  srand(time(NULL));
  int matricula = (rand() % 9999) + 1;

  for(int i = 0; i < *totalPessoas; i++) //Confere se a matrícula já existe
  {
    if (matricula == listaPessoas[i].matricula) matricula = validarMatricula(listaPessoas, totalPessoas);
  }
    return matricula;
}

void validarNome(char nome[]) //FINALIZADO
{
	bool valido = true, contemApenasEspacos = true;

	fgets(nome, MAX_TAM_STR, stdin);
	nome[strcspn(nome, "\n")] = '\0';

	for (int i = 0; nome[i] != '\0'; i++)
	{
		if (nome[i] != ' ')
		{
			contemApenasEspacos = false;
			break;
		}
	}

	if (nome[0] == '\0' || contemApenasEspacos)
	{
		printf("O NOME DIGITADO ESTÁ VAZIO!!!!! DIGITE NOVAMENTE: ");
		validarNome(nome);
	}
	else for (int i = 0; nome[i] != '\0'; i++) 
	{
		if (strcmp(nome, ENCERRAR_STR) == 0) break;
		else if (!isalpha(nome[i]) && nome[i] != ' ') 
		{
			valido = false;
			break;
		}
	}
	if (!valido)
	{
		printf("O NOME DIGITADO CONTÉM CARACTERES QUE NÃO SÃO LETRAS!!!!! DIGITE NOVAMENTE: ");
		validarNome(nome);
	}
}

char validarSexo() //FINALIZADO
{
	char sexo;
	sexo = getchar();
	while ((getchar()) != '\n');
	
	if (sexo == 'm') sexo = 'M';
	else if (sexo == 'f') sexo = 'F';

	if (sexo != 'M' && sexo != 'F')
	{
		printf("CARACTERE INVÁLIDO. DIGITE NOVAMENTE: ");
		validarSexo(sexo);
	}
	
    return sexo;
}

Data validarAniversario() //FINALIZADO
{
	Data dataAniversario;
  	int diaAniversario, mesAniversario, anoAniversario;
	
	do
	{
		printf("DIA DA DATA DE NASCIMENTO (FORMATO DD): ");
		scanf("%d", &diaAniversario);
	
	    printf("MÊS DA DATA DE NASCIMENTO (FORMATO MM): ");
		scanf("%d", &mesAniversario);
	
	    printf("ANO DA DATA DE NASCIMENTO (FORMATO AAAA): ");
		scanf("%d", &anoAniversario);
	} while(!validarData(diaAniversario, mesAniversario, anoAniversario));
	
	dataAniversario.dia = diaAniversario;
	dataAniversario.mes = mesAniversario;
	dataAniversario.ano = anoAniversario;
		  
	return dataAniversario;
}

void validarCPF(char cpf[]) //FINALIZADO
{
	fgets(cpf, MAX_TAM_STR, stdin);
	cpf[strcspn(cpf, "\n")] = '\0';

	int cpf_int[11];
	int aux = 0;

	for (int i = 0; i < strlen(cpf); i++)
	{
		if (cpf[i] >= 48 && cpf[i] <= 57)
		{
			cpf_int[aux] = cpf[i] - '0';
			aux ++;
		}
	}

	if (strcmp(cpf, ENCERRAR_STR) == 0) return;
	else if (aux != 11)
	{
		printf("O CPF ESTÁ INCORRETO!!! DIGITE NOVAMENTE: ");
		validarCPF(cpf);
	}
	else
	{
		//Descobre o primeiro dígito verificador
		int primeiraSoma = 0;
		for (int i = 0; i < aux - 2; i++)
		{
			primeiraSoma += cpf_int[i] * (i + 1);
		}
		int primeiroDigitoVerificador = primeiraSoma % 11;
		if (primeiroDigitoVerificador == 10) primeiroDigitoVerificador = 0;

		//Descobre o segundo dígito verificador
		int segundaSoma = 0;
		for (int i = 0; i < aux - 2; i++)
		{
			segundaSoma += cpf_int[i] * i;
		}
		segundaSoma += primeiroDigitoVerificador * (aux - 2);
		int segundoDigitoVerificador = segundaSoma % 11;
		if (segundoDigitoVerificador == 10) segundoDigitoVerificador = 0;

		if (!(primeiroDigitoVerificador == cpf_int[aux - 2] && segundoDigitoVerificador == cpf_int[aux - 1]))
		{
			printf("O CPF ESTÁ INCORRETO!!! DIGITE NOVAMENTE: ");
			validarCPF(cpf);
		}
	}
}

void validarCodigoDisciplina(char codigo[]) //FINALIZADO
{
	fgets(codigo, MAX_TAM_DSC, stdin);
	codigo[strcspn(codigo, "\n")] = '\0';

	if (codigo[0] == '\0')
		{
			printf("O NOME DIGITADO ESTÁ VAZIO!!!!! DIGITE NOVAMENTE: ");
			validarCodigoDisciplina(codigo);
		}
	else for (int i = 0; codigo[i] != '\0'; i++) 
	{
		if (strcmp(codigo, ENCERRAR_STR) == 0) break;
		if (!isalnum(codigo[i])) 
		{
			printf("O CÓDIGO DIGITADO CONTÉM CARACTERES QUE NÃO SÃO ALFANÚMERICOS!!!!! DIGITE NOVAMENTE: ");
			validarCodigoDisciplina(codigo); 
			break;
		}
	}
}

//FUNÇÕES AUXILIARES
bool bissexto(int ano)
{
	return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}

bool validarData(int dia, int mes, int ano)
{
	if (dia == 0 || mes == 0 || ano == 0) return true;
	if (mes < 1 || mes > 12 || dia < 1 || dia > 31) return false;
	if (dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) return false;
	if (dia > 29 && mes == 2 && bissexto(ano)) return false;
	if (dia > 28 && mes == 2 && !bissexto(ano)) return false;
	return true;
}

int buscarPessoa(bool * achou, Pessoa * listaPessoas, int * totalPessoas)
{
	int matriculaProcurada, posicaoCerta = 0;
	
	scanf("%d", &matriculaProcurada);

	if (matriculaProcurada == ENCERRAR_INT) return FALHA_NA_SOLICITACAO;

	while (posicaoCerta < *totalPessoas)
	{
		if (matriculaProcurada == listaPessoas[posicaoCerta].matricula)
		{
			*achou = true;
			break;
		}
		posicaoCerta++;
	}

	return posicaoCerta;
}

int buscarDisciplina(bool * achou, Disciplina * listaDisciplinas, int * totalDisciplinas)
{
	int posicaoCerta = 0;
	char codigoProcurado[MAX_TAM_DSC];

	fgets(codigoProcurado, MAX_TAM_DSC, stdin);
	codigoProcurado[strcspn(codigoProcurado, "\n")] = '\0';

	if (!strcmp(codigoProcurado, ENCERRAR_STR)) return FALHA_NA_SOLICITACAO;

	while (posicaoCerta < *totalDisciplinas)
	{
		if (!(strcmp(codigoProcurado, listaDisciplinas[posicaoCerta].codigo)))
		{
			*achou = true;
			break;
		}
		posicaoCerta++;
	}

	return posicaoCerta;
}