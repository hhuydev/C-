#include <iostream>
#include <string.h>
#include <stdlib.h>
#define MAX 10000
using namespace std;

typedef struct nhanvien{
    char manv[8],tennv[50];
    float hsl;
    int nbd;
}nv;

//typedef struct danhsach{
//    nv a[MAX];
//    int n;
//}Ds;

void Nhap__tt_1_nv(nv &temp){
    getchar();
    printf("\nNhap ma nhan vien: ");fgets(temp.manv,8,stdin);
    temp.manv[strlen(temp.manv)-1]='\0';
    printf("\nNhap ten nhan vien: ");fgets(temp.tennv,50,stdin);
    temp.tennv[strlen(temp.tennv)-1]='\0';
    printf("\nNhap he so luong: ");scanf("%f",&temp.hsl);
    printf("\nNhap nam bat dau: ");scanf("%d",&temp.nbd);
}

void Xuat__tt_1_nv(nv temp){
    printf("\nMa nhan vien: %s",temp.manv);
    printf("\nTen nhan vien: %s",temp.tennv);
    printf("\nHe so luong: %.2f",temp.hsl);
    printf("\nNam bat dau: %d",temp.nbd);
}

void Nhap(nv a[], int *n){
    printf("\nNhap so luong nhan vien: ");
    scanf("%d",n);
    for(int i=0;i<*n;++i){
        printf("\n\t\t\tNHAP THONG TIN NHAN VIEN %d",i+1);
        Nhap__tt_1_nv(a[i]);
    }
}

void Xuat(nv a[], int n){
    for(int i=0;i<n;++i){
        printf("\n\t\t\tTHONG TIN NHAN VIEN %d",i+1);
        Xuat__tt_1_nv(a[i]);
    }
}

void Ghitep(nv a[], char *duongdan, int n){
    FILE *f = fopen(duongdan,"wb");
    if(f==NULL){
        printf("\nKhong mo duoc tep!");exit(0);
    }
    fwrite(a,sizeof(nv),n,f);
    fclose(f);
}

void Doctep(nv a[], char *duongdan, int &n){
    FILE *f = fopen(duongdan,"rb");
    if(f==NULL){
        printf("Khong mo duoc tep!");exit(0);
    }
    //fseek(f,0,SEEK_END);
    //(*n) = (ftell(f)/sizeof(nv));
    n=0;
    printf("\n\t\t\tDoc thong tin tu tep");
    while(fread(&a[n],sizeof(nv),1,f)>0){
        n++;
    }
    //fread(a,sizeof(nv),(*n),f);
    fclose(f);
}

void lapBang(nv a[], int n){
    printf("\n\n|%-5s|%-10s | %-15s | %-15s | %-15s | %-20s |","STT","Ma nhan vien","Ho ten","He so luong","Nam bat dau","Luong");
    for(int i=0;i<n;++i){
        printf("\n");
        printf("|%-5d|%-13s| %-15s | %-15f | %-15d | %-20f |",i+1,a[i].manv,a[i].tennv,a[i].hsl,a[i].nbd,a[i].nbd*a[i].hsl*2000000);

    }
}

int main()
{
    nv a[1000];
    char duongdan[255];
    int n;
    Nhap(a,&n);
    Xuat(a,n);
    getchar();
    printf("\nNhap duong dan: ");fgets(duongdan,255,stdin);
    duongdan[strlen(duongdan)-1]='\0';
    Ghitep(a,duongdan,n);
    Doctep(a,duongdan,n);
    lapBang(a,n);
    return 0;
}
