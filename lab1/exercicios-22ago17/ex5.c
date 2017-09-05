#include <stdio.h>

void main(){
	int numero1, numero2, numero3;
	float media;

	printf("Informe 3 números inteiros\n");
	scanf("%d", &numero1);
	scanf("%d", &numero2);
	scanf("%d", &numero3);

	media = (numero3 + numero2 + numero1)/3.0;

	printf("A média é %f\n", media);
}
