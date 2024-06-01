#include<iostream>
using namespace std;

int main(){
    cout << "npos = " << string::npos << endl; 
    // 显示字符数组上限npos
    string s1;
    cout << "s1 = " << s1 << endl;
    cout << "s1.capacity = " << s1.capacity() << endl;
    cout << "s1.size = " << s1.size() << endl;
    cout << " 容器拓展前动态数组首地址:" << (void*)s1.c_str() << endl;
    s1 = "66666666667677677667767766767787";
    cout << "s1.capacity = " << s1.capacity() << endl;
    cout << "s1.size = " << s1.size() << endl;
    cout << " 容器拓展后动态数组首地址:" << (void*)s1.c_str() << endl;
// 1)string0：创建一个长度为0的string对象（默认构造函数）
    string s2("hello world");
    cout << "s2 = " << s2 << endl;
    string s3 = "hello world";
    cout << "s3 = " << s3 << endl;
    // 2)string(constchar*s)：将string对象初始化为s指向的NBTS（转换函数）
    string s4(s3);
    cout << "s4 = " << s4 << endl;
    string s5 = s4;
    cout << "s5 = " << s5 << endl;
    // 3)string(conststring&str)：将string对象初始化为str(拷贝构造函数）(深拷贝)
    string s6("hello world", 5);
    cout << "s6 = " << s6 << endl;
    cout << "s6.capacity = " << s6.capacity() << endl;
    cout << "s6.size = " << s6.size() << endl;
    string s7("hello world", 50);
    cout << "s7 = " << s7 << endl;
    cout << "s7.capacity = " << s6.capacity() << endl;
    cout << "s7.size = " << s6.size() << endl;
    // 4)string(constchar*s,sizetn)：将string对象初始化为s指向的NBTS的前n个字符，即使超过了NBTS结尾。
    string s8(s3, 3, 5);
    cout << "s8 = " << s8 << endl;
    string s9(s3, 3); // 从3开始到结尾，并且到结尾会自动停止
    cout << "s9 = " << s9 << endl;
    cout << "s9.cap = " << s9.capacity() << endl;
    cout << "s9.size = " << s9.size() << endl;

    //  5) string(const string & str, size t pos = 0, size t n = npos):
    // 6)template-classT>string(Tbegin,Tend)：将string对象初始化为区间lbegin,end]内的字符
    // 其中begin和end的行为就像指针，用于指定位置，范国包括begin在内，但不包括end.
    string s12(8, 'x');
    cout << "s12 = " << s12 << endl;
    cout << "s12.cap = " << s12.capacity() << endl;
    cout << "s12.size = " << s12.size() << endl;
    string s13(30, 0);
    cout << "s13 = " << s13 << endl;
    cout << "s13.cap = " << s13.capacity() << endl;
    cout << "s13.size = " << s13.size() << endl;
   
    // 7)string(sizetn,charc)：创建一个由n个字符c组成的string对象。
}