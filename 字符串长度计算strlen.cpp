#include<iostream>
using namespace std;

int length(const char* str){
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

int main(){
    char str[30];
    memset(str, 0, sizeof(str));
    cout << "请输入一个字符串:" << endl;
    cin >> str;
    cout << "长度为:" << length(str) << endl;
}