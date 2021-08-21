#include "DocGia.h"
#pragma once
using namespace std;

class Docgia_Treem : public DocGia
{
    private:
        string hotennguoiBH;
    public:
        Docgia_Treem();
        ~Docgia_Treem();
        void Input();
        void Output();
        long Tinh_Phi();
};

