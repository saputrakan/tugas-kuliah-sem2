#include <stdio.h>
#include <stdlib.h>
typedef struct simpul node;
struct simpul{
    int data ;
    node *next ;
};

void alokasi() ;
void akhir() ;
void hapusAwal() ;
void input() ;
int menu() ;
void pilihan(int) ;
void output() ;

int x ;
node *head = NULL, *p ;

int main()
{
    int pil ;
    do{
        pil = menu() ;
        pilihan(pil) ;
    }while(1) ;
    return 0;
}

int menu(){
    int pil ;
    printf("\nMenu Queue Dengan SLL\n") ;
    printf("1. Mengisi Queue (ENQUEUE)\n") ;
    printf("2. Mengambil Isi Queue (DEQUEUE)\n") ;
    printf("3. Menampilkan Isi QUEUE (FIFO)\n") ;
    printf("4. Keluar\n") ;
    printf("Masukkan Pilihan Anda: ") ;
    scanf("%d", &pil) ;
    return pil ;
}

void pilihan(int pil){
    if(pil == 4)
        exit(0) ;
    else{
        if(pil == 1){
            input() ;
            alokasi() ;
            akhir() ;
        }else{
            if(head == NULL){
                printf("\nStack Kosong\n") ;
            }else{
                if(pil == 2)
                    hapusAwal() ;
                else{
                    output() ;
                }
            }
        }
    }
}

void input(){
    printf("\n") ;
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
    }
    tail->next = p ;
    tail = tail->next ;
}

void bebaskan(node *x){
    free(x) ;
    x = NULL ;
}

void hapusAwal(){
    node *hapus ;
    hapus = head ;
    printf("\nData yang akan diambil %d\n", hapus->data) ;
    if(hapus->next == NULL){
        head = NULL ;
    }else{
        head = hapus->next ;
    }
    bebaskan(hapus) ;
}

void output(){
    node *baca ;
    baca = head ;
    printf("\n") ;
    printf("Isi Queue :\n") ;
    while(baca!=NULL){
        printf("%d\n", baca->data) ;
        baca = baca->next ;
    }
    printf("\n") ;
}
