//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//HEADERS
#include "validacoes.h"

//DEFINE
#define ENCERRAR_INT 0
#define ENCERRAR_STR "0"
#define ENCERRAR_CHR '0'
#define MAX_TAM_STR 50
#define MAX_TAM_CPF 15
#define MAX_TAM_CHR 0

int validarMatricula(Pessoa * listaPessoas, int * totalPessoas) //PROBLEMÁTICO
{
	int matricula;

	int isNumber = scanf("%d", &matricula);
	printf("isNumber é %d e matrícula é %d\n", isNumber, matricula);

	if (matricula == ENCERRAR_INT) //Confere se o usuário digitou 0 para sair do cadastro
	{
		return ENCERRAR_INT;
	}
	else if (matricula < 0) //Confere se a matrícula é menor do que 0
	{
		printf("MATRÍCULA MENOR DO QUE ZERO!!!!! DIGITE NOVAMENTE: ");
		matricula = validarMatricula(listaPessoas, totalPessoas);
	}
	else 
	{
		for (int i = 0; i < *totalPessoas; i++) //Confere se a matrícula já existe
		{
			if (matricula == listaPessoas[i].matricula)
			{
				printf("MATRÍCULA JÁ CADASTRADA!!!!! DIGITE NOVAMENTE: ");
				matricula = validarMatricula(listaPessoas, totalPessoas);
			}
		} 
	}
	
    return matricula;
}

void validarNome(char nome[])
{
	while ((getchar()) != '\n');
	fgets(nome, MAX_TAM_STR, stdin);
	nome[strcspn(nome, "\n")] = '\0';
}

char validarSexo(char sexo)
{
	sexo = getchar();
	while ((getchar()) != '\n');
	
	if (sexo == 'm') sexo = 'M';
	else if (sexo == 'f') sexo = 'F';

	if (sexo != 'M' && sexo != 'F')
	{
		printf("CARACTERE INVÁLIDO. DIGITE NOVAMENTE: ");
		sexo = validarSexo(sexo);
	}
	
    return sexo;
}

Data validarAniversario(Data dataAniversario)
{
    int diaAniversario, mesAniversario, anoAniversario;
	
	printf("DIA DA DATA DE NASCIMENTO (FORMATO DD): ");
	scanf("%d", &diaAniversario);

	printf("MÊS DA DATA DE NASCIMENTO (FORMATO MM): ");
	scanf("%d", &mesAniversario);

	printf("ANO DA DATA DE NASCIMENTO (FORMATO AAAA): ");
	scanf("%d", &anoAniversario);

    // Lógica de validação da data aqui
    // Por exemplo, verificação se o dia, mês e ano são válidos

    // Atribui os valores à variável Data se a validação for bem-sucedida
    dataAniversario.dia = diaAniversario;
    dataAniversario.mes = mesAniversario;
    dataAniversario.ano = anoAniversario;

    return dataAniversario;
}

void validarCPF(char cpf[])
{
	while ((getchar()) != '\n');
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

	if (aux != 11)
	{
		printf("O CPF ESTÁ INCORRETO!!! DIGITE NOVAMENTE: ");
		//ALGUMA FORMA 
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

		if (primeiroDigitoVerificador == cpf_int[aux - 2] && segundoDigitoVerificador == cpf_int[aux - 1])
		{
			printf("O CPF ESTÁ CORRETO");
		}
		else
		{
			printf("O CPF ESTÁ INCORRETO");
		}
	}
}