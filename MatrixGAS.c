#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define L 15
#define rate 10

void print_matrix2D(int matrix[][L],int sizeX,int sizeY);//A function to print one MATRIX 2D
void random_squadmatrix(int matrix[][L],int sizeX,int sizeY);// initialize a matrix with random numbers
void sum_matrix2D(int matrixA[][L],int matrixB[][L],int matrixresult[][L],int size); 
void mult_matrix2D(int matrixA[][L],int matrixB[][L],int matrixresult[][L],int size);
void return_primary(int matrix[][L],int size);

int main(){
    clock_t Ticks[2];
    double Tempo;
    
    //srand(time(NULL));
    int A[L][L], B[L][L], C[L][L], matrixresult[L][L];
    int result;

    //randomize matrix
    printf("Matrix A\n");
    random_squadmatrix(A,L,L);
    print_matrix2D(A,L,L);

    printf("Matrix B\n");
    random_squadmatrix(B,L,L);
    print_matrix2D(B,L,L);

    printf("Matrix C\n");
    random_squadmatrix(C,L,L);
    print_matrix2D(C,L,L);
    Ticks[0]= clock();
   //asm

    extern int exibirgas(int A[][L],int B[][L],int C[][L],int res[][L],int sizes);
    result = exibirgas(A,B,C,matrixresult,L);

   //end asm
   
    
    
    printf("(A X C + B) = \n");

    print_matrix2D(matrixresult,L,L);
    printf("primary diagonal : %d \n",result);
    
    Ticks[1]= clock();
    //TIME
    Tempo = ((((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC)/1.964158)/10);
    printf("\n\nEXECUTION - %.10g ms",Tempo);

    printf("\n");
   

}


void print_matrix2D(int matrix[][L],int sizeX,int sizeY){
    
    int i=0,j=0;

    for(i=0;i<sizeY;i++){

        for(j=0;j<sizeY;j++){

            

            printf(" %1d ",matrix[i][j]);

        }

        printf("\n");
    }
    printf("\n");
}

void random_squadmatrix(int matrix[][L],int sizeX,int sizeY){


    int i=0,j=0;

    for(i=0;i<sizeY;i++){

        for(j=0;j<sizeY;j++){

            matrix[i][j] = rand()%rate;
           
        }
    }

}

