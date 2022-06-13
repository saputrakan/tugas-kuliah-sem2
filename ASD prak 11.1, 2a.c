#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void generate(int []) ;
void bubble(int [], int) ;
void tampil(int []) ;
void tukar(int *, int *) ;
void reset() ;
int mode_urut() ;
clock_t t ;

int c, m, s, n ;

int main()
{
    //BUBBLE
    printf("Masukkan Jumlah Data( >=20000 ): ") ;
    scanf("%d", &n) ;
    int A[n] ;
    int mode ;
    srand(time(NULL)) ;
    generate(A) ;
    reset() ;
    mode = mode_urut() ;
    t = clock() ;
    bubble(A, mode) ;
    t = clock() - t ;
    double time_taken = ((double)t) / CLOCKS_PER_SEC ;
    printf("Durasi: %f\n", time_taken) ;
    printf("\nC = %d, M = %d, S = %d", c, m, s) ;
    return 0;
}

int mode_urut(){
    int urut ;
    printf("\nMode Urut\n") ;
    printf("1. Ascending\n") ;
    printf("2. Descending\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &urut) ;
    return urut ;
}

void generate(int x[]){
    int i ;
    for(i = 0; i < n; i++){
        x[i] = rand() / 1000 ;
    }
}

void bubble(int A[], int urut){
    int swap = 1, i, j, temp, kondisi;
    for(i = 0; i < n - 1; i++){
        if(swap == 1){
            swap = 0 ;
            for(j = 0; j < n - i - 1; j++){
                if(urut == 1){
                    kondisi = A[j] > A[j + 1] ;
                }else{
                    kondisi = A[j] < A[j + 1] ;
                }
                if(kondisi){
                    tukar(&A[j], &A[j + 1]) ;
                    s++ ;
                    m+=3 ;
                    swap = 1 ;
                }
                c++ ;
            }
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
