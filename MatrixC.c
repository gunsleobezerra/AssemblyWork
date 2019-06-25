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
    mult_matrix2D(A,C,matrixresult,L);
    print_matrix2D(matrixresult,L,L);
    sum_matrix2D(matrixresult,B,matrixresult,L);
    
   
    printf("(A X C + B) = \n");

    print_matrix2D(matrixresult,L,L);
    printf("primary diagonal : ");
    return_primary(matrixresult,L);
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



void return_primary(int matrix[][L],int size){

    int i=0,sum=0;

    for(;i<size;i++){

        sum+= matrix[i][i];

    }

    printf("%d",sum);
}
