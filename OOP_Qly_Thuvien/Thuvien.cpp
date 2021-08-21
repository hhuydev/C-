#include "Thuvien.h"

Thuvien::Thuvien()
{
    //ctor
}

Thuvien::~Thuvien()
{
    //dtor
}

void Thuvien::Input(){
    int luachon;
    while(true){
        system("cls"); // xóa hết các thứ có trong màn hình console trước cái lệnh này
		cout << "\n\n\t\t ============ THU VIEN X ============";
		cout << "\n\t 1. Nhap thong tin doc gia tre em";
		cout << "\n\t 2. Nhap thong tin doc gia nguoi lon";
		//cout << "\n\t 3. Xuat thong tin doc gia tre em";
		//cout << "\n\t 4. Xuat thong tin doc gia nguoi lon";
		cout << "\n\t 0. Thoat";
		cout << "\n\n\t\t ============     END    ============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

        DocGia *x;
		if(luachon == 1){
            x = new Docgia_Treem;
            cout<<"\n\n\t\tNHAP THONG TIN DOC GIA TRE EM\n";
            x->Input();
            int a = 1;
            x->Setter_Kiemtra(a);
            ds_docgia.push_back(x);
		}
		else if(luachon == 2){
            x = new Docgia_Nguoilon;
            cout<<"\n\n\t\tNHAP THONG TIN DOC GIA NGUOI LON\n";
            x->Input();
            int a = 2;
            x->Setter_Kiemtra(a);
            ds_docgia.push_back(x);
		}

		else{
            break;
		}
    }
}

void Thuvien::Output(){
    for(int i=0;i<ds_docgia.size();++i){
        if(ds_docgia[i]->Getter_Kiemtra() == 1){
            cout<<"\n\n\t\tTHONG TIN DOC GIA TRE EM THU "<<i+1<<endl;
            ds_docgia[i]->Output();
        }
        else{
            cout<<"\n\n\t\tTHONG TIN DOC GIA NGUOI LON THU "<<i+1<<endl;
            ds_docgia[i]->Output();

        }
}
}

long Thuvien::Tong_Chi_Phi(){
    long s = 0;
    for(int i=0;i<ds_docgia.size();++i){
        s+=ds_docgia[i]->Tinh_Phi();
    }

    //for(int i=0;i<ds_docgianguoilon.size();++i){
      //  s+=ds_docgianguoilon[i]->Tinh_Phi();
    //}
    return s;
}

