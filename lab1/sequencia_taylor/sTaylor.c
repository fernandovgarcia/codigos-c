#include <stdio.h>
#include <math.h>

int fatorial(int x){
	if (x<=1){
		return 1;
	}else{
		x=x*fatorial(x-1);
		return x;
	}
}

double seno(double x)
{
  int i = 0;
  int expden = 1;
  double resultado = 0;
  double sen = x; 
  double aux;

  while(i >= 0) {
    expden += 2;
    aux = pow(x, expden)/fatorial(expden);
    if (aux < pow(10,-6)) {
      break;  
    } else if (i % 2 == 0) {
	  sen -= aux;
	} else {
	  sen += aux;
    }
    i++;
  }

  return sen;
}

double cosseno(double x)
{
  int i = 0;
  int expden = 0;
  double resultado = 0;
  double cos = 1; 
  double aux;
  while(i >= 0) {
  	expden += 2;
    aux = pow(x, expden)/fatorial(expden);
    if (aux < pow(10,-6)) {
      break;  
    } else if (i % 2 == 0) {
	  cos -= aux;
	} else {
	  cos += aux;
    }
    i++;
  }
  return cos;
}

double tangente(double seno, double cosseno)
{
  double tg;
  tg = seno/cosseno;
  return tg;
}

void main(){  
  int i = 0;
  double xg = 0;
  double xrad;

  for (i = 1; i <= 90; i++) {
    xrad = (xg * M_PI)/180;
    if (xg < 10){
      printf("%.0lf  %lf   ", xg, tangente(seno(xrad), cosseno(xrad)));    	
    } else {
      printf("%.0lf %lf   ", xg, tangente(seno(xrad), cosseno(xrad)));
    }
    
    if (i % 3 == 0){
      xg = xg - 59;
      printf("\n");
    } else {
      xg = xg + 30;
    }
  }
}