#include <stdio.h>
#include <stdlib.h>
void faktorial (int) ;

int main()
{
    int n ;
    printf("Masukkan angka : ") ;
    scanf("%d",&n) ;
    faktorial(n) ;
    return 0;
}

void faktorial (int n){
    int i ;
    int total = 1 ;
    for(i = n; i > 0; i--){
        total = total * i ;
    }
    printf("Hasil Faktorialnya %d", total) ;
}
