#include"Thuvien.h"

int main(){
    Thuvien *x = new Thuvien;
    x->Input();
    x->Output();
    cout<<"\nTong chi phi lam the cua cac doc gia: "<<x->Tong_Chi_Phi();
    delete x;
   // x = nullptr;
    return 0;
}
