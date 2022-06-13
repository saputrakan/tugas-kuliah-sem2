#include <stdio.h>
#include <stdlib.h>

void shell(int []) ;
void tampil(int []) ;
void tukar(int *, int *) ;
void reset() ;

int c, m, s ;

int main()
{
    //SHELL
    //int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ;
    //int A[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5} ;
    int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1} ;
    tampil(A) ;
    puts("\nSebelum") ;
    reset() ;
    shell(A) ;
    printf("\nC = %d, M = %d, S = %d", c, m, s) ;
    return 0;
}

void shell(int A[]){
    int jarak, n = 10, i, swap = 1, temp ;
    jarak = n ;
    while(jarak > 1){
        jarak = jarak / 2 ;
        swap = 1 ;
        while(swap == 1){
            swap = 0 ;
            for(i = 0; i < (n - jarak); i++){
                if(A[i] > A[i + jarak]){
                    tukar(&A[i], &A[i + jarak]) ;
                    s++ ;
                    m+=3 ;
                    swap = 1 ;
                }
                c++ ;
            }
            puts("") ;
            tampil(A) ;
        }
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
