#include <stdio.h>
#include <stdlib.h>

long int faktorial(int, int);
int total = 1 ;

int main() {
    int angka;
    printf("Masukkan Angka: ");
    scanf("%d",&angka);
    fflush(stdin) ;
    if(angka < 0)
        printf("Kesalahan") ;
    else if(angka == 0)
        printf("Hasil faktorial: 1") ;
    else
        printf("Hasil faktorial: %ld", faktorial(angka, 1)) ;
    return 0;
}

long int faktorial(int angka, int total) {
    if(angka == 1)
        return total ;
    else
        faktorial(angka - 1,  angka * total) ;
}

