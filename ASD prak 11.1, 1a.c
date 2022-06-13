#include <stdio.h>
#include <stdlib.h>

void bubble(int []) ;
void tampil(int []) ;
void tukar(int *, int *) ;

int main()
{
    //BUBBLE
    //int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ;
    int A[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5} ;
    tampil(A) ;
    puts("\nSebelum") ;
    bubble(A) ;
    return 0;
}

void bubble(int A[]){
    int swap = 1, i, j, n = 10, temp;
    for(i = 0; i < n - 1; i++){
        if(swap == 1){
            swap = 0 ;
            for(j = 0; j < n - i - 1; j++){
                if(A[j] > A[j + 1]){
                    tukar(&A[j], &A[j + 1]) ;
                    swap = 1 ;
                }
            }
        }
        puts("") ;
        tampil(A) ;
    }
}

void tampil(int A[]){
    int i ;
    puts("") ;
    for(i = 0; i < 10; i++){
        printf("%d ", A[i]) ;
    }
}

void tukar(int *a, int *b){
    int  temp ;
    temp = *a ;
    *a = *b ;
    *b = temp ;
}
