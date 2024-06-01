#include<iostream>
using namespace std;

class Girl{
public:
    string name;
    int age;
    int yz;
    int acting;
    Girl(string m_name, int m_age, int m_yz, int m_acting) :
    name(m_name),age(m_age),yz(m_yz),acting(m_acting)
    {}
    ~Girl(){};
};

bool operator ==(Girl& g1,Girl& g2){
    if((g1.acting+g1.age+g1.yz)==(g2.acting + g2.age + g2.yz))
        return true;
    return false;
}

bool operator > (Girl& g1,Girl& g2){
    if((g1.acting+g1.age+g1.yz) < (g2.acting + g2.age + g2.yz))
        return true;
    return false;
}

bool operator < (Girl& g1,Girl& g2){
    if((g1.acting+g1.age+g1.yz) > (g2.acting + g2.age + g2.yz))
        return true;
    return false;
}
int main(){
    Girl g1("冰冰", 18, 2, 2), g2("西施", 18, 3, 2);

    if(g1 > g2){
        cout << g1.name << "为最好的" << endl;
    }
    else if(g1 == g2){
        cout << g1.name << "与" << g2.name << "都为最好的" << endl;
    }
    else{
        cout << g2.name << "为最好的" << endl;
    }

    return 0;
}