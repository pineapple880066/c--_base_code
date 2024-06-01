#include<iostream>
using namespace std;
 // 数出后一个字母
char outputNextChar(char a){
    return (char)((int)a+1);
}
 // 转化成相应整形数字输出
int char2num(char a){
    return (int)a - 48;
}

int main(){
    cout << "请输入一个字母或数字字符" << endl;
    char a = '\0';
    cin >> a;
    cout <<"下一个字母是:"<< outputNextChar(a) << endl;
    cout <<"相应的数字是"<< char2num(a) << endl;

    return 0;
}