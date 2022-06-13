#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef char typedata;
typedef struct node tree;
struct node{
    typedata data;
    tree *left;
    tree *right;
};

typedef struct{
    tree *data[MAX];
    int count;
}stack;

void input(typedata []);
tree *buatTree(typedata []);
int kosong(stack *s);
int penuh(stack *s);
void push(typedata x, stack *s);
tree *pop(stack *);
void preorder(tree *pointer);
void inorder(tree *root);
void postorder(tree *root);
tree *newNode(typedata x);
int priority(typedata x);
void tampil(tree *root);


int main()
{
    typedata inputan[MAX];
    input(inputan);
    tree *root = buatTree(inputan);
    tampil(root);
    return 0;
}

void input(typedata inputan[])
{
    printf("Masukkan data = ");
    scanf("%[^\n]s", inputan);
}

void inisialisasi(stack *s)
{
    s->count = 0;
}

tree *buatTree(typedata inputan[])
{
    int i;
    tree *temp, *left, *right;
    stack st_operan, st_operator;
    inisialisasi(&st_operan);
    inisialisasi(&st_operator);
    for(i=0; i<strlen(inputan); i++)
    {
        if(inputan[i] == '('){
            push(inputan[i], &st_operator);
        }else if((inputan[i] >= '0' && inputan[i] <= '9')){
            push(inputan[i], &st_operan);
        }else if(inputan[i] == '-' || inputan[i] == '+' || inputan[i] == '/' || inputan[i] == '*' || inputan[i] == '^'){
            push(inputan[i], &st_operator);
        }else if(inputan[i] == ')'){
            temp = pop(&st_operator);
            right = pop(&st_operan);
            left = pop(&st_operan);
            if(temp->data != '('){
                temp->left = left;
                temp->right = right;
                st_operan.data[st_operan.count] = temp;
                st_operan.count++;
            }
            pop(&st_operator);
        }
    }
    while(!kosong(&st_operator)){
        temp = pop(&st_operator);
        right = pop(&st_operan);
        left = pop(&st_operan);
        temp->left = left;
        temp->right = right;
        st_operan.data[st_operan.count] = temp;
        st_operan.count++;
    }
    return temp;
}

int kosong(stack *s)
{
    if(s->count == 0)
        return 1;
    else
        return 0;
}

int penuh(stack *s)
{
    if(s->count == MAX)
        return 1;
    else
        return 0;
}

void push(typedata x, stack *s)
{
    if(penuh(s)){
        printf("Data penuh\n");
    }else{
        s->data[s->count] = newNode(x);
        s->count++;
    }
}

tree *pop(stack *s)
{
    if(kosong(s)){
        printf("Data Kosong\n\n");
        return NULL;
    }else{
        s->count--;
        return s->data[s->count];
    }
}

void preorder(tree *root)
{
    if(root != NULL){
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(tree *root)
{
    if(root != NULL){
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(tree *root)
{
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

tree *newNode(typedata x)
{
    tree *p = (tree *) malloc(sizeof(tree));
    if(p == NULL){
        puts("Alokasi Gagal") ;
        exit(0) ;
    }else{
        p->data = x;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

void tampil(tree *root)
{
    printf("PREORDER = ");
    preorder(root);
    puts("");
    printf("INORDER = ");
    inorder(root);
    puts("");
    printf("POSTORDER = ");
    postorder(root);
    puts("");
}
