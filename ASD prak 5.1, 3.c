#include <stdio.h>
#include <stdlib.h>
typedef struct simpul Dnode ;
struct simpul{
    int data ;
    Dnode *prev, *next ;
};
int x ;
Dnode *head = NULL, *p ;
void input() ;
void alokasi() ;
void akhir() ;
void setelah() ;
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
        fflush(stdin) ;
    }while(jwb == 'Y' || jwb == 'y') ;
    output() ;
    input() ;
    fflush(stdin) ;
    alokasi() ;
    setelah() ;
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
        while(tail->next != NULL){
            tail = tail->next ;
        }
    p->prev = tail ;
    tail->next = p ;
    }
}
void setelah(){
    int key ;
    Dnode *aft ;
    printf("\nInsert data setelah: ") ;
    scanf("%d", &key) ;
    aft = head ;
    while(aft->data != key){
        if(aft->next == NULL){
            puts("Key tidak ada") ;
            exit(0) ;
        }else{
            aft = aft->next ;
        }
    }
    p->prev = aft ;
    if(aft->next != NULL){
        p->next = aft->next ;
        aft->next->prev = p ;
    }
    aft->next = p ;
}
void output(){
    Dnode *baca ;
    printf("\nIsi DLL\n") ;
    baca = head ;
    while(baca != NULL){
        printf("%d\n", baca->data) ;
        baca = baca->next ;
    }
}
