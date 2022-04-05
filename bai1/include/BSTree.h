#ifndef BSTree_H_  
#define BSTree_H_
#include "linkedList.h"

typedef struct elm{
    char word[50];
    int appearCount;
    dblist *rootLine, *curLine, *tailLine;
}elmType;

typedef struct node_type{
  elmType element;
  struct node_type *left,*right;
}nodeType;

typedef nodeType *treetype;//treetype a => nodeType* a

void makeNullTree(treetype* N);
int isEmptyTree(treetype N);
treetype leftChild(treetype N);
treetype rightChild(treetype N);
int Compare(elmType a, elmType b);
void insertNode(treetype* T,elmType data);
int isLeaf(treetype N);
int countNode(treetype N);
void InOrderPrint(treetype T);
int Max(int a, int b);
int treeHeight(treetype T);
int leafNode(treetype T);
int innerNode(treetype T);
int numRight(treetype T);
treetype searchT(treetype T, elmType x);
elmType deletemin(treetype *n);
void delete(treetype *n, elmType key);
void freeTree(treetype T);

#endif //BSTree_H_