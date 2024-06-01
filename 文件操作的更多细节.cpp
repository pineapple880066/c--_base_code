#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ofstream fout(R"(/Users/pineapple/Desktop/c:c++/知识点/abc.txt)");
    fout << "abcde";
    fout.close();

    cout << "end" << endl;
}