#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef int itemType ;
typedef struct{
    itemType data[MAX] ;
    int count ;
    int front ;
    int rear ;
}queue ;

void inisialisasi(queue *) ;
int full(queue *) ;
int empty(queue *) ;
void enqueue(itemType *, queue *) ;
itemType dequeue(queue *) ;
void input(itemType *) ;
int menu() ;
void pilihan(int, itemType *, queue *) ;
void output(queue *) ;
void minmax(queue *) ;
void cari(queue *) ;

int main()
{
    queue antri ;
    itemType nilai ;
    int pil ;
    inisialisasi(&antri) ;
    do{
        pil = menu() ;
        pilihan(pil, &nilai, &antri) ;
    }while(1) ;
    return 0;
}

int menu(){
    int pil ;
    printf("\nMenu Queue Dengan Array\n") ;
    printf("1. Tambah Data\n") ;
    printf("2. Hapus Data\n") ;
    printf("3. Tampilkan Data MIN & MAX\n") ;
    printf("4. Cari Data\n") ;
    printf("5. Cetak Isi Queue\n") ;
    printf("6. Keluar\n") ;
    printf("Masukkan Pilihan Anda: ") ;
    scanf("%d", &pil) ;
    fflush(stdin) ;
    return pil ;
}

void pilihan(int pil, itemType *nilai, queue *antri){
    if(pil == 6)
        exit(0) ;
    else{
        if(pil == 1){
            input(nilai) ;
            enqueue(nilai, antri) ;
        }else{
            if(empty(antri)){
                printf("\nQueue Kosong\n") ;
            }else{
                if(pil == 2){
                    printf("\nItem Yang Anda Ambil adalah %d\n", dequeue(antri)) ;
                }else if(pil == 3){
                    minmax(antri) ;
                }else if(pil == 4){
                    cari(antri) ;
                }else if(pil == 5){
                    output(antri) ;
                }
            }
        }
    }
}

void input(itemType *nilai){
    printf("\nMasukkan Elemen: ") ;
    scanf("%d", nilai) ;
    fflush(stdin) ;
}

void output (queue *antri){
    int i ;
    int sim = antri->front ;
    printf("\nIsi Queue:\n") ;
    if(empty(antri)){
        printf("\nQueue Kosong\n") ;
    }else{
        for(i = 0; i < antri->count; i++){
            printf("%d\n", antri->data[sim]) ;
            sim = (sim+1) % MAX ;
        }
    }
}

void minmax(queue *antri){
    int i, min, max;
    int sim = antri->front ;
    min = antri->data[sim] ;
    max = antri->data[sim] ;
    for(i = 0; i < antri->count; i++){
        if(antri->data[sim] > min){
            max = antri->data[sim] ;
        }else{
            min = antri->data[sim] ;
        }
        sim = (sim+1) % MAX ;
    }
    printf("\nNilai Terbesar %d\n", max) ;
    printf("Nilai Terkecil %d\n", min) ;
}

void cari(queue *antri){
    int i, key, cek = 0 ;
    int sim = antri->front ;
    printf("\nMasukkan Data Yang Dicari: ") ;
    scanf("%d", &key) ;
    for(i = 0; i < antri->count; i++){
        if(key == antri->data[sim]){
            cek++ ;
        }
        sim = (sim+1) % MAX ;
    }
    if(cek == 0){
        printf("\nData %d tidak ada\n", key) ;
    }else{
        printf("\nData %d sebanyak %d\n", key, cek) ;
    }
}

void inisialisasi(queue *antri){
    antri->count = 0 ;
    antri->front = 0 ;
    antri->rear = 0 ;
}

int full(queue *q){
    return(q->count == MAX ? 1 : 0);
}

int empty(queue *q){
    return(q->count == 0 ? 1 : 0);
}

void enqueue(itemType *x, queue *q){
    if(full(q))
        printf("\nQueue Penuh\n") ;
    else{
        q->data[q->rear] = *x ;
        q->rear = (q->rear + 1) % MAX ;
        q->count++ ;
    }
}

itemType dequeue(queue *q){
    itemType temp ;
    if(empty(q)){
        printf("\nQueue  Kosong\n") ;
        temp = ' ' ;
    }else{
        temp = q->data[q->front] ;
        q->front = (q->front + 1) % MAX ;
        q->count -- ;
    }
    return temp ;
}
