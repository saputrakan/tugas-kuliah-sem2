#include <stdio.h>
#include <stdlib.h>

void insertion(int []) ;
void selection(int []) ;
void bubble(int []) ;
void shell(int []) ;
void mergeSort(int [], int, int) ;
void merge(int [], int, int, int) ;
void quick(int [], int, int) ;
int partition(int [], int, int) ;
void tampil(int []) ;
int menu() ;
void pilihan(int, int[]) ;
void tukar(int *, int *) ;

int main()
{
    int A[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5} ;
    int sim ;
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
    printf("5. Merge\n") ;
    printf("6. Quick\n") ;
    printf("7. Keluar\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &pil) ;
    return pil ;
}

void pilihan(int pil, int A[]){
    int i, dup[10];
    if(pil == 7){
        exit(0) ;
    }else{
        for(i = 0; i < 10; i++){
            dup[i] = A[i] ;
        }
        tampil(A) ;
        if(pil == 1){
            insertion(dup) ;
        }else if(pil == 2){
            selection(dup) ;
        }else if(pil == 3){
            bubble(dup) ;
        }else if(pil == 4){
            shell(dup) ;
        }else if(pil == 5){
            mergeSort(dup, 0, 10 - 1) ;
        }else if(pil == 6){
            quick(dup, 0, 10 - 1) ;
        }
        tampil(dup) ;
    }
}

void insertion(int dup[]){
    int i, j, key ;
    for(i = 1; i < 10; i++){
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
    int i, j, min ;
    for(i = 0; i < 10; i++){
        min = i ;
        j = i + 1 ;
        while(j < 10){
            if(dup[j] < dup[min])
                min = j ;
            j++ ;
        }
        tukar(&dup[i], &dup[min]) ;
    }
}

void bubble(int A[]){
    int swap = 1, i, j ;
    for(i = 0; i < 10 - 1; i++){
        if(swap == 1){
            swap = 0 ;
            for(j = 0; j < 10 - i - 1; j++){
                if(A[j] > A[j + 1]){
                    tukar(&A[j], &A[j + 1]) ;
                    swap = 1 ;
                }
            }
        }
    }
}

void shell(int A[]){
    int jarak, i, swap = 1 ;
    jarak = 10 ;
    while(jarak > 1){
        jarak = jarak / 2 ;
        swap = 1 ;
        while(swap == 1){
            swap = 0 ;
            for(i = 0; i < (10 - jarak); i++){
                if(A[i] > A[i + jarak]){
                    tukar(&A[i], &A[i + jarak]) ;
                    swap = 1 ;
                }
            }
        }
    }
}

void mergeSort(int A[], int left, int right){
    int med ;
    if(left < right){
       med = (left + right) / 2 ;
       mergeSort(A, left, med) ;
       mergeSort(A, med + 1, right) ;
       merge(A, left, med, right) ;
    }
}

void merge(int A[], int left, int med, int right){
    int hasil[10] ;
    int kiri1, kiri2, kanan1, kanan2, i = left, j ;
    kiri1 = left ;
    kanan1 = med ;
    kiri2 = med + 1 ;
    kanan2 = right ;
    while(kiri1 <= kanan1 && kiri2 <= kanan2){
        if(A[kiri1] <= A[kiri2]){//POSISI
            hasil[i] = A[kiri1] ;
            kiri1++ ;
        }else{
            hasil[i] = A[kiri2] ;
            kiri2++ ;
        }
        i++ ;
    }
    while(kiri1 <= kanan1){
        hasil[i] = A[kiri1] ;
        kiri1++ ;
        i++ ;
    }
    while(kiri2 <= kanan2){
        hasil[i] = A[kiri2] ;
        kiri2++ ;
        i++ ;
    }
    j = left ;
    while(j <= right){
        A[j] = hasil[j] ;
        j++ ;
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
        }while(A[j] > x) ;//POSISI
        do{
            i++ ;
        }while(A[i] < x) ;//POSISI
        if(i < j){
            tukar(&A[i], &A[j]) ;
        }else{
            return j ;
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
