#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string filename_test = R"(/Users/pineapple/Desktop/c:c++/知识点/test.txt)";

    ifstream fin;
    // ifstream fin(filename_test, ios::in);

    fin.open(filename_test, ios::in);
    // 如果文件不存在输入流不会创建文件

    // 判断打开文件是否成功
    if(fin.is_open() == false){
        cout << "打开文件" << filename_test << "失败" << endl;
        return 0;
    }
    
    //  第一种方法
    string buffer;
    // getline(fin, buffer); // 读取一行数据
    //读取文件结束 getline 会返回空
    while(getline(fin,buffer)){
        cout << buffer << endl;
    }


    // 第二种方法,要保证缓冲区足够大
    char buffer[101];
    // getline 函数第二个参数指定一次读取最大
    while(fin.getline(buffer,100)){
        cout << buffer << endl;
    }

    // 第三种方法 fin >> buffer
    // 类似第一种方法
    string buffer;
    while(fin >> buffer){
        cout << buffer << endl;
    }


    fin.close();

    cout << "操作文件结束";
}