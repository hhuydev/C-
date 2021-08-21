#include<iostream>
using namespace std;
#include<fstream>
#include<Cstring>
#include<vector>
#pragma warning(disable:4996)

// khai báo cấu trúc môn học
struct monhoc
{
	string tenmonhoc;
	float diem;
};
typedef struct monhoc MonHoc;

// khai báo cấu trúc sinh viên
struct sinhvien
{
	string hoten;
	string maso;
	string namsinh;
	vector< MonHoc> ds_monhoc;// mảng 1 chiều các môn học của sinh viên
};
typedef struct sinhvien SinhVien;

// hàm đọc file thông tin của 1 thằng sinh viên
void Doc_File_Thong_Tin_Sinh_Vien(ifstream &filein, SinhVien &sv)
{
	getline(filein, sv.hoten, ','); // đọc dữ liệu đến dấu ','
	getline(filein, sv.maso, ','); // đọc dữ liệu đến dấu ','
	getline(filein, sv.namsinh); // đọc dữ liệu đến dấu ','
}

// hàm đọc file thông tin của 1 môn học
void Doc_File_Thong_Tin_Mon_Hoc(ifstream &filein, MonHoc &mon)
{
	getline(filein, mon.tenmonhoc, '-'); // đọc dữ liệu đến dấu '-'
	filein >> mon.diem; // đọc điểm từ file
}

// hàm đọc thông tin sinh viên và danh sách môn học tương ứng
void Doc_File(ifstream &filein, vector< SinhVien> &ds_sinhvien)
{
	// vòng lặp lặp đến cuối file thì dừng
	while (filein.eof() == false)
	{
		SinhVien sv; // khai báo ra sinh viên để nhận dữ liệu từ file về
		// BƯỚC 1: đọc thông tin của 1 thằng sinh viên
		Doc_File_Thong_Tin_Sinh_Vien(filein, sv);
		// BƯỚC 2: đọc số lượng môn học mà sinh viên đã học
		int n; // số lượng môn học
		filein >> n; // đọc dữ liệu mà số lượng môn học từ file

		// có cái này để đọc kí tự '\n' của cái dòng bên trên
		string temp;
		getline(filein, temp);
		// BƯỚC 3: đọc danh sách các môn học mà thằng sinh viên đã học
		for (int i = 1; i <= n; i++)
		{
			MonHoc mon; // khai báo MonHoc để chứa dữ liệu đọc từ file về
			Doc_File_Thong_Tin_Mon_Hoc(filein, mon);
			// có cái này để đọc kí tự '\n' của cái dòng bên trên
			getline(filein, temp);
			sv.ds_monhoc.push_back(mon); // thêm 1 môn học vào cuối mảng vector danh sách môn học của thằng sinh viên tương ứng
		}

		// BƯỚC 4: Thêm thông tin sinh viên vào mảng 1 chiều vector sinh viên - danh sách sinh viên
		ds_sinhvien.push_back(sv); // thêm sinh viên vào cuối mảng
	}
}

// hàm xuất thông tin của 1 thằng sinh viên
void Xuat_Thong_Tin_Sinh_Vien(SinhVien sv)
{
	cout << "\nHo ten sinh vien: " << sv.hoten;
	cout << "\nMa so sinh vien: " << sv.maso;
	cout << "\nNgay thang nam sinh: " << sv.namsinh;
}

// hàm xuất thông tin của 1 môn học
void Xuat_Thong_Tin_Mon_Hoc(MonHoc mon)
{
	cout << "\nTen mon hoc: " << mon.tenmonhoc;
	cout << "\nDiem: " << mon.diem;
}
// hàm test xuất dữ liệu sinh viên
void Test(vector<SinhVien> ds)
{
	for (int i = 0; i < ds.size(); i++)
	{
		cout << "\n\n\t\t\t SINH VIEN THU " << i + 1;
		// gọi hàm xuất thông tin của sinh viên
		Xuat_Thong_Tin_Sinh_Vien(ds[i]);
		cout << "\n=========== DANH SACH MON HOC TUONG UNG ===========\n";
		// xuất ra danh sách các môn học của thằng sinh viên thứ i tương ứng
		for (int j = 0; j < ds[i].ds_monhoc.size(); j++)
		{
			cout << "\n\t\tMON HOC THU " << j + 1;
			Xuat_Thong_Tin_Mon_Hoc(ds[i].ds_monhoc[j]);
		}
	}
}

// câu 2: hàm xuất tất cả thông tin của sinh viên có tên trùng
void Tim_Kiem_Sinh_Vien_Theo_Ho_Ten(vector<SinhVien> ds, string hoten)
{
	int dem = 1;
	for (int i = 0; i < ds.size(); i++)
	{
		// dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
		if (stricmp(ds[i].hoten.c_str(), hoten.c_str()) == 0)
		{
			cout << "\n\n\t\t\t SINH VIEN THU " << dem++;
			// BƯỚC 1: xuất thông tin của sinh viên
			Xuat_Thong_Tin_Sinh_Vien(ds[i]);
			// BƯỚC 2: xuất ra danh sách các môn học của sinh viên tương ứng
			int n = ds[i].ds_monhoc.size(); // số lượng các môn học
			for (int j = 0; j < n; j++)
			{
				cout << "\n\t\t MON HOC THU " << j + 1;
				Xuat_Thong_Tin_Mon_Hoc(ds[i].ds_monhoc[j]);
			}
		}
	}
}

// ======================= CÂU 3  =======================
// 21/11/1995
// temp: 1995
string Tach_Nam_Sinh(string str)
{
	string temp; // chứa năm sinh sau khi tách từ chuỗi ngày tháng năm
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			temp.insert(temp.begin() + 0, str[i]); // thêm kí tự str[i] vào vị trí số 0 - str[i] là các kí tự số [0 - 9]
		}
		else
		{
			break; // thoát khỏi vòng lặp - đã lấy xong năm sinh từ chuỗi ngày tháng năm
		}
	}
	return temp;
}

// hàm ghi thông tin môn học vào file
void Ghi_Thong_Tin_Mon_Hoc(ofstream &fileout, MonHoc mon)
{
	fileout << mon.tenmonhoc << "-" << mon.diem;
}

// hàm ghi vào file thông tin sinh viên
void Ghi_Thong_Tin_Sinh_Vien(ofstream &fileout, SinhVien sv)
{
	// dòng đầu tiên ghi vào file thông tin cơ bản
	fileout << sv.hoten << "," << sv.maso << "," << sv.namsinh << endl;
	// dòng thứ 2 lưu số lượng môn học của sinh viên
	fileout << sv.ds_monhoc.size() << endl;
	// các dòng tiếp theo ghi vào file các môn học của sinh viên tương ứng
	for (int i = 0; i < sv.ds_monhoc.size(); i++)
	{
		Ghi_Thong_Tin_Mon_Hoc(fileout, sv.ds_monhoc[i]);
		fileout << endl;
	}
}

// hàm lưu thông tin sinh viên vào file NAMSINH.TXT
void Cau_3_Luu_File_Nam_Sinh(ofstream &fileout, vector<SinhVien> ds, string namsinh)
{
	for (int i = 0; i < ds.size(); i++)
	{
		string temp = Tach_Nam_Sinh(ds[i].namsinh); // tách năm sinh từ chuỗi ngày tháng năm của thằng sinh viên thứ i
		if (stricmp(temp.c_str(), namsinh.c_str()) == 0)
		{
			Ghi_Thong_Tin_Sinh_Vien(fileout, ds[i]);
		}
	}
}

int main()
{
	ifstream filein;
	filein.open("SINHVIEN.TXT", ios_base::in); // mổ file SINHVIEN.TXT ra đọc dữ liệu
	// khai báo danh sách sinh viên
	vector< SinhVien> ds_sinhvien;
	// câu 1: đọc tất cả dữ liệu từ file SINHVIEN.TXT
	Doc_File(filein, ds_sinhvien);
	cout << "\nDu lieu da doc thanh cong !";

	//// xuất dữ liệu ra màn hình để kiểm tra
	//Test(ds_sinhvien);
	//string hoten;
	//cout << "\n Nhap ho ten sinh vien can tim kiem: ";
	//getline(cin, hoten);
	//Tim_Kiem_Sinh_Vien_Theo_Ho_Ten(ds_sinhvien, hoten);

	ofstream fileout;
	fileout.open("NAMSINH.TXT", ios_base::app);
	string namsinh;
	cout << "\nNhap nam sinh: ";
	getline(cin, namsinh);
	Cau_3_Luu_File_Nam_Sinh(fileout, ds_sinhvien, namsinh);

	fileout.close();
	filein.close(); // đóng file SINHVIEN.TXT
	system("pause");
	return 0;
}
