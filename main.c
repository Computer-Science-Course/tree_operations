#include <stdio.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node **v, int data)
{
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


void main(){
    struct node *root;
    root = NULL;

    insert(&root, 45);
    insert(&root, 34);
    insert(&root, 76);
    printf("Adicionado com sucesso\n");
}