#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insertion(int []) ;
void selection(int []) ;
void tampil(int []) ;
int menu() ;
void pilihan(int, int[]) ;
int mode_urut() ;

int main()
{
    int A[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5} ;
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
    printf("3. Keluar\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &pil) ;
    return pil ;
}


void pilihan(int pil, int A[]){
    int i, dup[MAX] ;
    if(pil == 3){
        exit(0) ;
    }else{
        if(pil == 1){
            for(i = 0; i < MAX; i++){
                dup[i] = A[i] ;
            }
            insertion(dup) ;
        }else if(pil == 2){
            for(i = 0; i < MAX; i++){
                dup[i] = A[i] ;
            }
            selection(dup) ;
        }
        tampil(dup) ;
    }
}

void insertion(int dup[]){
    int i, j, key ;
    for(i = 1; i < MAX; i++){
        key = dup[i] ;
        j = i - 1 ;
        while(j >= 0 && dup[j] > key){
            dup[j + 1] = dup[j] ;
            j-- ;
        }
        dup[j + 1] = key ;
    }
}

void selection(int dup[]){
    int i, j, min, temp, kondisi ;
    for(i = 0; i < MAX; i++){
        min = i ;
        j = i + 1 ;
        while(j < MAX){
            if(dup[j] < dup[min])
                min = j ;
            j++ ;
        }
        temp = dup[i] ;
        dup[i] = dup[min] ;
        dup[min] = temp ;
    }
}

void tampil(int A[]){
    int i ;
    puts("") ;
    for(i = 0; i < MAX; i++){
        printf("%d ", A[i]) ;
    }
}
