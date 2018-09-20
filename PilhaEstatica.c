#include <stdlib.h>
#include <stdio.h>

#define MAX 10

typedef int telem;

typedef struct {
    telem V[MAX];
    int topo;
}tpilha;
//criar uma pilha vazia
void criar(tpilha *p){
    p->topo = -1;
}
//testar se a pilha esta vazia
int vazia(tpilha *p){
    return(p->topo == -1);
}
//obter o elemento que esta no topo da pilha sem remover
int elemtopo(tpilha p, telem *valor){
    if(vazia(&p)){
        printf("Pilha vazia");
        return 0;
    }
    printf("O elemento que esta no topo da lista e: %d", *valor = p.V[p.topo]);
    return 1;
}
//inserir um novo elemento no topo da lista EMPILHAR
int push (tpilha *p, telem valor){
    if(p->topo == MAX -1){
        return 0;
    }
    p->V[++p->topo] = valor;
    printf("\nElemento inserido com sucesso !");
    return 1;
}
//remove um elemento do topo da pilha DESEMPILHAR
int pop(tpilha *p, telem *valor){
    if(vazia(p)){
        return 0;
    }
    *valor = p->V[p->topo--];
    printf("\nElemento %d removido com sucesso!", *valor);
    return 1;
}
//reiniciar a pilha
void reiniciar(tpilha *p){
    p->topo = -1;
}
void listar(tpilha p){
    int i;
//percorrendo os elementos e imprimindo a chave começando do topo para baixo
    for(i=p.topo; i>=0; i--){
        printf("%i ", p.V[i]);
    }
    printf("\"\n");
}
int main(){

    tpilha p;
    telem valor;
    criar(&p);
    int op;

    /*
    if(vazia(&p)){
        printf("Pilha vazia criada com sucesso !");

    push(&p, valor);

    elemtopo(p, &valor);

    pop(&p, &valor);
*/
    do{
        printf("    1 - Empilhar\n");
        printf("    2 - Desempilhar\n");
        printf("    3 - Exibir elemento no topo\n");
        printf("    4 - Exibir pilha\n");
        printf("    5 - Esvaziar pilha\n");
        printf("ESC - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\nDigite o valor que deseja adicionar a pilha: ");
                scanf("%d", &valor);
                push(&p, valor);
                printf("\n");
            break;
            case 2:
                if (vazia(&p)) {
                    printf("\nPilha vazia");
                break;
                }
                pop(&p, &valor);
            break;
            case 3:
                if (vazia(&p)) {
                    printf("\nPilha vazia");
                break;
                }
                elemtopo(p, &valor);
            break;
            case 4:
                if(vazia(&p)){
                    printf("\nPilha vazia");
                }
                listar(p);
            break;
            case 5:
                reiniciar(&p);
                printf("\nPilha esvaziada");
            break;
            case !27:
                printf("Sess�o encerrada !");
            break;
        }
    }while(op != 27);

    return 1;
}



