//HEADERS
#include "structs.h"
#include "validacoes.h"

// CREATE

int cadastroPessoa(Pessoa * listaPessoas, int limitePessoas, int * totalPessoas); //Cadastra um aluno ou professor, recebendo sua matrícula, nome, sexo, data de nascimento e CPF. Chama uma função para validar os dados antes de gravar no array correspondente.

int cadastroDisciplina(); // Cadastra uma disciplina, recebendo seu nome, código, semestre e professor responsável

// READ
void listarPessoas(Pessoa * listaPessoas, int * totalPessoas); // Lista o array de alunos ou professores, informando todos os dados das pessoas por linhas, separando os atributos com um |

void listarDisciplinas(); //Lista o array de disciplinas, informando todos os dados por linhas, separando os atributos com um |

int listarDisciplina(); //Lista uma disciplina e seus dados, incluindo os alunos matriculados

// UPDATE

int atualizacaoPessoa(Pessoa * listaPessoas, int * totalPessoas); //Atualiza um aluno ou professor, recebendo sua matrícula, nome, sexo, data de nascimento e CPF. Chama uma função para validar os dados antes de gravar no array correspondente.

int atualizacaoDisciplina(); // Atualiza uma disciplina, recebendo seu nome, código, semestre e professor responsável

// DELETE

int exclusaoPessoa(Pessoa * listaPessoas, int * totalPessoas); //Exclui o cadastro de um aluno ou professor, recebendo sua matrícula e reorganizando o array correspondente após apagar os dados

int exclusaoDisciplina(); // Exclui uma disciplina, recebendo seu código e reorganizando o array correspondente após apagar os dados

//RELATÓRIOS

int listarPessoasPorSexo(); //Lista todos os alunos ou professores em ordem de matrícula separando por sexo

int listarPessoasPorNome(); // Lista todos os alunos ou professores em ordem alfabética por nome

int listarPessoasPorAniversario(); // Lista todos os alunos ou professores por data de nascimento

int listarAniversariantesDoMes(); //  Lista todos os alunos e professores cujo mês da data de nascimento é igual ao do mês de execução do código

int buscarPessoas(); //Lista todas as pessoas a partir de uma string de busca de no mínimo três letras

int listarAlunosSubmatriculados(); //Lista todos os alunos matriculados em menos de três disciplinas

int listarDisciplinasSuperpopuladas(); //Lista todas as disciplinas com mais de 40 alunos, incluindo o nome do professor responsável