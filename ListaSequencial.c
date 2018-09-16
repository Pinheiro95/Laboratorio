#include <stdio.h>
#include <string.h>

#define MAX 30/*definindo o maximo de elementos*/
typedef int telem;//tipo da base dos elementos da lista

typedef struct LISTA{
    telem V[MAX];//vetor que contem a lista
    int n;//posicão do ultimo elemento da lista
}tlista;

//criar uma lista vazia
void criar(tlista *L){
    L->n = 0;
}
//verificar se uma lista esta vazia
int vazia(tlista *L){
    return(L->n == 0);
}
//verificar se uma lista esta cheia
int cheia(tlista *L){
    return(L->n == MAX);
}
//obter o tamanho da lista
int tamanho(tlista *L){
    return (L->n);
}
//obter i-esimo elemento de uma lista
int elemento(tlista L, int pos, telem *dado){
    //o parametro dado ira receber o elemento encontrado
    //retorna 0 se a posição for invalida. Caso contrario, retorna 1
    if((pos > L.n) || (pos <= 0)){
        printf("\nPosição invalida !");
        return 0;
    }
    *dado = L.V[pos-1];
    printf("\nO dado contido em %d é: %d", pos, *dado);
    return 1;
}
//pesquisar um dado elemento, retornando a sua posição
int posicao(tlista L, telem dado){
    //retorna a posicao do elemento ou 0 caso não seja encontrado
    int i; 
    for(i=0; i <= L.n; i++){
        if(L.V[i] == dado){
            return i;
        }
    }
    return 0;
}
//inserindo um elemento em uma determinada posição
int inserir(tlista *L, int pos, telem dado){
    int i;
    if(pos >= L->n){
        L->V[L->n] = dado;
        L->n = L->n+1;
        printf("\nelemento adicionado com sucesso!");
        return 1;
    }else{
        for(i = L->n; i >= pos; i--){
            L->V[i] = L->V[i-1];
        }
    }
    L->V[pos] = dado;
    L->n = L->n+1;
    printf("\nelemento adicionado com sucesso!");
    return 1;
}
//remover um elemento de uma determinada posição da lista
int remover(tlista *L, int pos, telem *dado){
    //O parametro dado ira receber o elemento encontrado
    //retorna 0 se a posição for invalida. caso contrario retorna 1;
    *dado = L->V[pos-1];
    for(int i=pos; i <= (L->n)-1; i++){
        L->V[i-1] = L->V[i];
    } 
    (L->n)--;
    return 1;
}
void listar(tlista *L){
    int i;
    telem dado;
    for(i=0;i < L->n; i++){
        dado = L->V[i];
        printf("Dado: %d\n", dado);
    }
}
//função mais eficiente para excluir um elemento da lista
/*
void remover(tlista *L, int pos){
     int i;
    for(i = pos; i < L->n + 1; i++){
		L->V[i] = L->V[i+1];
	}
	L->n = L->n-1;
}*/
int reinicia(tlista *L){
    if(vazia(L)){
        printf("\nLista já está vazia");
        return 0;
    }
    criar(L);
    return 1;
}
int main(int argc, char const *argv[])
{
    tlista L;
    criar(&L);
    telem dado;
    int pos;
    int op;  

    do{
        printf("    1 - Exibir lista\n");
        printf("    2 - Inserir\n");
        printf("    3 - Remover\n");
        printf("    4 - Exibir elemento\n");
        printf("    5 - Exibir posicao\n");
        printf("    6 - Esvaziar\n");
        printf("ESC - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
            if (vazia(&L)) {
                printf("\nLista vazia");
                break;
            }
                listar(&L);
                printf("\n");
            break;
            case 2:
            if (cheia(&L)) {
                printf("Lista cheia");
                break;
            }
            printf("\nDigite o elemento que deseja adicionar: ");
            scanf("%d", &dado);
            printf("\nDigite a posição que deseja inserir o elemento: ");
            scanf("%d", &pos);
            inserir(&L,pos,dado);
            break;
            case 3:
            if (vazia(&L)) {
                printf("\nLista vazia");
                break;
            }
            printf("\nDigite a posição que deseja excluir: ");
            scanf("%d", &pos);
            printf("\nDigite o dado que deseja excluir: ");
            scanf("%d", &dado);
            remover(&L, pos, &dado);
            printf("\nPosição %d excluida com sucesso!", pos);
            break;
            case 4:
            if(vazia(&L)){
                printf("\nLista vazia");
            }
            printf("\nDigite a posicao que deseja encontrar: ");
            scanf("%d", &pos);
            elemento(L, pos, &dado);
            break;
            case 5:
            if(vazia(&L)){
                printf("\nLista vazia");
            }
            printf("\nDigite o dado que deseja encontrar: ");
            scanf("%d", &dado);
            printf("\nA posição de %d é: %d", dado, posicao(L, dado));
            break;
            case 6:
            reinicia(&L);
            printf("\nLista esvaziada com sucesso!");
            break;
            case !27:
                printf("Sessão encerrada !");
            break;
        }
    }while(op != 27);
    
    return 0;
}


