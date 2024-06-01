#include<iostream>
using namespace std;

class Girl{
    public:
        string m_name;
        static int m_age; // 静态变量可以在不创建对象的情况下访问：Girl::m_age

        Girl(const string &name, int age) : m_name(name), m_age(age) {
        }
        ~Girl() {}
        void showname(){
            cout << "name:" << m_name << endl;
            m_age; // 非静态成员函数中可以访问静态成员或函数
        }
        static void showage(){ // 静态成员函数里只能访问静态成员，访问非静态成员会报错,访问非静态成员函数也不行
            cout << "age:" << m_age << endl;
            // 静态成员函数中没有this指针，因为其不是对象
        }
private:
    static int yz; // 私有静态成员在类外无法访问
    const int bh = 1; // const静态成员可以在定义的时候初始化（不常用)
};

int Girl::m_age = 18; // 静态变量需要在全局区加上类名和冒号声明,如果不初始化默认缺省值为0
int Girl::yz = 3;

int main(){
    Girl::showage();
    Girl g1("西施", 21); // 也可以在构造函数中初始化
    g1.showage(); // 跟全局变量相比，类的静态成员还具有类的性质，可以作为正常成员来访问
    g1.showname();

    return 0;
}