#include <iostream>
#include <math.h>
#include<string.h>
#define Max 100
using namespace std;

typedef struct nhanvien{
    char code[8];
    char name[20];
    double salary,allowance;
}nv;

typedef struct danhsachnhanvien{
    nv a[100];
    int n;
}ds;

void Nhap_tt_1nv(nv &x){
    getchar();
    printf("Nhap ma nhan vien: ");fgets(x.code,8,stdin);
    printf("\nNhap ho ten nhan vien: ");fgets(x.name,20,stdin);
    printf("\nNhap luong: ");scanf("%lf",&x.salary);
    printf("\nNhap tien thuong: ");scanf("%lf",&x.allowance);

}

void Xuat_tt_1nv(nv x){
    printf("Ma nhan vien: %s",x.code);
    printf("Ho ten nhan vien: %s",x.name);
    printf("\nLuong: %.2f",x.salary);
    printf("\nTien thuong: %.2f",x.allowance);
}

void Nhap(ds &dsnv){
    printf("\nNhap sl: ");scanf("%d",&dsnv.n);
    for(int i=0;i<dsnv.n;++i){
        printf("\n\tNhap thong tin nhan vien %d\n",i+1);
        Nhap_tt_1nv(dsnv.a[i]);
    }
}

void Xuat(ds dsnv){
    for(int i=0;i<dsnv.n;++i){
        printf("\n\tXuat thong tin nhan vien %d\n",i+1);
        Xuat_tt_1nv(dsnv.a[i]);
    }
}

void Timten(ds dsnv, char *temp){
    getchar();
    printf("\nNhap ten can tim: ");fgets(temp,20,stdin);
    int flag=0;
    temp[strlen(temp)-1] = '\n';
    for(int i=0;i<dsnv.n;++i){
        if(strcmpi(dsnv.a[i].name,temp)==0){
            flag=1;
            Xuat_tt_1nv(dsnv.a[i]);
        }
    }if(flag==0){
        printf("\nKhong tim thay ten!");
    }
}

void Xoanv(ds &dsnv, char *temp){
    getchar();
    printf("\nNhap ma nhan vien can tim: ");fgets(temp,20,stdin);
    temp[strlen(temp)-1]='\n';
    for(int i=0;i<dsnv.n;++i){
        if(strcmpi(dsnv.a[i].code,temp)==0){
        dsnv.a[i]=dsnv.a[i+1];
        dsnv.n--;
        }
    }
    Xuat(dsnv);
}

double Tongtien(nv x){
    float tongtien = x.salary + x.allowance;
    return tongtien;
}

void Swap(nv *nv1, nv *nv2){
    float temp = nv1->salary;
    nv1->salary = nv2->salary;
    nv2->salary = temp;
}

void Sapxepluongtangdan(ds dsnv){
    for(int i=0;i<dsnv.n-1;++i){
        for(int j=i+1;j<dsnv.n;++j){
            if(dsnv.a[i].salary > dsnv.a[j].salary){
                Swap(&dsnv.a[i],&dsnv.a[j]);
            }
        }
    }
    Xuat(dsnv);
}

int main()
{
   ds dsnv;
   Nhap(dsnv);
   Xuat(dsnv);
   char timten[20];
   Timten(dsnv, timten);
   char timma[8];
   Xoanv(dsnv,timma);
   Sapxepluongtangdan(dsnv);
    return 0;
}
