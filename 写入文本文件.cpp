#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // string filename_test = "\\Users\\pineapple\\Desktop\\c:c++\\知识点\\test.txt";
    // 原始字面量
    string filename_test = R"(/Users/pineapple/Desktop/c:c++/知识点/test.txt)";
    ofstream fout;
    // 创建文件输出流对象
    // 使用构造函数打开文件
    // ofstream xx(文件名 ，打开模式 )，打开模式缺省为 ios::out
    // ios::out 会截断文件内容
    // ios::trunc 会截断文件内容
    // ios::app 不会截断内容，会在文末追加内容
    // ofstream fout(filename_test);
    // ofstream fout(filename_test, ios::out);
    // ofstream fout(filename_test, ios::trunc);
    // ofstream fout(filename_test, ios::app);

    // 使用成员函数open()打开文件：
    // xx.open(filename , opening_mode(打开模式) );
    fout.open(filename_test, ios::app); // 打开文件，如果没有就创建一个
    
    // 判断打开文件是否成功
    // 一般失败有三种情况: 1.目录不存在  2.磁盘空间已满  3.没有权限
    if(fout.is_open() == false){
        cout << "打开文件" << filename_test << "失败" << endl;
        return 0;
    }
    //向文件中写入程序
    fout << "西施 | 19 | 漂亮" << endl;
    fout << "冰冰 | 22 | 好看" << endl;
    fout << "蜜蜜 | 66 | 一般" << endl;

    fout.close();

    cout << "操作写入文件完成 ." << endl;
}