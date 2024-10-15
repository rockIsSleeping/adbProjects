#include<stdio.h>
#include<stdlib.h>
#define Datatype int

typedef struct _node* pNode;
typedef struct _node* Heap;
typedef struct _node
{
    Datatype key;
    struct _node* left;
    struct _node* right;
}Node;



Heap Insertion(Heap H, Datatype key){
    pNode new = (pNode)malloc(sizeof(Node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    return Merge(H, new);
}

Datatype Delete_min(Heap* pH){
    pNode target = *pH;
    *pH = Merge(target->left, target->right);
    Datatype min = target->key;
    free(target);
    return min;
}

Heap Merge(Heap H1, Heap H2){
    if(H1 == NULL) return H2;
    if(H2 == NULL) return H1;
    if(H1->key > H2->key) return Merge(H2, H1);
    Heap temp = H1->right;
    H1->right = H1->left;
    H1->left = Merge(temp, H2);
    return H1;
}