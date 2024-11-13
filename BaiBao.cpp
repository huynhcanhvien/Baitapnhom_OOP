#include "BaiBao.hpp"
#include <stdexcept>
using namespace std;

BaiBao::BaiBao(string id, Date d, bool place, string Na, int Aut) : CTKH(id,d,place), name(Na), numOfAuthor(Aut){
    if(this->NXB.getYear()<1900){
        throw invalid_argument("Năm không hợp lệ trong constructor");
    }
}

BaiBao::BaiBao(const BaiBao& b){
    this->ID = b.ID;
    this->NXB = b.NXB;
    this->KhuVucXuatBan = b.KhuVucXuatBan;
    this->name = b.name;
    this->numOfAuthor = b.numOfAuthor;
    if(this->NXB.getYear()<1900){
        throw invalid_argument("Năm không hợp lệ trong constructor");
    }
}

BaiBao::~BaiBao(){}

istream& operator >>(istream& in, BaiBao& b){
    cout << "Nhập ID: "; in >> b.ID;
    cout << "Nhập ngày xuất bản: "; in >> b.NXB;
    cout << "Nhập khu vực xuất bản: "; in >> b.KhuVucXuatBan;
    cout << "Tên công trình: "; in >> b.name;
    cout << "Số tác giả: "; in >> b.numOfAuthor;
    return in;
}

ostream& operator <<(ostream& out, const BaiBao& b){
    out << "ID: " << b.ID << endl;
    out << "Ngày xuất bản: " << b.NXB << endl;
    out << "Khu vực xuất bản: " << b.KhuVucXuatBan << endl;
    out << "Tên công trình: " << b.name << endl;
    out << "Số tác giả: " << b.numOfAuthor << endl;
    return out;
}

void BaiBao::change(string id, Date d, bool place, string Na, int Aut){
    CTKH::change(id,d,place);
    this->name = Na;
    this->numOfAuthor = Aut;
}