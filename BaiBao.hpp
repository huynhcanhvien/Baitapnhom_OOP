#ifndef BaiBao_hpp
#define BaiBao_hpp

#include <iostream>
#include "CTKH.hpp"
using namespace std;

class BaiBao : public CTKH {
protected:
    string name;
    int numOfAuthor;
public:
    BaiBao(Date, string = "", bool = false, string = "", int = 1);
    BaiBao(const BaiBao&);
    ~BaiBao();
    friend istream& operator >>(istream& , BaiBao&);
    friend ostream& operator <<(ostream& , const BaiBao&);
    void change(string, Date, bool, string, int);
};

#endif
