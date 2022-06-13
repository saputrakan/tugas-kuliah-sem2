#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int no ;
    char nama [20]  ;
    float nilai ;
}siswa ;

int total = 0, keyNo ;
char keyNama[20] ;

void input(siswa[]) ;
void sequential(siswa [], int) ;
void binary(siswa [], int) ;
void quick(siswa [], int, int, int) ;
int partition(siswa [], int, int, int) ;
void tukar(siswa *, siswa *) ;
int menu() ;
int tampilanData() ;
int dasarPencarian() ;
void pilihan(int, siswa[]) ;
void tampil(siswa[]) ;
void cariKeyNo() ;
void cariKeyNama() ;

int main()
{
    printf("Masukkan Jumlah Data: ") ;
    scanf("%d", &total) ;
    siswa data[total] ;
    input(data) ;
    do{
        pilihan(menu(), data) ;
    }while(1) ;
    return 0;
}

int menu(){
    int pil ;
    printf("\nMenu\n") ;
    printf("1. Tampilkan Data\n") ;
    printf("2. Sequential Search\n") ;
    printf("3. Binary Search\n") ;
    printf("4. Keluar\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &pil) ;
    fflush(stdin) ;
    return pil ;
}

int tampilanData(){
    int bentuk ;
    printf("\nBentuk Data\n") ;
    printf("1. Tidak terurut\n") ;
    printf("2. Terurut Berdasarkan No\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &bentuk) ;
    fflush(stdin) ;
    return bentuk ;
}

int dasarPencarian(){
    int dasar ;
    printf("\nPencarian Berdasarkan\n") ;
    printf("1. No\n") ;
    printf("2. Nama\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &dasar) ;
    fflush(stdin) ;
    return dasar ;
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

void pilihan(int pil, siswa A[]){
    int i, urut, tam, cari;
    siswa dup[total] ;
    if(pil == 4){
        exit(0) ;
    }else{
        for(i = 0; i < total; i++){
            dup[i] = A[i] ;
            }
        if(pil == 1){
            tam = tampilanData() ;
            if(tam == 1){
                tampil(dup) ;
            }else if(tam == 2){
                quick(dup, 0, total - 1, 1) ;
                tampil(dup) ;
            }
        }else{
            cari = dasarPencarian() ;
            if(pil == 2){
                sequential(dup, cari) ;
            }else if(pil == 3){
                quick(dup, 0, total - 1, cari) ;
                binary(dup, cari) ;
            }
        }
    }
}

void sequential(siswa A[], int cari){
    int i = 0, find, kondisi, indeks ;
    find = 0 ;
    if(cari == 1){
        cariKeyNo() ;
    }else{
        cariKeyNama() ;
    }
    while(!find && i < total){
        if(cari == 1){
            kondisi = A[i].no == keyNo ;
        }else{
            kondisi = (strcmpi(A[i].nama, keyNama) == 0 ) ;
        }
        if(kondisi){
            find = 1 ;
            indeks = i ;
        }else{
            i++ ;
        }
    }
    if(find){
        printf("\nData berada di indeks ke-%d", indeks) ;
    }else{
        printf("\nData tidak ada") ;
    }
}

void binary(siswa A[], int cari){
    int find, kondisi, indeks, kondisi1, kondisi2 ;
    int L = 0, R = total - 1, m ;
    find = 0 ;
    if(cari == 1){
        cariKeyNo() ;
    }else{
        cariKeyNama() ;
    }
    while(L <= R && !find){
        m = (L + R) / 2 ;
        if(cari == 1){
            kondisi = A[m].no == keyNo ;
            kondisi1 = keyNo < A[m].no ;
            kondisi2 = keyNo > A[m].no ;
        }else{
            kondisi = (strcmpi(A[m].nama, keyNama) == 0 ) ;
            kondisi1 = strcmpi(A[m].nama, keyNama) > 0 ;
            kondisi2 = strcmpi(A[m].nama, keyNama) < 0;
        }
        if(kondisi){
            find = 1 ;
            indeks = m ;
        }
        if(kondisi1){
            R = m - 1 ;
        }
        if(kondisi2){
            L = m + 1 ;
        }
    }
    if(find){
        printf("\nData berada di indeks ke-%d", indeks) ;
    }else{
        printf("\nData tidak ada") ;
    }
}

void quick(siswa A[], int p, int r, int urutan){
    int q ;
    if(p < r){
        q = partition(A, p, r, urutan) ;
        quick(A, p, q, urutan) ;
        quick(A, q + 1, r, urutan) ;
    }
}

int partition(siswa A[], int p, int r, int urutan){
    int i, j, kondisiUrut1, kondisiUrut2 ;
    siswa x ;
    if(urutan == 1){
        x.no = A[p].no ;
    }else{
        strcpy(x.nama, A[p].nama) ;
    }
    i = p - 1;
    j = r + 1;
    while(i < j){
        do{
            j-- ;
            if(urutan == 1){
                kondisiUrut1 = A[j].no ;
                kondisiUrut2 = x.no ;
            }else{
                kondisiUrut1 = strcmpi(A[j].nama, x.nama) ;
                kondisiUrut2 = strcmpi(x.nama, A[j].nama) ;
            }
        }while(kondisiUrut1 > kondisiUrut2) ;
        do{
            i++ ;
            if(urutan == 1){
                kondisiUrut1 = A[i].no ;
                kondisiUrut2 = x.no ;
            }else{
                kondisiUrut1 = strcmpi(A[i].nama, x.nama) ;
                kondisiUrut2 = strcmpi(x.nama, A[i].nama) ;
            }
        }while(kondisiUrut1 < kondisiUrut2) ;
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

void cariKeyNo(){
    printf("\nMasukkan no yang dicari: ") ;
    scanf("%d", &keyNo) ;
}

void cariKeyNama(){
    printf("\nMasukkan nama yang dicari: ") ;
    fgets(keyNama, sizeof(keyNama), stdin) ;
    keyNama[strlen(keyNama) - 1] = '\0';
}

