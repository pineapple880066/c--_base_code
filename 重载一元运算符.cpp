#include<iostream>
using namespace std;

class Girl{
    public:
        int age;
        Girl(int m_age):age(m_age){

        }
        ~Girl(){}
        Girl& operator++(){
            age++;
            return *this;
        }
        void show() const{
            cout << "age: " << age << endl;
        }
        Girl& operator++(int){
            Girl tmp = *this;
            age++;
            return tmp;
        }
};

int main(){
    Girl g1(18);
    cout << g1++.age << endl;
    g1.show();
}