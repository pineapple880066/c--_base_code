#include"mystdio.h"

int main(){
    list<int> la = {8, 2, 3, 4, 5};

    for(auto &val:la)
        cout << val << " ";
    cout << endl;

    //反转链表
    la.reverse();
    for(auto &val:la)
        cout << val << " ";
    cout << endl;

    //链表排序
    la.sort(); //缺省为升序排序
    for(auto &val:la)
        cout << val << " ";
    cout << endl;

    list<int> lb = {1, 6, 7, 9,10};

    // 交换链表
    lb.swap(la);
    for(auto &val:la)
        cout << val << " ";
    cout << endl;
    for(auto &val:lb)
        cout << val << " ";
    cout << endl;

    // 合并并且进行归并排序
    la.merge(lb);
    for(auto &val:la)
        cout << val << " ";
    cout << endl;

    // 插入
    la.push_back(11);
    la.push_front(0);
    for(auto &val:la)
        cout << val << " ";
    cout << endl;

    //连接
    auto first = la.begin();
    first++;
    first++;
    auto last = la.end();
    last--;
    last--;

    lb.splice(lb.begin(),lb, first, last);
    for(auto &val:lb)
        cout << val << " ";
    cout << endl;

    //删除
    //删除所有值为 X 的元素

    lb.remove(3);
    for(auto &val:lb)
        cout << val << " ";
    cout << endl;


    lb.push_front(12);
    lb.push_front(4);
    lb.push_front(3);
    lb.push_front(1);
    lb.push_back(11);
    lb.push_back(12);
    //删除相邻的重复元素
    lb.unique();
    for(auto &val:lb)
        cout << val << " ";
    cout << endl;

    lb.sort();
    for(auto &val:lb)
        cout << val << " ";
    cout << endl;

}