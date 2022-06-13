#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int menu() ;
void pilihan(int) ;
void input(int *) ;
void fibonacciIterasi(int) ;
int fibonacciRekursi(int) ;

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
    printf("\nMenu Fibonacci\n") ;
    printf("1. Iterasi\n") ;
    printf("2. Rekursi\n") ;
    printf("3. Keluar\n") ;
    printf("Masukkan Pilihan: ") ;
    scanf("%d", &pil) ;
    fflush(stdin) ;
    return pil ;
}

void input(int *batas){
    printf("Masukkan Batas : ") ;
    scanf("%d", batas) ;
    fflush(stdin) ;
}

void pilihan(int pil){
    int batas, i ;
    double time_taken = 0.0 ;
	clock_t start, end ;
    if(pil == 3){
        exit(0) ;
    }else{
        input(&batas) ;
        if(pil == 1){
            start = clock() ;
            fibonacciIterasi(batas) ;
            sleep(2) ;
            end = clock() ;
            time_taken += (double)(end - start)/CLOCKS_PER_SEC;
            printf("\nWaktu: %f\n", time_taken);
        }else if(pil == 2){
            if(batas == 1){
                printf("%d", 0) ;
            }else{
                puts("") ;
                start = clock() ;
                for(i = 0; i < batas; i++){
                    printf("%d ", fibonacciRekursi(i));
                }
                sleep(2) ;
                end = clock() ;
                time_taken += (double)(end - start)/CLOCKS_PER_SEC;
                printf("\nWaktu: %f\n", time_taken);
            }
        }
    }
}

void fibonacciIterasi(int batas){
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

int fibonacciRekursi(int i){
    if(i == 0){
        return 0 ;
    }else if(i == 1){
        return 1 ;
    }else{
        return(fibonacciRekursi(i - 1) + fibonacciRekursi(i - 2)) ;
    }
}
