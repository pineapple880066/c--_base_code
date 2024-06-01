#include <iostream>
#include <string.h>
using namespace std;
typedef int Elemtype;
// 111
struct ListNode
{

    Elemtype data;
    struct ListNode *next;
};

ListNode *InitList()
{
    // 初始化链表，成功返回头节点
    ListNode *head = new ListNode;
    if (head == nullptr)
    {
        return nullptr;
    }
    head->next = nullptr;
    return head;
}
// 删除链表
void DestroyList(ListNode *head)
{
    ListNode *tmp = nullptr;
    while (head != nullptr)
    {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}
// 插入,头插法
bool PushFront(ListNode *head, const Elemtype &ee)
{
    if (head == nullptr)
    {
        cout << "节点为空,插入失败" << endl;
        return false;
    }
    ListNode *tmp = new ListNode;
    tmp->data = ee;
    if (tmp == nullptr)
    {
        cout << "分配内存失败" << endl;
        return false;
    }
    tmp->next = head->next;
    head->next = tmp;

    return true;
}
// 遍历链表并显示所有元素
void PrintList(const ListNode *head)
{
    if (head == nullptr)
    {
        cout << "链表不存在" << endl;
        return;
    }
    ListNode *tmp = head->next;
    while (tmp != nullptr)
    {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}
// 在链表尾部插入元素
bool PushBack(ListNode *head, const Elemtype &ee)
{
    if (head == nullptr)
    {
        cout << "链表不存在" << endl;
        return false;
    }
    ListNode *tmp = new ListNode;
    if (tmp == nullptr)
    {
        cout << "分配内存失败" << endl;
        return false;
    }
    tmp->data = ee;

    ListNode *p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    p->next = tmp;
    tmp->next = nullptr;
    return true;
}

bool PopFront(ListNode* head){
    if (head == nullptr)
    {
        cout << "链表不存在" << endl;
        return false;
    }
    ListNode *tmp = head->next;
    head->next = tmp->next;
    delete tmp;
    return true;
}

bool PopBack(ListNode* head){
    if (head == nullptr || head->next == nullptr)
    {
        cout << "链表不存在" << endl;
        return false;
    }
    ListNode *pp = head;
    ListNode *p = head->next;
    while(p->next != nullptr){
        p = p->next;
        pp = pp->next;
    }
    pp->next = nullptr;
    delete p;
    return true;
}

void ClearList(ListNode* head){
    if(head == nullptr){
        cout << "该链表不存在" << endl;
        return;
    }
    ListNode *tmp1;
    ListNode *tmp2 = head->next;

    while (tmp2 != nullptr){
        tmp1 = tmp2->next;
        delete tmp2;
        tmp2 = tmp1;
    }

    head->next = nullptr; // 头节点的next指向空，否则为野指针
}

int GetLength(ListNode* head){
    if(head == nullptr){
        return 0;
    }
    ListNode *p = head;
    int count = -1;
    while(p != nullptr){
        count++;
        p = p->next;
    }
    return count;
}

ListNode *GerLocateListNode(ListNode *head,unsigned int Location){
    if(head == nullptr){
        cout << "链表不存在" << endl;
        return nullptr;
    }
    if(Location > GetLength(head)){
        cout << "超出链表长度" << endl;
        return nullptr;
    }
    ListNode *p = head;
    int i = 0;
    while(p && i < Location){
        p = p->next;
        i++;
    }
    return p;
}

bool InsertNextNode(ListNode *pp, const Elemtype &ee){
    if(pp == nullptr){
        cout << "pp is not found" << endl;
        return false;
    }
    ListNode *tmp = new ListNode;
    tmp->data = ee;
    tmp->next = pp->next;
    pp->next = tmp;

    return true;
}

bool InsertPriorNode(ListNode *pp, const Elemtype &ee){
    if(pp == nullptr){
        cout << "pp is not found" << endl;
        return false;
    }
    ListNode *tmp = new ListNode;
    tmp->data = ee;
    tmp->next = pp->next;
    pp->next = tmp;
    Elemtype t = pp->data;
    pp->data = tmp->data;
    tmp->data = t;
    // 偷梁换柱
    return true;
}

bool DeleteNodePp(ListNode*head,ListNode *pp){
    if(pp == nullptr){
        cout << "pp is not found" << endl;
        return false;
    }
    if(pp->next == nullptr){
        PopBack(head);
        return true;
    }
    // 偷梁换柱
    ListNode *tmp = pp->next;
    pp->data = tmp->data;
    pp->next = tmp->next;
    delete tmp;
    return true;
}

int main(){
    ListNode *head = InitList();
    head->data = 1;
    head->next = nullptr;
    PushFront(head, 1);
    PushFront(head, 12);
    PushFront(head, 13);
    PushFront(head, 14);
    PushFront(head, 15);
    PushBack(head, 21);
    PushBack(head, 22);
    PushBack(head, 23);
    PopFront(head);
    PopFront(head);
    PopBack(head);
    PrintList(head);
    cout << GetLength(head) << endl;
    cout << GerLocateListNode(head, 3)->data << endl;
    ClearList(head);
    PrintList(head);
    DestroyList(head);

    return 0;
}
