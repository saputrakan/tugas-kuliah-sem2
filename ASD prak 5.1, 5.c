#include <stdio.h>
#include <stdlib.h>
typedef struct simpul Dnode ;
struct simpul{
    int data ;
    Dnode *prev, *next ;
};

int menu (int) ;
void pilihan(int) ;
void input () ;
void alokasi() ;
void awal() ;
void akhir() ;
void setelah() ;
void sebelum() ;
void output() ;

int x ;
Dnode *head = NULL, *p ;

int main(){
    int masuk, jwb ;
    do{
        masuk = menu(jwb) ;
        pilihan(masuk) ;
        output() ;
    }while(1) ;
    return 0;
}

int menu(int jwb){
    printf("\nMenu Insert\n") ;
    printf("1. Awal\n") ;
    printf("2. Akhir\n") ;
    printf("3. After\n") ;
    printf("4. Before\n") ;
    printf("5. Keluar\n") ;
    printf("Masukkan pilihan anda : ") ;
    scanf("%d", &jwb) ;
    return jwb ;
}

void pilihan(int masuk){
    if(masuk == 5){
        exit(0) ;
    }
    input();
    alokasi();
    if(masuk == 3 || masuk == 4){
        if(head == NULL){
            printf("Tidak bisa melakukan perintah (SSL masih kosong)\n") ;
        }else{
            if(masuk == 3){
                setelah() ;
            }else{
                sebelum() ;
            }
        }
    }else if(masuk == 1 || masuk == 2){
        if(masuk == 1){
            awal() ;
        }
        else{
            akhir() ;
        }
    }
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

void awal(){
    if(head != NULL){
        p->next = head ;
        head->prev = p ;
    }
    head = p ;
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
    while(baca != NULL){
        printf("%d\n", baca->data) ;
        baca = baca->next ;
    }
}
