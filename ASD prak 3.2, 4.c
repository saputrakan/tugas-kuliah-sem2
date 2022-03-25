#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct siswa node;
struct siswa{
    int no ;
    char nama[20] ;
    float nilai ;
    node *next ;
};

void input() ;
void alokasi() ;
void akhir() ;
void output() ;
void bebaskan(node *) ;
void hapusTertentu() ;
void hapusAwal() ;

int x ;
char y[20] ;
float z ;
node *head = NULL, *p ;

int main(){
    char jawab ;
    do{
        input() ;
        fflush(stdin) ;
        alokasi() ;
        akhir() ;
        printf("Ingin memasukkan data lagi(Y/T): ") ;
        jawab = getchar() ;
        printf("\n") ;
    }while(jawab == 'Y' || jawab == 'y') ;
    output() ;
    printf("Menghapus data tertentu...\n") ;
    hapusTertentu() ;
    output() ;
    return 0;
}

void input(){
    printf("Masukkan Nomor\t: ") ;
    scanf("%d", &x) ;
    fflush(stdin) ;
    printf("Masukkan Nama\t: ") ;
    fgets(y, sizeof(y), stdin) ;
    y[strlen(y) - 1] = '\0';
    fflush(stdin) ;
    printf("Masukkan Nilai\t: ") ;
    scanf("%f", &z) ;
    fflush(stdin) ;
}

void alokasi(){
    p = (node*)malloc(sizeof(node)) ;
    if(p == NULL){
        puts("Alokasi Gagal") ;
        exit(0) ;
    }else{
        p->no = x ;
        strcpy(p->nama, y) ;
        p->nilai = z ;
        p->next = NULL ;
    }
}

void akhir(){
    node *tail ;
    if(head == NULL)
        head = p ;
    else{
        tail = head ;
        while(tail->next!=NULL){
            tail = tail->next ;
        }
        tail->next = p ;
        tail = tail->next ;
    }
}

void output(){
    node *baca ;
    baca = head ;
    printf("\n") ;
    printf("Isi SLL :\n") ;
    printf("No\tNama\tNilai\n") ;
    while(baca!=NULL){
        printf("%d\t%s\t%.0f\n", baca->no, baca->nama, baca->nilai) ;
        baca = baca->next ;
        printf("\n") ;
    }
}

void bebaskan(node *x){
    free(x) ;
    x = NULL ;
}

void hapusTertentu(){
    node *hapus, *phapus ;
    int key ;
    printf("Data yang dihapus : ") ;
    scanf("%d", &key) ;
    fflush(stdin) ;
    hapus = head ;
    if(hapus->no == key){
        hapusAwal() ;
    }else{
        while(hapus->no != key){
            if(hapus->next == NULL){
                printf("%d tidak ada dalam SLL", key) ;
                exit(0) ;
            }else{
                phapus = hapus ;
                hapus = hapus->next ;
            }
        }
        phapus->next = hapus->next ;
    }
    bebaskan(hapus) ;
}

void hapusAwal(){
    node *hapus ;

    hapus = head ;
    if(hapus->next == NULL){
        head = NULL ;
    }else{
        head = hapus->next ;
    }
    bebaskan(hapus) ;
}
