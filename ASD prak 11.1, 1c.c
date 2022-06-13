#include <stdio.h>
#include <stdlib.h>

void bubble(int []) ;
void tampil(int []) ;
void tukar(int *, int *) ;
void reset() ;

int c, m, s ;

int main()
{
    //BUBBLE
    //int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ;
    //int A[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5} ;
    int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1} ;
    tampil(A) ;
    puts("\nSebelum") ;
    reset() ;
    bubble(A) ;
    printf("\nC = %d, M = %d, S = %d", c, m, s) ;
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
                    s++ ;
                    m+=3 ;
                    swap = 1 ;
                }
                c++ ;
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

void reset(){
    c = 0 ;
    m = 0 ;
    s = 0 ;
}
