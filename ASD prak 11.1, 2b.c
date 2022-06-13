#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void generate(int []) ;
void shell(int [], int) ;
void tampil(int []) ;
void tukar(int *, int *) ;
void reset() ;
int mode_urut() ;
clock_t t ;

int c, m, s, n ;

int main()
{
    //SHELL
    printf("Masukkan Jumlah Data(>=20000): ") ;
    scanf("%d", &n) ;
    int A[n] ;
    int mode ;
    srand(time(NULL)) ;
    generate(A) ;
    reset() ;
    mode = mode_urut() ;
    t = clock() ;
    shell(A, mode) ;
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

void shell(int A[], int urut){
    int jarak, i, swap = 1, temp, kondisi ;
    jarak = n ;
    while(jarak > 1){
        jarak = jarak / 2 ;
        swap = 1 ;
        while(swap == 1){
            swap = 0 ;
            for(i = 0; i < (n - jarak); i++){
                if(urut == 1){
                    kondisi = A[i] > A[i + jarak] ;
                }else{
                    kondisi = A[i] < A[i + jarak] ;
                }
                if(kondisi){
                    tukar(&A[i], &A[i + jarak]) ;
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
