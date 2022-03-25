#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef int itemType ;
typedef struct{
    itemType data[MAX] ;
    int count ;
}stack ;

void inisialisasi(stack *) ;
int full(stack *) ;
int empty(stack *) ;
void push(itemType *, stack *) ;
itemType pop(stack *) ;
void input(itemType *) ;
int menu() ;
void pilihan(int, itemType *, stack *) ;
void output(stack *) ;

int main()
{
    stack tumpukan ;
    itemType nilai ;
    int pil ;
    inisialisasi(&tumpukan) ;
    do{
        pil = menu() ;
        pilihan(pil, &nilai, &tumpukan) ;
    }while(1) ;
    return 0;
}

int menu(){
    int pil ;
    printf("\nMenu Stack Dengan Array\n") ;
    printf("1. Mengisi Stack (PUSH)\n") ;
    printf("2. Mengambil Isi Stack (POP)\n") ;
    printf("3. Menampilkan Isi Stack (LIFO)\n") ;
    printf("4. Keluar\n") ;
    printf("Masukkan Pilihan Anda: ") ;
    scanf("%d", &pil) ;
    return pil ;
}

void pilihan(int pil, itemType *nilai, stack *tumpukan){
    if(pil == 4)
        exit(0) ;
    else{
        if(pil == 1){
            input(nilai) ;
            push(nilai, tumpukan) ;
        }else{
            if(empty(tumpukan)){
                printf("\nStack Kosong\n") ;
            }else{
                if(pil == 2)
                    printf("\nItem Yang Anda Ambil Adalah %d\n", pop(tumpukan)) ;
                else{
                    output(tumpukan) ;
                    puts("") ;
                }
            }
        }
    }
}

void input(itemType *nilai){
    printf("\nMasukkan Elemen: ") ;
    scanf("%d", nilai) ;
}

void output (stack *tumpukan){
    int i ;
    printf("\nIsi Stack:\n") ;
    for(i = tumpukan->count-1; i >= 0 ; i--){
        printf("%d\n",tumpukan->data[i]);
    }
}

void inisialisasi(stack *s){
    s->count = 0 ;
}

int full(stack *s){
    return(s->count == MAX ? 1 : 0);
}

int empty(stack *s){
    return(s->count == 0 ? 1 : 0);
}

void push(itemType *x, stack *s){
    if(full(s))
        printf("\nStack Penuh\n") ;
    else{
        s->data[s->count] = *x ;
        s->count++ ;
    }
}

itemType pop(stack *s){
    itemType x ;
    if(empty(s)){
        printf("\nStack  Kosong\n") ;
        x = ' ' ;
    }else{
        s->count-- ;
        x = s->data[s->count] ;
    }
    return x ;
}
