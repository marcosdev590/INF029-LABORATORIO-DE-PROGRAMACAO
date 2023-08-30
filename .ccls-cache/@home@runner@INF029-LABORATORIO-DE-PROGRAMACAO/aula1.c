#include <stdio.h>
#define TAM 10

void aula1() 
{
  int age[TAM];
  int age_sum = 0;
  int age_average;
  
  for (int i = 0; i < 10; i++) 
  {
    printf("Escreva a %d° idade\n", i+1);
    scanf("%d", &age[i]);
    age_sum += age[i];
  }
  age_average = age_sum / TAM;
  printf("A soma foi %d e a media foi %d\n", age_sum, age_average);
  for (int i = 0; i < 10; i++) 
  {
    if (age[i] > age_average) printf("%d eh maior que a media\n", age[i]);
  }
}


