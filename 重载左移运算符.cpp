#include<iostream>
using namespace std;

class Girl{
public:
    int age;
    int yz;
    string name;

    Girl(int m_age,int m_yz,const string &m_name):age(m_age),yz(m_yz),name(m_name)  {}
    ~Girl(){}
};

ostream& operator<<(ostream& cout,Girl& g){
    cout << g.age << g.name << g.yz << endl;
    return cout;
}

int main(){
    Girl g1(18, 2, "冰冰");
    cout << g1 << endl;
}