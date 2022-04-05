#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <string.h>
#include <stdbool.h>

treetype searchTbyword(treetype T, char* word){
    elmType wordData;
    strcpy(wordData.word, word);
    return searchT(T, wordData);
}

void AddWord(treetype* wordTree ,char *word, int line){
    treetype curword = searchTbyword(*wordTree, word);
    if(curword==NULL){
        elmType wordData;
        strcpy(wordData.word, word);
        wordData.appearCount=1;
        makeNullList(&(wordData.rootLine), &(wordData.curLine), &(wordData.tailLine));
        AppendList(line, &(wordData.rootLine), &(wordData.curLine), &(wordData.tailLine));
        insertNode(wordTree, wordData);
    }
    else{
        curword->element.appearCount++;
        AppendList(line, &(curword->element.rootLine), &(curword->element.curLine), &(curword->element.tailLine));
    }
}

void ReadFile(char* fileName ,treetype* wordTree, treetype* stopTree){
    char c, prevC;
    int count, line;
    char word[20];
    bool danhTuRieng, isAword;
    FILE *ptr=fopen(fileName,"r");
    if(ptr==NULL){
        printf("cant open %s\n", fileName);
        return;
    }
    for(count=0, line=1, prevC='f', isAword = false, danhTuRieng = false;(c=fgetc(ptr))!=EOF; prevC = c){

        if( c>='A' && c<='Z'){// Is Upper
            c+=32; // lower
            if(prevC==' '){  //check proper noun
                danhTuRieng=true;
            }
        }

        if( c<'a' || c>'z'){  //last char of word

            if(!danhTuRieng && isAword){ 
                word[count] = '\0';
                if(searchTbyword(*stopTree, word) == NULL){
                    AddWord(wordTree, word, line);
                }
            }
            count = 0;
            danhTuRieng = false;
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