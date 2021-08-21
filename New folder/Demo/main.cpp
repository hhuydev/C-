#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;
typedef struct monhoc{
    string tenmh;
    float diem;
}mH;

typedef struct sinhvien{
    string hoten,masv,namsinh;
    vector<mH> ds_mH;
}sV;

void Doc_File_1_Sv(ifstream &filein, sV &sv){
    getline(filein, sv.hoten, ',');
    getline(filein, sv.masv, ',');
    getline(filein, sv.namsinh);
}


void Doc_File_Tt_Mh(ifstream &filein, mH &mh){
    getline(filein, mh.tenmh, '-');
    filein >> mh.diem;
}

void Doc_FIle(ifstream &filein, vector<sV>ds_sV){
    while(!filein.eof()){   //Ham eof doc den cuoi file
        sV sv;
        Doc_File_1_Sv(filein,sv);
        int n;
        filein >> n;
        for(int i=1; i<=n; ++i){
            mH mh;
            Doc_File_Tt_Mh(filein,mh);
            sv.ds_mH.push_back(mh);
        }
        ds_sV.push_back(sv);
    }
}

void Xuat_Tt_1_Sv(sV sv){
    cout<<"\nHo ten sinh vien: "<<sv.hoten;
    cout<<"\nMa so sinh vien: "<<sv.masv;
    cout<<"\nNgay thang nam sinh: "<<sv.namsinh;
}

void Xuat_Tt_1_Mh(mH mh){
    cout<<"\nTen mon hon: "<<mh.tenmh;
    cout<<"\nDiem mon hon: "<<mh.diem;
}

void Output(vector<sV>ds){
    for(int i=0;i<ds.size();++i){
        cout<<"\n\n\t\t\tThong tin sinh vien thu "<<i+1;
        Xuat_Tt_1_Sv(ds[i]);
        for(int j=0;j<ds[i].ds_mH.size();++j){
            cout<<"\n\t\t\tDanh sach cac mon hoc ";
            Xuat_Tt_1_Mh(ds[i].ds_mH[j]);
        }
    }
}

void Tim_Kiem_Sinh_Vien_Theo_Ho_Ten(vector<sV> ds, string hoten)
{
	int dem = 1;
	for (int i = 0; i < ds.size(); i++)
	{
		if (strcmp(ds[i].hoten.c_str(), hoten.c_str()) == 0)
		{
			cout << "\n\n\t\t\t SINH VIEN THU " << dem++;
			 Xuat_Tt_1_Sv(ds[i]);
			int n = ds[i].ds_mH.size();
			for (int j = 0; j < n; j++)
			{
				cout << "\n\t\t MON HOC THU " << j + 1;
				Xuat_Tt_1_Mh(ds[i].ds_mH[j]);
			}

		}
	}
}

int main()
{
    ifstream filein;
    string line;
    filein.open("SINHVIEN.TXT",ios_base::in);
    vector<sV>ds_sV;
    if(filein.is_open()){
        cout<<"\nDa doc du lieu thanh cong!";
    }
    Doc_FIle(filein,ds_sV);

    Output(ds_sV);
    string hoten;
	cout << "\n Nhap ho ten sinh vien can tim kiem: ";
	getline(cin, hoten);
	Tim_Kiem_Sinh_Vien_Theo_Ho_Ten(ds_sV, hoten);
    filein.close();
    system("pause");
    return 0;
}
