#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void generate(int []) ;
void insertion(int [], int) ;
void selection(int [], int) ;
void bubble(int [], int) ;
void shell(int [], int) ;
void tampil(int []) ;
int menu() ;
void pilihan(int, int[]) ;
int mode_urut() ;
int n ;
clock_t t ;
void tukar(int *, int *) ;

int main()
{
    printf("Masukkan Jumlah Data(Maksimal 100000): ") ;
    scanf("%d", &n) ;
    int A[n] ;
    srand(time(NULL)) ;
    generate(A) ;
    do{
        pilihan(menu(), A) ;
    }while(1) ;
    return 0;
}

int menu(){
    int pil ;
    printf("\nMenu\n") ;
    printf("1. Insertion\n") ;
    printf("2. Selection\n") ;
    printf("3. Bubble\n") ;
    printf("4. Shell\n") ;
    printf("5. Keluar\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &pil) ;
    return pil ;
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

void pilihan(int pil, int A[]){
    int i, dup[n], urut ;
    if(pil == 5){
        exit(0) ;
    }else{
        urut = mode_urut() ;
        for(i = 0; i < n; i++){
            dup[i] = A[i] ;
        }
        if(pil == 1){
            t = clock() ;
            insertion(dup, urut) ;
            t = clock() - t ;
            double time_taken = ((double)t) / CLOCKS_PER_SEC ;
            printf("Durasi: %f\n", time_taken) ;
        }else if(pil == 2){
            t = clock() ;
            selection(dup, urut) ;
            t = clock() - t ;
            double time_taken = ((double)t) / CLOCKS_PER_SEC ;
            printf("Durasi: %f\n", time_taken) ;
        }else if(pil == 3){
            t = clock() ;
            bubble(dup, urut) ;
            t = clock() - t ;
            double time_taken = ((double)t) / CLOCKS_PER_SEC ;
            printf("Durasi: %f\n", time_taken) ;
        }else if(pil == 4){
            t = clock() ;
            shell(dup, urut) ;
            t = clock() - t ;
            double time_taken = ((double)t) / CLOCKS_PER_SEC ;
            printf("Durasi: %f\n", time_taken) ;
        }
    }
}

void generate(int x[]){
    int i ;
    for(i = 0; i < n; i++){
        x[i] = rand() / 1000 ;
    }
}

void insertion(int dup[], int urut){
    int i, j, key, kondisi ;
    for(i = 1; i < n; i++){
        key = dup[i] ;
        j = i - 1 ;
        if(urut == 1){
            while(j >= 0 && dup[j] > key){
                dup[j + 1] = dup[j] ;
                j-- ;
            }
        }else{
            while(j >= 0 && dup[j] < key){
                dup[j + 1] = dup[j] ;
                j-- ;
            }
        }
        dup[j + 1] = key ;
    }
}

void selection(int dup[], int urut){
    int i, j, min, temp, kondisi ;
    for(i = 0; i < n; i++){
        min = i ;
        j = i + 1 ;
        while(j < n){
            if(urut == 1){
                kondisi = dup[j] < dup[min] ;
            }else
                kondisi = dup[j] > dup[min] ;
            if(kondisi)
                min = j ;
            j++ ;
        }
        tukar(&dup[i], &dup[min]) ;
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
                    swap = 1 ;
                }
            }
        }
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
                    swap = 1 ;
                }
            }
        }
    }
}

void tampil(int A[]){
    int i ;
    puts("") ;
    for(i = 0; i < n; i++){
        printf("%d ", A[i]) ;
    }
}

void tukar(int *a, int *b){
    int  temp ;
    temp = *a ;
    *a = *b ;
    *b = temp ;
}
