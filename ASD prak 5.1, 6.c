#include <stdio.h>
#include <stdlib.h>
typedef struct simpul Dnode ;
struct simpul{
    int data ;
    Dnode *prev, *next ;
};

void input() ;
void alokasi() ;
void awal() ;
void akhir() ;
void setelah() ;
void sebelum() ;
void output() ;
int menuUtama(int) ;
int menuInsert(int) ;
int menuDelete(int) ;
void pilihan(int, int, int) ;
void pilihanInsert(int) ;
void pilihanDelete(int) ;
void bebaskan(Dnode *) ;
void hapusAwal() ;
void hapusAkhir() ;
void hapusTertentu() ;

int x ;
Dnode *head = NULL, *p, *hapus ;

int main(){
    int masuk1, masuk2, masuk3, jwb1, jwb2, jwb3 ;
    do{
        masuk1 = menuUtama(jwb1) ;
        if(masuk1 == 1){
            masuk2 = menuInsert(jwb2) ;
        }else if(masuk1 == 2){
            masuk3 = menuDelete(jwb3) ;
        }
        pilihan(masuk1, masuk2, masuk3) ;
        output() ;
    }while(1) ;
    return 0;
}

int menuUtama(int jwb1){
    printf("\nMenu DLL\n") ;
    printf("1. Insert\n") ;
    printf("2. Delete\n") ;
    printf("3. Keluar\n") ;
    printf("Masukkan pilihan anda : ") ;
    scanf("%d", &jwb1) ;
    return jwb1 ;
}

int menuInsert(int jwb2){
    printf("\n") ;
    printf("Menu Insert\n") ;
    printf("1. Awal\n") ;
    printf("2. Akhir\n") ;
    printf("3. After\n") ;
    printf("4. Before\n") ;
    printf("Masukkan pilihan anda : ") ;
    scanf("%d", &jwb2) ;
    return jwb2 ;
}

int menuDelete(int jwb3){
    printf("\n") ;
    printf("Menu Delete\n") ;
    printf("1. Awal\n") ;
    printf("2. Akhir\n") ;
    printf("3. Tertentu\n") ;
    printf("Masukkan pilihan anda : ") ;
    scanf("%d", &jwb3) ;
    return jwb3 ;
}

void pilihan(int masuk1, int masuk2, int masuk3){
    if(masuk1 == 3){
        exit(0) ;
    }
    if(masuk1 == 1){
        input();
        alokasi();
        pilihanInsert(masuk2) ;
    }else if(masuk1 == 2){
        pilihanDelete(masuk3) ;
    }
}

void pilihanInsert(int masuk2){
    if(masuk2 == 3 || masuk2 == 4){
        if(head == NULL){
            printf("\nTidak bisa melakukan perintah (DLL masih kosong)\n") ;
        }else{
            if(masuk2 == 3){
                setelah() ;
            }else{
                sebelum() ;
            }
        }
    }else if(masuk2 == 1 || masuk2 == 2){
        if(masuk2 == 1){
            awal() ;
        }else{
            akhir() ;
        }
    }
}

void pilihanDelete(int masuk3){
    if(head == NULL){
        printf("\nTidak bisa melakukan perintah (DLL masih kosong)\n") ;
    }else{
        if(masuk3 == 1){
            hapusAwal() ;
        }else if(masuk3 == 2){
            hapusAkhir() ;
        }else if(masuk3 == 3){
            hapusTertentu() ;
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
    tail = p ;
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
        aft->next->prev = p ;
    }
    p->next = aft->next ;
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

void bebaskan(Dnode *x){
    free(x) ;
    x = NULL ;
}

void hapusAwal(){
    hapus = head ;
    if(head->next == NULL){
        head = NULL ;
    }else{
        hapus->next->prev = NULL ;
        head = hapus->next ;
    }
    bebaskan(hapus) ;
}

void hapusAkhir(){
    hapus = head ;
    if(head->next == NULL){
        head = NULL ;
    }else{
        while(hapus->next != NULL){
            hapus = hapus->next ;
        }
        hapus->prev->next = NULL ;
    }
    bebaskan(hapus) ;
}

void hapusTertentu(){
    int key ;
    printf("Masukkan data yang dihapus: ") ;
    scanf("%d", &key) ;
    if(head->data == key){
        hapusAwal() ;
    }else{
        hapus = head ;
        while(hapus->data != key){
            if(hapus->next == NULL){
                printf("Key tidak ada") ;
                exit(0) ;
            }
            hapus = hapus->next ;
        }
        if(hapus->next == NULL){
            hapus->prev->next = NULL ;
        }else{
            hapus->prev->next = hapus->next ;
            hapus->next->prev = hapus->prev ;
        }
        bebaskan(hapus) ;
    }
}


