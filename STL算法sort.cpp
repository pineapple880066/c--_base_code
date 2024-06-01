#include "mystdio.h"

//仿函数
template<typename T>
class ascend_{
    public:
    bool operator()(const T& left,const T& right){
        return left < right;
    }
};

template<typename T>
class descend_{
    public:
    bool operator()(const T& left,const T& right){
        return left > right;
    }
};
template <typename T>
bool comparea(const T &left, const T &right)
{
    return left < right;
}

template<typename T>
bool compared(const T&left,const T& right){
    return left > right;
}
template<typename T,typename compare>
void bsort(const T first,const T last,compare comp){
    while(true){
        bool bswap = false;
        // bubble sort
        for (auto it = first; it != prev(last); ++it)
        {
            if(comp(*(next(it)),*it)){
                iter_swap(it, next(it));
                bswap = true; // 说明该轮交换过元素
            }
        }
        if(bswap == false)   // 如果未交换过元素,说明已经是有序
            break;
    }
}

int main(){
    vector<int> bh = {3, 6, 7, 9, 3, 5, 3, 25, 2};
    list<string> bh1 = {"04", "06", "02", "09", "03"};
    // numeric string & data can be sorted like numbers


    // bsort(bh.begin(), bh.end(),comparea<int>); // 普通函数
    // bsort(bh.begin(), bh.end(),ascend_<int>());   // 仿函数
    // bsort(bh1.begin(), bh1.end(),less<int>());
    sort(bh.begin(), bh.end(), less<int>());
    for (auto val : bh)
    {
        cout << val << " ";
    }
    cout << endl;

    // bsort(bh1.begin(), bh1.end(),compared<string>); 
    // bsort(bh1.begin(), bh1.end(),descend_<string>());
    // bsort(bh1.begin(), bh1.end(),less<string>());
    bh1.sort();
    for (auto val : bh1)
    {
        cout << val << " ";
    }
    cout << endl;

}