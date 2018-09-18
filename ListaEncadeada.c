#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//definindo um datanode
typedef struct datanode{
    int id;//carrega a identificação do nó
    //aqui poderia ter uma outra estrutura como uma pessoa
}DataNode;

//defininido o nó
typedef struct node{
    DataNode data; //definindo o dado
    struct node* next;//referencia para o proximo nó
}Node;


//definindo a lista
typedef struct list{
    int size;//tamanho da lista
    Node* head;//nó cabeça
}List;

//headers
List* createList();
void push(List* list, DataNode data);
void printlist(List* list);
void pop(List* list);
bool isEmpty(List* list);
Node* atPos(List* list, int index);
int indexOf(List* list, Node* node);
void erase(List* list, int index);
void insert(List* list, DataNode data,int index);
void xchgNodes(List* list, Node* nodeA, Node* nodeB);
Node* min(List* list, int index);
Node* max(List* list, int index);
void incSort(List* list);
void decSort(List* list);

//inicializa a lista e retorna uma referencia para a lista
List* createList(){
    List* list = (List*) malloc(sizeof(List));//criar um ponteiro para a lista e aloca o espaço de memoria 
    
//como a lista esta vazia o tamanho é 0 e a cabeça aponta para NULL
    list->size=0;
    list->head =NULL;
//retornando a lista criada
    return list;
}

//inserir elementos no começo da lista
void push(List* list, DataNode data){
    //criando o nó e alocando a memoria. Esse vai ser o nó cabeça
    Node* node = (Node*) malloc(sizeof(Node));

    node->data = data;
    node->next = list->head;
    list->head =node;
    list->size++;
}

//imprime a lista
void printlist(List* list){

//testando se a lista esta vazia
    if(isEmpty(list)){
    printf("Lista vazia\n");
    return;
    }

//percorrendo a lista sem alterar a lista. Precisamos de um nó apontador(corredor) que vai apontar para cada nó da lista e mandar imprimir, quando ele apontar para NULL significa que chegou a fim da lista
    
    //criando o nó apontador que vai começar apontando para a cabeça da lista
    Node* pointer = list->head;

    //enquanto o nó apontador não chega em NUll continue imprimindo
    while(pointer != NULL){
        printf("%d", pointer->data.id);
        //indo para o proximo nó
        pointer = pointer->next;
        printf("\n");
    }
    
}

//verifica se a lista esta vazia
bool isEmpty (List* list){
    return(list->size == 0);
}

//remove o primeiro nó da lista
void pop(List* list){
//criando um ponteiro auxiliar que aponta para a cabeca da lista (para não perdermos a referencia do nó que será removido assim podendo liberar a memoria que ele alocou)
    if(!isEmpty(list)){
//ponteiro auxiliar que aponta para a cabeça
        Node* pointer = list->head;
//A cabeça aponta para o elemento sucessor do nó que será excluido
        list->head = pointer->next;
//liberando o espaço de memoria que estava alocado para o antigo nó cabeça
        free(pointer);
//decrementando o tamanho da lista
        list->size--;
    }
}

//retornando um nó a partir da sua posição
Node* atPos(List* list, int index){
    //verificar se o indice é valido
    if(index >= 0 && index < list->size){
        //criando nó auxiliar que começa apontando para a cabeça para percorrer a lista até achar a posição que se deseja acessar
        Node* node = list->head;
        int i;
        for(i=0; i<index; i++){
            node = node->next;
        }
//retornando a posição desejada
        return node;
    }
    return NULL;
}
//retorna uma posição de um nó
int indexOf(List* list, Node* node){
    if(node!= NULL){
    //criando um nó auxiliar para percorrer a lista que começa apontando para a cabeça
    Node* pointer = list->head;
    int index = 0;
    while(pointer != node && pointer != NULL){
     pointer = pointer->next;
    index++;
    }
    if(pointer != NULL){
    return index;
    }
    }
    printf("Nó não existe !");
    return -1;
}
//apaga um nó dada o seu indice
void erase(List* list, int index){
    if(index == 0){
        pop(list);
    }else{
//pegando o nó que queremos excluir
        Node* current = atPos(list, index);
        if(current != NULL){
//pegando o nó anterior
            Node* previus = atPos(list, index - 1);
            previus->next = current->next;
            free(current);
            list->size--;
        }
    }
}

//insere um nó em uma determinada posição da lista
void insert(List* list, DataNode data, int index){
    if(index == 0){
        push(list, data);
    }else{
//pegando o nó que se quer inserir
        Node* current = atPos(list, index);
        if(current != NULL){
//pegando o nó anterior
            Node* previus = atPos(list, index - 1);
        //adicionando o novo nó e alocando memoria para ele
            Node* newNode = (Node*) malloc(sizeof(Node));
            newNode->data = data;
//fazendo o nó anterior apontar para o novo e o novo apontar para o proximo (que ocupava o lugar dele antes, logo, jogando o antigo para frente)
            previus->next = newNode;
            newNode->next = current;
            list->size++;
        }
    }
}
//troca dois nos
void xchgNodes(List* list, Node* nodeA, Node* nodeB){
    if(nodeA == nodeB){
        return;
    }
//pegar o indice de um no com a função indexOf
    int indexA = indexOf(list, nodeA);
    int indexB = indexOf(list, nodeB);
//verificando se os nos existem na lista
    if(indexA == -1 || indexB == -1){
        return;
    }
//verificando se o index A é maior que o index B; A vai passar a apontar para onde o B apontava e o b vai apontar para aonde o A apontava

    if(indexA < indexB){
//fazendo A pontar para o local aonde B apontava
        nodeA = nodeB;
//recuperando a referencia do ponteiro de A e fazendo B apontar para ela
        nodeB = atPos(list, indexA);
//atualizando os indices
        indexA = indexB;
        indexB = indexOf(list, nodeB);
    }
//pegando as referencias dos nos anteriores 
    //ponteiro anterior a B
    Node* pb = atPos(list, indexB -1);
    //ponteiro anterior a A. verifica se A é a cabeça da lista
    if(nodeA == list->head){
//trocando a cabeça da lista
        list->head = nodeB;
    }else{
//caso A não seja a cabeça da lista
        //pegando o no anterior a A
        Node* pa = atPos(list, indexA -1);
        //fazendo o no anterior a A apontar para B
        pa->next = nodeB;
    }
    //no anterior a B. Fazendo apontar para A
    pb->next = nodeA;
//alterar para quem o no A e o no B apontam usando um ponteiro auxiliar
    Node* pointer = nodeA->next;
    nodeA->next = nodeB->next;
    nodeB->next = pointer;
}
//retornando o no de menor indice a partir do no passado
Node* min(List* list, int index){
//usando um no auxiliar para guardar a referencia do no passado para a função e percorrer a lista usando a função atPos para acha-lo    
    Node* pointer = atPos(list, index);

//verificando se retornou um ponteiro nulo
    if(pointer != NULL){
//usando um no auxiliar para guardar a referencia do no de id minimo
        Node* minNode = pointer;
//percorrendo a lista e comparando qual o menor
        while(pointer != NULL){
            //comparando o menor ponteiro
            if(pointer->data.id < minNode->data.id){
                minNode = pointer;
            }
            pointer = pointer->next;
        }
            return minNode;
    }
    return NULL;
}
//retornando o no de maior indice a partir do no passado
Node* max(List* list, int index){
//usando um no auxiliar para guardar a referencia do no passado para a função e percorrer a lista usando a função atPos para acha-lo    
    Node* pointer = atPos(list, index);

//verificando se retornou um ponteiro nulo
    if(pointer != NULL){
//usando um no auxiliar para guardar a referencia do no de id maximo
        Node* maxNode = pointer;
//percorrendo a lista e comparando qual o menor
        while(pointer != NULL){
            //comparando o maior ponteiro
            if(pointer->data.id > maxNode->data.id){
                maxNode = pointer;
            }
            pointer = pointer->next;
        }
            return maxNode;
    }
    return NULL;
}
//ordenando a lista em ordem crescente
void incSort(List* list){
    int i;
//ciclo de repetição para que se percorra a lista e enquanto a função Node* min encontre um nó de indice menor que o atual ela use a função xchgNodes para troca-los de lugar, desixando em ordem crescente  
    for(i = 0; i < list->size - 1; i++){
//usando a xchgNodes para trocar os nos de posição; atPos para encontrar os indices; min para definir o menor
        xchgNodes(list, atPos(list, i), min(list, i));
    }

}
//ordenando a lista em ordem decrescente
void decSort(List* list){
    int i;
//ciclo de repetição para que se percorra a lista e enquanto a função Node* max encontre um nó de indice maior que o atual ela use a função xchgNodes para troca-los de lugar, desixando em ordem decrescente  
    for(i = 0; i < list->size - 1; i++){
//usando a xchgNodes para trocar os nos de posição; atPos para encontrar os indices; min para definir o menor
        xchgNodes(list, atPos(list, i), max(list, i));
    }
}
int main(){
    //criando a lista
    List* l = createList();

    //testando a lista recem criada
    //printf("%d: ", l->size);

    //criando um data node
    DataNode data;
    
    //inserindo um elemento no começo da lista
    data.id = 14;
    push(l, data);

    data.id = 6;
    push(l, data);
    
    data.id = 20;
    push(l, data);
    
    data.id = 8;
    push(l, data);
    
    data.id = 9;
    push(l, data);

    //imprimindo a cabeça da lista
    //printf("%d", l->head->data.id);
//imprimindo a lista
    //printlist(l);

//removendo o primeiro elemento da lista
    //pop(l);

//mostrando o conteudo de um nó a partir da sua posição
    //printf("%d", atPos(l,0)->data.id);

//impirmindo a lista
  // printlist(l);
//imprimindo a cabeça da lista
    //printf("\n%d\n", indexOf(l, l->head));
//imprimindo o proximo nó
    //printf("\n%d\n", indexOf(l, l->head->next));
//imprimindo o proximo
    //printf("\n%d\n", indexOf(l, l->head->next->next));
    
    //erase(l, 1);

    //printlist(l);

    //data.id = 11;
//inserindo o nó 11 na posição 2
//    insert(l, data, 2);

 //   printlist(l);

    //xchgNodes(l, l->head->next, l->head->next->next);
    //printlist(l);
//encontrando o minimo  
    //printf("%d", min(l, 2)->data.id);
//encontrando o maximo
    //printf("%d", max(l, 2)->data.id);

//ordenando em ordem crescente
   // incSort(l);
    //printlist(l);
}