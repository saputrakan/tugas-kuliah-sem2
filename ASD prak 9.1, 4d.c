#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int menu() ;
void pilihan(int) ;
void input(int *) ;
void faktorialIterasi(int) ;
long int faktorialRekursi(int) ;
long int faktorialRekursiTail(int, int) ;

int main()
{
    int pil ;
    do{
        pil = menu();
        pilihan(pil) ;
    }while(1) ;
    return 0;
}

int menu(){
    int pil ;
    printf("\nMenu Faktorial\n") ;
    printf("1. Iterasi\n") ;
    printf("2. Rekursi\n") ;
    printf("3. Rekursi Tail\n") ;
    printf("4. Keluar\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &pil) ;
    fflush(stdin) ;
    return pil ;
}

void input(int *angka){
    printf("Masukkan angka : ") ;
    scanf("%d",angka) ;
    fflush(stdin) ;
}

void pilihan(int pil){
    int angka ;
    double time_taken = 0.0 ;
	clock_t start, end ;
    if(pil == 4){
        exit(0) ;
    }else{
        input(&angka) ;
        if(pil == 1){
            start = clock() ;
            faktorialIterasi(angka) ;
            sleep(2) ;
            end = clock() ;
            time_taken += (double)(end - start)/CLOCKS_PER_SEC;
            printf("\nWaktu: %f\n", time_taken);
        }else if(pil == 2){
            start = clock() ;
            printf("\nHasil faktorialnya = %ld\n", faktorialRekursi(angka));
            sleep(2) ;
            end = clock() ;
            time_taken += (double)(end - start)/CLOCKS_PER_SEC;
            printf("\nWaktu: %f\n", time_taken);
        }else if(pil == 3){
            start = clock() ;
            printf("\nHasil faktorialnya = %ld\n", faktorialRekursiTail(angka, 1));
            sleep(2) ;
            end = clock() ;
            time_taken += (double)(end - start)/CLOCKS_PER_SEC;
            printf("\nWaktu: %f\n", time_taken);
        }
    }
}

void faktorialIterasi(int angka){
    int i ;
    int total = 1 ;
    for(i = angka; i > 0; i--){
        total = total * i ;
    }
    printf("\nHasil Faktorialnya %d\n", total) ;
}

long int faktorialRekursi(int angka){
    if (angka > 1)
        return angka * faktorialRekursi(angka - 1);
    else
        return 1;
}

long int faktorialRekursiTail(int angka, int total) {
    if(angka == 1)
        return total ;
    else
        faktorialRekursiTail(angka - 1,  angka * total) ;
}


