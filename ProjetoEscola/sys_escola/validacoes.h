//BIBLIOTECAS
#include <stdbool.h>

//HEADERS
#include "structs.h"

#ifndef VALIDACOES_H
#define VALIDACOES_H
//PROTÓTIPOS DE FUNÇÃO
int validarMatricula(Pessoa * listaPessoas, int * totalPessoas);
void validarNome(char nome[]);
char validarSexo();
Data validarAniversario();
void validarCPF(char cpf[]);
void validarCodigoDisciplina(char codigo[]);
int buscarMatriculaProfessorResponsavel();
bool bissexto(int ano);
bool validarData(int dia, int mes, int ano);
int buscarPessoa(bool * achou, Pessoa * listaPessoas, int * totalPessoas);
int buscarDisciplina(bool * achou, Disciplina * listaDisciplinas, int * totalDisciplinas);
#endif