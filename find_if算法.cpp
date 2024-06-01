#include "mystdio.h"


//zs的个性化表白类
template<typename T>
class zs{
    public:
        T m_no; //张三喜欢的超女编号
        zs(const T& no):m_no(no){}
        bool operator()(const T &no)
        { // 改为重载()
            if (no != m_no)
                return false;
            cout << "表白" << no << endl;
            return true;
        }
};

template<typename T>
//个性化表白函数
bool show(const T &no){
    if(no != 3)
        return false;
    cout << "表白" << no << endl;
    return true;
}

template<typename T1,typename T2>
T1 findif(const T1 first,const T1 last,T2 pfun){
    for (auto it = first; it != last;it++)
        if(pfun(*it)==true)
            return it;

    return last;
}

int main(){
    vector<int> bh = {2,3,4,5,6,7}; //存放编号
    
    // 函数中遍历容器，向超女表白

    auto it1 = findif(bh.begin(),bh.end(),show<int>); // 回调函数
    if(it1 == bh.end())
        cout << "查找失败" << endl;
    else
        cout << "查找成功:" << *it1 << endl;

    auto it2 = findif(bh.begin(), bh.end(), zs<int>(6)); // 用匿名对象zs类的成员函数，不需要创建对象，简洁
    if(it2 == bh.end())
        cout << "查找失败" << endl;
    else
        cout << "查找成功:" << *it2 << endl;
}