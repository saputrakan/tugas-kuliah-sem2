#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void insertion(int []) ;
void tampil(int []) ;
void tukar(int *, int *) ;

int main()
{
    //INSERTION
    int A[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5} ;
    insertion(A) ;
    tampil(A) ;
    return 0;
}

void insertion(int A[]){
    int i, j, key ;
    for(i = 0; i < MAX; i++){
        printf("%d ", A[i]) ;
    }
    for(i = 1; i < MAX; i++){
        key = A[i] ;
        j = i - 1 ;
        while(j >= 0 && A[j] > key){
            A[j + 1] = A[j] ;
            j-- ;
        }
        A[j + 1] = key ;
    }
}

void tampil(int A[]){
    int i ;
    puts("") ;
    for(i = 0; i < MAX; i++){
        printf("%d ", A[i]) ;
    }
}

