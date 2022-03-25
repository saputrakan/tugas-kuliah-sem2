#include <stdio.h>
#include <stdlib.h>
typedef struct simpul node;
struct simpul{
    int data ;
    node *next ;
};
int menu (int) ;
void pilihan(int) ;
void input () ;
void alokasi() ;
void awal() ;
void akhir() ;
void sesudah() ;
void sebelum() ;
void output() ;

int x ;
node *head = NULL, *p ;

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
    printf("Menu Insert\n") ;
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
                sesudah() ;
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

void sesudah(){
    node *aft ;
    int key ;
    printf("Disisipkan setelah data ke : ") ;
    scanf("%d", &key) ;
    aft = head ;
    while(aft->data != key){
        if(aft->next == NULL){
            printf("%d tidak ada dalam SSL", key) ;
            exit(0) ;
        }else{
            aft = aft->next ;
        }
    }
    p->next = aft->next ;
    aft->next = p ;

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
    printf("\n") ;
}
