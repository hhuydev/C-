/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#define Max 50
using namespace std;

typedef struct SINHVIEN{
    char mssv[8],hoten[30],gioitinh[8],diachi[50];
    float diemtb;
}sv;

void Nhap_TT_1_SV(sv &x){
    getchar();
    cout<<"\nNhap ma sinh vien: "<<endl;gets(x.mssv);
    cout<<"Nhap ho ten: "<<endl;gets(x.hoten);
    if(x.hoten[0]=='\0') return;
    cout<<"Nhap gioi tinh: "<<endl;gets(x.gioitinh);
    cout<<"Nhap dia chi: "<<endl;gets(x.diachi);
    cout<<"Nhap diem trung binh: "<<endl;cin>>x.diemtb;
}


void Xuat_TT_1_SV(sv x){
    cout<<"Ma sinh vien: "<<x.mssv<<endl;
    cout<<"Ho ten: "<<x.hoten<<endl;
    cout<<"Gioi tinh: "<<x.gioitinh<<endl;
    cout<<"Dia chi: "<<x.diachi<<endl;
    cout<<"Diem trung binh: "<<x.diemtb<<endl;
}

void Nhap_TT_n_SV(sv *ds, int &n){
    cout<<"Nhap so luong sinh vien: "<<endl;cin>>n;
    while(n > 50 || n < 1){
        cout<<"So luong sinh vien khong qua 50!!!";
    }
    for (int i = 0; i < n; i++) {
        Nhap_TT_1_SV(ds[i]);
    }
}

void Xuat_TT_n_SV(sv *ds, int n){
    for (int i = 0; i < n; i++) {
        Xuat_TT_1_SV(ds[i]);
    }
}

void Search(sv *ds, int n, char *x){
    int flag=0;
    cout<<"\nNhap ma sinh vien can tim: ";cin>>x;
    for(int i=0;i<n;++i){
        if(strstr(ds[i].mssv,x)){
            flag=1;
            Xuat_TT_1_SV(ds[i]);
        }
    }if(flag==0) cout<<"\nKhong tim thay ma sinh vien theo yeu cau!!!";
}

void Hoanvi(sv *a, sv *b){
    float temp = a->diemtb;
    a->diemtb = b->diemtb;
    b->diemtb = temp;
}

void Sort_Mark_Increase(sv *ds, int n){
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            if(ds[i].diemtb > ds[j].diemtb) Hoanvi(&ds[i],&ds[j]);
        }
    }
    cout<<"\nDanh sach sau khi sap theo diem trung binh tang dan"<<endl;
    Xuat_TT_n_SV(ds,n);
}

void Sort_Name_Increase(sv *ds, int n){
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            if(strcmp(ds[i].hoten, ds[j].hoten) > 0){
                sv temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    cout<<"\nDanh sach sau khi sap theo ho ten tang dan"<<endl;
    Xuat_TT_n_SV(ds,n);
}


int main()
{
    sv *ds = new sv [Max];
    int n;
    Nhap_TT_n_SV(ds,n);
    Xuat_TT_n_SV(ds,n);
    char *timmasv = new char [8];
    Search(ds,n,timmasv);
    Sort_Mark_Increase(ds,n);
    Sort_Name_Increase(ds,n);
    return 0;
}
