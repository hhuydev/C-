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

void ghiTep(sach x[], int n, char *duongdan){
    FILE *f = fopen(duongdan,"wb");
    if(f==NULL) {
        printf("\nKhong mo duoc tep!");exit(0);
    }
    fwrite(x,sizeof(sach),n,f);
    fclose(f);
}

void docTep(sach x[], int &n, char *duongdan){
    FILE *f = fopen(duongdan,"rb");
    n=0;
    if(f==NULL) {
        printf("\nKhong mo duoc tep!");exit(0);
    }
    while(fread(&x[n],sizeof(sach),1,f)>0){
        ++n;
    }
    fclose(f);
}

unsigned int trungBInh(sach x[], int n){
    unsigned int tb =0;
    for(int i=0;i<n;++i){
        tb+=x[i].don_gia;
    }
    return tb/n;
}

int Search(sach x[], int n){
    int flag=0;
    unsigned int tb = trungBInh(x,n);
    for(int i=0;i<n;++i){
        if(x[i].don_gia > tb){
            flag=1;
            return i;
        }
    }
    if(flag==0) return -1;
}

int main()
{
    int n;
    sach ds[Max];
//    printf("\nNhap sl:  ");scanf("%d",&n);
//    nhap_n(ds,n);
    char duongdan[255];
//    getchar();
    printf("\nNhap duong dan: ");gets(duongdan);
//    ghiTep(ds,n,duongdan);
    docTep(ds,n,duongdan);
    xuat_n(ds,n);
    int tim = Search(ds,n);
    if(tim != -1){
        printf("\nVi tri %d",Search(ds,n));
    }else{
        printf("\nkhong tim thay!");
    }
    return 0;
}
