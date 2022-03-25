#include <stdio.h>
#include <stdlib.h>
typedef struct simpul Dnode ;
struct simpul{
    int data ;
    Dnode *next, *prev ;
};

int x ;
Dnode *head = NULL, *p ;
void input() ;
void alokasi() ;
void akhir() ;
void output() ;

int main()
{
    char jwb ;
    do{
        input() ;
        fflush(stdin) ;
        alokasi() ;
        akhir() ;
        printf("Ingin memasukkan data lagi?(Y/T): ") ;
        scanf("%c", &jwb) ;
    }while(jwb == 'Y' || jwb == 'y') ;
    output() ;
    return 0;
}

void input(){
    printf("\nMasukkan data: ") ;
    scanf("%d", &x) ;
}

void alokasi(){
    p = (Dnode*)malloc(sizeof(Dnode)) ;
    if(p == NULL){
        puts("Alokasi Gagal") ;
        exit(0) ;
    }else{
        p->prev = NULL ;
        p->data = x ;
        p->next = NULL ;
    }
}

void akhir(){
    Dnode *tail ;
    if(head == NULL){
        head = p ;
    }else{
        tail = head ;
        while(tail->next !=NULL){
            tail = tail->next ;
        }
        p->prev = tail ;
        tail->next = p ;
    }
}

void output(){
    Dnode *baca ;
    baca = head ;
    printf("\nIsi DLL\n") ;
    while(baca != NULL){
        printf("%d\n", baca->data) ;
        baca = baca->next ;
    }
}
