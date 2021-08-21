#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct NGAY
{
    int ngay,thang,nam;
};

struct SINHVIEN
{
    char maSV[8];
    char hoTen[50];
    int gioiTinh; // 0:nam - 1:nu
    NGAY ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};

int Nhap_1_SV(SINHVIEN &x)
{
    cout<<"\nNhap ma sv: ";
    gets(x.maSV);
    if(strcmp(x.maSV,"0")==0) return 0;
    cout<<"\nNhap ho ten: ";
    gets(x.hoTen);
    cout<<"\nNhap gioi tinh (0.Nam 1.Nu): ";
    cin>>x.gioiTinh;
    cout<<"\nNhap ngay sinh: ";
    cin>>x.ngaySinh.ngay>>x.ngaySinh.thang>>x.ngaySinh.nam;
    getchar();
    cout<<"\nNhap dia chi: ";
    gets(x.diaChi);
    cout<<"\nNhap lop: ";
    gets(x.lop);
    cout<<"\nNhap khoa: ";
    gets(x.khoa);
    return 1;
}

//void Xuat_1_SV(SINHVIEN x){
//    cout<<"Ma sv: ";gets(x.maSV);
//    cout<<"\nHo ten: ";gets(x.hoTen);
//    cout<<"\nGioi tinh (1.Nam 2.Nu): ";cin>>x.gioiTinh;
//    cout<<"\nNgay sinh: ";cin>>x.ngaySinh.ngay>>x.ngaySinh.thang>>x.ngaySinh.nam;
//    cout<<"\nDia chi: ";gets(x.diaChi);
//    cout<<"\Lop: ";gets(x.lop);
//    cout<<"\nKhoa: ";gets(x.khoa;)
//
//}

struct NODE
{
    SINHVIEN data;
    NODE *pnext;
};

NODE *getNode(SINHVIEN x)
{
    NODE *p = new NODE;
    if(p==NULL) return NULL;
    p->data = x;
    p->pnext = NULL;
    return p;
}


struct LIST
{
    NODE *phead, *ptail;
};

void init(LIST &lt)
{
    lt.phead=NULL;
    lt.ptail=NULL;
}

void addHead(LIST &lt, NODE *p)
{
    if(lt.phead==NULL)  lt.phead = lt.ptail = p;
    else
    {
        p->pnext = lt.phead;
        lt.phead = p;
    }
}
void addTail(LIST &lt, NODE *p)
{
    if(lt.phead==NULL) lt.phead = lt.ptail = p;
    else
    {
        lt.ptail->pnext = p;
        lt.ptail = p;
    }
}

void insertTail(LIST &lt, SINHVIEN x)
{
    NODE *p = getNode(x);
    if(p==NULL) return;
    addTail(lt,p);
}



void nhapDS(LIST &lt)
{
    SINHVIEN x;
    int flag = Nhap_1_SV(x);
    while(flag)
    {
        insertTail(lt,x);
        flag = Nhap_1_SV(x);
    }
}



void xuat_1_SV(SINHVIEN x)
{
    char gt[4];
    if(x.gioiTinh == 0) strcpy(gt,"Nam");
    else strcpy(gt,"Nu");
    cout<<"\n"<<x.maSV<<"\t"<<x.hoTen<<"\t"<<gt<<"\t"<<x.ngaySinh.ngay<<"/"<<x.ngaySinh.thang<<"/"<<x.ngaySinh.nam<<"\t"<<x.diaChi<<"\t"<<x.lop<<"\t"<<x.khoa;
//    "\n%10s %20s %5d/%d/%d %5s %40s %8s %8s",
}

void xuatDS(LIST lt)
{
    int j=0;
    for(NODE *i=lt.phead; i!=NULL; i=i->pnext)
    {
        cout<<"n\t\t\t\t\tTHONG TIN SINH VIEN "<<j+1<<"";
        xuat_1_SV(i->data);
    }
}

int Search(LIST lt, char* ma)
{
    for(NODE *i=lt.phead; i!=NULL; i=i->pnext)
    {
        if(strcmp(i->data.maSV,ma)==0) return 1;
    }
    return 0;
}

void themKhongTrung(LIST &lt, SINHVIEN x, char *ma)
{
    if(Search(lt,ma)==1)
    {
        cout<<"\nMa sv trung!";
        return;
    }
    else
    {
        Nhap_1_SV(x);
        insertTail(lt,x);
    }
}

void interchangeSort(LIST &lt)
{
    for(NODE *i=lt.phead; i!=lt.ptail; i=i->pnext)
    {
        for(NODE *j = i->pnext; j!=NULL; j=j->pnext)
        {
            if(strcmp(i->data.hoTen,j->data.hoTen)>0)
            {
                SINHVIEN temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    cout<<"\nSap xep danh sach tang dan theo ten";
    xuatDS(lt);
}

void xoaNodeDau(LIST &lt)
{
    if(lt.phead == NULL)
        return;
    NODE *temp = lt.phead;
    lt.phead = temp->pnext;
    delete temp;
}

void xoaNodeCuoi(LIST &lt)
{
    if(lt.phead == NULL)
    {
        return;
    }
    if(lt.phead->pnext == NULL)
    {
        xoaNodeDau(lt);
    }
    for(NODE *i=lt.phead; i!=NULL; i=i->pnext)
    {
        if(i->pnext == lt.ptail)
        {
            delete lt.ptail;
            i->pnext=NULL;
            lt.ptail=i;
        }
    }

}

void xoa(LIST &lt, char *temp)
{
    int dem=0;
    for(NODE *i=lt.phead; i!=NULL; i=i->pnext)
    {
        ++dem;
    }
    if(strcmp(lt.phead->data.maSV,temp)==0)
    {
        xoaNodeDau(lt);
    }
    else if(strcmp(lt.ptail->data.maSV,temp)==0)
    {
        xoaNodeCuoi(lt);
    }
    NODE *p=NULL;
    for(NODE *j=lt.phead; j!=NULL; j=j->pnext)
    {
        if(strcmp(j->data.maSV,temp)==0)
        {
            p->pnext=j->pnext;
            delete j;
        }

        p=j;
    }
}

int main()
{
    LIST lt;
    SINHVIEN x;
    init(lt);
    nhapDS(lt);
    xuatDS(lt);
    char ma[8];
    cout<<"\nNhap ma sinh vien can them: ";
    gets(ma);
    themKhongTrung(lt,x,ma);
    xuatDS(lt);
    cout<<"\nSap xep danh sach ho ten tang dan"<<endl;

    interchangeSort(lt);
    char temp[8];
    cout<<"\nNhap ma sv tim xoa: ";
    gets(temp);
    xoa(lt,temp);
    xuatDS(lt);
    return 0;
}
