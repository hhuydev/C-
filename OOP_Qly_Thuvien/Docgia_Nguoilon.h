#pragma once
#include"DocGia.h"
using namespace std;
class Docgia_Nguoilon : public DocGia
{
    private:
        string cmnd;
    public:
        void Input();
        void Output();
        Docgia_Nguoilon();
        ~Docgia_Nguoilon();
        long Tinh_Phi();
};

