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
void awal() ;
void sebelum() ;
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
    input() ;
    fflush(stdin) ;
    alokasi() ;
    sebelum() ;
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
        puts("Alokasi gagal") ;
        exit(0) ;
    }else{
        p->prev = NULL ;
        p->data = x ;
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
void akhir(){
    Dnode *tail ;
    if(head == NULL)
        head = p ;
    else{
        tail = head ;
        while(tail->next != NULL){
            tail = tail->next ;
        }
    }
    p->prev = tail ;
    tail->next = p ;
}
void sebelum(){
    Dnode *bef ;
    int key ;
    printf("Insert data sebelum: ") ;
    scanf("%d", &key) ;
    if(head->data == key){
        awal() ;
    }else{
        bef = head ;
        while(bef->data != key){
            if(bef->next == NULL){
                printf("Key tidak ada") ;
                exit(0) ;
            }else{
                bef = bef->next ;
            }
        }
        p->next = bef ;
        p->prev = bef->prev ;
        bef->prev->next = p ;
        bef->prev = p ;
    }
}
void output(){
    Dnode *baca ;
    printf("\nIsi DLL\n") ;
    baca = head ;
    while(baca !=  NULL){
        printf("%d\n", baca->data) ;
        baca = baca->next ;
    }
}


