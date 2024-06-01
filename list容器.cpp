#include "mystdio.h"

int main(){
    // 创建一个空的list容器

    //构造函数1)
    list<int> l1;
    //list容器没有capacity()

    //2) 统一初始化列表
    list<int> l2({1, 2, 3, 4, 5, 6, 7, 8, 9});
    for(int val:l2){
        cout << val << " ";
    }
    cout << endl;

    //3)拷贝构造函数
    list<int> l3(l2);
    for(int val:l3){
        cout << val << " ";
    }
    cout << endl;

    //4)迭代器创建list容器
    list<int> l4(l3.begin(), l3.end()); // 不支持随机访问，只能begin()或end()

    for(int val:l4){
        cout << val << " ";
    }
    cout << endl;

    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    list<int> l5(v1.begin() + 1, v1.end() - 1); // vector容器支持随机访问
    for(int val:l5){
        cout << val << " ";
    }
    cout << endl;

    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    list<int> l6(a1 + 1, a1 + 7 - 1); // 数组的指针是天然的迭代器
    for(int val:l6){
        cout << val << " ";
    }
    cout << endl;

    // 字符串
    char str[] = "hello world";
    string s1(str, str + 7);
    // string容器也有迭代器 
    for(auto value:s1){
        cout << value << " ";
    }
    cout << endl;
    cout << s1 << endl;

    //v容器的初始化同样可以使用
    vector<int> v2(l3.begin(), l3.end());
    for(auto value:v2)
        cout << value << " ";
    cout << endl;
}
