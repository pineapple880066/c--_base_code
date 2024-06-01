#include<iostream>
using namespace std;

class Girl{
public:
    int bh;
    Girl(int m_bh): bh(m_bh) {
        cout << "调用了有参数的" << endl;
    }
    ~Girl(){}
    Girl(){
        bh = 1;
        cout << "调用了没有参数的" << endl;
    }
    void show() const{
        cout << "bh: " << bh << endl;
    }
};

int main(){
    string name = "666";
    Girl g1 = 8;
    g1.show();
    Girl g2(8);
    g2.show();
    Girl g3;
    g3.show();

    return 0;
}