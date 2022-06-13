#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

void generate(int []) ;
void sequential(int []) ;
void binary(int []) ;
void quick(int [], int, int) ;
int partition(int [], int, int) ;
void tukar(int *, int *) ;
int menu() ;
void pilihan(int, int[]) ;
int n = 10, key ;
clock_t t ;

int main()
{
    printf("Masukkan Jumlah Data: ") ;
    scanf("%d", &n) ;
    int A[n] ;
    srand(time(NULL)) ;
    generate(A) ;
    printf("Masukkan Key: ") ;
    scanf("%d", &key) ;
    do{
        pilihan(menu(), A) ;
    }while(1) ;
    return 0;
}

int menu(){
    int pil ;
    printf("\nMenu\n") ;
    printf("1. Sequential\n") ;
    printf("2. Sequential Sorted\n") ;
    printf("3. Binary\n") ;
    printf("4. Keluar\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &pil) ;
    return pil ;
}

void pilihan(int pil, int A[]){
    int i, dup[n], urut ;
    if(pil == 4){
        exit(0) ;
    }else{
        for(i = 0; i < n; i++){
            dup[i] = A[i] ;
        }
        t = clock() ;
        if(pil == 1){
            sequential(dup) ;
            sleep(1) ;
        }else if(pil == 2){
            quick(dup, 0, n - 1) ;
            sequential(dup) ;
        }else if(pil == 3){
            quick(dup, 0, n - 1) ;
            binary(dup) ;
        }
        t = clock() - t ;
        double time_taken = ((double)t) / CLOCKS_PER_SEC ;
        printf("Durasi: %f\n", time_taken) ;
    }
}

void sequential(int A[]){
    int i = 0, find ;
    find = 0 ;
    while(!find && i < n){
        if(A[i] == key){
            find = 1 ;
        }else{
            i++ ;
        }
    }
}

void binary(int A[]){
    int find ;
    int L = 0, R = n - 1, m ;
    find = 0 ;
    while(L <= R && !find){
        m = (L + R) / 2 ;
        if(A[m] == key){
            find = 1 ;
        }
        if(key < A[m]){
            R = m - 1 ;
        }
        if(key > A[m]){
            L = m + 1 ;
        }
    }
}

void quick(int A[], int p, int r){
    int q ;
    if(p < r){
        q = partition(A, p, r) ;
        quick(A, p, q) ;
        quick(A, q + 1, r) ;
    }
}

int partition(int A[], int p, int r){
    int x, i, j ;
    x = A[p] ;
    i = p - 1;
    j = r + 1;
    while(i < j){
        do{
            j-- ;
        }while(A[j] > x) ;
        do{
            i++ ;
        }while(A[i] < x) ;
        if(i < j){
            tukar(&A[i], &A[j]) ;
        }else{
            return j ;
        }
    }
}

void tukar(int *a, int *b){
    int  temp ;
    temp = *a ;
    *a = *b ;
    *b = temp ;
}

void generate(int x[]){
    int i ;
    for(i = 0; i < n; i++){
        x[i] = rand() / 1000 ;
    }
}

