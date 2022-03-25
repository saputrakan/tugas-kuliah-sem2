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
void awal() ;
void sebelum() ;
void output() ;

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
        awal() ;
        printf("\n") ;
        printf("Ingin memasukkan data lagi(Y/T): ") ;
        jawab = getchar() ;
        printf("\n") ;
    }while(jawab == 'Y' || jawab == 'y') ;
        output() ;
    input() ;
    fflush(stdin) ;
    alokasi() ;
    sebelum() ;
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

void awal(){
    if(head != NULL)
        p->next = head ;
    head = p ;
}

void sebelum(){
    node *bef, *pbef ;
    int key ;
    printf("Disisipkan sebelum data ke : ") ;
    scanf("%d", &key) ;
    bef = head ;
    if(head->no == key){
        awal() ;
    }else{
        while(bef->no != key){
        if(bef->next == NULL){
            printf("%d tidak ada dalam SLL", key) ;
            exit(0) ;
        }else{
            pbef = bef ;
            bef = bef->next ;
        }
    }
    p->next = bef ;
    pbef->next = p ;
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
