#include "DocGia.h"

DocGia::DocGia()
{
    //ctor
}

DocGia::~DocGia()
{
    //dtor
}

void DocGia::Input(){
    cin.ignore();
    cout<<"\nNhap ho ten doc gia: ";getline(cin,hoten);
    fflush(stdin);
    cout<<"\nNhap ngay lap the DD//MM//YYYY: ";getline(cin,ngaylapthe);
    cout<<"\nNhap hieu luc the: ";cin>>hieulucthe;
}

void DocGia::Output(){
    cout<<"\nHho ten doc gia: "<<hoten;
    cout<<"\nNgay lap the DD//MM//YYYY: "<<ngaylapthe;
    cout<<"\nHieu luc the: "<<hieulucthe;
}

int DocGia::Getter_Kiemtra(){
    return Kiemtra;
}

void DocGia::Setter_Kiemtra(int kt){
    Kiemtra = kt;
}
