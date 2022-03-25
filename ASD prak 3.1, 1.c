#include <stdio.h>
#include <stdlib.h>
typedef struct simpul node;
struct simpul{
    int data ;
    node *next ;
};

void input() ;
void alokasi() ;
void akhir() ;
void output() ;
void bebaskan(node *) ;
void hapusAwal() ;

int x ;
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
    }while(jawab == 'Y' || jawab == 'y') ;
    output() ;
    do{
        printf("\n") ;
        printf("Menghapus Awal Isi SLL...") ;
        hapusAwal() ;
        output() ;
        if(head==NULL)
            printf("Kosong\n") ;
    }while(head != NULL) ;
    return 0;
}

void input(){
    printf("Masukkan data : ") ;
    scanf("%d", &x) ;
    fflush(stdin) ;
}

void alokasi(){
    p = (node*)malloc(sizeof(node)) ;
    if(p == NULL){
        puts("Alokasi Gagal") ;
        exit(0) ;
    }else{
        p->data = x ;
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
    while(baca!=NULL){
        printf("%d\n", baca->data) ;
        baca = baca->next ;
    }
}

void bebaskan(node *x){
    free(x) ;
    x = NULL ;
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
