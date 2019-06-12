#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINE 250
#define COLUMN 250


void fill(int mat[LINE][COLUMN]){
    int i,j;

    for(i = 0 ; i < LINE ; i++){
        for(j = 0 ; j < COLUMN ; j++){
            mat[i][j] = rand()%10;
            printf(" %d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void sum(int mat[LINE][COLUMN],int matB[LINE][COLUMN]){
    int matResult[LINE][COLUMN];
    int i,j;
     printf("MATRIX (AxC) + B\n\n");
     for(i = 0 ; i < LINE ; i++){
        for(j = 0 ; j < COLUMN ; j++){
            matResult[i][j] = mat[i][j] + matB[i][j];
            printf(" %d ",matResult[i][j]);
        }
         printf("\n");
    }    
}   

void mul(int matA[LINE][COLUMN],int matC[LINE][COLUMN],int matB[LINE][COLUMN]){
    int matResult[LINE][COLUMN];
    int i,j,k;

    for(i = 0 ; i < LINE ; i++){
        for(j = 0 ; j < COLUMN ; j++){
           for(k = 0; k < COLUMN; k++)
        		matResult[i][j] += matA[i][k]*matC[k][j];
            printf(" %d ",matResult[i][j]);                   
        }
          printf("\n");
    }
    printf("\n\n");
    sum(matResult,matB);
}

int main(void){
    clock_t Ticks[2];
    double Tempo;
    Ticks[0]= clock();
    //start couting
    int matA[LINE][COLUMN];
    int matB[LINE][COLUMN];
    int matC[LINE][COLUMN];

    printf("MATRIX A\n\n");
    fill(matA);
    printf("MATRIX B\n\n");
    fill(matB);
    printf("MATRIX C\n\n");
    fill(matC);

    printf("MATRIX AxC\n\n");
    mul(matA,matC,matB);
    

   


}
