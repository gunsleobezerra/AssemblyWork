#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define L 3
#define rate 10

void print_matrix2D(int matrix[][L],int sizeX,int sizeY);//A function to print one MATRIX 2D
void random_squadmatrix(int matrix[][L],int sizeX,int sizeY);// initialize a matrix with random numbers
void sum_matrix2D(int matrixA[][L],int matrixB[][L],int matrixresult[][L],int size); 
void mult_matrix2D(int matrixA[][L],int matrixB[][L],int matrixresult[][L],int size);
void convert_matrix2D(int **matrix,int matrixA[][L]);//converter a pointer matrix to matrix(array);
void return_primary(int matrix[][L],int size);

int main(){
    srand(time(NULL));
    int A[L][L], B[L][L], C[L][L], matrixresult[L][L];
    
    //randomize matrix
    //printf("Matrix A\n");
    random_squadmatrix(A,L,L);
    //print_matrix2D(A,L,L);

    //printf("Matrix B\n");
    random_squadmatrix(B,L,L);
    //print_matrix2D(B,L,L);

    //printf("Matrix C\n");
    random_squadmatrix(C,L,L);
    //print_matrix2D(C,L,L);

    mult_matrix2D(A,C,matrixresult,L);
    //print_matrix2D(matrixresult,L,L);
    sum_matrix2D(matrixresult,B,matrixresult,L);

    printf("(A X C + B) = \n");

    print_matrix2D(matrixresult,L,L);
    printf("primary diagonal\n");
    return_primary(matrixresult,L);

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

void sum_matrix2D(int matrixA[][L],int matrixB[][L],int matrixresult[][L],int size){

     int i=0,j=0;

    

    for(i=0;i<size;i++){

        for(j=0;j<size;j++){


            matrixresult[i][j] = matrixA[i][j] + matrixB[i][j];
            
           
        }
    }
}

void mult_matrix2D(int matrixA[][L],int matrixB[][L],int matrixresult[][L],int size){
    int i=0,j=0,k=0,sum=0;

     for(i=0;i<size;i++){         
        for (;k<size;k++){
                  
            for(j=0;j<size;j++){


                sum += matrixA[i][j] * matrixB[j][k];
                
            
            }
            matrixresult[i][k] =sum;
            sum=0; 
        }
        k=0;
    }

}

void convert_matrix2D(int **matrix,int matrixA[][L]){
    int i=0,j=0,size=L;
    for(i=0;i<size;i++){

        for(j=0;j<size;j++){


             
            
           
        }
    }

}

void return_primary(int matrix[][L],int size){

    int i=0;

    for(;i<size;i++) printf(" %d ",matrix[i][i]);
}