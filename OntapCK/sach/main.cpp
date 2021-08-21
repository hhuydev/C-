#include <stdio.h>
#include <string>
#define Max 100

using namespace std;

typedef struct SACH{
    char ma_sach[10];
    char ten_sach[200];
    unsigned int nam_xb;
    unsigned int don_gia;
}sach;

void nhap_1(sach &x){
    getchar();
    printf("\nNhap ma sach: ");gets(x.ma_sach);
    printf("\nNhap ten sach: ");gets(x.ten_sach);
    printf("\nNhap nam xuat ban: ");scanf("%d",&x.nam_xb);
    printf("\nNhap don gia: ");scanf("%d",&x.don_gia);
}

void xuat_1(sach x){
    printf("\nMa sach: %s",x.ma_sach);
    printf("\nTen sach: %s",x.ten_sach);
    printf("\nNam xuat ban: %d",x.nam_xb);
    printf("\nDon gia: %d",x.don_gia);
}

void nhap_n(sach x[], int n){
    for (int i = 0; i < n; i++) {
        nhap_1(x[i]);
    }
}


void xuat_n(sach x[], int n){
    for (int i = 0; i < n; i++) {
        xuat_1(x[i]);
    }
}

int main()
{
    int n;
    sach ds[Max];
    printf("\nNhap sl:  ");scanf("%d",&n);

    nhap_n(ds,n);
    xuat_n(ds,n);
    return 0;
}
