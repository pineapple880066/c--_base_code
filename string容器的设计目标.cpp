#include<iostream>
using namespace std;
#include<string.h>

int main(){

    struct st_girl{
        int bh;
        char name[30];
        bool yz;
        double weight;
        string memo;
    } girl;

    char cc[8]; // 分配8个字节的内存空间

    // 把cc的内存用于字符串
    strcpy(cc, "hello");
    cout << "cc = " << cc << endl << endl;

    // cc的内存用于int型整数
    int *a, *b;
    a = (int *)cc;
    b = (int *)cc;
    *a = 12345;
    *b = 54321;
    cout << "*a = " << *a << endl;
    cout << "*b = " << *b << endl;

    // cc用于double
    double *d = (double *)cc;
    *d = 12345.5;
    cout << "*d = " << *d << endl << endl;

    // cc 用于结构体
    struct st_t{
        int a;
        char b[4];
    };
    struct st_t *st = (struct st_t *)cc;
    st->a = 1;
    strcpy(st->b,"abc");
    cout << "st->a = " << st->a << endl;
    cout << "st->b = " << st->b << endl;

    cout << "st_girl结构体的大小:" << sizeof(st_girl) << endl;

    string buffer;

    for (int i = 1; i <= 10;i++){
        memset(&girl, 0, sizeof(st_girl));
        girl.bh = i;
        printf(girl.name, "西施%02d", i);
        girl.yz = true;
        girl.weight = 48.5 + i;
        girl.memo = "zfahjfa";

        //把超女结构体追加到buffer容器中
        buffer.append((char*)&girl,sizeof(struct st_girl));

    }

    cout << "buffer.size = " << buffer.size() << endl;
    cout << "buffer.cap = " << buffer.capacity() << endl;

    for (int i = 0; i < buffer.size() / sizeof(struct st_girl);i++){
        // 初始化结构体中的数据
        memset(&girl, 0, sizeof(struct st_girl));

        //把容器中的数据复制到超女结构体
        memcpy(&girl, buffer.data() + i * sizeof(struct st_girl), sizeof(struct st_girl));

        //显示超女结构体的data
        cout << "bh = " << girl.bh << " . name = " << girl.name << " . yz = " << girl.yz << " . weight = " << girl.weight << " .  memo = " << girl.memo << endl;

    }
}