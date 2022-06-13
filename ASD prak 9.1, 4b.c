#include <stdio.h>
#include <stdlib.h>

long int faktorial(int);
int main() {
    int angka;
    printf("Masukkan Angka: ");
    scanf("%d", &angka);
    printf("Hasil faktorialnya = %ld", faktorial(angka));
    return 0;
}

long int faktorial(int angka) {
    if (angka > 1)
        return angka * faktorial(angka - 1);
    else
        return 1;
}
