#include <stdio.h>
#include <stdlib.h>
typedef struct simpul Dnode ;
struct simpul{
    int data ;
    Dnode *prev, *next ;
};

int nilai ;
Dnode *head = NULL, *p ;
void input() ;
void alokasi() ;
void awal() ;
void output() ;

int main()
{
    char jwb ;
    do{
        input() ;
        fflush(stdin) ;
        alokasi() ;
        awal() ;
        printf("Mau memasukkan data lagi?(Y/T): ") ;
        scanf("%c", &jwb) ;
        fflush(stdin) ;
    }while(jwb == 'Y' || jwb == 'y') ;
    output() ;
    return 0;
}

void input(){
    printf("\nMasukkan data: ") ;
    scanf("%d", &nilai) ;
}

void alokasi(){
    p = (Dnode*)malloc(sizeof(Dnode)) ;
    if(p == NULL){
        puts("Alokasi Gagal") ;
        exit(0) ;
    }else{
        p->prev = NULL ;
        p->data = nilai ;
        p->next = NULL ;
    }
}

void awal(){
    if(head != NULL){
        p->next = head ;
        head->prev = p ;
    }
    head = p ;
}

void output(){
    Dnode *baca ;
    printf("\nIsi DLL adalah\n") ;
    baca = head ;
    while(baca != NULL){
        printf("%d\n", baca->data) ;
        baca = baca->next ;
    }
}
