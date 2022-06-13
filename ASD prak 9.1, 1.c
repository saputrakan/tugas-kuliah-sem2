#include <stdio.h>
#include <stdlib.h>
void angka(int) ;

int main()
{
    int n ;
    printf("Masukkan Angka Awal: ") ;
    scanf("%d", &n) ;
    angka(n) ;
    return 0;
}

void angka(int n){
    int i = n ;
    if(n<0)
        exit(0) ;
    printf("%d ", i--) ;
    angka(n-1) ;
}
