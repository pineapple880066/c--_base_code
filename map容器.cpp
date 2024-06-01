#include "mystdio.h"

int main(){
    map<int, string> map1;

    //统一初始化列表
    map<int, string> map2({{8, "bingbing"}, {2, "xishi"}, {3, "mimi"}, {6, "jinlian"}, {5, "xigua"}});

    for(auto&val:map2)
        cout << val.first << "," << val.second << " ";
    cout << endl;

    //拷贝构造函数
    map<int, string> map3 = map2;
    for(auto&val:map3)
        cout << val.first << "," << val.second << " ";
    cout << endl;

    //迭代器创建容器
    auto first = map3.cbegin();
    first++;
    auto last = map3.cend();
    last--;
    map<int, string> map4(first, last);
    for(auto&val:map4)
        cout << val.first << "," << val.second << " ";
    cout << endl;

    //长度、是否为空、清除
    //size,empty,clear
    cout << "map3的长度为:" << map3.size() << endl;
    cout << "map3是否为空:";
    if(map3.empty()){
        cout << "是" << endl;
    }
    else
        cout << "否" << endl;
    // 清空容器
    // map3.clear();
    // for(auto value:map3)
    //     cout << value.first << "," << value.second << " ";
    // cout << endl;

    //显示 （使用下标访问）
    cout << "map3[6] = " << map3[6] << endl;

    map<string, string> map5 = {{"01", "jfsf"}, {"02", "adad"}, {"03", "dawf"}, {"06", "dgth"}};

    cout << "map5[03] = " << map5["03"] << endl;
    // 可以修改元素
    map5["03"] = "花花";
    cout << "map5[03] = " << map5["03"] << endl;
    // 容器内没有的元素将会新插入一个元素
    map5["05"] = "xiaoqiao";
    cout << "map5[05] = " << map5["05"] << endl;

    //交换
    cout << "交换前:" << endl;
    for (auto &val : map3)
    {
        cout << val.first << "," << val.second << " ";
    }
    cout << endl;
    for(auto& val:map4){
        cout << val.first << "," << val.second << " ";
    }
    cout << endl;
    //交换后
    cout << "交换后:" << endl;
    map4.swap(map3);
    for(auto& val:map3){
        cout << val.first << "," << val.second << " ";
    }
    cout << endl;
    for(auto& val:map4){
        cout << val.first << "," << val.second << " ";
    }
    cout << endl;

    //查找
    //find找到key为X的元素并返回迭代器
    cout << " map3中key = 3的元素:" << (*map3.find(3)).second << endl;

    //查找第一个键>key的键值对:(返回迭代器)
    cout << "第一个大于3的元素:" << (*map3.upper_bound(3)).second << endl;

    //查找第一个键值>=key的键值对:
    cout << "第一个键值>=5的键值对" << (*map3.lower_bound(5)).second << endl;

    //插入删除
    map<int, string> m;

    m.insert({{8, "冰冰"}, {3, "西施"}});
    m.insert({pair<int, string>(1, "秘密"), make_pair<int, string>(2,"包子")});
    m.insert({{18, "月月"}, {3, "西施"}});

    // pair<itrator,bool> insert(const pair<K,V> &value);
    // 插入一个元素value并返回pair:first是插入元素的迭代器，second是插入结果

    auto ret = m.insert(pair<int, string>(12, "花花"));
    if(ret.second == true)
        cout << "插入成功" << ret.first->first << "," << ret.first->second << endl;
    else
        cout << "插入失败" << endl;

    for(auto& val:m){
        cout << val.first << "," << val.second << " ";
    }
    cout << endl;

    map<int, string> m3 = {{1, "宝马"}, {2, "梅赛德斯"}, {3, "奥迪"}, {4, "保时捷"}, {5, "凯迪拉克"}};

    for(auto &val:m3){
        cout << val.first << "," << val.second << " ";
    }
    cout << endl;

    // 3）insert(iterator first ,iterator last);
    first = m3.cbegin();
    last = m3.cbegin();
    last++;
    map<int, string> m4;
    m4.insert(first, last);
    for(auto& val:m4){
    cout <<val.first<<","<< val.second << " ";
    }
    cout << endl;

    // 4) pair<iterator,bool> emplace(..);
    // 效率更高,少调用一次构造函数
    auto ret1 = m.emplace(20, "huahua");
    if(ret1.second == true)
        cout << "插入成功" << ret1.first->first << "," << ret1.first->second << endl;

    else
        cout << "插入失败" << endl;
    
    for(auto&val:m){
        cout << val.first << "," << val.second << " ";
    }
    cout << endl;

    

}