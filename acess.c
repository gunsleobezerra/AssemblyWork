#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINE 2
#define COLUMN 2

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
void impress(int mat[LINE][COLUMN]){
    int i,j;

    for(i = 0 ; i < LINE ; i++){
        for(j = 0 ; j < COLUMN ; j++){
            printf(" %d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
int main(){
    //srand(time(NULL));
    int matA[LINE][COLUMN];
    int matB[LINE][COLUMN];
    int matC[LINE][COLUMN];
    int matRes[LINE][COLUMN] = {0};
    int acesso=0;
    printf("MATRIX A\n\n");
    fill(matA);
    
    extern int exibir(int(*)[LINE],int(*)[LINE],int(*)[LINE],int(*)[LINE],int);
    acesso = exibir(matA,matB,matC,matRes,LINE);
    printf(" ----- %d -----\n",acesso);
   

}
