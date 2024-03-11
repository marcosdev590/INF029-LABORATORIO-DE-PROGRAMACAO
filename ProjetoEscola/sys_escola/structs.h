#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct DDMMAAAA
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct dadosAlunoProfessor
{
    int matricula;
    char nome[50];
    char sexo;
    Data dataNascimento;
    char cpf[15];
} Pessoa;

typedef struct dadosDisciplina
{
    char nome[50];
    char codigo[6];
    char semestre[6];
    Pessoa professor;
} Disciplina;


#endif // STRUCTS_H