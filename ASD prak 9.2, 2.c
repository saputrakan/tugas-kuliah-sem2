#include <stdio.h>
#include <stdlib.h>

void input(int *) ;
void fibonacci(int) ;

int main()
{
    int batas ;
    input(&batas) ;
    fibonacci(batas) ;
    return 0;
}

void input(int *batas){
    printf("Masukkan Batas: ");
    scanf("%d", batas);
}

void fibonacci(int batas){
int angka1 = 0, angka2 = 1, angka3, i ;
    if(batas == 1){
        printf("%d", angka1) ;
    }else{
        printf("\n%d %d", angka1, angka2) ;
        for(i = 2; i < batas; ++i){
            angka3 = angka1 + angka2;
            printf(" %d",angka3);
            angka1 = angka2;
            angka2 = angka3;
        }
    }
}
