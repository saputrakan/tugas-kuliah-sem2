#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void selection(int []) ;
void tampil(int []) ;
void tukar(int *, int *) ;

int main()
{
    // SELECTION
    int A[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5} ;
    selection(A) ;
    return 0;
}

void selection(int A[]){
    int i, j, min, temp ;
    for(i = 0; i < MAX; i++){
        printf("%d ", A[i]) ;
    }
    for(i = 0; i < MAX; i++){
        min = i ;
        j = i + 1 ;
        while(j < MAX){
            if(A[j] < A[min])
                min = j ;
            j++ ;
        }
        tukar(&A[i], &A[min]) ;
        puts("") ;
        tampil(A) ;
    }
}

void tampil(int A[]){
    int i ;
    puts("") ;
    for(i = 0; i < MAX; i++){
        printf("%d ", A[i]) ;
    }
}

void tukar(int *a, int *b){
    int  temp ;
    temp = *a ;
    *a = *b ;
    *b = temp ;
}
