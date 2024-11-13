#include <iostream>
#include "LLKHCaNhan.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    LLKHCaNhan Lylich("Nhom");
    
    while(true){
        cout << "Ban muon them bai bao hay sach vao LLKH?\n";
        cout << "1.Bai Bao: nhan 1\n2.Sach: nhan 2\n3. Nhan nut bat ky de ket thuc!\n";
        int choose;
        cin >> choose;
        if(choose == 1){
            BaiBao a;
            cin >> a;
            Lylich.append(&a);
        }
        else if(choose == 2){
            Sach a;
            cin >> a;
            Lylich.append(&a);
        }
        else{
            break;
        }
    }
    cout << "Update một CTKH trong lý lịch:\n";
    cout << "Nhập ID: ";
    string id;
    cin >> id;
    try{
        Lylich.update(id);
        cout << "CTKH vừa được update:\n";
    }
    catch(runtime_error& e){
        cout << e.what();
    }
    cout << *(Lylich.search(id));
    cout << "Xoa mot CTKH trong lý lịch:\n";
    cout << "Nhập ID: ";
    cin >> id;
    try{
        Lylich.remove(id);
        cout << "Đã xoá thành công\n!";
    }
    catch(runtime_error& e){
        cout << e.what();
    }
    cout << "In ra toàn bộ CTKH của lý lịch:\n";
    cout << Lylich;
    cout << "Nhap ID của CTKH bạn muốn xem!: ";
    cin >> id;
    cout << *(Lylich[id]);
    cout << "Nhap số thứ tự của CTKH bạn muốn xem: ";
    int index;
    cin >> index;
    cout << *(Lylich[index]);
    cout << "DEMO ENDED";
}
