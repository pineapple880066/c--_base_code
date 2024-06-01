#include <iostream>
#include <cstdio>
#include <stack>
#include <cmath>
#include<string>
#include<string>

/*
 * 进制转换 10——>n（n<10）
 * */
using namespace std;

void Ten2N(int n,int num){
    // 输入的进制，输入数字
    //转化
    stack<int> a;
    while (num != 0)
    {
        a.push(num % n);
        num /= n;
    }
    while(!a.empty()){
        printf("%d", a.top());
        a.pop();
    }
    printf("\n");
}

int char2Int(char num){
    if(num >='0' && num <='9'){
        return num - '0';
    }
    else if(num >='A' && num <='Z'){ //十进制以上
        return num - "A" + 10;
    }
    else if(num >= 'a' && num<='z'){
        return num - 'a' + 36;
    }
    return 0;
}
void N2Ten(int n,string num){
    //输入的进制，输入的数字
    long long result = 0;
    int len = num.length();

    for (int i = 0; i < len;i++){
        int digitValue = char2Int(num[i]);
        result += digitValue * pow(n, len - i - 1);
    }
}
// void ConvertT2N(int number,int n){
//     stack<char> s;
//     if (number == 0) {  //特殊情况，当输入是0时，输出也是0，否则输入0时就卡那了
//         s.push(0);
//     } else {
//         while (number) {
//             s.push(number % n);
//             number /= n;
//         }
//     }
//     // 把栈中的余数输出
//     while (!s.empty()) {
//         printf("%d", s.top());
//         s.pop();
//     }
//     printf("\n");
// }

int main(){
    int number;
    int n;
    cout << "请输入进制n:" << endl;
    cin >> n;
    cout << "请输入数字num:" << endl;
    cin >> number;
    Ten2N(n, number);

    // while (scanf("%d", &number) != EOF)
    // {
    //     ConvertT2N(number, 5);
    // }
    return 0;
}