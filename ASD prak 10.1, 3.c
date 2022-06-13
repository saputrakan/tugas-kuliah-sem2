#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insertion(int [], int) ;
void selection(int [], int) ;
void tukar(int *, int *) ;
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
    printf("\n\nMenu\n") ;
    printf("1. Insertion\n") ;
    printf("2. Selection\n") ;
    printf("3. Keluar\n") ;
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
    int i, dup[MAX], urut ;
    if(pil == 3){
        exit(0) ;
    }else{
        urut = mode_urut() ;
        tampil(A) ;
        if(pil == 1){
            for(i = 0; i < MAX; i++){
                dup[i] = A[i] ;
            }
            insertion(dup, urut) ;
        }else if(pil == 2){
            for(i = 0; i < MAX; i++){
                dup[i] = A[i] ;
            }
            selection(dup, urut) ;
        }
        tampil(dup) ;
    }
}

void insertion(int dup[], int urut){
    int i, j, key, kondisi ;
    for(i = 1; i < MAX; i++){
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
    for(i = 0; i < MAX; i++){
        min = i ;
        j = i + 1 ;
        while(j < MAX){
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
