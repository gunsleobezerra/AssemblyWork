#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define L 3
#define rate 2

void print_matrix2D(int matrix[][L],int sizeX,int sizeY);//A function to print one MATRIX 2D
void random_squadmatrix(int matrix[][L],int sizeX,int sizeY);// initialize a matrix with random numbers
void sum_matrix2D(int matrixA[][L],int matrixB[][L],int size);
int **allocintmatrix2D(int size);

int main(){
    srand(time(NULL));
    int A[L][L], B[L][L], C[L][L];
    
    //randomize matrix
    random_squadmatrix(A,L,L);
    print_matrix2D(A,L,L);
    random_squadmatrix(B,L,L);
    print_matrix2D(B,L,L);
    random_squadmatrix(C,L,L);
    print_matrix2D(C,L,L);




    

}

int **allocintmatrix2D(int size){

    int **matrix;
    int i =0, j=0;

        matrix = (int**)malloc(sizeof(int*)*size);
        
        for(i=0;i<size;i++){
            *(matrix[i])=(int*)malloc(sizeof(int)*size);
            
        }
    
    


}
void print_matrix2D(int matrix[][L],int sizeX,int sizeY){
    
    int i=0,j=0;

    for(i=0;i<sizeY;i++){

        for(j=0;j<sizeY;j++){

            

            printf(" %d ",matrix[i][j]);

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

void sum_matrix2D(int matrixA[][L],int matrixB[][L],int size){

     int i=0,j=0;

    for(i=0;i<size;i++){

        for(j=0;j<size;j++){

            
           
        }
    }
}