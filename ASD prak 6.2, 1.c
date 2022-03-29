#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef int itemType ;
typedef struct{
    itemType data[MAX] ;
    int count ;
}stack ;

void inisialisasi(stack *) ;
int full(stack *) ;
int empty(stack *) ;
void push(itemType , stack *) ;
itemType pop(stack *) ;
void input(itemType *) ;
int menu() ;
void pilihan(int, itemType *, stack *) ;
void biner(itemType *, stack *) ;
void oktal(itemType *, stack *) ;
void heksa(itemType *, stack *) ;
int cekHeksa(itemType) ;

int main()
{
    stack tumpukan ;
    itemType inp ;
    input(&inp) ;
    do{
        inisialisasi(&tumpukan) ;
        pilihan(menu(), &inp, &tumpukan) ;
    }while(1) ;
    return 0;
}

void input(itemType *inp){
    printf("Masukkan Angka: ") ;
    scanf("%d", inp) ;
    fflush(stdin) ;
}

int menu(){
    int pil ;
    printf("\nMenu Konversi\n") ;
    printf("1. Biner\n") ;
    printf("2. Oktal\n") ;
    printf("3. Heksadesimal\n") ;
    printf("4. Keluar\n") ;
    printf("Masukkan Pilihan Anda: ") ;
    scanf("%d", &pil) ;
    return pil ;
}

void pilihan(int pil, itemType *inp, stack *tumpukan){
    if(pil == 4){
        exit(0) ;
    }else{
        if(pil == 1){
            biner(inp, tumpukan) ;
        }else if(pil == 2){
            oktal(inp, tumpukan) ;
        }else{
            heksa(inp, tumpukan) ;
        }
    }
}

void biner(itemType *inp, stack *tumpukan){
    int sisa = 0;
    itemType num = *inp ;
    while(num != 0){
        sisa = num % 2 ;
        push(sisa, tumpukan) ;
        num = num / 2 ;
    }
    printf("\nHasil Konversi Ke Biner:\n") ;
    while(!empty(tumpukan)){
        printf("%d", pop(tumpukan));
    }
    puts(" ") ;
}

void oktal(itemType *inp, stack *tumpukan){
    int sisa = 0;
    itemType num = *inp ;
    while(num != 0){
        sisa = num % 8 ;
        push(sisa, tumpukan) ;
        num = num / 8 ;
    }
    printf("\nHasil Konversi Ke Oktal:\n") ;
    while(!empty(tumpukan)){
        printf("%d", pop(tumpukan));
    }
    puts(" ") ;
}

void heksa(itemType *inp, stack *tumpukan){
    int sisa = 0;
    itemType num = *inp, sim ;
    while(num != 0){
        sisa = num % 16 ;
        push(sisa, tumpukan) ;
        num = num / 16 ;
    }
    printf("\nHasil Konversi Ke Heksa:\n") ;
    while(!empty(tumpukan)){
        sim = pop(tumpukan) ;
        if(sim >= 10 && sim<= 15){
            printf("%c", (char)cekHeksa(sim));
        }else{
            printf("%d", sim) ;
        }
    }
    puts(" ") ;
}

int cekHeksa(itemType sisa){
    switch(sisa){
    case 10 :
        return 65 ;
        break ;
    case 11 :
        return 66 ;
        break ;
    case 12 :
        return 67 ;
        break ;
    case 13 :
        return 68 ;
        break ;
    case 14 :
        return 69 ;
        break ;
    case 15 :
        return 70 ;
        break ;
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

void push(itemType x, stack *s){
    if(full(s))
        printf("\nStack Penuh\n") ;
    else{
        s->data[s->count] = x ;
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

