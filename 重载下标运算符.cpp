#include<iostream>
using namespace std;

class Girl{
private:
    string boys[3];
public:
    int age;

    Girl(const string &b1, const string &b2, const string &b3) : age(18){
        boys[0] = b1;
        boys[1] = b2;
        boys[2] = b3;
    }
    ~Girl() {}
    void show() const
    {
        cout<<"该女生的三个男友分别为" << boys[0] << " " << boys[1] << " " << boys[2] << endl;
    }
    string& operator[](int i){
        return boys[i];
    }
    const string& operator[](int i) const {

        return boys[i];
    }
};

int main(){
    Girl g1("金平", "泽东", "惊涛");
    g1[1] = "sb";
    g1.show();
}