#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
using namespace std;

typedef struct ngay {
    int ngay, thang, nam;
}Date;

typedef struct sv {
    string hoten;
    string masv;
    Date date;
    float diem;
}Sv;

typedef struct node {
    Sv data;
    struct node* pnext;
}Node;

typedef struct list {
    Node* phead;
    Node* ptail;
}List;

void Khoitao(List& lt) {
    lt.phead = NULL;
    lt.ptail = NULL;
}

Node* Taonode(Sv sv) {
    Node* p = new Node;
    if (p == NULL) {
        cout << "\Khoi tao Node khong thanh cong!";
        return NULL;
    }
    p->data = sv;
    p->pnext = NULL;
    return p;
}

void Themdau(List& lt, Node, Node* p) {
    if (lt.phead == NULL)
        lt.phead = lt.ptail = p;
    p->pnext = lt.phead;
    lt.phead = p;
}


void Themcuoi(List& lt, Node* p) {
    if (lt.phead == NULL)
        lt.phead = lt.ptail = p;
    lt.ptail->pnext = p;
    lt.ptail = p;
}

void Docngaythangnam(ifstream& filein, Date& x) {
    filein >> x.ngay;
    filein.seekg(1, ios_base::cur);
    filein >> x.thang;
    filein.seekg(1, ios_base::cur);
    filein >> x.nam;
}

void Docthongtin_1_Sv(ifstream& filein, Sv& sv) {
    getline(filein, sv.hoten, ',');
    filein.seekg(1, ios_base::cur);
    getline(filein, sv.masv, ',');
    filein.seekg(1, ios_base::cur);
    Docngaythangnam(filein, sv.date);
    filein.seekg(1, ios_base::cur); // Kieu du lieu so bo bao nhieu byte k quan trong vi du bo 2 byte
    filein >> sv.diem;
}

void Xuatthongtin_1_Sv(Sv sv) {
    cout << "\nHo ten:" << sv.hoten;
    cout << "\nMa sinh vien:" << sv.masv;
    cout << "\nNgay sinh:" << sv.date.ngay << "/" << sv.date.thang << "/" << sv.date.nam;
    cout << "\nDiem trung binh:" << sv.diem;
}

void Docthongtin_nhieu_Sv(ifstream& filein, List& lt) {
    while (filein.eof() == false) {
        Sv sv;
        Docthongtin_1_Sv(filein, sv);
        Node* p = Taonode(sv);
        Themcuoi(lt, p);
    }
}

void Xuatthongtin_nhieu_Sv(List lt) {
    int dem = 1;
    for (Node* i = lt.phead; i != NULL; i = i->pnext) {
        cout << "\Thong tin sinh vien thu " << i++;
        Xuatthongtin_1_Sv(i->data);
    }
}

void Giaiphong(List& lt) {
    for (Node* i = lt.phead->pnext; i != NULL; i = i->pnext) {
        delete i;
    }
    delete lt.phead;
}

int main()
{
    Sv sv;
    List lt;

    ifstream filein;
    filein.open("SINHVIEN.TXT", ios::in);
    //Docthongtin_1_Sv(filein,sv);
   // Xuatthongtin_1_Sv(sv);
    Khoitao(lt);
    Docthongtin_nhieu_Sv(filein, lt);
    Xuatthongtin_nhieu_Sv(lt);
    Giaiphong(lt);
    filein.close();
    return 0;
}
