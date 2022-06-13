#include <stdio.h>
#include <stdlib.h>

int prima(int, int);

int main()
{
    int angka, check;
    printf("Enter a number: ");
    scanf("%d", &angka);
    if(angka == 1 && angka == 0){
        printf("Bukan bilangan prima") ;
        exit(0) ;
    }
    check = prima(angka, angka / 2);
    if (check == 1){
        printf("%d bilangan prima\n", angka);
    }else{
        printf("%d bukan bilangan prima\n", angka);
    }
    return 0;
}

int prima(int num, int i){
    if (i == 1){
        return 1;
    }
    else{
       if (num % i == 0){
         return 0;
       }
       else{
         prima(num, i - 1);
       }
    }
}
