#include <stdio.h>
#include <math.h>

void main( )
{
  //Declaração de variáveis
  float nota1, nota2, nota3, exame;
  float media; 
  
  //Entrada de dados
  printf("Digite a primeira nota\n");
  scanf("%f", &nota1);
  printf("Digite a segunda nota\n");
  scanf("%f", &nota2);
  printf("Digite a terceira nota\n");
  scanf("%f", &nota3);

  //Calcula a média
  media = (nota1 + nota2 + (nota3 * 2))/4;
  printf("A media e' %f\n", media);

  //Verifica se a média é menor que 7
  if (media < 7){
    printf("Digite a quarta nota\n");
    scanf("%f", &exame);
    //Calcula a média do exame
    media = (media + exame) / 2;

    if (media >= 7){
      printf("Media com exame: %f\n Situacao: Aprovado\n", media);
    }else{
      printf("Media com exame: %f\n Situacao: Reprovado\n", media);
    }    
  }else{
    printf("Situacao: Aprovado\n");
  }
}