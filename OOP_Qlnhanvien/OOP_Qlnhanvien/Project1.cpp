#include <iostream>
#include <string>
using namespace std;
class Nhanviensuaongnuoc {
private:
	string hoten;
	string gioitinh;
	string diachi;
	string so_h_sua;
	long sdt;
public:
	void Nhap();
	void Xuat();
	float Tinhtienluong();
	Nhanviensuaongnuoc();
	~Nhanviensuaongnuoc();
};

class Nhanviengiaohang {
private:
	string hoten;
	string gioitinh;
	string diachi;
	string so_h_giao;
	long sdt;
public:
	void Nhap();
	void Xuat();
	float Tinhtienluong();
	Nhanviengiaohang();
	~Nhanviengiaohang();
};

class Nhanvienxeom {
private:
	string hoten;
	string gioitinh;
	string diachi;
	float so_h_chay;
	long sdt;
public:
	void Nhap();
	void Xuat();
	float Tinhtienluong();
	Nhanvienxeom();
	~Nhanvienxeom();
};

void Nhanviensuaongnuoc::Nhap() {
	fflush(stdin);
	cout << "\nNhap ho ten: "; getline(cin, hoten);
	cout << "\nNhap gioi tinh: "; getline(cin, hoten);
	cout << "\nNhap so dien thoai: "; cin >> sdt;
	cin.ignore();
	cout << "\nNhap dia chi: "; getline(cin, hoten);
	cout << "\nNhap so gio sua ong nuoc: "; cin >> so_h_sua;
}

void Nhanviengiaohang::Nhap() {
	fflush(stdin);
	cout << "\nNhap ho ten: "; getline(cin, hoten);
	cout << "\nNhap gioi tinh: "; getline(cin, hoten);
	cout << "\nNhap so dien thoai: "; cin >> sdt;
	cin.ignore();
	cout << "\nNhap dia chi: "; getline(cin, hoten);
	cout << "\nNhap so gio giao hang: "; cin >> so_h_giao;
}

void Nhanvienxeom::Nhap() {
	fflush(stdin);
	cout << "\nNhap ho ten: "; getline(cin, hoten);
	cout << "\nNhap gioi tinh: "; getline(cin, hoten);
	cout << "\nNhap so dien thoai: "; cin >> sdt;
	cin.ignore();
	cout << "\nNhap dia chi: "; getline(cin, hoten);
	cout << "\nNhap so gio chay "; cin >> so_h_chay;
}

void Nhanviensuaongnuoc::Xuat() {
	cout << "\nNhap ho ten: "<< hoten;
	cout << "\nNhap gioi tinh: "<< hoten;
	cout << "\nNhap so dien thoai: "<<sdt;
	cout << "\nNhap dia chi: "<<hoten;
	cout << "\nNhap so gio sua ong nuoc: "<< so_h_sua;
}

void Nhanviengiaohang::Xuat() {
	cout << "\nNhap ho ten: " << hoten;
	cout << "\nNhap gioi tinh: " << hoten;
	cout << "\nNhap so dien thoai: " << sdt;
	cout << "\nNhap dia chi: " << hoten;
	cout << "\nNhap so gio sua ong nuoc: " << so_h_giao;
}

void Nhanvienxeom::Xuat() {
	cout << "\nNhap ho ten: " << hoten;
	cout << "\nNhap gioi tinh: " << hoten;
	cout << "\nNhap so dien thoai: " << sdt;
	cout << "\nNhap dia chi: " << hoten;
	cout << "\nNhap so gio sua ong nuoc: " << so_h_chay;
}

void Menu(Nhanviensuaongnuoc ds_nv_suaongnuoc[], Nhanviengiaohang ds_nv_giaohang[], Nhanvienxeom ds_nv_xeom[], int n, int m, int l) {
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
			cout << "\nMoi nhap lai lua chon! ";
		} while (chon < 0 || chon>8);

		{
			if (chon == 1) {
				Nhanviensuaongnuoc nv_suaongnuoc;
				cout << "\n\n\n\tNHAP THONG TIN NHAN VIEN SUA ONG NUOC\n";
				nv_suaongnuoc.Nhap();
				ds_nv_suaongnuoc[n] = nv_suaongnuoc;
				++n;
			}

			else if (chon == 2) {
				Nhanviengiaohang nv_giaohang;
				cout << "\n\n\n\tNHAP THONG TIN NHAN VIEN SUA ONG NUOC\n";
				nv_giaohang.Nhap();
				ds_nv_giaohang[m] = nv_giaohang;
				++m;
			}

			else if (chon == 3) {
				Nhanvienxeom nv_xeom;
				cout << "\n\n\n\tNHAP THONG TIN NHAN VIEN SUA ONG NUOC\n";
				nv_xeom.Nhap();
				ds_nv_xeom[l] = nv_xeom;
				++l;
			}

			else if (chon == 4) {
				cout << "\n\n\t\t DANH SACH THONG TIN NHAN VIEN SUA ONG NUOC\n";
				for (int i = 0; i < n; i++)
				{
					cout << "\n\n\t THONG TIN NHAN VIEN SUA ONG NUOC THU " << i + 1;
					ds_nv_suaongnuoc[i].Xuat();
				}
				//cout << "\n\n\t\t TONG TIEN LUONG: " << (size_t)Tong_Tien_Luong_Nhan_Vien_Sua_Ong_Nuoc(ds_nv_suaongnuoc, n);
			}

			else if (chon == 5) {
				cout << "\n\n\t\t DANH SACH THONG TIN NHAN VIEN GIAO HANG\n";
				for (int i = 0; i < m; i++)
				{
					cout << "\n\n\t THONG TIN NHAN VIEN GIAO HANG THU " << i + 1;
					ds_nv_giaohang[i].Xuat();
				}

				//cout << "\n\n\t\t TONG TIEN LUONG: " << (size_t)Tong_Tien_Luong_Nhan_Vien_Giao_Hang(ds_nv_giaohang, m);
				//system("pause");
			}

			else if (chon == 6) {
				cout << "\n\n\t\t DANH SACH THONG TIN NHAN VIEN XE OM\n";
				for (int i = 0; i < l; i++)
				{
					cout << "\n\n\t THONG TIN NHAN VIEN XE OM THU " << i + 1;
					ds_nv_giaohang[i].Xuat();
				}

				//cout << "\n\n\t\t TONG TIEN LUONG: " << (size_t)Tong_Tien_Luong_Nhan_Vien_Giao_Hang(ds_nv_giaohang, m);
				//system("pause");
			}

		}
	}
}

int main() {
	Nhanviensuaongnuoc ds_nv_suaongnuoc[100];
	Nhanviengiaohang ds_nv_giaohang[100];
	Nhanvienxeom ds_nv_xeom[100];
	int n = 0, m = 0, l = 0;
	Menu(ds_nv_suaongnuoc, ds_nv_giaohang, ds_nv_xeom, n, m, l);
	return 0;
}
