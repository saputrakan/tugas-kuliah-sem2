#include <stdio.h>
#include <stdlib.h>

void input(int *, int *) ;
long int factorial(int);
long kombinasi(int, int);
long permutasi(int, int);

int main(){
    int n, r;
    input(&n, &r) ;
    printf("Kombinasi: %ld\n", kombinasi(n, r)) ;
    printf("Permutasi: %ld\n", permutasi(n, r)) ;
    return 0;
}

void input(int *n, int *r){
   printf("Masukkan Nilai n: ");
   scanf("%d",n);
   printf("Masukkan Nilai r: ");
   scanf("%d", r);
}

long kombinasi(int n, int r) {
   long result;
   result = factorial(n)/(factorial(r)*factorial(n-r));
   return result;
}

long permutasi(int n, int r) {
   long result;
   result = factorial(n)/factorial(n-r);
   return result;
}

long int factorial(int n) {
    if (n >= 1)
        return n * factorial(n - 1);
    else
        return 1;
}
