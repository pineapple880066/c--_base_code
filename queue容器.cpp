#include "mystdio.h"

class girl{
public:
    int bh;
    string name;
    girl(const int &m_bh, const string &m_name) : bh(m_bh), name(m_name){}
};
int main()
{

    // 构造函数
    // 1)queue();
    


    //常用操作
    // 入队push
    // emplace(可以构造元素)
    // size()元素个数
    // empty()是否为空
    // front()返回对头元素
    // back()返回队尾元素
    // pop()出队

    queue<girl, list<girl>> q; //物理结构为链表
    queue<girl, deque<girl>> q1;//物理结构为数组
    queue<girl> q2; //缺省为数组
    // 不能用vector : queue<girl, vector<girl>> q;


    //  其他操作
    //1) 重载赋值运算
    //2）交换swap
    //3）比较 重载 ==
    //4）重载 ！=

}