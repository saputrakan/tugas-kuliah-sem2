#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int no ;
    char nama [20]  ;
    float nilai ;
}siswa ;

int total = 0 ;

void input(siswa[]) ;
void pilihan(int, siswa[]) ;
int menu() ;
int modeUrut() ;
int urut() ;
void insertion(siswa[], int, int) ;
void selection(siswa[], int, int) ;
void bubble(siswa [], int, int) ;
void shell(siswa [], int, int) ;
void mergeSort(siswa [], int, int, int, int) ;
void merge(siswa [], int, int, int, int, int) ;
void quick(siswa [], int, int, int, int) ;
int partition(siswa [], int, int, int, int) ;
void tampil(siswa[]) ;
void tukar(siswa *, siswa *) ;

int main()
{
    printf("Masukkan Berapa Data: ") ;
    scanf("%d", &total) ;
    siswa data[total] ;
    input(data) ;
    tampil(data) ;
    do{
        pilihan(menu(), data) ;
    }while(1) ;
    return 0;
}

void input(siswa data []){
    int i ;
    for(i = 0; i < total; i++){
        printf("\nData Mahasiswa Ke-%d\n", i + 1) ;
        printf("\nMasukkan Nomor\t: ") ;
        scanf("%d", &data[i].no) ;
        fflush(stdin) ;
        printf("Masukkan Nama\t: ") ;
        fgets(data[i].nama, sizeof(data[i].nama), stdin) ;
        data[i].nama[strlen(data[i].nama) - 1] = '\0';
        fflush(stdin) ;
        printf("Masukkan Nilai\t: ") ;
        scanf("%f", &data[i].nilai) ;
        fflush(stdin) ;
        puts("") ;
    }
}

void pilihan(int pil, siswa data[]){
    int i, mode, urutan ;
    siswa dup[total] ;
    if(pil == 7){
        exit(0) ;
    }else{
        mode = modeUrut() ;
        urutan = urut() ;
        printf("\nSebelum\n") ;
        tampil(data) ;
        for(i = 0; i < total; i++){
            dup[i] = data[i] ;
            }
        if(pil == 1){
            insertion(dup, mode, urutan) ;
        }else if(pil == 2){
            selection(dup, mode, urutan) ;
        }else if(pil == 3){
            bubble(dup, mode, urutan) ;
        }else if(pil == 4){
            shell(dup, mode, urutan) ;
        }else if(pil == 5){
            mergeSort(dup, 0, total - 1, mode, urutan) ;
        }else if(pil == 6){
            quick(dup, 0, total - 1, mode, urutan) ;
        }
        printf("\nSesudah\n") ;
        tampil(dup) ;
    }
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

int modeUrut(){
    int mode ;
    printf("\nMode Urut\n") ;
    printf("1. Ascending\n") ;
    printf("2. Descending\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &mode) ;
    return mode ;
}

int urut(){
    int urut ;
    printf("\nPengurutan Berdasarkan\n") ;
    printf("1. No\n") ;
    printf("2. Nama\n") ;
    printf("3. Nilai\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &urut) ;
    return urut ;
}

void insertion(siswa dup[], int mode, int urutan){
    int i, j, kondisiUrut1, kondisiUrut2 ;
    siswa key ;
    for(i = 1; i < total; i++){
        key = dup[i] ;
        j = i - 1 ;
        if(urutan == 1){
            kondisiUrut1 = dup[j].no ;
            kondisiUrut2 = key.no ;
        }else if(urutan == 2){
            kondisiUrut1 = strcmpi(dup[j].nama, key.nama) ;
            kondisiUrut2 = strcmpi(key.nama, dup[j].nama) ;
        }else{
            kondisiUrut1 = dup[j].nilai ;
            kondisiUrut2 = key.nilai ;
        }
        if(mode == 1){
            while(j >= 0 && kondisiUrut1 > kondisiUrut2){
                dup[j + 1] = dup[j] ;
                j-- ;
            }
        }else{
            while(j >= 0 && kondisiUrut1 < kondisiUrut2){
                dup[j + 1] = dup[j] ;
                j-- ;
            }
        }
        dup[j + 1] = key ;
    }
}

void selection(siswa dup[], int mode, int urutan){
    int i, j, min, kondisi, kondisiUrut1, kondisiUrut2 ;
    for(i = 0; i < total; i++){
        min = i ;
        j = i + 1 ;
        while(j < total){
            if(urutan == 1){
                kondisiUrut1 = dup[j].no ;
                kondisiUrut2 = dup[min].no ;
            }else if(urutan == 2){
                kondisiUrut1 = strcmpi(dup[j].nama, dup[min].nama) ;
                kondisiUrut2 = strcmpi(dup[min].nama, dup[j].nama) ;
            }else{
                kondisiUrut1 = dup[j].nilai ;
                kondisiUrut2 = dup[min].nilai ;
            }
            if(mode == 1){
                kondisi = kondisiUrut1 < kondisiUrut2 ;
            }else
                kondisi = kondisiUrut1 > kondisiUrut2 ;
            if(kondisi)
                min = j ;
            j++ ;
        }
        tukar(&dup[i], &dup[min]) ;
    }
}

void bubble(siswa dup[], int mode, int urutan){
    int swap = 1, i, j, kondisi, kondisiUrut1, kondisiUrut2;
    for(i = 0; i < total - 1; i++){
        if(swap == 1){
            swap = 0 ;
            for(j = 0; j < total - i - 1; j++){
                if(urutan == 1){
                    kondisiUrut1 = dup[j].no ;
                    kondisiUrut2 = dup[j + 1].no  ;
                }else if(urutan == 2){
                    kondisiUrut1 = strcmpi(dup[j].nama, dup[j + 1].nama) ;
                    kondisiUrut2 = strcmpi(dup[j + 1].nama, dup[j].nama) ;
                }else{
                    kondisiUrut1 = dup[j].nilai ;
                    kondisiUrut2 = dup[j + 1].nilai ;
                }
                if(mode == 1){
                    kondisi = kondisiUrut1 > kondisiUrut2 ;
                }else{
                    kondisi = kondisiUrut1 < kondisiUrut2 ;
                }
                if(kondisi){
                    tukar(&dup[j], &dup[j + 1]) ;
                    swap = 1 ;
                }
            }
        }
    }
}

void shell(siswa dup[], int mode, int urutan){
    int jarak, i, swap = 1, kondisi, kondisiUrut1, kondisiUrut2 ;
    jarak = total ;
    while(jarak > 1){
        jarak = jarak / 2 ;
        swap = 1 ;
        while(swap == 1){
            swap = 0 ;
            for(i = 0; i < (total - jarak); i++){
                if(urutan == 1){
                    kondisiUrut1 = dup[i].no ;
                    kondisiUrut2 = dup[i + jarak].no  ;
                }else if(urutan == 2){
                    kondisiUrut1 = strcmpi(dup[i].nama, dup[i + jarak].nama);
                    kondisiUrut2 = strcmpi(dup[i + jarak].nama, dup[i].nama);
                }else{
                    kondisiUrut1 = dup[i].nilai ;
                    kondisiUrut2 = dup[i + jarak].nilai ;
                }
                if(mode == 1){
                    kondisi = kondisiUrut1 > kondisiUrut2 ;
                }else{
                    kondisi = kondisiUrut1 < kondisiUrut2 ;
                }
                if(kondisi){
                    tukar(&dup[i], &dup[i + jarak]) ;
                    swap = 1 ;
                }
            }
        }
    }
}

void mergeSort(siswa A[], int left, int right, int mode, int urutan){
    int med ;
    if(left < right){
       med = (left + right) / 2 ;
       mergeSort(A, left, med, mode, urutan) ;
       mergeSort(A, med + 1, right, mode, urutan) ;
       merge(A, left, med, right, mode, urutan) ;
    }
}

void merge(siswa A[], int left, int med, int right, int mode, int urutan){
    siswa hasil[total] ;
    int kiri1, kiri2, kanan1, kanan2, i = left, j, kondisi, kondisiUrut1, kondisiUrut2 ;
    kiri1 = left ;
    kanan1 = med ;
    kiri2 = med + 1 ;
    kanan2 = right ;
    while(kiri1 <= kanan1 && kiri2 <= kanan2){
        if(urutan == 1){
            kondisiUrut1 = A[kiri1].no ;
            kondisiUrut2 = A[kiri2].no ;
        }else if(urutan == 2){
            kondisiUrut1 = strcmpi(A[kiri1].nama, A[kiri2].nama) ;
            kondisiUrut2 = strcmpi(A[kiri2].nama, A[kiri1].nama) ;
        }else{
            kondisiUrut1 = A[kiri1].nilai ;
            kondisiUrut2 = A[kiri2].nilai ;
        }
        if(mode == 1){
            kondisi = kondisiUrut1 <= kondisiUrut2 ;
        }else{
            kondisi = kondisiUrut1 >= kondisiUrut2 ;
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

void quick(siswa A[], int p, int r, int mode, int urutan){
    int q ;
    if(p < r){
        q = partition(A, p, r, mode, urutan) ;
        quick(A, p, q, mode, urutan) ;
        quick(A, q + 1, r, mode, urutan) ;
    }
}

int partition(siswa A[], int p, int r, int mode, int urutan){
    int i, j, kondisi1, kondisi2, kondisiUrut1, kondisiUrut2 ;
    siswa x ;
    if(urutan == 1){
        x.no = A[p].no ;
    }else if(urutan == 2){
        strcpy(x.nama, A[p].nama) ;
    }else{
        x.nilai = A[p].nilai ;
    }
    i = p - 1;
    j = r + 1;
    while(i < j){
        do{
            j-- ;
            if(urutan == 1){
                kondisiUrut1 = A[j].no ;
                kondisiUrut2 = x.no ;
            }else if(urutan == 2){
                kondisiUrut1 = strcmpi(A[j].nama, x.nama) ;
                kondisiUrut2 = strcmpi(x.nama, A[j].nama) ;
            }else if(urutan == 3){
                kondisiUrut1 = A[j].nilai ;
                kondisiUrut2 = x.nilai ;
            }
            if(mode == 1)
                kondisi1 = kondisiUrut1 > kondisiUrut2 ;
            else
                kondisi1 = kondisiUrut1 < kondisiUrut2 ;
        }while(kondisi1) ;
        do{
            i++ ;
            if(urutan == 1){
                kondisiUrut1 = A[i].no ;
                kondisiUrut2 = x.no ;
            }else if(urutan == 2){
                kondisiUrut1 = strcmpi(A[i].nama, x.nama) ;
                kondisiUrut2 = strcmpi(x.nama, A[i].nama) ;
            }else if(urutan == 3){
                kondisiUrut1 = A[i].nilai ;
                kondisiUrut2 = x.nilai ;
            }
            if(mode == 1)
                kondisi2 = kondisiUrut1 < kondisiUrut2 ;
            else
                kondisi2 = kondisiUrut1 > kondisiUrut2 ;
        }while(kondisi2) ;
        if(i < j){
            tukar(&A[i], &A[j]) ;
        }else{
            return j ;
        }
    }
}

void tukar(siswa *a, siswa *b){
    siswa  temp ;
    temp = *a ;
    *a = *b ;
    *b = temp ;
}

void tampil(siswa data[]){
    int i ;
    puts("") ;
    printf("No\tNama Mahasiswa\tNilai\n") ;
    for(i = 0; i < total; i++){
        printf("%d\t%s\t\t%.0f\n", data[i].no, data[i].nama, data[i].nilai) ;
    }
}
