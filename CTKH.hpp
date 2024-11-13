#ifndef CTKH_hpp
#define CTKH_hpp

#include <iostream>
#include "Date.hpp"
using namespace std;

class CTKH {
protected:
    string ID;
    Date NXB;
    bool KhuVucXuatBan;
public:
    CTKH(Date, string = "", bool = false);
    CTKH(const CTKH&);
    ~CTKH();
    friend istream& operator >>(istream& , CTKH&);
    friend ostream& operator <<(ostream& , const CTKH&);
    virtual void change(string, Date, bool);
    string getID();
};

#endif
