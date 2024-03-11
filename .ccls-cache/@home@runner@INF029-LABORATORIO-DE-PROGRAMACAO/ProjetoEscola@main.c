// https://github.com/renatoln/INF029/tree/master/AtividadesExtras
// https://www.youtube.com/playlist?list=PLtHqLyFn7jQsgVexAkyeGpSeoy5IhzLX7
// https://docs.google.com/document/d/1yYW3NnylPDPcjifmB319Kga92LBbo9Pr0Taq1l0GoiM/edit
// https://ads.ifba.edu.br/INF029

#include <stdio.h>
#define TAM_ALUNO 3
#define FALSO 0

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
              printf("Opcao invalida")
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