#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef char itemType ;
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
    printf("1. Mengisi Queue (ENQUEUE)\n") ;
    printf("2. Mengambil Isi Queue (DEQUEUE)\n") ;
    printf("3. Menampilkan Isi QUEUE (FIFO)\n") ;
    printf("4. Keluar\n") ;
    printf("Masukkan Pilihan Anda: ") ;
    scanf("%d", &pil) ;
    fflush(stdin) ;
    return pil ;
}

void pilihan(int pil, itemType *nilai, queue *antri){
    if(pil == 4)
        exit(0) ;
    else{
        if(pil == 1){
            input(nilai) ;
            enqueue(nilai, antri) ;
        }else{
            if(empty(antri)){
                printf("\nQueue Kosong\n") ;
            }else{
                if(pil == 2)
                    printf("\nItem Yang Anda Ambil Adalah %c\n", dequeue(antri)) ;
                else{
                    output(antri) ;
                    puts("") ;
                }
            }
        }
    }
}

void input(itemType *nilai){
    printf("\nMasukkan Elemen: ") ;
    scanf("%c", nilai) ;
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
            printf("%c\n", antri->data[sim]) ;
            sim = (sim+1) % MAX ;
        }
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
