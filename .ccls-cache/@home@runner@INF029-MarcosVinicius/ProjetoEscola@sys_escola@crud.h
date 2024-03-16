//HEADERS
#include "structs.h"
#include "validacoes.h"

 // Cadastra uma disciplina, recebendo seu nome, código, semestre e professor responsável

// READ

 //Lista o array de disciplinas, informando todos os dados por linhas, separando os atributos com um |

 //Lista uma disciplina e seus dados, incluindo os alunos matriculados

// UPDATE

 // Atualiza uma disciplina, recebendo seu nome, código, semestre e professor responsável

// DELETE

 // Exclui uma disciplina, recebendo seu código e reorganizando o array correspondente após apagar os dados

//RELATÓRIOS
int listarDisciplina(Disciplina * listaDisciplinas, int * totalDisciplinas);

int listarPessoasPorSexo(); //Lista todos os alunos ou professores em ordem de matrícula separando por sexo

int listarPessoasPorNome(); // Lista todos os alunos ou professores em ordem alfabética por nome

int listarPessoasPorAniversario(); // Lista todos os alunos ou professores por data de nascimento

int listarAniversariantesDoMes(); //  Lista todos os alunos e professores cujo mês da data de nascimento é igual ao do mês de execução do código

int buscarPessoas(); //Lista todas as pessoas a partir de uma string de busca de no mínimo três letras

int listarAlunosSubmatriculados(); //Lista todos os alunos matriculados em menos de três disciplinas

int listarDisciplinasSuperpopuladas(); //Lista todas as disciplinas com mais de 40 alunos, incluindo o nome do professor responsável