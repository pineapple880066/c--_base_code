#include<iostream>
using namespace std;

typedef int Elemtype;

struct ListNode{
    Elemtype data;
    struct ListNode *prior, *next;
};

ListNode* InitList(){
    ListNode *head = new(nothrow) ListNode;
    if(head == nullptr){
        cout << "分配内存失败" << endl;
        return nullptr;
    }
    head->prior = nullptr;
    head->next = nullptr;
    head->data = 0;
    return head;
}

void DestroyList(ListNode*head){
    if(head == nullptr){
        delete head;
        return;
    }
    ListNode *tmp = head->next;
    while(head != nullptr){
        delete head;
        head = tmp;
        tmp = tmp->next;
    }
    delete head;
}

bool InsertNext(ListNode* List,const Elemtype& ee){
    if(List == nullptr){
        cout << "没找到该节点" << endl;
        return false;
    }
    ListNode *tmp = new ListNode;
    if(List->next == nullptr){
        tmp->next = nullptr;
        tmp->prior = List;
        List->next = tmp;
        return true;
    }
    
    tmp->data = ee;
    tmp->next = List->next;
    tmp->prior = List;
    List->next = tmp;
    tmp->next->prior = tmp;
    return true;
}

bool DeleteNext(ListNode *List){
    if (List == nullptr){
        return false;
    }
    if(List->next == nullptr){
        return true;
    }
    ListNode *tmp = List->next;
    if(tmp->next = )
    List->next = tmp->next;
    tmp = List->next;
    tmp->prior = List;
    return true;
}

bool PushFront(ListNode *head, Elemtype &ee){
    if(head == nullptr){
        return false;
    }
    ListNode *tmp = new ListNode;
    if(tmp == nullptr){
        cout << "内存分配失败" << endl;
        return false;
    }
    tmp->data = ee;
    tmp->next = head->next;
    head->next = tmp;
    tmp->prior = head;
    return true;
}

int main(){
    return 0;
}