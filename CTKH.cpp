#include "CTKH.hpp"
#include <stdexcept>
using namespace std;

CTKH::CTKH(string id, Date d, bool place) : ID(id), NXB(d), KhuVucXuatBan(place){
    if(this->NXB.getYear()<1900){
        throw invalid_argument("Năm không hợp lệ trong constructor");
    }
}

CTKH::CTKH(const CTKH& c){
    this->ID = c.ID;
    this->NXB = c.NXB;
    this->KhuVucXuatBan = c.KhuVucXuatBan;
    if(this->NXB.getYear()<1900){
        throw invalid_argument("Năm không hợp lệ trong constructor");
    }
}

CTKH::~CTKH(){}

istream& operator >>(istream& in, CTKH& ct){
    cout << "Nhập ID: "; in >> ct.ID;
    cout << "Nhập ngày xuất bản: "; in >> ct.NXB;
    cout << "Nhập khu vực xuất bản: "; in >> ct.KhuVucXuatBan;
    return in;
}

ostream& operator <<(ostream& out, const CTKH& ct){
    out << "ID: " << ct.ID << endl;
    out << "Ngày xuất bản: " << ct.NXB << endl;
    out << "Khu vực xuất bản: " << ct.KhuVucXuatBan << endl;
    return out;
}

void CTKH::change(string id, Date d, bool place){
    this->ID = id;
    this->NXB = d;
    this->KhuVucXuatBan = place;
}