#include <stdio.h>

#define TAM 10

void main()
{
  int v[TAM];
  int i;
  printf("Escreva 10 numeros:\n");

  for(i = 0; i < TAM; i++) {
  	scanf("%d", &v[i]);
  }

  int s = 0;
  for (i = 0; i < TAM; i++) {
    s = s + v[i];	
  }

  float m;
  m = s / TAM;
  printf("Os numeros maiores que a media sao:\n");
  for (i = 0; i < TAM; i++) {
  	if (v[i] > m) {
  		printf("%d\n", v[i]);
  	}
  }
  
}