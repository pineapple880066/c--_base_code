
#include<iostream>
using namespace std;

class Girl{
    public:
        string m_name;
        int m_yz;

        //两个参数的普通构造函数
        Girl(const string &name,int yz){
            m_name = name;
            m_yz = yz;
        }
        //自我介绍
        void show() const{
            cout << "我是: " << m_name << ",最漂亮" << endl;
            }
        const Girl& pk(Girl& g) const { // 函数必须用const修饰，因为函数的返回值类型为const Girl
            if(g.m_yz < m_yz)
                return g;
            return *this;
        }
};

int main(){
    Girl g1("西瓜", 3), g2("西施", 2),g3("冰冰",4),g4("胡桃",2),g5("芙宁娜",1);
    const Girl &g = g1.pk(g2).pk(g3).pk(g4).pk(g5);

    cout << g.m_name << "最漂亮" << endl;

    return 0;
}