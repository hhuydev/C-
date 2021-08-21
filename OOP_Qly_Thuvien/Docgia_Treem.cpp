#include "Docgia_Treem.h"

Docgia_Treem::Docgia_Treem()
{
    //ctor
}

Docgia_Treem::~Docgia_Treem()
{
    //dtor
}

void Docgia_Treem::Input(){
    DocGia::Input();
    cin.ignore();
    cout<<"\nNhap ho ten nguoi bao ho: ";getline(cin, hotennguoiBH);
}

void Docgia_Treem::Output(){
    DocGia::Output();
    cout<<"\nHo ten nguoi bao ho: "<<hotennguoiBH;
}

long Docgia_Treem::Tinh_Phi(){
    return hieulucthe * 5000;
}
