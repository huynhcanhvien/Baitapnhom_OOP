#include <iostream>
#include "LLKHCaNhan.hpp"

using namespace std;

int main(){
    LLKHCaNhan l("Phạm Quang Thắng");
    BaiBao b;
    Sach s;
    BaiBao* bp = &b;
    Sach* sp = &s;
    b.change("B001",Date(1,3,1995),true,"Nguyên lý hệ điều hành",1);
    l.append(bp);
    s.change("S001",Date(17,8,2001),false,"Sách chuyên khảo");
    l.append(sp);
    s.change("S002",Date(22,11,2006),false,"Sách tham khảo");
    l.append(sp);
    cout << l;
    l.update("B001");
    cout << l[2];

    l.remove(l.search("S001")->getID());
    cout << l;
    return 0;
}
