#include<iostream>
#include<cstdlib>
using namespace std;

class Girl{
public:
    int age;
    int *ptr;
    Girl(int m_age):age(m_age),ptr(nullptr){
        ptr = new int(3);
    }
    ~Girl(){
        delete ptr;
    }
    void* operator new(size_t size){
        void* ptr = malloc(size);
        cout << "调用了成员new函数" << endl;
        return ptr;
    }
    void operator delete(void* ptr){
        cout << "调用了成员delete函数" << endl;
        if(ptr == nullptr){
            return;
        }
        free(ptr);
    }
};
void *operator new(size_t size)
{
    void *ptr = malloc(size);
    cout << "调用了全局new函数" << endl;
    return ptr;
}
void operator delete(void* ptr){
    cout << "调用了全局delete函数" << endl;
    if(ptr == nullptr){
        return;
    }
    free(ptr);
}
int main(){
    Girl *g1 = new Girl(18);
    delete g1;

    return 0;
    // 输出日志：调用了成员new函数
    // 调用了全局new函数    //由于有指针对象g1与指针g1->ptr所以要调用两次new与delete
//     调用了全局delete函数
//     调用了成员delete函数
}