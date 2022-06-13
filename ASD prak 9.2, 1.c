#include <stdio.h>
#include <stdlib.h>

int fpb(int , int);
void input(int *, int *) ;
int main() {
    int n1, n2;
    input(&n1, &n2) ;
    printf("Hasil FPB: %d", fpb(n1, n2));
    return 0;
}

void input(int *n1, int *n2){
    printf("Masukkan Angka Pertama: ");
    scanf("%d", n1);
    printf("Masukkan Angka Kedua: ");
    scanf("%d", n2);
    fflush(stdin) ;
}

int fpb(int n1, int n2) {
    if(n2 != 0)
        return fpb(n2, n1 % n2);
    else
        return n1;
}
