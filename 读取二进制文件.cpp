#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string filename_test = R"(/Users/pineapple/Desktop/c:c++/知识点/test.dat)";

    ifstream fin;
    //二进制文件的打开方式: ios::binary
    // ifstream fin(filename_test, ios::binary);

    fin.open(filename_test, ios::in | ios::binary);
    // 如果文件不存在输入流不会创建文件

    // 判断打开文件是否成功
    if(fin.is_open() == false){
        cout << "打开文件" << filename_test << "失败" << endl;
        return 0;
    }
    
    // 怎么写的文件，就怎么读取
    struct st_girl{ // 结构体
        char name[31];
        int no;
        char memo[310];
        double weight;
    } girl;

    //读取文件用输入流的read()函数
    while(fin.read((char *)&girl, sizeof(st_girl))){
        cout << "name = " << girl.name << " , no = " << 
        girl.no << " , memo = " << girl.memo << " , weight = " << 
        girl.weight << endl;
    }

    fin.close();

    cout << "操作文件结束";
}