#include<iostream>
using namespace std;

int main(){
    char cc[11];
    string s = (string)cc;
    s = "ddddadddddd";

    // 常规操作
    cout << s.size() << endl;
    cout << s.capacity() << endl;
    cout << s.length() << endl;
    cout <<"s: "<< s << endl;
    // s.clear();
    cout <<"s: "<< s << endl;
    // s.reserve(1000); // s的容量至少为1000字节

    // 字符操作
    //  char &operator[](int n);重载了[]可以用下标访问元素
    cout << s[0] << " . " << s[1] << endl; // 不提供范围检查，越界会直接报错
    // const char *c_str()const;返回动态数组首地址
    cout <<"首地址为"<< s.c_str() << endl;
    // const char *data()const;返回首地址，但只关心数据
    // int copy(char *s,int n,int pos = 0) const; 从pos开始拷贝n个字节到s中
    char *s1 = new char(5);
    s.copy(s1, 4, 3); // 使用copy函数后要在c风格字符串后末尾加上‘\0’
    s1[4] = '\0';
    for (int i = 0; i < 4; i++)
        cout << s1[i];
    cout << endl;
    delete s1;

    string s2 = "aaaaaaaaa";
    //交换前:
    cout << "s:" << s << " s2:" << s2 << endl;
    cout << "&s:" << &s << "  &s2:" << &s2 << endl;
    // 交换操作
    //  void swap(string &str);// 当前容器与str交换
    
    s.swap(s2);
    cout << "s:" << s << " s2:" << s2 << endl;
    cout << "&s:" << &s << "  &s2:" << &s2 << endl;

    //截取操作:
    // string substr(size_t pos = 0,size_t n = npos) const
    //返回pos开始后的n个字节组成的子容器
    cout << s2.substr(3, 3) << endl;

    //比较操作:
    // bool operator==(const string &str1,const string &str2)const
    // 比较两个字符串是否相等
    // int compare(const string &str) const
    //比较当前字符串与str的大小

    //查找操作
    //替换操作
    //插入操作
    //删除操作
}