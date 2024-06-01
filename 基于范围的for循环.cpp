#include"mystdio.h"

class AA{
public:
    string name;

    AA(){
        cout << "默认构造函数" << endl;

    }

    AA(const string & m_name): name(m_name){
        cout << "构造函数" << endl;
        cout << "name = " << name << endl;
    }
    AA(const AA&a):name(a.name){
        cout << "拷贝构造函数"
             << "name = " << name << endl;
    }
    AA&operator=(const AA&a){
        name = a.name;
        cout << "重载赋值函数, name = " << name << endl;
        return *this;
    }
    ~AA(){
        cout << "析构函数,name" << name << "." << endl;
    }

};
int main()
{
    vector<int> vv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // for (auto it = vv.cbegin(); it != vv.cend();it++){
    //     cout << *it << " ";
    // }
    // cout << endl;

    // for(int val : vv){ // 用基于范围的for循环
    //     cout << val << " ";
    // }
    // cout << endl;

    // 迭代变量的声明一般用auto
    for(auto val : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ){ // 用统一初始化列表
        cout << val << " ";
    }
    cout << endl;

    // for(迭代变量 ：迭代范围(数组名、容器名、统一初始化列表)){
        // 循环体 
    // }

    vector<AA> v;

        cout << "111,v.cap = " << v.capacity() << endl;
        v.emplace_back("西施"); // 插入最后 
        cout << "222,v.cap = " << v.capacity() << endl;
        v.emplace_back("bingbing");
        cout << "333,v.cap = " << v.capacity() << endl;
        v.emplace_back("mimi");

        for(auto& a:v){ // 在修改对象中的元素的情况下，加上&引用效率更高，不需要拷贝构造函数
            cout << a.name << " ";
        }
        cout << endl;

        for(const auto& a:v){ // 不修改的情况下用const修饰
            cout << a.name << " ";

        }
        cout << endl;

        vector<int> vvv = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        //迭代器失效
        for(auto val:vvv){
            cout << val << " ";
            vvv.push_back(10);
        }
        cout << endl;
}