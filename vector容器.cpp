#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<int> v;
    // v.vector(); // 创建一个vector容器
    int n = 4;
    // explicit vector(const size_t n);创建vector容器，元素个数为n
    // 加了explicit关键字，不能当转换函数来用
    // 例如: vector<int> v2 = (n);
    vector<int> v2(n);
    cout << "v.size :" << v.size() << endl;
    cout << "v.cap :" << v.capacity() << endl;
    cout << "v2.size :" << v2.size() << endl;
    cout << "v2.cap :" << v2.capacity() << endl;

    for (int i = 0; i < n;i++){
        v2[i] = i;
    }
    cout << endl;

    // c11标准，可以当作转换函数使用
    // vector<int> v3({1, 2, 3, 4});
    // vector<int> v4 = {1, 2, 3, 4};

    // 特性操作:
    //  capacity(),size(),empty(),clear(),reserve()
    //  shrink_to_fit()//将容量降低到实际大小(需要重新分配内存)
    //  void resize(size_t size) // 把实际大小改为size

    // 元素操作:
    //  operator[] // 下标访问元素
    //  data() // 显示首地址

    v2[1] = 11; // 下标访问
    v2.data()[0] = 66; // 数组访问法访问元素
    *(v2.data() + 2) = 33; // 指针访问法，需要解引用*
    
    for (int i = 0; i < n; i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;
    cout << "v2 的首地址为" << v2.data() << endl;
    cout << "v 的首地址为" << v.data() << endl;

    // 返回第一个元素和最后一个元素
    //T &front()
    //const T &front() // 只读
    //const T &back() // 只读
    //T &back()

    cout <<"v2的最后一个元素"<< v2.back() << endl;
    cout << "v2的第一个元素" << v2.front() << endl;

    //赋值操作:
    // 使用同一初始化列表赋值:
    vector<int> v3;
    v3 = {1, 2, 3, 4, 5};
    for (int i = 0; i < v3.size();i++){
        cout << v3[i] << "  ";
    }
    cout << endl;

    //使用赋值函数的重载函数:
    vector<int> v4;
    v4 = v3;
    for (int i = 0; i < v4.size();i++){
        cout << v4[i] << "  ";
    }
    cout << endl;

    //使用assign()函数给当前容器赋值，参数是统一初始化列表
    vector<int> v5;
    v5.assign({1,2,3});
    for (int i = 0; i < v5.size();i++){
        cout << v5[i] << "  ";
    }
    cout << endl;

    //插入删除操作:

    //void push_back(const int a)
    v5.push_back(3);
    for (int i = 0; i < v5.size();i++){
        cout << v5[i] << "  ";
    }
    cout << endl;

    // emplace_back() // 相比 push_back函数emplace_back不需要拷贝构造函数，效率更高
    v5.emplace_back(5);
    for (int i = 0; i < v5.size();i++){
        cout << v5[i] << "  ";
    }
    cout << endl;

    // pop_back() // 在容器尾部删除一个元素


    //vector的嵌套,像二维数组
    vector<vector<int>> vv;

    // vv.push_back(v);

    v = {1, 2, 3, 4, 5};
    vv.push_back(v);

    v = {11, 23, 5345, 65, 67, 757, 2};
    vv.push_back(v);

    v = {32, 2, 3232, 332, 3, 3, 2, 3, 323, 2, 5, 232, 3, 3};
    vv.push_back(v);

    for (int i = 0; i < vv.size();i++){
        for (int j = 0; j < vv[i].size();j++){
            cout << vv[i][j] << "  ";
        }
        cout << endl;
    }

}