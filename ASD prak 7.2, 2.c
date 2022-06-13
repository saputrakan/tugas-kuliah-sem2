#include <stdio.h>
#include <stdlib.h>
typedef struct simpul node;
struct simpul{
    char data ;
    int angPri ;
    node *next ;
};

void alokasi() ;
void enqueue() ;
void dequeue() ;
void input() ;
int menu() ;
void pilihan(int) ;
void output() ;

char x ;
int ang ;
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
    printf("1. Mengisi Queue\n") ;
    printf("2. Mengambil Isi Queue\n") ;
    printf("3. Menampilkan Isi Queue\n") ;
    printf("4. Keluar\n") ;
    printf("Masukkan Pilihan Anda: ") ;
    scanf("%d", &pil) ;
    fflush(stdin) ;
    return pil ;
}

void pilihan(int pil){
    if(pil == 4)
        exit(0) ;
    else{
        if(pil == 1){
            input() ;
            alokasi() ;
            enqueue() ;
        }else{
            if(head == NULL){
                printf("\nStack Kosong\n") ;
            }else{
                if(pil == 2)
                    dequeue() ;
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
    scanf("%c", &x) ;
    fflush(stdin) ;
    printf("Nilai Prioritasnya : ") ;
    scanf("%d", &ang) ;
    fflush(stdin) ;
}

void alokasi(){
    p = (node*)malloc(sizeof(node)) ;
    if(p == NULL){
        puts("Alokasi Gagal") ;
        exit(0) ;
    }else{
        p->data = x ;
        p->angPri = ang ;
        p->next = NULL ;
    }
}

void enqueue(){
    node *cek, *pcek ;
    if(head == NULL){
        head = p ;
    }else{
        if(p->angPri <= head->angPri){
            if(p->angPri == head->angPri){
                cek = head ;
                while(cek->next->angPri == p->angPri){
                    cek = cek->next ;
                }
                p->next = cek->next ;
                cek->next = p ;
            }else{
                p->next = head ;
                head = p ;
            }
        }else{
            cek = head ;
            while(p->angPri >= cek->angPri && cek->next != NULL){
                pcek = cek ;
                cek = cek->next ;
            }
            if(p->angPri >= cek->angPri && cek->next == NULL){
                cek->next = p ;
            }else{
                p->next = cek ;
                pcek->next = p ;
            }
        }
    }
}

void bebaskan(node *x){
    free(x) ;
    x = NULL ;
}

void dequeue(){
    node *hapus ;
    hapus = head ;
    printf("\nData yang akan diambil %c\n", hapus->data) ;
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
    printf("Data\tPrioritas\n") ;
    while(baca!=NULL){
        printf("%c\t%d\n", baca->data, baca->angPri) ;
        baca = baca->next ;
    }
    printf("\n") ;
}
