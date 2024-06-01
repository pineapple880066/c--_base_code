#include "mystdio.h"

template<typename T>
class girl{
public:
    T yz;
    int yz_count;

    girl(T m_yz):yz(m_yz),yz_count(0){}
    void operator()(const T& m_yz){
        if(yz == m_yz){
            yz_count++;
        }
    }
};

int main(){
    vector<int> vv = {1, 3, 5, 6, 3, 3, 2, 63, 1, 1, 1, 4, 1};

    // Function for_each;可以返回类来保存数据例如统计;
    girl<int> g = for_each(vv.cbegin(), vv.cend(), girl<int>(1));

    cout << " g.yz_count = " << g.yz_count << endl;
}