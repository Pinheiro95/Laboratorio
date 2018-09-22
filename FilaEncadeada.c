#include <stdio.h>
#include <malloc.h>

typedef int telem;

typedef struct no{
    telem dado;
    struct no* prox;
}tno;

typedef struct fila{
    tno* inicio;
    tno* final;
}tfila;

//cirar fila vazia
void criar(tfila *f){
    f->inicio = f->final = NULL;
}
//testar se a fila esta vazia
int vazia(tfila f){
    return (f.inicio == NULL && f.final == NULL);
}
//exibir primeiro elemento da fila
int primeiro(tfila f, telem *dado){
    if(vazia(f)){
        return 0;
    }
    *dado = (f.inicio)->dado;
    printf("\n O primeiro elemento da fila é: %d", *dado);
    return 1;
}
//insere elemento na fila
int inserir(tfila *f, telem dado){
    tno *novo;
    novo = (tno*) malloc(sizeof(tno));

    if(novo == NULL){
        return 0;
    }
    novo->dado = dado;
    novo->prox = NULL;

    if(vazia(*f)){
        f->inicio = novo;
    }else{
        (f->final)->prox = novo;
    }
    f->final = novo;
    return 1;
}
//remove elementos da fila
int remover(tfila *f, telem *dado){
    tno *aux;
    if(vazia(*f)){
        return 0;
    }
    primeiro(*f, dado);
    if(f->inicio == f->final){
        f->final = NULL;
    }
    aux = f->inicio;
    f->inicio = (f->inicio)->prox;
    free(aux);
    return 1;
}
//listar elementos
void imprimir(tfila f){
    tno* novo = f.inicio;
    printf("\nFila: \" ");
    while(novo != NULL){
        printf("%d ", novo->dado);
        novo = novo->prox;
    }
    printf("\"\n");
}
//reiniciar a fila
 void reiniciar(tfila *f){
    tno* novo = f->inicio;
    while(novo != NULL){
        tno* apagar = novo;
        novo = novo->dado;
        free(apagar);
    }
    f->inicio = NULL;
    f->final = -NULL;
}
int main(){
    tfila f;
    criar(&f);
    telem dado;
    int op;

    do{
        printf("\n  1-Inserir");
        printf("\n  2-Excluir");
        printf("\n  3-Exibir primeiro elemento");
        printf("\n  4-Exibir fila");
        printf("\n  5-Esvaziar");
        printf("\n 27-Sair\n:");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d", &dado);
                inserir(&f, dado);
                printf("\nElemento inserido com sucesso !");
                break;
            case 2:
                remover(&f, &dado);
                printf("\nPrimeiro elemento da fila excluido!");
                break;
            case 3:
                primeiro(f, &dado);
                break;
            case 4:
                imprimir(f);
                break;
            case 5:
                reiniciar(&f);
                printf("\nReiniciada com sucesso !");
                break;
            case 27:
                printf("Sessão encerrada !");
                break;
        }
    }while(op != 27);
    return 0;
}   
