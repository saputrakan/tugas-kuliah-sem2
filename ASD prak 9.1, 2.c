#include <stdio.h>
#include <stdlib.h>
void angka(int) ;

int main()
{
    int n ;
    printf("Masukkan Batas: ") ;
    scanf("%d", &n) ;
    angka(n) ;
    return 0;
}

void angka(int n){
    static int i=0 ;
    if(n<0)
        exit(0) ;
    printf("%d ", i++) ;
    angka(n-1) ;
}
