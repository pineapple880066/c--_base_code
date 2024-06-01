#include "mystdio.h"

int main(){
    //插入删除:insert / emplace(效率更高)
    cout << "开始创建umap" << time(0) << endl;
    unordered_map<int, string> m6(100000000);
    for (int i = 0; i < 100000000;i++){
        // m6.insert({i, "西施"});
        m6.emplace(i, "西式");
    }
    cout << "创建umap完成" << time(0) << endl;
    return 0;
    // 1) umap(); //创建一个空的哈希表
    // umap<int,string> m(size_t n),n可以指定创建时桶的数量
    unordered_map<int, string> m1;

    // 2) 初始化列表
    unordered_map<int, string> m2({{1, "bb"}, {2, "ddd"}, {3, "ll"}, {4, "ff"}});

    for(auto& val:m2)
        cout << val.first << "," << val.second << " ";
    cout << endl;

    // 3)拷贝构造函数
    unordered_map<int, string> m3 = m2;
    for(auto& val:m3)
        cout << val.first << "," << val.second << " ";
    cout << endl;

    // 4)unordered_map(fast,last) //迭代器创建容器
    auto first = m3.cbegin();
    first++;
    auto last = m3.cend();
    unordered_map<int, string> m4(first, last);
    for(auto& val:m4)
        cout << val.first << "," << val.second << " ";
    cout << endl;

    //特性操作
    cout <<"m4.size = "<< m4.size() << endl;
    // m4.empty()
    m4.clear();
    // 返回当前桶的数量,到达该值时，容器将会自动拓展
    cout << m4.bucket_count() << endl;
    size_t itmp = m4.bucket_count();

    // 展示自动拓展日志 ,20w装填示例
    // for (int i = 0; i < 200000;i++){
    //     char name[50];
    //     printf(name, "西施%d", i);
    //     m4.emplace(i,name);

    //     if(itmp != m4.bucket_count()){
    //         cout << m4.bucket_count() << endl;
    //         itmp = m4.bucket_count();
    //     }

    // }
    // 返回当前的装填因子 float load_factor(); 
    // 装填因子 = 当前占用桶的数量/当前桶的数量
    //设置容器的最大装填因子，到达该值之后容器将会拓展,缺省值为1
    unordered_map<int, string> m;

    m.max_load_factor(0.5);
    // 设置最大装填因子max_load_factor (float z)
    cout << "最大装填因子" << m.max_load_factor() << endl;

    m.insert({{1, "fa"}, {2, "fgg"}, {3, "akfa"}, {4, "po"}});
    cout << "当前桶数" << m.bucket_count() << endl;
    cout << "当前装填因子" << m.load_factor() << endl;
    cout << "最大装填因子" << m.max_load_factor() << endl;

    m.insert({{6, "faft"}});
    cout << "当前桶数" << m.bucket_count() << endl;
    cout << "当前装填因子" << m.load_factor() << endl;
    cout << "最大装填因子" << m.max_load_factor() << endl;

    
    m.insert({{8, "faafafft"}});
    cout << "当前桶数" << m.bucket_count() << endl;
    cout << "当前装填因子" << m.load_factor() << endl;
    cout << "最大装填因子" << m.max_load_factor() << endl;

    unordered_map<int, string> mm;
    mm.insert({{3, "dad"}, {2, "dadg"}, {5, "aghf"}, {6, "fahj"}, {7, "ahfaj"}, {8, "fajk"}, {9, "ahfja"}, {10, "djakj"}, {111, "jaior"}, {109, "ajro"}, {93, "fahfua"}});

    // begin(size_t n) & end(size_t n) 
    // 返回第n个桶的第一个（最后一个）元素的迭代器，
    // 缺省为第一个桶的第一个元素与最后一个桶的最后一个元素
    // 遍历umap容器
    for(auto& val:mm)
        cout << val.first << "," << val.second << " ";
    cout << endl;

    // or:
    for (auto it = m.cbegin(); it != m.cend();it++){
        cout << it->first << "," << it->second << " ";
    }
    cout << endl;

    // 遍历每个桶中的元素
    for (int i = 0; i < mm.bucket_count();i++){
        cout << "桶" << i << " :";
        for (auto it = mm.begin(i); it != mm.end(i);it++){
            cout << it->first << "," << it->second << " ";
        }
        cout << endl;
    }

    //在哈希表中桶是数组，桶中的元素是链表，每次拓展都必须重新创建一个哈希表，效率低

    
}