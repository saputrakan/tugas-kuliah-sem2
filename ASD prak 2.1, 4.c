#include <stdio.h>
#include <stdlib.h>
typedef struct simpul node;
struct simpul{
    int data ;
    node *next ;
};

void input() ;
void alokasi() ;
void awal() ;
void akhir() ;
void sebelum() ;
void output() ;

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
    input() ;
    fflush(stdin) ;
    alokasi() ;
    sebelum() ;
    output() ;
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

void awal(){
    if(head != NULL)
        p->next = head ;
    head = p ;
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
    }
    tail->next = p ;
    tail = tail->next ;
}

void sebelum(){
    node *bef, *pbef ;
    int key ;
    printf("Disisipkan sebelum data ke : ") ;
    scanf("%d", &key) ;
    bef = head ;
    if(head->data == key){
        awal() ;
    }else{
        while(bef->data != key){
        if(bef->next == NULL){
            printf("%d tidak ada dalam SSL", key) ;
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
    printf("Isi SSL :\n") ;
    while(baca!=NULL){
        printf("%d\n", baca->data) ;
        baca = baca->next ;
    }
}
