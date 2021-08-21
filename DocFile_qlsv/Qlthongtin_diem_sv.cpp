#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

typedef struct monhoc{
	string tenmon;
	float diem;
}Mh;

typedef struct sinhvien{
	string hoten;
	string maso;
	string namsinh;
	vector<Mh>Ds_mh;

}Sv;
// Doc thong tin 1 sinh vien
void Doc_file_1_sv(ifstream &filein, Sv &x){
	getline(filein, x.hoten, ','); // Doc den day ',' thi dung, con tro nam sau dau phay
	getline(filein, x.maso, ',');
	getline(filein, x.namsinh);
}
// Doc thong tin 1 mon hoc
void Doc_file_tt_monhoc(ifstream &filein, Mh &x){
	getline(filein, x.tenmon, '-'); // Doc den dau '-' thi dung, con tro nam sau dau phay
	filein >> x.diem;
}

void Doc_File(ifstream &filein, vector<Sv> &Ds_sv){
	while(filein.eof() == false){
		Sv sv; //Khai bao de doc thong tin tu ham Doc_file_1_sv
		Doc_file_1_sv(filein,sv);
		int n; //Khai bao de dem so luong mon hoc
		filein >> n;
		string temp; //Khai bao de doc ki tu '\n'
		getline(filein,temp);
		for(int i=1;i<=n;i++){
			Mh mh; // Khai bao de doc thong tin tu ham Doc_file_tt_monhoc
			Doc_file_tt_monhoc(filein,mh);
			getline(filein,temp); //Doc ki tu '\n' o tren
			sv.Ds_mh.push_back(mh); //Them 1 mon vao cuoi mang vector cua 1 sinh vien

		}
		//Them thong tin sinh vien vao mang vector Ds_sv
		Ds_sv.push_back(sv);
	}
}

void Xuat_tt_sinhvien(Sv sv){
	cout<<"\nHo ten sinh vien: "<<sv.hoten;
	cout<<"\nMa so sinh vien: "<<sv.maso;
	cout<<"\nThong tin nam sinh sinh vien: "<<sv.namsinh;
}

void Xuat_tt_monhoc(Mh mh){
	cout<<"\nTen mon hoc: "<<mh.tenmon;
	cout<<"\nDiem: "<<mh.diem;

}



void Xuatmanhinh(vector<Sv>ds){
	for(int i=0;i<ds.size();i++){
		cout<<"\n\n\tSinh vien thu "<<i+1;
		Xuat_tt_sinhvien(ds[i]);
		for(int j=0;j<ds[i].Ds_mh.size();j++){
			cout<<"\n\n\tMon hoc thu "<<j+1;
			Xuat_tt_monhoc(ds[i].Ds_mh[j]);
		}
	}
}

void Timhoten(vector<Sv>ds, string hotentk){
	for(int i=0;i<ds.size();i++){
		if(strcmp(ds[i].hoten.c_str(), hotentk.c_str()) == 0){
		cout<<"\n\n\tSinh vien thu "<<i+1;
		Xuat_tt_sinhvien(ds[i]);
		for(int j=0;j<ds[i].Ds_mh.size();j++){
			cout<<"\n\n\tMon hoc thu "<<j+1;
			Xuat_tt_monhoc(ds[i].Ds_mh[j]);
		}
		}
	}
}

string Tachnamsinh(string namsinh){
	string temp;
	for(int i = namsinh.length() -1; i>=0; i--){
		if(namsinh[i]>='0' && namsinh[i]<='9'){
            temp.insert(temp.begin() +0, namsinh[i]); // Them ki tu vao truoc v tri 0
		}
		else{
           break;
		}
	}
	return temp;
}

void Ghithongtinmonhocsvnamsinhcantim(ofstream &fileout, Mh mh){
	fileout << mh.tenmon << "-" <<mh.diem;
}

void Luuthongtinsvconamsinhcantim(ofstream &fileout, Sv sv){
	fileout << sv.hoten << "," << sv.maso << "," <<sv.namsinh << endl;
	fileout << sv.Ds_mh.size() << endl;
	for(int i=0;i<sv.Ds_mh.size();i++){
		Ghithongtinmonhocsvnamsinhcantim(fileout,sv.Ds_mh[i]);
		cout << endl;
	}
}

void Luunamsinh_ttsinhvienvaofile(ofstream &fileout, vector<Sv>ds, string t){
	for(int i=0;i<ds.size();i++){
		string temp = Tachnamsinh(ds[i].namsinh);
		if(strcmp(temp.c_str(),t.c_str()) == 0){
			Luuthongtinsvconamsinhcantim(fileout,ds[i]);
		}
	}
}

float Timmax(ofstream &fileout,Mh temp, vector<Sv>ds)
    float Max = 0;
    for(int i=0;i<ds.Ds_mh.size();++i){
        if(ds.Ds_mh.diem > Max)
            Max = sv.Ds_mh.diem;
    }
    for(int j=0;j<ds.Ds_mh.size();++i){
        Luuthongtinsvconamsinhcantim(fileout,ds[i]);
    }
}

int main(){
	ifstream filein;
	filein.open("Sinhvien.txt",ios_base::in);
	vector<Sv> ds_sv;
	Doc_File(filein,ds_sv);
	cout<<"\nDu lieu doc thanh cong!";
	Xuatmanhinh(ds_sv);

	string hotentk;
	Timhoten(ds_sv,hotentk);

	ofstream fileout;
	fileout.open("Namsinh.txt",ios_base::app); //app dung de luu tiep thong tin, out tao moi (xoa) thong tin cu
	string namsinhcantim;
	cout<<"\nNhap nam sinh can tim: ";getline(cin,namsinhcantim);
	Luunamsinh_ttsinhvienvaofile(fileout,ds_sv,namsinhcantim);


	filein.close();
	fileout.close();
	return 0;
}
