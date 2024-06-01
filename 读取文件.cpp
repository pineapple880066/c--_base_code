#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int rows = 10;
    const int cols = 10;
    int arr[rows][cols];

    ifstream infile("array.txt"); // 替换为数组文件的路径和文件名
    if (!infile) {
        cerr << "无法打开文件" << endl;
        return 1;
    }

    // 读取数组文件内容到二维数组中
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            infile >> arr[i][j];
        }
    }

    infile.close();

    // 输出读取的数组内容
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
