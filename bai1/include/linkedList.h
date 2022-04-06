#ifndef LINKEDLIST_H_  
#define LINKEDLIST_H_

typedef int elementtype; 
struct list_el{
  elementtype element;
  struct list_el *next;
  struct list_el *prev;
};
typedef struct list_el dblist;

void makeNullList(dblist **root,dblist **cur,dblist **tail);
dblist* makeNewNode(elementtype data);
void displayNode(dblist* p);
void traversinglist(dblist *root);
void insertAtHead(elementtype data,dblist **root,dblist **cur,dblist **tail);
void AppendList(elementtype data,dblist **root,dblist **cur,dblist **tail);
void insertAfterCur(elementtype data,dblist **root,dblist **cur,dblist **tail);
void insertBeforeCur(elementtype data,dblist **root,dblist **cur,dblist **tail);
void insertAtPos(elementtype data,dblist **root,dblist **cur,dblist **tail,int p);
void deleteFirstElement(dblist **root,dblist **cur,dblist **tail);
void deleteLastElement(dblist **root,dblist **cur,dblist **tail);
void deleteCurElement(dblist **root,dblist **cur,dblist **tail);
void deleteAtPos(dblist **root,dblist **cur,dblist **tail,int p);
void list_reverse(dblist **root,dblist **cur,dblist **tail);
void freeNode(dblist **root);

#endif // LINKEDLIST_H_