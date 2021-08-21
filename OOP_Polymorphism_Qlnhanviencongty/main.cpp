#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Namsinh{
private:
    int ngay;
    int thang;
    int nam;
public:
    int Getter_Ngay(){
        return ngay;
    }
    void Setter_Ngay(int NGAY){
        ngay = NGAY;
    }
    int Getter_Thang(){
        return thang;
    }
    void Setter_Thang(int THANG){
        thang = THANG;
    }
    int Getter_Nam(){
        return nam;
    }
    void Setter_Nam(int NAM){
        nam = NAM;
    }
};


class Nhanvien{
protected:
    string manv;
    string tennv;
    Namsinh namsinh;
    string diachi;
    float luongcoban;
    float hesoluong;
public:
    virtual void DocFile(ifstream &);
    virtual void Xuat();

};

class NhanvienLT  : public Nhanvien
{
private:
    float tienlamthem;
public:
    void DocFile(ifstream &);
    void Xuat();
};

class NhanvienTK  : public Nhanvien
{
private:
    float tienthuongthem;
public:
    void DocFile(ifstream &);
    void Xuat();
};

void Nhanvien::DocFile(ifstream &filein){
    cin.ignore();
    getline(filein,manv,',');
    filein.seekg(1,ios_base::cur);  //tham so 1 thu hai la vi tri con tro can dich
    fflush(stdin);
    getline(filein,tennv,','); //-1 la ben trai, 0 hien tai, 1 ben phai
    int ngay;               //tham so 1 dau la so byte can dich chuyen
    filein >> ngay;
    namsinh.Setter_Ngay(ngay);
    filein.seekg(1,ios_base::cur);
    int thang;
    filein >> thang;
    namsinh.Setter_Thang(thang);
    filein.seekg(1,ios_base::cur);
    int nam;
    filein >> nam;
    namsinh.Setter_Nam(nam);
    filein.seekg(2,ios_base::cur);
    fflush(stdin);
    getline(filein, diachi, ',');
    filein >> hesoluong;
    filein.seekg(1,ios_base::cur);
    filein >> luongcoban;
    filein.seekg(1,ios_base::cur);
}

void Nhanvien::Xuat(){
    cout<<"\nMa nhan vien: "<<manv;
    cout<<"\nHo ten nhan vien: "<<tennv;
    cout<<"\nNgay thang nam sinh: "<<namsinh.Getter_Ngay() <<"/"<<namsinh.Getter_Thang()<<"/"<<namsinh.Getter_Nam();
    cout<<"\nDia chi nhan vien: "<<diachi;
    cout<<"\nhe so luong: "<<hesoluong;
    cout<<"\nLuong co ban: "<<luongcoban;
}

void NhanvienLT::DocFile(ifstream &filein){
    Nhanvien::DocFile(filein);
    filein >> tienlamthem;
}

void NhanvienLT::Xuat(){
    Nhanvien::Xuat();
    cout<<"\nTien lam ngoai gio: "<<tienlamthem;
}

void NhanvienTK::DocFile(ifstream &filein){
    Nhanvien::DocFile(filein);
    filein >> tienthuongthem;
}


void NhanvienTK::Xuat(){
    Nhanvien::Xuat();
    cout<<"\nTien thuong them: "<<tienthuongthem;
}

void Menu(Nhanvien *a[], int &n){
    int luachon;
    ifstream filein;
    filein.open("NHANVIEN.txt",ios_base::in);
    while(69){
    system("cls");
    cout<<"\n|1.Doc thong tin cac nhan vien .";
    cout<<"\n|2.Xuat thong tin cac nhan vien.";

    cout<<"\nHay chon: ";cin>>luachon;
    if(luachon == 1){
        filein >> n;
        Nhanvien *x = NULL;
        for(int i=0;i<n;++i){
            char c;
            filein >> c;
           // filein.seekg(-1,ios_base::cur); //Lui con tro ve dau vong de doc het thong tin
            if(c == 'P'){
               x = new NhanvienLT() ;
               x->DocFile(filein);

            }
            else if(c == 'D'){
                x = new NhanvienTK();
                x->DocFile(filein);

            }
            a[i] = x;
        }

    }
    else if(luachon == 2){
        for(int i=0;i<n;++i){
            cout<<"\nThong tin nhan vien thu "<<i+1;
            a[i]->Xuat();

        }
        system("pause");

    }
    else{
        break;
    }

    }
    filein.close();
}

int main()
{
    Nhanvien *a[100];
    int n=0;
    Menu(a,n);
    return 0;
}
