#include<iostream>
#define MAXSIZE 100
using namespace std;

typedef int ElemType;

struct SeqList{
    ElemType data [MAXSIZE];
    size_t length;

};

void ClearList(SeqList& List){ // 清空顺序表
    List.length = 0;
    memset(&List, 0, sizeof(ElemType) * MAXSIZE);
    // 或者 memset(&List, 0,sizeof(SeqList));
}

bool InsertList(SeqList& L,const int pos, const ElemType& ee){
    if(L.length == MAXSIZE){
        cout << "空间已满" << endl;
    }
    if(pos < 1 || pos >L.length + 1){
        cout << "插入位置不合法,应该在1-" << L.length + 1 << "之间" << endl;
    }
    if(pos <= L.length){
        memmove(L.data + pos, L.data + pos - 1, sizeof(ElemType) * (L.length - pos + 1));
    }
    L.data[pos - 1] = ee; // 赋值
    L.length++; // 表长加一

    return true;
}

int GetLength(const SeqList& List){
    return List.length;
}

ElemType GetPos(const SeqList& List,const int pos){ //返回pos位置的元素
    if(pos < 1 || pos >List.length){
        cout << "插入位置不合法,应该在1-" << List.length << "之间" << endl;
    }

    return List.data[pos - 1];
}

bool PushFront(SeqList& List,const ElemType& ee){ // 头部插入元素
    InsertList(List, 1, ee);
    return true;
}

bool PushBack(SeqList& List,const ElemType& ee){ // 尾部插入元素
    InsertList(List, List.length + 1, ee);
    return true;
}

int main(){
    SeqList L;
    ClearList(L);
    cout << GetLength(L) << endl;
    InsertList(L, 1, 666);
    InsertList(L, 2, 555);
    PushBack(L, 444);
    PushFront(L, 111);
    
    int i = 0;
    while (L.data[i] != 0){
        cout << L.data[i] << endl;
        i++;
    }
    cout << GetLength(L) << endl;
    // cout << GetPos(L,5) << endl;
    return 0;
}
