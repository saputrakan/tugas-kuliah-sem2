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
int menuUtama (int) ;
int menuInsert(int) ;
int menuDelete(int) ;
void pilihan(int, int, int) ;
void input () ;
void alokasi() ;
void awal() ;
void akhir() ;
void sesudah() ;
void sebelum() ;
void output() ;
void hapusAwal() ;
void hapusAkhir() ;
void hapusTertentu() ;
void bebaskan(node *) ;

int x ;
char y[20] ;
float z ;
node *head = NULL, *p ;

int main(){
    int masuk1, masuk2, masuk3, jwb1, jwb2, jwb3 ;
    do{
        masuk1 = menuUtama(jwb1) ;
        if(masuk1 == 1){
            input();
            alokasi();
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
    printf("Menu SLL\n") ;
    printf("1. Insert\n") ;
    printf("2. Delete\n") ;
    printf("3. Keluar\n") ;
    printf("Masukkan pilihan anda : ") ;
    scanf("%d", &jwb1) ;
    printf("\n") ;
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
    printf("\n") ;
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
    printf("\n") ;
    return jwb3 ;
}

void pilihan(int masuk1, int masuk2, int masuk3){
    if(masuk1 == 3){
        exit(0) ;
    }
    if(masuk1 == 1){
        if(masuk2 == 3 || masuk2 == 4){
            if(head == NULL){
                printf("\n") ;
                printf("Tidak bisa melakukan perintah (SLL masih kosong)\n") ;
            }else{
                if(masuk2 == 3){
                    sesudah() ;
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
    }else if(masuk1 == 2){
        if(head == NULL){
            printf("\n") ;
            printf("Tidak bisa melakukan perintah (SLL masih kosong)\n") ;
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

void sesudah(){
    node *aft ;
    int key ;
    printf("\n") ;
    printf("Disisipkan setelah data ke : ") ;
    scanf("%d", &key) ;
    aft = head ;
    while(aft->no != key){
        if(aft->next == NULL){
            printf("\n") ;
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
    printf("\n") ;
    printf("Disisipkan sebelum data ke : ") ;
    scanf("%d", &key) ;
    bef = head ;
    if(head->no == key){
        awal() ;
    }else{
        while(bef->no != key){
        if(bef->next == NULL){
            printf("\n") ;
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
    printf("Isi SLL :\n") ;
    printf("No\tNama\tNilai\n") ;
    while(baca!=NULL){
        printf("%d\t%s\t%.0f\n", baca->no, baca->nama, baca->nilai) ;
        baca = baca->next ;
        printf("\n") ;
    }
    printf("\n") ;
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

void hapusAkhir(){
    node *hapus, *phapus ;
    hapus = head ;
    if(hapus->next == NULL){
        head = NULL ;
    }else{
        while(hapus->next != NULL){
            phapus = hapus ;
            hapus = hapus->next ;
        }
        phapus->next = NULL ;
    }
    bebaskan(hapus) ;
}

void hapusTertentu(){
    node *hapus, *phapus ;
    int key ;
    printf("Data yang dihapus : ") ;
    scanf("%d", &key) ;
    fflush(stdin) ;
    hapus = head ;
    if(hapus->no == key){
        hapusAwal() ;
    }else{
        while(hapus->no != key){
            if(hapus->next == NULL){
                printf("\n") ;
                printf("%d tidak ada dalam SLL", key) ;
                exit(0) ;
            }else{
                phapus = hapus ;
                hapus = hapus->next ;
            }
        }
        phapus->next = hapus->next ;
        bebaskan(hapus) ;
    }
}
