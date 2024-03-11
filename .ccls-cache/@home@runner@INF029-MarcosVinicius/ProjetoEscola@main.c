

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define TAM_ALUNO 3

typedef struct {
  int matricula;
  char nome[50];
  char sexo;
} Aluno;

void main(){

  int listaAluno[TAM_ALUNO];
  int opcao;
  int sair = FALSO;
  
  while (!sair){
    printf("Bem vindo a Escola Exemplar\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");

    scanf("%d", &opcao);

    switch (opcao){
      case 0:{
        sair = 1;
        break;
      }
      case 1:{
        printf("Modulo do Aluno\n");
        int sairAluno = FALSO;
        int opcaoAluno;
        while (!sairAluno){
          printf("0 - Voltar\n");
          printf("1 - Cadastrar aluno\n");
          printf("2 - Listar alunos\n");
          printf("3 - Atualizar aluno\n");
          printf("4 - Excluir aluno\n");
          scanf("%d", &opcaoAluno);
          switch (opcaoAluno){
            case 0:{
              sairAluno = 1;
              break;
            }
            case 1:{
              printf("1 - Cadastrar aluno\n");
              break;
            }
            case 2:{
              printf("2 - Listar alunos\n");
              break;
            }
            case 3:{
              printf("3 - Atualizar aluno\n");
              break;
            }
            case 4:{
              printf("4 - Excluir aluno\n");
              break;
            }
            default:{
              printf("Opcao invalida");
            }
          }
        break;
      }
      case 2:{
        printf("Modulo do Professor\n");
        break;
      }
      case 3:{
        printf("Modulo de Disciplinas\n");
        break;
      }
      default:{
        printf("Opcao invalida\n");
      }
    }
  }
}
}