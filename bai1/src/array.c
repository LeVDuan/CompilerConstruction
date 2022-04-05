#include <stdio.h>
#include <stdlib.h>
#include "array.h"

//ham khoi tao danh sach rong
/*Danh sach L duoc khai bao kieu con tro
de khi ra khoi ham no co the thay doi duoc*/
void Init(List *L){
    (*L).size = 0; //size = 0.
}

int Isempty (List L)
{
    return (L.size==0);
}

int Isfull (List L)
{
    return (L.size==MAX_LEN);
}

item init_x() //khoi tao gia tri x
{
    int temp;
    scanf("%d",&temp);
    return temp;
}

int Insert_k (List *L, item x, int k)//chen x vao vi tri k
{
    if (Isfull(*L)) //kiem tra danh sach day
    {
        printf("Danh sach day !");
        return 0;
    }
 
    if (k<1 || k>(*L).size+1) //kiem tra dieu kien vi tri chen
    {
        printf("Vi tri chen khong hop le !\n");
        return 0;
    }
    printf ("Nhap thong tin: ");
    x = init_x(); //gan x = ham khoi tao x
    int i;
    //di chuyen cac phan tu ve cuoi danh sach
    for (i = (*L).size; i >= k; i--)
        (*L).Elems[i] = (*L).Elems[i-1];
    (*L).Elems[k-1]=x;//chen x vao vi tri k
    (*L).size++;//tang size len 1 don vi.
    return 1;
}
 
void Input_arr (List *L)
{
    printf("Nhap so phan tu cua danh sach: ");
    scanf("%d",&(*L).size);
    int i;
    for (i=0; i<(*L).size; i++)
    {
        printf("Nhap phan tu thu %d : ",i+1);
        (*L).Elems[i] = init_x();
    }
}
 
void Output (List L)
{
    printf("Danh sach: \n");
    int i;
    for (i=0; i<L.size; i++)
        printf("%5d",L.Elems[i]);
    printf("\n");
}
 
int Search_arr (List L, item x)
{
    int i;
    for (i=0; i<L.size; i++)
        if (L.Elems[i] == x)
            return i+1;
    return 0;
}
 
int Del_k (List *L, item *x, int k)
{
    if (Isempty(*L))
    {
        printf("Danh sach rong !");
        return 0;
    }
    if (k<1 || k>(*L).size)
    {
        printf("Vi tri xoa khong hop le !");
        return 0;
    }
    *x=(*L).Elems[k-1]; //luu lai gia tri cua phan tu can xoa
    int i;
    for (i=k-1; i<(*L).size-1; i++) //don cac phan tu ve truoc
    (*L).Elems[i]=(*L).Elems[i+1];
    (*L).size--; //giam size
    return 1;
}
 
int Del_x (List *L, item x)
{
    if (Isempty(*L))
    {
        printf("Danh sach rong !");
        return 0;
    }
 
    int i = Search_arr(*L,x);
    if (!i)
    {
        printf("Danh sach khong co %d",x);
        return 0;
    }
    do
    {
        Del_k(L,&x,i);
        i = Search_arr(*L,x);
    }
    while (i);
    return 1;
}
