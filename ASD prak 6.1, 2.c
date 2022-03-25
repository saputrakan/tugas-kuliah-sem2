#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef char itemType;
typedef struct{
    itemType data[MAX];
    int count;
}stack;

void inisialisasi(stack *);
int empty(stack *);
int full(stack *) ;
void push(itemType, stack *s);
itemType pop(stack *);
void konversi(char[MAX], stack *);
int derajat(itemType);
void input(char[MAX]) ;

int main(){
    stack tumpukan;
    char jawab;
    char inp[MAX] ;
    inisialisasi(&tumpukan);
    do{
        input(inp) ;
        konversi(inp, &tumpukan);
        fflush(stdin);
        printf("\n\nMasukkan Data Lagi(Y/T)?: ");
        jawab = getchar();
        fflush(stdin);
        puts("");
    }while(jawab == 'Y' || jawab == 'y');
    return 0;
}

void input(char inp[MAX]){
    printf("Masukan notasi infix: ");
    gets(inp) ;
    fflush(stdin);
}

void inisialisasi(stack *s){
    s->count = 0;
}

int full(stack *s){
    return(s->count == MAX ? 1 : 0);
}

int empty(stack *s){
    return(s->count == 0 ? 1 : 0);
}

void push(itemType x, stack *s){
    if(s->count == MAX)
        printf("Stack penuh\n");
    else{
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop(stack *s){
    itemType temp;

    if(s->count == 0) {
        printf("Stack kosong\n");
        temp = ' ' ;
    } else{
        s->count--;
        temp = s->data[s->count];
    }
    return temp ;
}

void konversi(char inp[MAX], stack *s) {
    puts("Hasil Postfix: ");
    for(int i = 0; i < strlen(inp); i++){
        if(inp[i] >= '0' && inp[i] <= '9')
            printf("%c", inp[i]);
        else if(inp[i] == '(')
            push(inp[i], s);
        else if(inp[i] == ')'){
            while(s->data[s->count-1] != '(')
                printf("%c",pop(s));
            (s->count)--;
        }else{
            if(empty(s) || derajat(inp[i]) > derajat(s->data[s->count-1]))
                push(inp[i], s);
            else{
                while((!empty(s)) || derajat(inp[i]) < derajat(s->data[s->count-1]))
                    printf("%c", pop(s));
                push(inp[i], s);
            }
        }
    }
    while(!empty(s))
        printf("%c", pop(s));
}

int derajat(itemType tanda){
    if(tanda == '^')
        return 3;
    else if(tanda == '*' || tanda == '/')
        return 2;
    else if(tanda == '+' || tanda == '-')
        return 1;
    else
        return 0;
}
