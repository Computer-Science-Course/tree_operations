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




void main(){
    struct node *root;
    root = NULL;

    insert(&root, 45);
    insert(&root, 34);
    insert(&root, 76);
    printf("Adicionado com sucesso\n");
}