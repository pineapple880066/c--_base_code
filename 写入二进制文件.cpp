#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string filename_test = R"(/Users/pineapple/Desktop/c:c++/知识点/test.dat)";

    // 打开模式: ios::binary 以二进制方式打开文件
    // fout.open(filename_test, ios::app|ios::binary);
    // fout.open(filename_test, ios::out|ios::binary);
    // fout.open(filename_test, ios::trunc|ios::binary);
    ofstream fout;
    fout.open(filename_test, ios::binary);

    if(fout.is_open() == 0){
        cout << "打开失败" << endl;
    }

    struct st_girl{ // 结构体
        char name[31];
        int no;
        char memo[310];
        double weight;
    } girl;

    girl = {"西施", 2, "古代第一美女", 49.9};
    //将结构体写入二进制文件
    fout.write((const char *)&girl, sizeof(st_girl));

    fout.close();
}