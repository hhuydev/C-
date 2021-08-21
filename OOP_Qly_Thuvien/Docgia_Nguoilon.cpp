#include "Docgia_Nguoilon.h"

Docgia_Nguoilon::Docgia_Nguoilon()
{
    //ctor
}

Docgia_Nguoilon::~Docgia_Nguoilon()
{
    //dtor
}

void Docgia_Nguoilon::Input(){
    DocGia::Input();
    cin.ignore();
    cout<<"\nNhap CMND: ";getline(cin,cmnd);
}

void Docgia_Nguoilon::Output(){
    DocGia::Output();
    cout<<"\nCMND: "<<cmnd;
}

long Docgia_Nguoilon::Tinh_Phi(){
    return hieulucthe * 10000;
}
