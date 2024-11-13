#ifndef Sach_hpp
#define Sach_hpp

#include <iostream>
#include "CTKH.hpp"
using namespace std;

class Sach : public CTKH {
protected:
    string type;
public:
    Sach(string = "", Date, bool = false, string = "");
    Sach(const Sach&);
    ~Sach();
    friend istream& operator >>(istream& , Sach&);
    friend ostream& operator <<(ostream& , const Sach&);
    void change(string, Date, bool, string);
};

#endif
