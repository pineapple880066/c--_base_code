#include<iostream>
using namespace std;

class Girl{
public:
    int age;
    string name;
    double weight;
    Girl(int m_age,const string& m_name,double m_weight): age(m_age),name(m_name),weight(m_weight) {}
    ~Girl(){}
    void show()const {
        cout << "age: " << age << "  name: " << name << "  weight: " << weight << endl;
    }
    operator int (){
        return age;
    }
    operator string (){
        return name;
    }operator double (){
        return weight;
    }
};

int main(){
    Girl g1(18, "冰冰", 50.1);
    int n_age = g1;      cout << "n_age = " << n_age << endl;
    double n_weight = g1;cout << "n_weight = " << n_weight << endl;
    string n_name = g1;  cout << "n_name = " << n_name << endl;
    // or
    /*
    int n_age = int(g1);
    double n_weight = double(g1);
    string n_name = string(g1);
    cout << "n_age = " << n_age << endl;
    cout << "n_weight = " << n_weight << endl;
    cout << "n_name = " << n_name << endl;
    */
    
    g1.show();

    return 0;
}