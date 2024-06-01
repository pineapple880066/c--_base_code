#include<iostream>
using namespace std;

class Girl{
    friend void operator+(Girl &g, int m_score);

private:
    int xw;
    int score;

public:
    int age;
    string name;
    int yz;
    Girl(int m_age, string m_name, int m_yz):age(m_age), name(m_name), yz(m_yz) {
        xw = 80;
        score = 60;
    }
    ~Girl(){}

    void show() const {
        cout << "age :" << age << " name:" << name << " xw:" << xw << " score:" << score << endl;
    }
};

void operator+(Girl &g,int m_score){ // 重载运算符函数中的参数应该至少有一个是用户自定义的数据类型，防止与内置的数据类型运算符冲突
    g.score = g.score + m_score;
}
 // 运算符重载应该优先考虑为成员函数
int main(){
    Girl g1(18, "666", 2);
    // addScore(g1, 30); 正常调用函数
    g1 + (-30);
    g1.show();
    return 0;
}