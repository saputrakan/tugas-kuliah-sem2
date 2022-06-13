#include <stdio.h>
#include <stdlib.h>
#define M 100
#define A 500

typedef int typedata;
typedef struct{
    typedata data[M];
    int count;
}stack;

void awal();
void tampil();
void warshall();
void warshall_beban();
void warshall_jalur();
void warshall_rute();
void cari_rute();
void inisialisasi_stack(stack *s);
void push_stack(typedata x, stack *s);
int penuh_stack(stack *s);
typedata pop_stack(stack *s);
int kosong_stack(stack *s);
void input();

typedata node;
typedata Q[A][A];
typedata P[A][A];
typedata R[A][A];


int main()
{
    char jwb;
    awal();
    warshall();
    do
    {
        cari_rute();
        printf("\nLagi? ");
        scanf("%c", &jwb); fflush(stdin);
    }while(jwb == 'Y' || jwb == 'y');
    return 0;
}

void awal()
{
    puts("Graph - WARSHALL");
    puts("Matriks Q-P-R asal");
    input();
    tampil();
}

void tampil()
{
    int i, j;
    puts("Matriks Beban (Q)");
    for(i=0; i<node; i++)
    {
        for(j=0; j<node; j++)
        {
            if(Q[i][j] == M)
                printf("M ");
            else
                printf("%d ", Q[i][j]);
        }
        puts("");
    }
    puts("");
    puts("Matriks Jalur (P)");
    for(i=0; i<node; i++)
    {
        for(j=0; j<node; j++)
        {
            if(P[i][j] == M)
                printf("M ");
            else
                printf("%d ", P[i][j]);
        }
        puts("");
    }
    puts("");
    puts("Matriks Rute (R)");
    for(i=0; i<node; i++)
    {
        for(j=0; j<node; j++)
        {
            if(R[i][j] == M)
                printf("M ");
            else
                printf("%d ", R[i][j]);
        }
        puts("");
    }
}

void warshall()
{
    puts("matriks Q-P-R baru");
    warshall_beban();
    warshall_jalur();
    warshall_rute();
    tampil();
}

void warshall_beban()
{
    int i, j, k;
    for(k=0; k<node; k++)
    {
        for(i=0; i<node; i++)
        {
            for(j=0; j<node; j++)
            {
                if(Q[i][k] + Q[k][j] < Q[i][j]){
                    Q[i][j] = Q[i][k] + Q[k][j];
                }
            }
        }
    }
}

void warshall_jalur()
{
    int i, j, k;
    for(k=0; k<node; k++)
    {
        for(i=0; i<node; i++)
        {
            for(j=0; j<node; j++)
            {
                P[i][j] = P[i][j] || (P[i][k] && P[k][j]);
            }
        }
    }
}

void warshall_rute()
{
    int i, j, k;
//    puts("tes7");
    for(k=0; k<node; k++)
    {
//        puts("tes6");
        for(i=0; i<node; i++)
        {
//            puts("tes5");
            for(j=0; j<node; j++)
            {
//                puts("tes4");
                if((Q[i][k] + Q[k][j]) <= Q[i][j]){
//                    puts("tes1");
                    if(R[k][j] == 1){
                        R[i][j] = k+1;
//                        puts("tes2");
                    }else{
                        R[i][j] = R[k][j];
//                        puts("tes3");
                    }
                }
            }
        }
    }
}

void cari_rute()
{
    int i,j;
    typedata asal, tujuan, beban;
    stack tampung;
    printf("\nMasukkan asal : ");
    scanf("%d", &asal);
    fflush(stdin);
    printf("Masukkan tujuan : ");
    scanf("%d", &tujuan);
    puts("");
    fflush(stdin);
    inisialisasi_stack(&tampung);
    i=asal-1;
    push_stack(tujuan, &tampung);
    j=node;
    do
    {
        j--;
        push_stack(R[i][j], &tampung);
    }while(R[i][j]!=asal);
    printf("Rute terpendek adalah ");
    while(!kosong_stack(&tampung))
    {
        if(tampung.count != 1)
            printf("%d - ", pop_stack(&tampung));
        else
            printf("%d ", pop_stack(&tampung));
    }
    puts("");
    beban = Q[asal-1][tujuan-1];
    for(i=0; i<node; i++)
    {
        if(Q[asal-1][i] + Q[i][tujuan-1] <= Q[asal-1][tujuan-1]){
            beban = Q[asal-1][i] + Q[i][tujuan-1];
        }
    }
    printf("Beban = %d", beban);
}

void inisialisasi_stack(stack *s)
{
    s->count = 0;
}

void push_stack(typedata x, stack *s)
{
    if(!penuh_stack(s)){
        s->data[s->count] = x;
        s->count++;
    }else
        puts("stack penuh");
}

int penuh_stack(stack *s)
{
    if(s->count == M)
        return 1;
    else
        return 0;
}

typedata pop_stack(stack *s)
{
    if(kosong_stack(s)){
        puts("stack kosong");
        return 0;
    }else{
        s->count--;
        return s->data[s->count];
    }
}

int kosong_stack(stack *s)
{
    if(s->count == 0)
        return 1;
    else
        return 0;
}

void input()
{
    int i, j;
    printf("Mau berapa node : ");
    scanf("%d", &node); fflush(stdin);
    puts("\nInput Q (Beban)");
    for(i=0; i<node; i++)
    {
        for(j=0; j<node; j++)
        {
            printf("Q[%d][%d] = ", i, j);
            scanf("%d", &Q[i][j]);
            fflush(stdin);
            if(Q[i][j] == 0)
                Q[i][j] = M;
        }
    }
    puts("\nInput P (Jalur)");
    for(i=0; i<node; i++)
    {
        for(j=0; j<node; j++)
        {
            printf("P[%d][%d] = ", i, j);
            scanf("%d", &P[i][j]);
            fflush(stdin);
        }
    }
    puts("\nInput R (Rute)");
    for(i=0; i<node; i++)
    {
        for(j=0; j<node; j++)
        {
            printf("R[%d][%d] = ", i, j);
            scanf("%d", &R[i][j]);
            fflush(stdin);
            if(R[i][j] == 0)
                R[i][j] = M;
        }
    }
}
