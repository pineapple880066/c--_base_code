#include <iostream>
using namespace std;
typedef int Elemtype;

struct Stack{
    Elemtype data;
    struct Stack *next;
};

Stack *InitStack()
{
    // 初始化链表，成功返回头节点
    Stack *head = new Stack;
    if (head == nullptr)
    {
        return nullptr;
    }
    head->next = nullptr;
    return head;
}
// 删除链表
void DestroyStack(Stack *head)
{
    Stack *tmp = nullptr;
    while (head != nullptr)
    {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}
// 插入,头插法
bool Push(Stack *head, const Elemtype &ee)
{
    if (head == nullptr)
    {
        cout << "节点为空,插入失败" << endl;
        return false;
    }
    Stack *tmp = new Stack;
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
void PrintStack(const Stack *head)
{
    if (head == nullptr)
    {
        cout << "链表不存在" << endl;
        return;
    }
    Stack *tmp = head->next;
    while (tmp != nullptr)
    {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

bool Pop(Stack* head){
    if (head == nullptr)
    {
        cout << "链表不存在" << endl;
        return false;
    }
    Stack *tmp = head->next;
    head->next = tmp->next;
    delete tmp;
    return true;
}

int GetLength(Stack* head){
    if(head == nullptr){
        return 0;
    }
    Stack *p = head;
    int count = -1;
    while(p != nullptr){
        count++;
        p = p->next;
    }
    return count;
}

int main(){
    Stack *SS = InitStack(); // 初始化栈
    cout << "入栈三个元素(1,2,3)" << endl;
    Push(SS, 1);
    Push(SS, 2);
    Push(SS, 3);
    PrintStack(SS);

    cout << "链栈的长度为:" << GetLength(SS) << endl;

    Pop(SS);
    PrintStack(SS);
}