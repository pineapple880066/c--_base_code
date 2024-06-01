#include<iostream>
using namespace std;

void show(string str){
    cout << "全局函数：" << str << endl;
}

class Girl{
public:
    void operator()(string str){
        cout << "成员函数:" << str << endl;
    }
};

int main(){
    Girl show;
    ::show("666"); // 用 :: 调用全局函数
    show("555");
    return 0;
}