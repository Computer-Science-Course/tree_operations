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

void main(){
    struct node *root;
    root = NULL;

    insert(&root, 20);
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 30);
    insert(&root, 25);
    insert(&root, 35);
    insert(&root, 2);
    insert(&root, 12);
    insert(&root, 15);
    insert(&root, 33);
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