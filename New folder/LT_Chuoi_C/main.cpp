#include <stdio.h>
#include <string.h>
#include <string>
void Str_Lwr(char *x){
    printf("\nChuyen chuoi thanh in thuong: %s", strlwr(x));
}

void Delete(char *x, int position){
    int n = strlen(x);
    for(int i=position; i<n; ++i){
        x[i] = x[i+1];
    }
    x[n-1] = '\0';
}

void Delete_Space(char *x){
    int n = strlen(x);
    if(x[0] == ' ')
        Delete(x,0);
    for(int i=0;i<n;++i){
        if(x[i] == ' ' && x[i+1] == ' '){
            Delete(x,i+1);
            --i;
        }
    }
    if(x[n-1]==' ')
        Delete(x,n-1);
}

void InHoaDau(char *x){
    int n = strlen(x);
    if(x[0]!=' '){
        if(x[0] >= 'a' && x[0] <= 'z')
            x[0]-=32;
        for(int i=1;i<n-1;++i){
            if(x[i]==' ' && x[i+1]!=' ')
                x[i+1]-=32;
        }
    }
}

char *Xuat_Tu_Dai_Nhat(char *x ,char *temp, char *result){
    //char temp[20];
    //char result[20];
    int lengest = 0, j=0;
    for(int i=0;i<=strlen(x);++i){
        if(x[i]!=' ' && x[i]!='\0'){
            temp[j++] = x[i];
        }
        else{
            temp[j] = '\0';
            if(strlen(temp) > lengest){
                strcpy(result, temp);
                lengest = strlen(temp);
            }
            j=0;
        }
    }
    return result;
}

void Trich_Xuat_Vitri(char *x, int &vt){
    printf("\nMoi nhap vi tri can trich xuat trong chuoi: ");
    while(vt<0 || vt > strlen(x)-1){
        scanf("%d",&vt);
        if(vt<0 || vt > strlen(x)-1)
            printf("\nMoi nhap lai vi tri phu hop!");
    }
    printf("\n%s",substr(x,0,vt));
}

int main () {
   char str[50];
  fflush(stdin);
   printf("Enter a string : ");
   fgets(str,50,stdin);
   //gets(str);
   printf("\nDo dai chuoi: %d",strlen(str));
    puts(str);
    Str_Lwr(str);
    printf("\Xoa cac khoang trang trong chuoi: ");
    Delete_Space(str);
    printf("\nChuoi sau khi xoa: %s",str);
    printf("\nDo dai chuoi sau khi xoa: %d",strlen(str));
    printf("\nIn hoa ki tu dau trong chuoi: ");
    InHoaDau(str);
    printf("%s",str);
    char result[20],temp[20];
    printf("\nXuat tu dai nhat trong chuoi: ");
    printf("%s",Xuat_Tu_Dai_Nhat(str,temp,result));
    int vt;
    Trich_Xuat_Vitri(str);
   return(0);
}
