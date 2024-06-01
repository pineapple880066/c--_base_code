#include<iostream>
using namespace std;

typedef int ElemType;

struct ListNode{
    ElemType data;
    struct ListNode *next;
};

struct LinkQueue{
    ListNode *head, *tail;
};

bool InitQueue(LinkQueue& qq){
    qq.head = new (nothrow) ListNode;
    if(qq.head == nullptr)
        return false;
    qq.head->next = nullptr;
    qq.tail = qq.head;
    return true;
}

void DestroyQueue(LinkQueue&qq){
    ListNode *tmp;
    while(qq.head != nullptr){
        tmp = qq.head->next;
        delete qq.head;
        qq.head = tmp;
    }
}

//入队
bool inQueue(LinkQueue& qq,const ElemType& ee){
    if(qq.head == nullptr){
        cout << "队列未初始化" << endl;
        return false;
    }

    ListNode *tmp = new (nothrow) ListNode;
    if(tmp == nullptr)
        return false;
    
    tmp->data = ee;
    tmp->next = nullptr;

    qq.tail->next = tmp; //tmp追加到qq.tail之后
    qq.tail = tmp;

    return true;
}

// 出队
bool OutQueue(LinkQueue& qq,ElemType& ee){
    if(qq.head == nullptr){
        cout << "队列未初始化" << endl;
        return false;
    }

    if(qq.head->next == nullptr){
        cout << "队列为空" << endl;
        return false;
    }

    ListNode *tmp = qq.head->next;
    ee = tmp->data;
    qq.head->next = tmp->next;

    // 如果出队的是最后一个节点
    if(tmp == qq.tail){
        qq.tail = qq.head;
    }

    delete tmp;

    return true;
}

void PrintQueue(LinkQueue&qq){
    if(qq.head == nullptr){
        cout << "队列未初始化" << endl;
        return;
    }
    ListNode *pp = qq.head->next;
    while(pp != nullptr){
        cout << pp->data << "  ";
        pp = pp->next;
    }

    cout << endl;
}

int Length(LinkQueue& qq){
    if(qq.head == nullptr){
        cout << "队列未初始化" << endl;
        return -1;
    }
    ListNode *pp = qq.head->next;
    int length = 0;
    while(pp != nullptr){
        pp = pp->next;
        length++;
    }
    return length;
}

//清空队列

void Clear(LinkQueue&qq){
    if(qq.head == nullptr){
        cout << "队列未初始化" << endl;
        return;
    }

    // 释放全部数据节点，保留头节点
    ListNode *tmp = qq.head->next, *tmpnext;
    while (tmp != nullptr){
        tmpnext = tmp->next;
        delete tmp;
        tmp = tmpnext;
    }

    // 必须更新指针，否则为野指针删除时报错
    qq.head->next = nullptr;
}

int main(){
    LinkQueue qq;
    memset(&qq, 0, sizeof(qq));

    InitQueue(qq);

    cout << "元素1,2,3,4,5入队" << endl;
    inQueue(qq, 1);
    inQueue(qq, 2);
    inQueue(qq, 3);
    inQueue(qq, 4);
    inQueue(qq, 5);
    PrintQueue(qq);
    Clear(qq);
    PrintQueue(qq);
    DestroyQueue(qq);

    return 0;
}
