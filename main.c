#include <stdio.h>

typedef struct node
{
    /*Struct que implementa um nó de uma árvore
    */
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node **v, int data)
{
    /*Função para a inserção de um nó em uma árvore.

    struct node **v:    inicialmente, o endereço do nó raiz, posteriormente,
                        o endereço dos nós subsequentes até encontrar um nó
                        capaz de apontar para o dado em questão (um nó que
                        aponte para NULL).
    int data:           dado a ser armazenado no nó que será iserido na árvore.
    */
    if (*v == NULL)
    {
        *v = (struct node *) malloc(sizeof(struct node));
        (*v)->data = data;
        (*v)->left = NULL;
        (*v)->right = NULL;
    }
    else
    {
        if (data <= (*v)->data)
        {
            insert(&(*v)->left, data);
        }
        else
        {
            insert(&(*v)->right, data);
        }
    }
};

struct node **biggestLeft(struct node *v)
{
    /*Função para encontrar o maior valor na sub-árvore à esquerda do nó
    em questão.

    struct node *v:     Nó pai da sub-árvore onde ocorre a busca (Nó a ser 
                        substituido).
    */
   printf("\nI got: %d.\n", (*v));
    struct node **aux = &(v);
    if ((*aux)->left != NULL)
    {
        aux = &(*aux)->left;
        while ((*aux)->right != NULL)
        {
            aux = &(*aux)->right;
        }
    }
    return aux;
};

struct node **smallestRight(struct node *v)
{
    /*Função para encontrar o menor valor na sub-árvore à direita do nó
    em questão.

    struct node *v:     Nó pai da sub-árvore onde ocorre a busca (Nó a ser 
                        substituido).
    */
    struct node **aux = &(v);
    if ((*aux)->right != NULL)
    {
        aux = &(*aux)->right;
        while ((*aux)->left != NULL)
        {
            aux = &(*aux)->left;
        }
    }
    return aux;
}

void removeNode(struct node **v, int num)
{
    /*Função para a remoção de um nó em uma árvore.

    struct node **v:    inicialmente, o endereço do nó raiz, posteriormente,
                        o endereço dos nós subsequentes até encontrar um que
                        aponte para um nó, cujo o dado seja o valor a ser
                        removido ((*v)->data == num)).
    int data:           dado do nó a ser removido.
    */
    struct node **aux2, *aux3;
    if (*v != NULL)
    {
        if ((*v)->data == num)
        {
            if ((*v)->left == (*v)->right)
            {
                free(*v);
                *v = NULL;
            }
            else
            {
                if ((*v)->left != NULL)
                {
                    aux2 = biggestLeft(*v);
                    aux3 = *aux2;
                    (*aux2) = (*aux2)->left;
                }
                else
                {
                    aux2 = smallestRight(*v);
                    aux3 = *aux2;
                    (*aux2) = (*aux2)->right;
                }
                (*v)->data = aux3->data;
                free(aux3);
                aux3 = NULL;
            }
        }
        else
        {
            if (num < (*v)->data)
            {
                removeNode(&(*v)->left, num);
            }
            else
            {
                removeNode(&(*v)->right, num);
            }
        }
    }
}

void searchNode(struct node **v, int num, int step){
    /*Função para precorrer e buscar um nó com o dado especificado.

    struct node **v:    inicialmente, o endereço do nó raiz, posteriormente,
                        o endereço de todos os nós restantes da árvore,
                        até chegar no nó do dado em questão.
    */
    if(step == 1){
        printf("\nCaminho ate o numero buscado (%d):", num);
    }

    if((*v) != NULL){
        printf(" %d", (*v)->data);
        if((*v)->data != num){
            if(num < (*v)->data){
                searchNode(&(*v)->left, num, ++step);
            }else {
                searchNode(&(*v)->right, num, ++step);
            }
        }else {
            printf("\nEu encontrei um valor : %d.\n", (*v)->data);
        }
    }else {
        printf("\nNa moral, eu percorri a arvore, mas nao encontrei o %d.\n", num);
    }
}

void preOrder(struct node **v){
    /*Função para precorrer e imprimir a árvore "pre-order".

    struct node **v:    inicialmente, o endereço do nó raiz, posteriormente,
                        o endereço de todos os nós restantes da árvore,
                        um a um.
    */
    if(*v != NULL){
        printf("%d ", (*v)->data);
        preOrder(&((*v)->left));
        preOrder(&((*v)->right));
    }
}

void inOrder(struct node **v){
    /*Função para precorrer e imprimir a árvore "in-order".

    struct node **v:    inicialmente, o endereço do nó raiz, posteriormente,
                        o endereço de todos os nós restantes da árvore,
                        um a um.
    */
    if(*v != NULL){
        inOrder(&((*v)->left));
        printf("%d ", (*v)->data);
        inOrder(&((*v)->right));
    }
}

void posOrder(struct node **v){
    /*Função para precorrer e imprimir a árvore "pos-order".

    struct node **v:    inicialmente, o endereço do nó raiz, posteriormente,
                        o endereço de todos os nós restantes da árvore,
                        um a um.
    */
    if(*v != NULL){
        posOrder(&((*v)->left));
        posOrder(&((*v)->right));
        printf("%d ", (*v)->data);
    }
}

int nodeWalker(struct node **v){
    /*Função para precorrer e contar todos os nós de um árvore, dado o endereço
    de sua raiz.

    struct node **v:    inicialmente, o endereço do nó raiz, posteriormente,
                        o endereço de todos os nós restantes da árvore,
                        um a um.
    */
    if(*v != NULL){
        nodeWalker(&((*v)->left));
        counter++;
        nodeWalker(&((*v)->right));
    }
    return counter;
}
int countNodes(struct node **v){
    counter = 0;
    return nodeWalker(&(*v));
}

int leafWalker(struct node **v){

    /*Função para precorrer e contar todos os nós de um árvore, dado o endereço
    de sua raiz.

    struct node **v:    inicialmente, o endereço do nó raiz, posteriormente,
                        o endereço de todos os nós restantes da árvore,
                        um a um.
    */
    if(*v != NULL){
        leafWalker(&((*v)->left));
        if((*v)->left == NULL && (*v)->right == NULL){
            counter++;
        }
        leafWalker(&((*v)->right));
    }
    return counter;
}
int countLeaves(struct node **v){
    counter = 0;
    return leafWalker(&(*v));
}

int getBiggestNodeData(struct node **v){
    /*Função para encontrar o maior valor na árvore.

    struct node **v:     Raiz da árvore onde ocorre a busca.
    */
    struct node **aux = v;
    if ((*aux)->right != NULL)
    {
        aux = &(*aux)->right;
        while ((*aux)->right != NULL)
        {
            aux = &(*aux)->right;
        }
    }
    return (*aux)->data;
}

int max(int a, int b){
    /* Função que retorna o maior entre dois valores inteiros, ou o segundo
    caso sejam iguais. Vamos utilizar essa função para definir o maior caminho
    de uma árvore.

    int a, b:       Valores a serem comparados.
    */
    if(a > b){
        return a;
    }else {
        return b;
    }
}
int treeHeight(struct node **v) {
    /*Função para encontrar o maior valor na árvore.

    struct node **v:     Raiz da árvore onde ocorre a busca.
    */
    if ((*v) == NULL){
        return 0;
    }else {
        return max(treeHeight(&(*v)->left), treeHeight(&(*v)->right)) + 1;
    }
}

void main(){
    struct node *root;
    root = NULL;
    // int nodes[] = {20, 10, 5, 15, 30, 25,35, 2, 12, 15, 33, 50, 55, 60};
    int nodes[] = {20, 10, 5, 15, 30, 25, 35, 2, 12, 15, 33};
    // int nodes[] = {20, 10, 15, 30};
    int nodes_length = sizeof(nodes)/sizeof(nodes[0]);

    for(int i = 0; i < nodes_length; i++){
        insert(&root, nodes[i]);
    }

    printf("Adicionado com sucesso\n");
    printf("\nPrinting pre order: ");
    preOrder(&root);
    printf("\nPrinting in order: ");
    inOrder(&root);
    printf("\nPrinting pos order: ");
    posOrder(&root);

    printf("Biggest at left: %d.\n", **biggestLeft(root));
    printf("Smallest at right: %d.\n", **smallestRight(root));
}