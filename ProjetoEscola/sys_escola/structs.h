#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct DDMMAAAA
{
    int dia, mes, ano;
} Data;

typedef struct dadosAlunoProfessor
{
    int matricula;
    char nome[50];
    char sexo;
    Data dataNascimento;
    char cpf[15];
    int qtdDisciplinasMatriculadas;
} Pessoa;

typedef struct dadosDisciplina
{
    char nome[50];
    char codigo[6];
    char semestre[6];
    Pessoa * professor;
	int qtdAlunosCadastrados;
	Pessoa * alunos[50];
} Disciplina;

typedef struct anoSemestre
{
	int ano;
	int semestre;
} anoSemestre;

#endif // STRUCTS_H