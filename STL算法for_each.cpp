#include "mystdio.h"


//zs的个性化表白类
class zs{
    public:
    void operator()(const string& no){ //改为重载()
        cout << "表白" << no << endl;
    }
};

template<typename T>
//个性化表白函数
void show(const T &no){
    cout << "表白" << no << endl;
}

// void foreach(const vector<int>& v){
//     for (auto it = v.begin(); it != v.end();it++)
//         cout << "亲爱的" << *it << "hao,woshiyizhishashaniao" << endl;

// }

// 函数指针
// template<typename T>
// void foreach(const T first,const T last,void(*ptfunc)(const string&)){
//     for (auto it = first; it != last;it++)
//         // cout << "亲爱的" << *it << "hao:woshi..." << endl;
//         ptfunc(*it); //回调以超女编号为参数的用户自定义的函数


// }

//函数模版，同时可以用函数指针与类成员函数
template<typename T1,typename T2>
void foreach(const T1 first,const T1 last,T2 pfun){
    for (auto it = first; it != last;it++)
        // cout << "亲爱的" << *it << "hao:woshi..." << endl;
        // zs1.zsshow(*it); //回调以超女编号为参数的用户自定义的函数
        pfun(*it); //重载()运算符
}

int main(){
    list<string> bh = {"2","3","4","6","7"}; //存放编号
    
    // 函数中遍历容器，向超女表白

    foreach(bh.begin(),bh.end(),show<string>); // 回调函数

    foreach(bh.begin(),bh.end(),zs()); // 用匿名对象zs类的成员函数，不需要创建对象，简洁
}