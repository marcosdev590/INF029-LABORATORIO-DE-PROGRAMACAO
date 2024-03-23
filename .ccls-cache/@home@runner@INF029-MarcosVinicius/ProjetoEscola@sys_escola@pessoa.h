//HEADERS
#include "structs.h"
#include "validacoes.h"


#ifndef PESSOA_H
#define PESSOA_H
//PROTÓTIPOS
int cadastroPessoa(Pessoa * listaPessoas, int limitePessoas, int * totalPessoas);
void listarPessoas(Pessoa * listaPessoas, int * totalPessoas);
int atualizacaoPessoa(Pessoa * listaPessoas, int * totalPessoas);
int exclusaoPessoa(Pessoa * listaPessoas, int * totalPessoas);
#endif