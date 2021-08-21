#include <iostream>
#include <string>
using namespace std;

class Nhanviensuaongnuoc{
private:
    string hoten;
    int tuoi;
    string sdt;
    string quequan;
    string gioitinh;
    float giosua;
public:
    void Nhap();
    void Xuat();
    float Tinh_luong();
    Nhanviensuaongnuoc();
    ~Nhanviensuaongnuoc();
};
void Nhanviensuaongnuoc::Nhap(){
    cin.ignore();
    cout<<"\nNhap ten: ";getline(cin,hoten);
    cout<<"\nNhap tuoi: ";cin>>tuoi;
    fflush(stdin);
    cout<<"\nNhap sdt: ";getline(cin,sdt);
    fflush(stdin);
    cout<<"\nNhap que quan: ";getline(cin,quequan);
    fflush(stdin);
    cout<<"\nNhap gioi tinh: ";getline(cin,gioitinh);
    cout<<"\nSo gio sua: ";cin>>giosua;
}
void Nhanviensuaongnuoc::Xuat(){
    //cin.ignore();
    cout<<"\nTen: "<<hoten;
    cout<<"\nTtuoi: "<<tuoi;
    //cin.ignore();
    cout<<"\nSdt: "<<sdt;
    //cin.ignore();
    cout<<"\nQue quan: "<<quequan;
    cout<<"\nGioi tinh: "<<gioitinh;
    cout<<"\nGio sua: "<<giosua;
}

class Nhanviengiaohang{
private:
    string hoten;
    int tuoi;
    string sdt;
    string quequan;
    string gioitinh;
    float hanggiao;
public:
    void Nhap();
    void Xuat();
    float Tinh_luong();
    Nhanviengiaohang();
    ~Nhanviengiaohang();
};

void Nhanviengiaohang::Nhap(){
    cin.ignore();
    cout<<"\nNhap ten: ";getline(cin,hoten);
    cout<<"\nNhap tuoi: ";cin>>tuoi;
    fflush(stdin);
    cout<<"\nNhap sdt: ";getline(cin,sdt);
    fflush(stdin);
    cout<<"\nNhap que quan: ";getline(cin,quequan);
    fflush(stdin);
    cout<<"\nNhap gioi tinh: ";getline(cin,gioitinh);
    cout<<"\nSo hang giao: ";cin>>hanggiao;
}
void Nhanviengiaohang::Xuat(){
    //cin.ignore();
    cout<<"\nTen: "<<hoten;
    cout<<"\nTtuoi: "<<tuoi;
    //cin.ignore();
    cout<<"\nSdt: "<<sdt;
    //cin.ignore();
    cout<<"\nQue quan: "<<quequan;
    cout<<"\nGioi tinh: "<<gioitinh;
    cout<<"\nHang giao: "<<hanggiao;
}

class Nhanvienxeom{
private:
    string hoten;
    int tuoi;
    string sdt;
    string quequan;
    string gioitinh;
    float sokm;
public:
    void Nhap();
    void Xuat();
    float Tinh_luong();
    Nhanvienxeom();
    ~Nhanvienxeom();
};
void Nhanvienxeom::Nhap(){
    cin.ignore();
    cout<<"\nNhap ten: ";getline(cin,hoten);
    cout<<"\nNhap tuoi: ";cin>>tuoi;
    fflush(stdin);
    cout<<"\nNhap sdt: ";getline(cin,sdt);
    fflush(stdin);
    cout<<"\nNhap que quan: ";getline(cin,quequan);
    fflush(stdin);
    cout<<"\nNhap gioi tinh: ";getline(cin,gioitinh);
    cout<<"\nSo km ";cin>>sokm;
}
void Nhanvienxeom::Xuat(){
    //cin.ignore();
    cout<<"\nTen: "<<hoten;
    cout<<"\nTtuoi: "<<tuoi;
    //cin.ignore();
    cout<<"\nSdt: "<<sdt;
    //cin.ignore();
    cout<<"\nQue quan: "<<quequan;
    cout<<"\nGioi tinh: "<<gioitinh;
    cout<<"\nKm: "<<sokm;
}
float Nhanvienxeom::Tinh_luong(){
    return sokm*10000;
}
float Nhanviensuaongnuoc::Tinh_luong(){
    return giosua*50000;
}
float Nhanviengiaohang::Tinh_luong(){
    return hanggiao*25000;
}
Nhanviengiaohang::Nhanviengiaohang(){

}
Nhanviengiaohang::~Nhanviengiaohang(){

}
Nhanviensuaongnuoc::Nhanviensuaongnuoc(){

}
Nhanviensuaongnuoc::~Nhanviensuaongnuoc(){

}
Nhanvienxeom::Nhanvienxeom(){

}
Nhanvienxeom::~Nhanvienxeom(){

}

double Tong_Tien_Luong_Nhan_Vien_Sua_Ong_Nuoc(Nhanviensuaongnuoc ds[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += ds[i].Tinh_luong();
	}
	return sum;
}
double Tong_Tien_Luong_Nhan_Vien_Giao_Hang(Nhanviengiaohang ds[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += ds[i].Tinh_luong();
	}
	return sum;
}
double Tong_Tien_Luong_Nhan_Vien_Xe_Om_Cong_Nghe(Nhanvienxeom ds[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += ds[i].Tinh_luong();
	}
	return sum;
}

void Menu(Nhanviensuaongnuoc ds_nv_suaongnuoc[], Nhanviengiaohang ds_nv_giaohang[], Nhanvienxeom ds_nv_xeom[], int n, int m, int l)
{
    int chon;
    while(true){
        system("cls");
        cout << "\n\n\t\t ====== CHUONG TRINH QUAN LI ======";
		cout << "\n1. Nhap thong tin nhan vien SUA ONG NUOC";
		cout << "\n2. Nhap thong tin nhan vien GIAO HANG";
		cout << "\n3. Nhap thong tin nhan vien XE OM CONG NGHE";
		cout << "\n4. Xuat danh sach thong tin nhan vien SUA ONG NUOC";
		cout << "\n5. Xuat danh sach thong tin nhan vien GIAO HANG";
		cout << "\n6. Xuat danh sach thong tin nhan vien XE OM CONG NGHE";
		cout << "\n7. Tong tien luong cua 3 loai nhan vien";
		//cout << "\n8. Sap xep danh sach cac loai nhan vien giam dan theo luong";
		cout << "\n0. KET THUC";
		cout << "\n\n\t\t ============= END =================";

        do{
          cout<<"\nNhap lua chon: ";
          cin>>chon;
          if(chon < 0 || chon > 7)
            cout<<"\nMoi nhap lai lua chon! ";
        }while(chon < 0 || chon > 7);
        if(chon == 0){
            break;
        }
        else if(chon == 1){
            Nhanviensuaongnuoc nv_suaongnuoc;
            cout<<"\n\n\t\tNhap thong tin nhan vien sua ong nuoc";
            nv_suaongnuoc.Nhap();
            ds_nv_suaongnuoc[n] = nv_suaongnuoc;
            n++;
        }
        else if(chon == 2){
            Nhanviengiaohang nv_giaohang;
            cout<<"\n\n\t\tNhap thong tin nhan vien giao hang";
            nv_giaohang.Nhap();
            ds_nv_giaohang[m] = nv_giaohang;
            m++;
        }
        else if(chon == 3){
            Nhanvienxeom nv_xeom;
            cout<<"\n\n\t\tNhap thong tin nhan vien xe om";
            nv_xeom.Nhap();
            ds_nv_xeom[l] = nv_xeom;
            l++;
        }
        else if(chon == 4){
            for (int i = 0; i < n; i++)
			{
				cout << "\n\n\t THONG TIN NHAN VIEN SUA ONG NUOC THU " <<i + 1;
				ds_nv_suaongnuoc[i].Xuat();
			}
			cout<<"\nTONG LUONG: "<<(size_t)Tong_Tien_Luong_Nhan_Vien_Sua_Ong_Nuoc(ds_nv_suaongnuoc, n);
			system("pause");
        }
        else if(chon == 5){
            for (int i = 0; i < m; i++)
			{
				cout << "\n\n\t THONG TIN NHAN VIEN GIAO HANG THU " << i + 1;
				ds_nv_giaohang[i].Xuat();
			}
			cout<<"\nTONG LUONG: "<<(size_t)Tong_Tien_Luong_Nhan_Vien_Giao_Hang(ds_nv_giaohang, m);
			system("pause");
        }
        else if(chon == 6){
            for (int i = 0; i < l; i++)
			{
				cout << "\n\n\t THONG TIN NHAN VIEN XE OM CONG NGHE THU " << i + 1;
				ds_nv_xeom[i].Xuat();
			}
			cout<<"\nTONG LUONG: "<<(size_t)Tong_Tien_Luong_Nhan_Vien_Xe_Om_Cong_Nghe(ds_nv_xeom, l);
			system("pause");
        }
        else if(chon == 7){
            cout<<"\nTONG LUONG CAC NHAN VIEN: "<<(size_t)(Tong_Tien_Luong_Nhan_Vien_Sua_Ong_Nuoc(ds_nv_suaongnuoc,n)+Tong_Tien_Luong_Nhan_Vien_Giao_Hang(ds_nv_giaohang,m)+Tong_Tien_Luong_Nhan_Vien_Xe_Om_Cong_Nghe(ds_nv_xeom,l));
        }
    }
}

int main(){
    Nhanviengiaohang ds_nv_giaohang[100];
    Nhanviensuaongnuoc ds_nv_suaongnuoc[100];
    Nhanvienxeom ds_nv_xeom[100];
    int n,m,l;
    n=0;m=0;l=0;
    Menu(ds_nv_suaongnuoc,ds_nv_giaohang,ds_nv_xeom,n,m,l);
}
