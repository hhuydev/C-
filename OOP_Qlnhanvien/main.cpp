
#include <iostream>
#include <string>
using namespace std;
class Nhanvien{
protected:
    string hoten;
	string gioitinh;
	string diachi;
    string sdt;
public:
    void Nhap();
	void Xuat();
	Nhanvien();
	~Nhanvien();
};


class Nhanviensuaongnuoc : public Nhanvien{
private:
	float so_h_sua;
public:
	void Nhap_tt();
	void Xuat_tt();
	float Tinhtienluong();
};

class Nhanviengiaohang : public Nhanvien{
private:
	float so_h_giao;
public:
	void Nhap_tt();
	void Xuat_tt();
	float Tinhtienluong();

};

class Nhanvienxeom : public Nhanvien{
private:
	float so_h_chay;
public:
	void Nhap_tt();
	void Xuat_tt();
	float Tinhtienluong();
};

Nhanvien::Nhanvien(){

}

Nhanvien::~Nhanvien(){

}

void Nhanvien::Nhap() {
	cin.ignore();
	cout << "\nNhap ho ten: "; getline(cin, hoten);
	fflush(stdin);
	cout << "\nNhap gioi tinh: "; getline(cin, gioitinh);
	fflush(stdin);
	cout << "\nNhap so dien thoai: "; getline(cin,sdt);
	fflush(stdin);
	cout << "\nNhap dia chi: "; getline(cin, diachi);
}

void Nhanvien::Xuat() {
	cout << "\nHo ten: "<< hoten;
	cout << "\nGioi tinh: "<< gioitinh;
	cout << "\nSo dien thoai: "<<sdt;
	cout << "\nDia chi: "<<diachi;

}

void Nhanviensuaongnuoc::Nhap_tt(){
    Nhanvien::Nhap();
    cout << "\nNhap so gio sua: "; cin >> so_h_sua;
}

void Nhanviengiaohang::Nhap_tt() {
	Nhanvien::Nhap();
	cout << "\nNhap so gio giao hang: "; cin >> so_h_giao;
}

void Nhanvienxeom::Nhap_tt() {
	Nhanvien::Nhap();
	cout << "\nNhap so gio chay "; cin >> so_h_chay;
}

void Nhanviensuaongnuoc::Xuat_tt() {
	Nhanvien::Xuat();
	cout << "\nSo gio sua ong nuoc: " << so_h_sua;
}

void Nhanviengiaohang::Xuat_tt() {
	Nhanvien::Xuat();
	cout << "\nSo gio giao: " << so_h_giao;
}

void Nhanvienxeom::Xuat_tt() {
	Nhanvien::Xuat();
	cout << "\nSo gio chay: " << so_h_chay;
}

void Giai_phong(Nhanviensuaongnuoc *ds_nv_suaongnuoc[], Nhanviengiaohang *ds_nv_giaohang[], Nhanvienxeom *ds_nv_xeom[], int &n, int &m, int &l){
    for(int i=0;i<n;++i){
        delete ds_nv_suaongnuoc[i];
    }
    for(int i=0;i<m;++i){
        delete ds_nv_giaohang[i];
    }
    for(int i=0;i<l;++i){
        delete ds_nv_xeom[i];
    }
    ds_nv_giaohang = nullptr;
    ds_nv_suaongnuoc = nullptr;
    ds_nv_xeom = nullptr;
}

void Menu(Nhanviensuaongnuoc *ds_nv_suaongnuoc[], Nhanviengiaohang *ds_nv_giaohang[], Nhanvienxeom *ds_nv_xeom[], int n, int m, int l) {
	int chon;
	while (true) {
		system("cls");
		cout << "\n\n\t\t ====== CHUONG TRINH QUAN LI ======";
		cout << "\n1. Nhap thong tin nhan vien SUA ONG NUOC";
		cout << "\n2. Nhap thong tin nhan vien GIAO HANG";
		cout << "\n3. Nhap thong tin nhan vien XE OM CONG NGHE";
		cout << "\n4. Xuat danh sach thong tin nhan vien SUA ONG NUOC";
		cout << "\n5. Xuat danh sach thong tin nhan vien GIAO HANG";
		cout << "\n6. Xuat danh sach thong tin nhan vien XE OM CONG NGHE";
		cout << "\n7. Tong tien luong cua 3 loai nhan vien";
		cout << "\n8. Sap xep danh sach cac loai nhan vien giam dan theo luong";
		cout << "\n0. KET THUC";
		cout << "\n\n\t\t ============= END =================";

		cout << "\nNhap lua chon: "; cin >> chon;
		do
        {
            if(chon < 0 || chon>8)
                cout << "\nMoi nhap lai lua chon! ";
		} while (chon < 0 || chon>8);

		{
			if (chon == 1) {
				Nhanviensuaongnuoc *nv = new Nhanviensuaongnuoc();
				cout << "\n\n\n\tNHAP THONG TIN NHAN VIEN SUA ONG NUOC\n";
				nv->Nhap_tt();
				ds_nv_suaongnuoc[n] = nv;
				n++;

			}

			else if (chon == 2) {
				Nhanviengiaohang *nv = new Nhanviengiaohang();
				cout << "\n\n\n\tNHAP THONG TIN NHAN VIEN SUA ONG NUOC\n";
				nv->Nhap_tt();
				ds_nv_giaohang[m] = nv;
				m++;

			}

			else if (chon == 3) {
				Nhanvienxeom *nv = new Nhanvienxeom();
				cout << "\n\n\n\tNHAP THONG TIN NHAN VIEN SUA XE OM\n";
				nv->Nhap_tt();
				ds_nv_xeom[l] = nv;
				l++;

			}

			else if (chon == 4) {
				cout << "\n\n\t\t DANH SACH THONG TIN NHAN VIEN SUA ONG NUOC\n";
				for (int i = 0; i < n; i++)
				{
					cout << "\n\n\t THONG TIN NHAN VIEN SUA ONG NUOC THU " << i + 1;
					ds_nv_suaongnuoc[i]->Xuat_tt();
				}
				//cout << "\n\n\t\t TONG TIEN LUONG: " << (size_t)Tong_Tien_Luong_Nhan_Vien_Sua_Ong_Nuoc(ds_nv_suaongnuoc, n);
				system("pause");
			}

			else if (chon == 5) {
				cout << "\n\n\t\t DANH SACH THONG TIN NHAN VIEN GIAO HANG\n";
				for (int i = 0; i < m; i++)
				{
					cout << "\n\n\t THONG TIN NHAN VIEN GIAO HANG THU " << i + 1;
					ds_nv_giaohang[i]->Xuat_tt();
				}

				//cout << "\n\n\t\t TONG TIEN LUONG: " << (size_t)Tong_Tien_Luong_Nhan_Vien_Giao_Hang(ds_nv_giaohang, m);
				//system("pause");
				system("pause");
			}

			else if (chon == 6) {
				cout << "\n\n\t\t DANH SACH THONG TIN NHAN VIEN XE OM\n";
				for (int i = 0; i < l; i++)
				{
					cout << "\n\n\t THONG TIN NHAN VIEN XE OM THU " << i + 1;
					ds_nv_xeom[i]->Xuat_tt();
				}

				//cout << "\n\n\t\t TONG TIEN LUONG: " << (size_t)Tong_Tien_Luong_Nhan_Vien_Giao_Hang(ds_nv_giaohang, m);
				system("pause");
			}
			else if (chon == 0){
                break;
			}

		}
	}
}

int main() {
	Nhanviensuaongnuoc *ds_nv_suaongnuoc[100];
	Nhanviengiaohang *ds_nv_giaohang[100];
	Nhanvienxeom *ds_nv_xeom[100];
	int n = 0, m = 0, l = 0;
	Menu(ds_nv_suaongnuoc, ds_nv_giaohang, ds_nv_xeom, n, m, l);
	Giai_phong(ds_nv_suaongnuoc,ds_nv_giaohang,ds_nv_xeom,n,m,l);
	return 0;
}
