#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char typeInfo ;
typedef struct node tree ;
struct node{
    typeInfo info ;
    tree *kiri, *kanan ;
};

typeInfo inp ;
char data[50] ;
tree *neew, *root = NULL;
void input() ;
void bentuk(typeInfo) ;
void sisip() ;
int menu_kunjungan() ;
void preorder(tree *) ;
void postorder(tree *) ;
void inorder(tree *) ;
void pilihanKunjungan(int) ;

int main()
{
    int i ;
    char jwb ;
    input() ;
    fflush(stdin) ;
    do{
        pilihanKunjungan(menu_kunjungan()) ;
        printf("\nMencoba metode yang lain? (Y/T): ") ;
        scanf("%c", &jwb) ;
        fflush(stdin) ;
    }while(jwb == 'y' || jwb == 'Y') ;
    return 0;
}

void input(){
    int i = 0;
    printf("Ketikkan sekumpulan data/infonya, pisahkan dengan spasi: ") ;
    gets(data) ;
    fflush(stdin) ;
    while(i < strlen(data)){
        if(data[i] == ' '){
            i++ ;
            continue ;
        }
        bentuk(data[i]) ;
        sisip() ;
        i++ ;
    }

}

void sisip(){
    int stop = 0 ;
    tree *p, *q ;
    if(stop == 0){
        if(root == NULL){
            root = neew ;
            stop = 1 ;
        }else{
            p = root ;
            q = root ;
            while(q != NULL && neew->info != p->info){
                p = q ;
                if(neew->info < p->info){
                    q = p->kiri ;
                }else{
                    q = p->kanan ;
                }
            }
            if(neew->info == p->info){
                stop = 1 ;
            }else{
                if(neew->info < p->info){
                    p->kiri = neew ;
                }else{
                    p->kanan = neew ;
                }
            }
        }
    }
}

void bentuk(typeInfo dat){
    neew = (tree*)malloc(sizeof(tree)) ;
    if(neew == NULL){
        puts("Alokasi Gagal") ;
        exit(0) ;
    }else{
        neew->kiri = NULL ;
        neew->info = dat ;
        neew->kanan = NULL ;
    }
}

int menu_kunjungan(){
    int pil ;
    printf("Pilih Penelusuran Tree\n") ;
    printf("1. Preorder\n") ;
    printf("2. Postorder\n") ;
    printf("3. Inorder\n") ;
    printf("Pilihan anda: ") ;
    scanf("%d", &pil) ;
    fflush(stdin) ;
    return pil ;
}

void preorder(tree *root){
    if(root != NULL){
        printf("%c ", root->info) ;
        preorder(root->kiri) ;
        preorder(root->kanan) ;
    }
}

void postorder(tree *root){
    if(root != NULL){
        postorder(root->kiri) ;
        postorder(root->kanan) ;
        printf("%c ", root->info) ;
    }
}

void inorder(tree *root){
    if(root != NULL){
        inorder(root->kiri) ;
        printf("%c ", root->info) ;
        inorder(root->kanan) ;
    }
}

void pilihanKunjungan(int pil){
    if(pil == 1){
        printf("\nHasil kunjungan secara PREORDER adalah:\n") ;
        preorder(root) ;
    }else if(pil == 2){
        printf("\nHasil kunjungan secara INORDER adalah:\n") ;
        inorder(root) ;
    }else{
        printf("\nHasil kunjungan secara POSTORDER adalah:\n") ;
        postorder(root) ;
    }
}

