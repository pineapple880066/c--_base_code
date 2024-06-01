#include "mystdio.h"
int main(){
    vector<int> vv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //迭代器用于赋值 vector<int>::iterator可以用auto代替
    vector<int>::iterator it1 = vv.begin(); // 用begin()获取第一个迭代器

    *it1 = 9;
    it1++;
    *it1 = 8;

    //迭代器用于循环
    //用cbegin()获取元素的第一个常量迭代器，用于遍历等只读不修改的情况,即c(onst )begin()
    //常量迭代器可以配合auto来使用
    for (auto it2 = vv.cbegin(); it2 != vv.end();it2++){
        cout << *it2 << "  ";
    }
    cout << endl; // 这里auto代表 vector<int>::const_iterator

    // 迭代器用于初始化
    vector<int> v2(vv.cbegin() + 2, vv.cend() - 3);
    // 反向迭代器，++始终是正向（从尾到头）
    for (auto it2 = v2.crbegin(); it2 != v2.crend();it2++){
        cout << *it2 << " ";
    }
    cout << endl;

    //迭代器插入删除操作
    auto it3 = v2.insert(v2.cbegin(), 16);
    for (auto it2 = v2.crbegin(); it2 != v2.crend();it2++){
        cout << *it2 << " ";
    }
    cout << endl;

    // resize()、reserve()、assign()、pushback()、popback()、insert()、erase()
    // 等函数会引起vector容器的动态数组发生变化，可能导致vector迭代器失效。

    for (auto it2 = v2.cbegin(); it2 != v2.cend();){
        cout << *it2 << "  ";
        it2 = v2.erase(it2); // 删除元素后返回下一个迭代器
    }
    cout << endl;
}