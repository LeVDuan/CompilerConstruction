#ifndef ARRAY_H_  
#define ARRAY_H_

#define MAX_LEN 100 //so phan tu toi da la 100
typedef int item;
/*kieu cac phan tu la item
ma cu the o day item la kieu int */

typedef struct
{
    item Elems[MAX_LEN]; //mang kieu item
    int size; //so phan tu toi da cua mang
}List; //kieu danh sach List

void Init(List *L); //ham khoi tao danh sach rong
void Init(List *L); //ham khoi tao danh sach rong
int Isempty (List L); //kiem tra danh sach rong
int Isfull (List L); //kiem tra danh sach day
int Insert_k (List *L, item x, int k); //chen x vao vi tri k
void Input_arr (List *L);//nhap danh sach
void Output (List L);//xuat danh sach
int Search_arr(List L, item x); //tim phan tu x trong danh sach
int Del_k (List *L, item *x, int k);//xoa phan tu tai vi tri k
int Del_x(List *L, item x);//xoa phan tu x trong danh sach
item init_x(); //tao phan tu x.

#endif //ARRAY_H_