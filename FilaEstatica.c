#include <stdio.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int inicio;
    int nroElem;
}FILA;
//criando uma fila
void criar(FILA *f){
    f->inicio = 0;
    f->nroElem = 0;
}
//retornando o numero de elementos
int tamanho(FILA *f){
    return f->nroElem;
}
//imprimir os elementos da fila
void imprimir(FILA *f){
    printf("Fila: \" ");
    int i = f->inicio;
    int temp;
    for(temp = 0; temp < f->nroElem; temp++){
        printf("%i ", f->A[i].chave);
        i = (i + 1) % MAX;
    }
    printf("\"\n");
}
//inserindo um elemento na fila
int inserir(FILA *f, REGISTRO reg){
    if(f->nroElem >= MAX){
        printf("\nLimite alcançado! não foi possivel inserir!");
        return 0;
    }
    int posicao = (f->inicio + f->nroElem) % MAX;
    f->A[posicao] = reg;
    f->nroElem++;
    return 1;
}
//excluindo elementos da fila
int excluir(FILA *f, REGISTRO *reg){
    if(f->nroElem == 0){
        printf("\nFila vazia !");
        return 0;
    }
    f->inicio = (f->inicio+1) % MAX;
    return 1;
}
//reiniciando a fila
void reiniciar(FILA *f){
    criar(f);
}
int main(){
    FILA f;
    criar(&f);
    REGISTRO reg;
    int op;

    do{
        printf("\n  1-Inserir");
        printf("\n  2-Excluir");
        printf("\n  3-Listar");
        printf("\n  4-Tamanho");
        printf("\n  5-Esvaziar");
        printf("\n 27-Sair\n:");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d", &reg.chave);
                inserir(&f, reg);
                printf("\nElemento inserido com sucesso !");
                break;
            case 2:
                excluir(&f, &reg);
                printf("\nPrimeiro elemento da fila excluido!");
                break;
            case 3:
                imprimir(&f);
                break;
            case 4:
                printf("\n Tamanho da fila: %d", tamanho(&f));
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
