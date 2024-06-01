#include<iostream>
#include<cstdlib>
using namespace std;

class Girl{
public:
    int age;
    int bh;
    static char *pool ; // 内存池的起始地址，因为要在new与delete重载函数中使用所以需要static声明
    static bool initPool(){ // 必须用static声明，因为要用到pool
        pool = (char *)malloc(36);
        if(pool == 0){
            return false;
        }
        memset(pool, 0, 36);
        cout << "内存池设置成功，起始地址为："<<(void*)pool << endl;
        return true;
    }

    static void freePool(){
        if(pool == 0)
            return;
        free(pool);
        cout << "内存池已释放" << endl;
    }
    Girl(int m_age,int m_bh) : age(m_age),bh(m_bh)
    {
    }
    ~Girl(){
    }
    void* operator new(size_t size){
        if(pool[0] == 0){
            cout << "分配了第一个内存位置" << (void *)(pool[0] + 1) << endl;
            pool[0] = 1;
            return pool + 1;
        }
        if(pool[9] == 0){
            cout << "分配了第二个内存的空间" << (void *)(pool[9] + 1) << endl;
            pool[9] = 1;
            return pool + 10;
        }
        if(pool[19] == 0){
            cout << "分配了第二个内存的空间" << (void *)(pool[19] + 1) << endl;
            pool[19] = 1;
            return pool + 20;
        }
        if(pool[29] == 0){
            cout << "分配了第二个内存的空间" << (void *)(pool[29] + 1) << endl;
            pool[29] = 1;
            return pool + 30;
        }
        void *ptr = malloc(size);
        cout << "申请到的内存是：" << ptr << endl;
        return ptr;
    }
    void operator delete(void* ptr){
        if(ptr == nullptr) // 如果是空
            return;
        if(ptr == pool + 1){ // 如果是第一块内存
            cout << "第一块内存被清空" << endl;
            pool[0] == 0; // 清空内存第一个位置设置为0即可代表空
            return;
        }
        if(ptr == pool + 9){ // 如果是第二块
            pool[9] == 0; // pool[0-17]第十个位置为pool[9]用于储存占位与否的标志
            cout << "第二块内存被清空" << endl;
            return;
        }
        if(ptr == pool + 19){ 
            pool[19] == 0;
            cout << "第三块内存被清空" << endl;
            return;
        }
        if(ptr == pool + 29){
            pool[29] == 0;
            cout << "第四块内存被清空" << endl;
            return;
        }

        // 如果不属于内存池
        free(ptr);
    }
};

char* Girl::pool = nullptr; // 静态变量初始化需要在全局

int main(){
    if(Girl::initPool() == false){
        cout << "内存池初始化失败" << endl;
        return -1;
    }
    else{ // 如果使用 if(Girl::initPool() == true) 而不是 else 来检查内存池的初始化会使得内存池再次初始化
        cout << "初始化内存池成功(main)" << endl;
    }
    Girl *g1 = new Girl(18, 2);
    cout << "g1的地址为:" << g1 << endl;
    delete g1;
    Girl *g2 = new Girl(18, 2);
    cout << "g2的地址为:" << g2 << endl;
    Girl *g3 = new Girl(18, 2);
    cout << "g3的地址为:" << g3 << endl;
    Girl *g4 = new Girl(18, 2);
    cout << "g4的地址为:" << g4 << endl;
    delete g2;
    delete g3;
    delete g4;
    Girl::freePool();
    return 0;
}