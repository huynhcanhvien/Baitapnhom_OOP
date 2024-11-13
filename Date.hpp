
#ifndef Date_hpp
#define Date_hpp

#include <iostream>


using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int = 1, int = 1, int = 2024);
    Date(const Date&);
    friend istream& operator >>(istream& , Date&);
    friend ostream& operator <<(ostream& , const Date&);
    Date operator +(int days);
    Date operator -(int days);
    Date& operator ++();
    Date operator ++(int);
    Date& operator --();
    Date operator --(int);
    friend bool checkNamNhuan(const int&);
    friend bool isValid(const Date& date);
    const Date& operator =(const Date&);
};

#endif /* Date_hpp */
