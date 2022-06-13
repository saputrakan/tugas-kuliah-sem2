#include <stdio.h>
#include <stdlib.h>

void fibonacci(int) ;
void input(int *) ;

int main(){
    int batas ;
    input(&batas) ;
    if(batas == 1){
        printf("%d", 0) ;
    }else{
        printf("\n%d %d ", 0, 1);
        fibonacci(batas - 2);
    }
  return 0;
}

void input(int *batas){
    printf("Masukkan Batas: ") ;
    scanf("%d", batas) ;
}

void fibonacci(int batas){
    static int angka1 = 0, angka2 = 1, angka3 ;
    if(batas > 0){
         angka3 = angka1 + angka2 ;
         angka1 = angka2 ;
         angka2 = angka3 ;
         printf("%d ",angka3) ;
         fibonacci(batas - 1) ;
    }
}
