#pragma once
#include "Docgia_Nguoilon.h"
#include "Docgia_Treem.h"
#include<vector>

class Thuvien
{
    private:
        vector<DocGia *> ds_docgia;
    public:
        void Input();
        void Output();
        long Tong_Chi_Phi();
        Thuvien();
        ~Thuvien();

};

