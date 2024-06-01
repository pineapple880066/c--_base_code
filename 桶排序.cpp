#include <iostream>
#define MAXSIZE 100
using namespace std;
typedef int Elemtype;

struct ListNode{
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
        cout << tmp->data << "   ";
        tmp = tmp->next;
    }
    cout << endl;
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

bool InsertSorted(ListNode*head,const Elemtype&ee){
    if(head == nullptr){
        return false;
    }
    ListNode *tail = head;
    ListNode *p = head->next;
    while(p!=nullptr){
        if(p->data > ee){ // 有比ee大的元素
            InsertPriorNode(p, ee);
            return true;
        }
        tail = p;
        p = p->next;
    }

    if(p == nullptr){ // ee为最大元素，该插入最后
        return InsertNextNode(tail, ee); // 插入尾部之后,但不用尾插法，用尾指针
    }
    return true;
}

// 归并排序链表

void MergeList(ListNode *La, ListNode *Lb, ListNode *Lc){
    ListNode *pa = La->next;
    ListNode *pb = Lb->next;

    ListNode *p;

    while((pa!=nullptr)&&(pb!=nullptr)){
        // 取pa、pb里的较小者
        if(pa->data <= pb->data){
            p = pa;
            pa = pa->next;
        }
        else{
            p = pb;
            pb = pb->next;
        }

        Lc->next = p;
        Lc = Lc->next;
    }
    if(pa!=nullptr)
        Lc->next = pa;
    if(pb!=nullptr)
        Lc->next = pb;

    La->next = Lb->next = nullptr; // 置空
}

void bucketsort(int nums[],int size,int bucketnum){
    // 为桶结构体数组分配空间
    ListNode *buckets = new ListNode[bucketnum];

    //初始化桶,指针置空
    for (int i = 0; i < bucketnum;i++){
        buckets[i].next = nullptr;
    }
    // 为每个桶分配元素
    for (int i = 0; i < size;i++){
        InsertSorted(&buckets[nums[i] % bucketnum], nums[i]);
    }
    //显示每个桶中的元素
    cout << "每个桶中的元素:\n";
    for (int i = 0; i < bucketnum;i++)
        PrintList(&buckets[i]);
    // 归并到List 中
    ListNode *List = new ListNode;
    List->next = nullptr;
    ListNode *tmp = new ListNode;
    tmp->next = nullptr;

    for (int i = 0; i < bucketnum;i++){
        MergeList(&buckets[i], List, tmp);
        swap(List->next, tmp->next);
    }

    ListNode *p = List->next;
    for (int i = 0; i < size;i++){
        nums[i] = p->data;
        p = p->next;
    }

    // 回收内存，先删除一开始分配的桶结构数组
    for (int i = 0; i < bucketnum; i++){
    DestroyList(&buckets[i]);
    }

    DestroyList(List);
    delete[] buckets;
    delete tmp;
    delete List;
}

int main(){
    
    /*调试
    ListNode *La = InitList();
    ListNode *Lb = InitList();
    ListNode *Lc = InitList();

    InsertSorted(La, 2);
    InsertSorted(La, 3);
    InsertSorted(Lb, 7);
    InsertSorted(Lb, 5);
    InsertSorted(Lb, 6);
    PrintList(La);
    PrintList(Lb);
    MergeList(La, Lb, Lc);
    PrintList(Lc);
    DestroyList(La);
    DestroyList(Lb);
    DestroyList(Lc);*/

    int arr[] = {44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    int size = sizeof(arr) / sizeof(int); // 长度
    bucketsort(arr, size, 3);

    for (int i = 0; i < size;i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
    return 0;
}
