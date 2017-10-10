#include <stdio.h>

void main(){
	int n;
	printf("Escreva um numero de 1 a 9\n");
	scanf("%d", &n);
	if (n >=1 && n <=9)	{
		for (int i = 1; i <= 10; ++i)
		{
			printf("%d x %d = %d\n", n, i, n*i);
		}
	}
}