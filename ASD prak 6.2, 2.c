#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
typedef char itemType ;
typedef struct{
    itemType data[MAX] ;
    int count ;
}stack ;

void inisialisasi(stack *) ;
int full(stack *) ;
int empty(stack *) ;
void push(itemType , stack *) ;
itemType pop(stack *) ;
void input(itemType [MAX]) ;
int cekPali(itemType [MAX], stack *) ;

int main()
{
    char jwb ;
    itemType inp[MAX] ;
    stack tumpukan ;
    int cek ;
    do{
        inisialisasi(&tumpukan) ;
        input(inp) ;
        cek = cekPali(inp, &tumpukan) ;
        if(cek != 0){
            printf("\nBukan Palindrom\n") ;
        }else{
            printf("\nPalindrom\n") ;
        }
        printf("\nIngin Mencoba Lagi(Y/T): ") ;
        scanf("%c", &jwb) ;
        fflush(stdin) ;
    }while(jwb == 'Y' || jwb == 'y') ;
    return 0;
}

void input(itemType inp[MAX]){
    printf("\nMasukkan Kata: ") ;
    gets(inp) ;
    fflush(stdin) ;
}

int cekPali(itemType inp[MAX], stack *tumpukan){
    int i, cek = 0, jum;
    itemType sim ;
    jum = strlen(inp) ;
    for(i = 0; i < jum; i++){
        push(inp[i], tumpukan) ;
    }
    for(i = 0; i < jum; i++){
        if(inp[i] != pop(tumpukan)){
            cek++ ;
        }
    }
    return cek ;
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

