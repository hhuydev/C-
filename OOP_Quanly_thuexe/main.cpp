#include <iostream>
#include <string>
using namespace std;

//Khai bao lop cha
class Xe{
protected:
    string Tennguoithue;
    float Giothue;
public:
    void Nhap(){
    cin.ignore();
    cout<<"\nNhap ho ten nguoi thue: ";getline(cin,Tennguoithue);
    cout<<"\nNhap so gio thue: ";cin>>Giothue;
    }
    void Xuat(){
    cout<<"\nNhap ho ten nguoi thue: "<<Tennguoithue;
    cout<<"\nNhap so gio thue: "<<Giothue;
    }
};

class Xedap : public Xe
{
private:
public:
    float Tinhtienthue(){
        return 10000 + (Giothue - 1)*8000;
    }
};

class Xemay : public Xe
{
private:
    int loaixe;
    string bienso;
public:
    void Nhap_tt(){
    Xe::Nhap();
    cout<<"\nNhap loai phan khoi xe (100 - 250): ";cin>>loaixe;
    cin.ignore();
    cout<<"\nNhap bien so: ";getline(cin,bienso);
    }
    void Xuat_tt(){
    Xe::Xuat();
    cout<<"\nLoai phan khoi xe (100 - 250): "<<loaixe;
    cout<<"\nBien so: "<<bienso;
    }
    float Tinhtienthue(){
    float s = 0;
    if(loaixe == 100){
        s=150000;
    }
    else{
        s=200000;
    }
    return (size_t)s + (Giothue - 1)*100000;
    }
    int Getter_loaixe(){
        return loaixe;
    }
    void Setter_loaixe(int LoaiXE){
        loaixe = LoaiXE;
    }

};

void XuatThongTin(Xedap ds_xedap[], int n, Xemay ds_xemay[], int m){
    for(int i=0;i<n;i++){
        cout<<"\n\n\t\tXuat thong tin xe dap thu "<<i+1;
        ds_xedap[i].Xuat();
        cout<<"\nTien thue: "<<ds_xedap[i].Tinhtienthue();
    }
    for(int i=0;i<m;i++){
        cout<<"\n\n\t\tXuat thong tin xe may thu "<<i+1;
        ds_xemay[i].Xuat_tt();
        cout<<"\nTien thue: "<<ds_xemay[i].Tinhtienthue();
    }
}

float Tong_Tien_Thue_Xe(Xedap ds_xedap[], int n, Xemay ds_xemay[], int m){
    float s = 0;
    for(int i=0;i<n;i++){
        s+=ds_xedap[i].Tinhtienthue();
    }
    for(int i=0;i<m;i++){
        s+=ds_xemay[i].Tinhtienthue();
    }
    return s;
}

long Tong_Tien_Thue_Xe_250(Xemay ds_xemay[], int m){
    for(int i=0;i<m;i++){
        if(ds_xemay[i].Getter_loaixe() == 250){
            cout<<"\n\n\t\tXuat thong tin xe may thu "<<i+1;
           // ds_xemay[i].Xuat_tt();
            cout<<"\nTien thue: "<<ds_xemay[i].Tinhtienthue();
        }
    }
}

void Menu(Xedap ds_xedap[], int n, Xemay ds_xemay[], int m){
    int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ====== QUAN LY XE ======";
		cout << "\n\t1. Nhap danh sach thue xe dap va xe may";
		cout << "\n\t2. Xuat tat ca thong tin thue xe";
		cout << "\n\t3. Tinh tong so tien cho thue xe dap va xe may";
		cout << "\n\t4. Xuat tat ca cac thong tin lien quan den viec cho thue xe dap";
		cout << "\n\t5. Tinh tong so tien cho thue xe may loai 250 phan khoi";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== END ============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if(luachon == 1){
            int chon;
            while(true){
                system("cls");
                cout<<"\n1.Thue xe dap";
                cout<<"\n2.Thue xe may";
                cout<<"\n0.Thoat";
                cout<<"\nNhap lua chon: ";cin>>chon;

                if(chon == 1){
                    Xedap x;
                    cout<<"\n\n\t\tNhap thong tin xe dap";
                    x.Nhap();
                    ds_xedap[n] = x;
                    n++;
                }
                else if(chon == 2){
                    Xemay x;
                    cout<<"\n\n\t\tNhap thong tin xe may";
                    x.Nhap_tt();
                    ds_xemay[m] = x;
                    m++;
                }
                else {
                    break;
                }
                }
            }
        else if(luachon == 2){
            XuatThongTin(ds_xedap,n,ds_xemay,m);
            system("pause");
        }
        else if(luachon == 3){
            Tong_Tien_Thue_Xe(ds_xedap,n,ds_xemay,m);
            system("pause");
        }
        else if(luachon == 4){
            for(int i=0;i<n;i++){
                cout<<"\n\n\t\tXuat thong tin xe dap thu "<<i+1;
                ds_xedap[i].Xuat();
                cout<<"\nTien thue: "<<ds_xedap[i].Tinhtienthue();
            }
            system("pause");
        }
        else if(luachon == 5){
            Tong_Tien_Thue_Xe_250(ds_xemay,m);
            system("pause");
        }
        else{
            break;
        }
	}
}

int main()
{
    Xedap ds_xedap[100];
    Xemay ds_xemay[100];
    int n=0,m=0;
    Menu(ds_xedap,n,ds_xemay,m);
    return 0;
}
