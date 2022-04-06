#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <string.h>
#include <stdbool.h>

/*
typedef struct elm{
    char word[50];
    int appearCount;
    dblist *rootLine, *curLine, *tailLine;
}elmType;

typedef struct node_type{
  elmType element;
  struct node_type *left,*right;
}nodeType;

luu cac tu bang cay BS tree 
trong cac node chua tu, so lan xuat hien va 1 linkedlist chua so thu tu cac dong ma tu do xuat hien
*/


/* tim tu word trong cay
    ham tra ve node neu tim thay, nguoc lai tra ve null
*/
treetype searchTbyword(treetype Tree, char* word){
    elmType wData;
    strcpy(wData.word, word);
    return searchT(Tree, wData);
}

// ham them tu va dong xuat hien vao cay 
void AddWord(treetype* Tree ,char *word, int line){
    treetype wCur = searchTbyword(*Tree, word);

    /* neu khong tim thay -> xuat hien lan dau
    -> tao list de luu cac dong xuat hien va them so thu tu dong hien tai vao danh sach
    */
    if(wCur==NULL){
        elmType wData;
        strcpy(wData.word, word);
        wData.appearCount=1;
        makeNullList(&(wData.rootLine), &(wData.curLine), &(wData.tailLine));
        AppendList(line, &(wData.rootLine), &(wData.curLine), &(wData.tailLine));
        insertNode(Tree, wData);
    }
    // neu tu da co trong cay -> them so thu tu dong hien tai vao list
    else{
        wCur->element.appearCount++;
        AppendList(line, &(wCur->element.rootLine), &(wCur->element.curLine), &(wCur->element.tailLine));
    }
}

// doc file va luu vao cau truc cay

void ReadFile(char* fileName ,treetype* wordTree, treetype* stopTree){
    char c, prevC;
    int count, line;
    char word[20];
    bool pNoun, isAword;
    FILE *ptr=fopen(fileName,"r");
    if(ptr==NULL){
        printf("cant open %s\n", fileName);
        return;
    }
    for(count=0, line=1, prevC='f', isAword = false, pNoun = false;(c=fgetc(ptr))!=EOF; prevC = c){

        if( c>='A' && c<='Z'){// Is Upper
            c+=32; // lower
            if(prevC==' '){  //check proper noun
                pNoun=true;
            }
        }

        if( c<'a' || c>'z'){  //last char of word
            // neu khong phai danh tu rieng thi them vao cay
            if(!pNoun && isAword){ 
                word[count] = '\0';
                if(searchTbyword(*stopTree, word) == NULL){
                    AddWord(wordTree, word, line);
                }
            }
            count = 0;
            pNoun = false;
            isAword = false;

            if(c == '\n'){
                line++;
            }
        }
        else{
            if(!isAword) isAword = true;
            word[count++] = c;
        }
    }
    fclose(ptr);
}

void displayNodeToFile(dblist* p, FILE* file){ //Must fix
  if(p==NULL){
    printf("ERROR pointer NULL\n");
    return;
  }
  fprintf(file,", %d",p->element);
}

void traversingListFileToFile(dblist *root, FILE* file){
    dblist *cur;
  for(cur=root;cur!=NULL;cur=cur->next){
    displayNodeToFile(cur, file);
  }
}

void InOrderPrintToFile(treetype T, FILE *fp){
    if(T!=NULL){
        InOrderPrintToFile(T->left, fp);
        fprintf(fp,"%s %d", T->element.word, T->element.appearCount);
        traversingListFileToFile(T->element.rootLine,fp);
        fprintf(fp,"\n");
        InOrderPrintToFile(T->right, fp);
    }
}

int main(int argc, char const *argv[])
{
    treetype wordTree, stopTree;
    makeNullTree(&wordTree);
    makeNullTree(&stopTree);
    
    ReadFile("stopw.txt", &stopTree, &wordTree);//build stop word

    ReadFile("alice30.txt", &wordTree, &stopTree);//buil need to read word

	FILE *fp = fopen("ketqua.txt","w");

    // print to ketqua.txt
    InOrderPrintToFile(wordTree, fp);
    // print to terminal
    InOrderPrint(wordTree);

    fclose(fp);
    freeTree(wordTree);
    freeTree(stopTree);
    return 0;
};