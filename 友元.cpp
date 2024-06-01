#include<iostream>
using namespace std;

class Girl;

class Boy{
public:
    void func1(const Girl &g);
};

class Girl
{
public:
    friend void Boy::func1(const Girl &g);
    friend void show(const Girl &girl); // 将show函数设置为友元函数
    friend int main(); // 将主函数main设置为类Girl的友元，可以在主函数内访问Girl的私有成员
    int age;
    int yz;
    string name;
    Girl(int m_age,int m_yz,const string& m_name): age(m_age),yz(m_yz),name(m_name){
    }
    ~Girl(){}
    void showage(){
        cout << "age:" << age << endl;
    }

private:
    int xw;
};

void Boy::func1(const Girl &g){
    cout << "girl胸围为:" << g.xw << endl;
}
void show(const Girl& girl){
    cout << "xw为" << girl.xw << endl;
}

int main()
{
    Girl g1(18, 2, "冰冰");
    g1.xw = 35;
    show(g1);
    Boy *b = nullptr;
    b->func1(g1);
    return 0;
}