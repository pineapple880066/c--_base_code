#include<iostream>
using namespace std;

class Girl{
public:
    static int m_age;
    int m_bh;
    string m_name;
    Girl(int bh, const string& name): m_bh(bh), m_name(name) {
         
    }
    ~Girl(){

    }
    void show() const {
        cout << "name: " << m_name << " age: " << m_age << endl; // 在成员函数中调用成员其实是用this指针
    }                                                            // eg: m_name其实是this->m_name,但编译器省略了这些
    static void showage() // 静态函数
    {
        cout << "age :" << m_age << endl; // 该成员函数中只调用了静态变量，没有用到非静态变量，所以可以用空指针调用
    }
};

int Girl::m_age = 18; // 静态变量初始化
int aaa = 0; // 全局变量
int main()
{
    Girl::showage();
    Girl g1( 1,"冰冰");
    cout << "g1占的内存为:" << sizeof(g1) << endl;
    cout << "g1的地址:" << (void*)&g1 << endl;
    cout << "m_bh的地址为:" << (void *)&g1.m_bh << endl;
    cout << "m_name的地址为:" << (void *)&g1.m_name << endl;
    cout << "m_age的地址为:" << (void *)&g1.m_age << endl;
    cout << "全局变量aaa的地址为" << (void *)&aaa << endl;
    printf("成员函数show的地址为:%p\n", &Girl::show); // c风格输出成员函数地址
    printf("成员函数showage的地址为:%p\n", &Girl::showage);

    Girl *g2 = nullptr;
    g2->showage(); // 新建一个空指针调用只含有静态变量的成员函数

    return 0;
}