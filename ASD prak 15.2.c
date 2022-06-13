#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10

typedef int data;
typedef struct
{
    data isi_q[max];
    int count;
} stack;
stack s;
int n;
typedef int item;
typedef struct
{
    item isi_q[max];
    int front, rear, count;
} queue;
queue que;

void inisialisasi_stack();
void push(int);
int pop();
int empty();
int full();

void inisialisasi_queue();
void tampilkan();
int penuh();
int kosong();
void enqueue(int);
int dequeue();
int cari_q(int);

void asiggn();
void tampil();
void tampil_cari();
void djikstra();

int q[max][max], r[max], tq[max], x, y;

void main()
{
    char jawab;
    inisialisasi_stack();
    inisialisasi_queue();

    asiggn();
    do
    {
        puts("Matrix Asal : ");
        tampil();
        printf("Posisi Awal : ");
        scanf("%d", &x);
        printf("Posisi Tujuan : ");
        scanf("%d", &y);
        djikstra();
        tampil();
        tampil_cari();
        printf("\nSearch Lagi (y/n) : ");
        fflush(stdin);
        scanf("%c", &jawab);
    } while (jawab == 'y' || jawab == 'Y');
    exit(0);
}

void asiggn()
{
    int i, j;
    printf("Masukkan jumlah Node : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Masukkan nilai q[%d][%d] : ", i, j);
            scanf("%d", &q[i][j]);
            if (q[i][j] == 0)
                q[i][j] = max;
        }
    }
    tq[0] = 0;
    tq[1] = max;
    tq[2] = max;
    tq[3] = max;
    tq[4] = max;
    r[0] = -1;
    r[1] = -1;
    r[2] = -1;
    r[3] = -1;
    r[4] = -1;
    printf("\n");
}

void tampil()
{
    int i, j;
    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (q[i][j] != max)
                printf("%d ", q[i][j]);
            else
                printf("M ");
        }
        puts(" ");
    }
    puts(" ");

    for (i = 0; i < n; i++)
    {
        if (tq[i] != max)
            printf("%d ", tq[i]);
        else
            printf("M ");
    }
    puts(" ");
    for (i = 0; i < n; i++)
    {
        if (r[i] != -1)
            printf("%d ", r[i]);
        else
            printf("M ");
    }
    puts(" ");
}

void djikstra()
{
    int cn, i;
    x -= 1;
    y -= 1;
    enqueue(x);
    while (!kosong())
    {
        cn = dequeue();
        for (i = 0; i < n; i++)
        {
            if (q[cn][i] != max)
            {
                if (q[cn][i] + tq[cn] < tq[i])
                {
                    tq[i] = q[cn][i] + tq[cn];
                    r[i] = cn;
                    if (i != x && i != y && cari_q(i))
                    {
                        enqueue(i);
                    }
                }
            }
        }
    }
}

int cari_q(int i)
{
    int j = que.front;
    do
    {
        if (que.isi_q[j] == i)
        {
            return 0;
        }
        j = (j + 1) % max;
    } while (j != que.rear);
    return 1;
}

void tampil_cari()
{
    int i;
    printf("\n");
    for (i = y; y > x; i--)
    {
        if (r[i] != 0)
            push(r[i]);
        else
            break;
    }
    printf("Rute Terpendek : %d - ", x + 1);
    while (!empty())
    {
        printf("%d - ", pop() + 1);
    }
    printf("%d\n", y + 1);
    printf("Bobot Adalah : %d \n", tq[y]);
}

void inisialisasi_stack()
{
    s.count = 0;
}

void push(int x)
{
    if (full())
    {
        puts("Stack Penuh");
    }
    else
    {
        s.isi_q[s.count] = x;
        s.count++;
    }
}

int pop()
{
    if (full())
    {
        puts("Stack Kosong");
        return 0;
    }
    else
    {
        s.count--;
        return s.isi_q[s.count];
    }
}

int empty()
{
    return s.count == 0 ? 1 : 0;
}

int full()
{
    return s.count == max ? 1 : 0;
}

void inisialisasi_queue()
{
    que.front = que.rear = que.count = 0;
}

int penuh()
{
    return que.count == max ? 1 : 0;
}

int kosong()
{
    return que.count == 0 ? 1 : 0;
}

void enqueue(int x)
{
    que.isi_q[que.rear] = x;
    que.rear = (que.rear + 1) % max;
    que.count++;
}

int dequeue()
{
    int x = que.isi_q[que.front];
    que.front = (que.front + 1) % max;
    que.count--;
    return x;
}
