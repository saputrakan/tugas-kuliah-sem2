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
void insertion(siswa[], int) ;
void selection(siswa[], int) ;
void tampil(siswa[]) ;
void tukar(siswa, int, int, siswa[]) ;

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
    int i, urut ;
    siswa dup[total] ;
    if(pil == 3){
        exit(0) ;
    }else{
        urut = modeUrut() ;
        printf("\nSebelum\n") ;
        tampil(data) ;
        if(pil == 1){
            for(i = 0; i < total; i++){
                dup[i] = data[i] ;
            }
            insertion(dup, urut) ;
        }else if(pil == 2){
            for(i = 0; i < total; i++){
                dup[i] = data[i] ;
            }
            selection(dup, urut) ;
        }
        printf("\nSesudah\n") ;
        tampil(dup) ;
    }
}

int menu(){
    int pil ;
    printf("\nMenu Metode Sorting") ;
    printf("\n1. Insertion") ;
    printf("\n2. Selection") ;
    printf("\n3. Keluar") ;
    printf("\nMasukkan Pilihan Anda: ") ;
    scanf("%d", &pil) ;
    return pil ;
}

int modeUrut(){
    int urut ;
    printf("\nMode Urut\n") ;
    printf("1. Ascending\n") ;
    printf("2. Descending\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &urut) ;
    return urut ;
}

void insertion(siswa dup[], int urut){
    int i, j, kondisi ;
    siswa key ;
    for(i = 1; i < total; i++){
        key = dup[i] ;
        j = i - 1 ;
        if(urut == 1){
            while(j >= 0 && dup[j].no > key.no){
                dup[j + 1] = dup[j] ;
                j-- ;
            }
        }else{
            while(j >= 0 && dup[j].no < key.no){
                dup[j + 1] = dup[j] ;
                j-- ;
            }
        }
        dup[j + 1] = key ;
    }
}

void selection(siswa dup[], int urut){
    int i, j, min, kondisi ;
    siswa temp ;
    for(i = 0; i < total; i++){
        min = i ;
        j = i + 1 ;
        while(j < total){
            if(urut == 1){
                kondisi = dup[j].no < dup[min].no ;
            }else
                kondisi = dup[j].no > dup[min].no ;
            if(kondisi)
                min = j ;
            j++ ;
        }
        tukar(temp, min, i, dup) ;
    }
}

void tukar(siswa temp, int min, int i, siswa dup[]){
    temp = dup[i] ;
    dup[i] = dup[min] ;
    dup[min] = temp ;
}

void tampil(siswa data[]){
    int i ;
    puts("") ;
    printf("No\tNama Mahasiswa\tNilai\n") ;
    for(i = 0; i < total; i++){
        printf("%d\t%s\t\t%.0f\n", data[i].no, data[i].nama, data[i].nilai) ;
    }
}
