#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void balik(int);
char kata [20] ;

int main() {
    printf("Masukkan Kata: ");
    fgets(kata, sizeof kata, stdin) ;
    balik(strlen(kata)) ;
    return 0;
}

void balik(int n) {
    if(n < 0){
        exit(0) ;
    }
    printf("%c", kata[n]) ;
    balik(n-1) ;
}

