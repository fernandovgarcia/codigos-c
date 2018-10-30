#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define tam_bucket 1000000
#define max 1000000
#define num_bucket 12

typedef struct bucket{
    int topo;
    int* balde;
}Bucket;


void heapsort(int a[], int n) {
    int i = n / 2, pai, filho, t;
    while(true) {
        if (i > 0) {
            i--;
            t = a[i];
        } else {
            n--;
            if (n == 0) return;
            t = a[n];
            a[n] = a[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
                filho++;
            if (a[filho] > t) {
                a[pai] = a[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        a[pai] = t;
    }
}

void shellSort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i;
            while (j >= gap && value < vet[j - gap]) {
                vet[j] = vet [j - gap];
                j = j - gap;
            }
            vet [j] = value;
        }
    }
}

void insertionSort(int *original, int length) {
    int i, j, atual;
    for (i = 1; i < length; i++) {
        atual = original[i];
        for (j = i - 1; (j >= 0) && (atual < original[j]); j--) {
            original[j + 1] = original[j];
        }
        original[j+1] = atual;
    }
}                                              
          
void bucket_sort(int* vet, int tam) {
    int i, j, k, clas;
    clas = (int) ceill(1 + 3.3 * log10((double) tam));
    Bucket *b[clas];
    for (i = 0; i < clas; i++){
        b[i] = malloc(sizeof(Bucket));
        b[i]->topo = 0;
        b[i]->balde = malloc(sizeof(int) * tam);
    }

    for(i=0;i<tam;i++){                          
        j=(clas)-1;
        while(1){
            if(j<0)
                break;
            if(vet[i]>=j*10){
                b[j]->balde[b[j]->topo]=vet[i];
                (b[j]->topo)++;
                break;
            }
            j--;
        }
    }

    for(i=0;i<clas;i++)                     
        if(b[i]->topo)
            heapsort(b[i]->balde, b[i]->topo);

    i=0;

    for(j=0;j<clas;j++){                   
        for(k=0;k<b[j]->topo;k++){
            vet[i]=b[j]->balde[k];
            i++;
        }
    }

    for (i = 0; i < tam; ++i){
        printf("%d\n", vet[i]);
    }
}

void main(){

    int v[max];
    srand(time(NULL));
    int i;
    for (i = 0; i < max; i++){
        v[i] = rand()%max;
    }

    clock_t Ticks[2];
    Ticks[0] = clock();
    bucket_sort(v, max);


    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.", Tempo);
    return ;
}