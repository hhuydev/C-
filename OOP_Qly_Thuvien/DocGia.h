#pragma once
#include <iostream>
#include <string>
using namespace std;
class DocGia
{
    protected:
        string hoten;
        string ngaylapthe;
        int hieulucthe;
        int Kiemtra; // 1: Doc gia tre e  - 2: Doc gia nguoi lon
    public:
        virtual void Input(); //Phuong thuc ao de nhap tt
        virtual void Output(); //Phuong thuc ao de xuat thong tin
        virtual long Tinh_Phi() = 0; //Phuong thuc thuan ao de class con tu dinh nghia
        int Getter_Kiemtra();
        void Setter_Kiemtra(int kt);
        DocGia();
        ~DocGia();
};


