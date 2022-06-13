#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void generate(int []) ;
void insertion(int [], int) ;
void selection(int [], int) ;
void bubble(int [], int) ;
void shell(int [], int) ;
void mergeSort(int [], int, int, int) ;
void merge(int [], int, int, int, int) ;
void quick(int [], int, int, int) ;
int partition(int [], int, int, int) ;
void tampil(int []) ;
int menu() ;
void pilihan(int, int[]) ;
int mode_urut() ;
int n ;
clock_t t ;
void tukar(int *, int *) ;

int main()
{
    printf("Masukkan Jumlah Data(>=30000): ") ;
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
    printf("5. Merge\n") ;
    printf("6. Quick\n") ;
    printf("7. Keluar\n") ;
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
    if(pil == 7){
        exit(0) ;
    }else{
        urut = mode_urut() ;
        for(i = 0; i < n; i++){
            dup[i] = A[i] ;
        }
        t = clock() ;
        if(pil == 1){
            insertion(dup, urut) ;
        }else if(pil == 2){
            selection(dup, urut) ;
        }else if(pil == 3){
            bubble(dup, urut) ;
        }else if(pil == 4){
            shell(dup, urut) ;
        }else if(pil == 5){
            mergeSort(dup, 0, n - 1, urut) ;
        }else if(pil == 6){
            quick(dup, 0, n - 1, urut) ;
        }
        t = clock() - t ;
        double time_taken = ((double)t) / CLOCKS_PER_SEC ;
        printf("Durasi: %f\n", time_taken) ;
    }
}

void generate(int x[]){
    int i ;
    for(i = 0; i < n; i++){
        x[i] = rand() / 1000 ;
    }
}

void insertion(int dup[], int urut){
    int i, j, key ;
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
    int i, j, min, kondisi ;
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
    int swap = 1, i, j, kondisi;
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
    int jarak, i, swap = 1, kondisi ;
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

void mergeSort(int A[], int left, int right, int urut){
    int med ;
    if(left < right){
       med = (left + right) / 2 ;
       mergeSort(A, left, med, urut) ;
       mergeSort(A, med + 1, right, urut) ;
       merge(A, left, med, right, urut) ;
    }
}

void merge(int A[], int left, int med, int right, int urut){
    int hasil[n] ;
    int kiri1, kiri2, kanan1, kanan2, i = left, j, kondisi ;
    kiri1 = left ;
    kanan1 = med ;
    kiri2 = med + 1 ;
    kanan2 = right ;
    while(kiri1 <= kanan1 && kiri2 <= kanan2){
        if(urut == 1){
            kondisi = A[kiri1] <= A[kiri2] ;
        }else{
            kondisi = A[kiri1] >= A[kiri2] ;
        }
        if(kondisi){
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

void quick(int A[], int p, int r, int urut){
    int q ;
    if(p < r){
        q = partition(A, p, r, urut) ;
        quick(A, p, q, urut) ;
        quick(A, q + 1, r, urut) ;
    }
}

int partition(int A[], int p, int r, int urut){
    int x, i, j, kondisi1, kondisi2 ;
    x = A[p] ;
    i = p - 1;
    j = r + 1;
    while(i < j){
        do{
            j-- ;
            if(urut == 1)
                kondisi1 = A[j] > x ;
            else
                kondisi1 = A[j] < x ;
        }while(kondisi1) ;
        do{
            i++ ;
            if(urut == 1)
                kondisi2 = A[i] < x ;
            else
                kondisi2 = A[i] > x ;
        }while(kondisi2) ;
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
