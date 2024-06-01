#include<iostream>
using namespace std;

class Girl{
public:
    int age;
    int bh;
    string name;
    int* ptr;
    Girl(int m_age, int m_bh, const string &m_name) : age(m_age), bh(m_bh), name(m_name),ptr(nullptr){
        ptr = new int;
    }
    ~Girl(){
        delete ptr;
    }
    Girl& operator=(const Girl& g){
        if(this == &g)
            return *this;
        if(g.ptr == nullptr){
            ptr = nullptr;
        }
        else{
            ptr = nullptr;
            ptr = new int;
            *ptr = *g.ptr;
        }
        age = g.age;
        bh = g.bh;
        name = g.name;
        cout << "调用了赋值函数" << endl;
        return *this;
    }
    void show() const{
        cout << "age: " << age << "  bh:" << bh << "  name:" << name <<"  *ptr:"<<*ptr<< endl;
    }
};

int main(){
    Girl g1(18, 3, "冰冰");
    *g1.ptr = 3;
    Girl g2(17, 2, "66");
    g2 = g1; // 要想调用赋值函数两个类型的对象必须都先初始化
    g2.show();
}