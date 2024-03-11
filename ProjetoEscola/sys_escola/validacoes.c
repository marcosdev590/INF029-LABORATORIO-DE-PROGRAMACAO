//BIBLIOTECAS
#include <stdlib.h>
#include <string.h>

//HEADERS
#include "validacoes.h"

int validarMatricula(int matricula)
{
    return matricula;
}

char * validarNome(char nome[])
{
    return nome;
}

char validarSexo(char sexo)
{
    return sexo;
}

Data validarAniversario(int diaAniversario, int mesAniversario, int anoAniversario)
{
    Data dataAniversario;

    // Lógica de validação da data aqui
    // Por exemplo, verificação se o dia, mês e ano são válidos

    // Atribui os valores à variável Data se a validação for bem-sucedida
    dataAniversario.dia = diaAniversario;
    dataAniversario.mes = mesAniversario;
    dataAniversario.ano = anoAniversario;

    return dataAniversario;
}

char * validarCPF(char cpf[])
{
    return cpf;
}