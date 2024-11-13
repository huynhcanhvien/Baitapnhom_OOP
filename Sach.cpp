#include "Sach.hpp"
#include <stdexcept>
using namespace std;

Sach::Sach(string id, Date d, bool place, string Ty) : CTKH(id,d,place), type(Ty){
    if(this->NXB.getYear()<1900){
        throw invalid_argument("Năm không hợp lệ trong constructor");
    }
}

Sach::Sach(const Sach& s){
    this->ID = s.ID;
    this->NXB = s.NXB;
    this->KhuVucXuatBan = s.KhuVucXuatBan;
    this->type = s.type;
    if(this->NXB.getYear()<1900){
        throw invalid_argument("Năm không hợp lệ trong constructor");
    }
}

Sach::~Sach(){}

istream& operator >>(istream& in, Sach& s){
    cout << "Nhập ID: "; in >> s.ID;
    cout << "Nhập ngày xuất bản: "; in >> s.NXB;
    cout << "Nhập khu vực xuất bản: "; in >> s.KhuVucXuatBan;
    cout << "Loại sách: "; in >> s.type;
    return in;
}

ostream& operator <<(ostream& out, const Sach& s){
    out << "ID: " << s.ID << endl;
    out << "Ngày xuất bản: " << s.NXB << endl;
    out << "Khu vực xuất bản: " << s.KhuVucXuatBan << endl;
    out << "Loại sách: " << s.type << endl;
    return out;
}

void Sach::change(string id, Date d, bool place, string Ty){
    CTKH::change(id,d,place);
    this->type = Ty;
}