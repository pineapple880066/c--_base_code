#include<iostream>
#include<fstream>  // For ifstream class 
#include<cstdlib>  // For malloc, realloc
#include<cstring>  // For memset, strlen

using namespace std;

int main() {
    const char* filename_test = "/Users/pineapple/Desktop/c:c++/知识点/test.txt";
    ifstream fin(filename_test, ios::in);

    if (!fin.is_open()) {
        cout << "打开" << filename_test << "失败" << endl;
        return 1;
    }

    size_t bufferSize = 11;
    char* buffer = (char*)malloc(bufferSize);
    memset(buffer, 0, bufferSize);

    while (!fin.eof()) { // 

        fin.getline(buffer, bufferSize);
        while (fin.fail() && !fin.eof()) {
            fin.clear(); // 清除错误状态

            size_t currentLength = strlen(buffer); // 目前读取到的数据长度
            bufferSize *= 2; // 增加两倍缓冲区
            buffer = (char*)realloc(buffer, bufferSize); // 重新分配更大的缓冲区
            memset(buffer + currentLength, 0, bufferSize - currentLength); // 清零新空间 利用指针返回读取之前未读取完的数据行

            fin.getline(buffer + currentLength, bufferSize - currentLength); // 继续读取剩余部分
        }

        if (strlen(buffer) > 0) {
            cout << buffer << endl; // 输出读取到的行
        }
    }

    free(buffer);
    fin.close();
    cout << "文件操作完毕" << endl;

    return 0;
}