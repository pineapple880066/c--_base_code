#include "mystdio.h"

void func(int bh,string& name){
    cout << "dear :" << bh << " ," << name << endl;
}

int main(){
    int bh = 3;
    string name = "fafa";

    func(bh, message);//调用函数

    void (*pfunc)(int, string); //声明函数指针
    pfunc = func;      //对函数指针赋值

    pfunc(bh, name); // 用函数指针调用函数
    (*pfunc)(bh, name); //c语言

    
}