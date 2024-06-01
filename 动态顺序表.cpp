#include<iostream>
using namespace std;

#define INITSIZE 5 // 初始化表长
#define EXTSIZE 3 // 每次增加的长度

typedef int ElemType;

struct SeqList{
    ElemType *data;
    size_t length;
    unsigned int maxsize;
};

void ClearList(SeqList& List){ // 清空顺序表
    List.length = 0;
    memset(&List, 0, sizeof(ElemType) * List.maxsize);
    // 或者 memset(&List, 0,sizeof(SeqList));在动态表里不能用，会清空指针
}

void InitList(SeqList& L) {
    L.maxsize = INITSIZE;
    L.data = new ElemType[L.maxsize]; //分配空间
    Clear(L);
}

void DestroyList(SeqList& L){ // 销毁顺序表
    delete[] L.data;
    L.data = nullptr; // 指针置空
    L.length = 0; // 表长置空
    L.maxsize = 0; // 现有长度置空
}

bool ExtList(SeqList& L){
    L.data = new (nothrow) ElemType[L.maxsize + EXTSIZE]; // nothrow 是为了分配失败时不报异常
    
}
