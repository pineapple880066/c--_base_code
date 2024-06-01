#include<iostream>
using namespace std;

void InsertSort(int nums[],int size){
    if(size < 2)
        return;
    int tmp;
    for (int i = 0; i < size; i++){
        tmp = nums[i];
        int j;
        for (j = i - 1; j >= 0; j--){
            if(nums[j]<=tmp)
                break;
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = tmp;
    }
}

int main(){
    int nums[] = {3, 4, 2, 6, 1, 5, 8, 9, 10};
    InsertSort(nums, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << nums[i] << "  ";
    }
    cout << endl;

    return 0;
}