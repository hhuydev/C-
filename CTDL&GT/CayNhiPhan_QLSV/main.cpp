#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
struct SINHVIEN {
    char id[20];
    char name[20];
    double scores;
};
struct Node {
   SINHVIEN data; //truong key cua du lieu
    Node *Left, *Right; //con trai va con phai
};

typedef Node *Tree;  //cay

// So sanh MaSV

int compare(SINHVIEN x, SINHVIEN y) { // so sanh 2 item theo key
    return strcmp(x.id, y.id);
}

// Nhap thong tin SV
int inputSV(SINHVIEN &x) {

    char id[20];
    fflush(stdin);
    printf("Enter id of student (0 to quit): ");
    gets(x.id);

    if (strcmp(x.id, "0") == 0 ) {
        return 0;
    }
 	fflush(stdin);
    printf("Enter name of student: ");
    gets(x.name);

    printf("Enter scores of student:");
    scanf("%lf", &x.scores);
	return 1;
}

void outSV(SINHVIEN x){
    cout<<""<<x.id<<"\t "<<x.name<<"\t"<<x.scores<<"";
}

int insertNode(Tree &t, SINHVIEN x){
    if(t){
        if(compare(t->data,x)==0) return -1;
        if(compare(t->data,x)>0) return insertNode(t->Left,x);
        else if(compare(t->data,x)<0) return insertNode(t->Right,x);
    }
    t=new Node;
    if(t==NULL) return 0;
    t->data=x;
    t->Left=t->Right=NULL;
    return 1;
}

void CreateTree(Tree &T)        // nhap cay
{

    SINHVIEN x;
    int kq;
    printf("Enter a student: ");
    kq = inputSV(x);
    while (kq) {

        if (strcmp(x.id, "0") == 0)
            break;  // x = 0 thi thoat
        int check = insertNode(T, x);
        if (check == -1)
            printf("Student is exits!");
        else if (check == 0)
            printf("Memory full");
        printf("Enter a student: ");
        kq = inputSV(x);
    }
}

// Duyet theo LNR
void LNR(Tree T) {
    if (T != NULL) {
        LNR(T->Left);
        outSV(T->data);
        LNR(T->Right);
    }
}

void searchMa(Tree t, char *ma){
    if(t){
        if(strcmp(t->data.id,ma)==0) outSV(t->data);
        if(strcmp(t->data.id,ma)>0) searchMa(t->Left,ma);
        else if(strcmp(t->data.id,ma)<0) searchMa(t->Right,ma);
    }
    else cout<<"\nKhong tim thay ma!";
}

int main()
{
    Tree t=NULL;
    SINHVIEN x;
//    inputSV(x);
//    outSV(x);
    CreateTree(t);
    LNR(t);
    char tim[20];
    getchar();
    cout<<"\nNhap ma can tim: ";gets(tim);
    searchMa(t,tim);
    return 0;
}
