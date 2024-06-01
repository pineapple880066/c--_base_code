#include<iostream>
using namespace std;

void SelectSort(int nums[],int size){
    for (int i = 0; i < size;i++){
        int min = nums[i];
        int MinPos = i;
        for (int ii = i + 1; ii < size; ii++)
        {
            if (nums[ii] < min)
            {
                min = nums[ii];
                MinPos = ii;
            }
        }
        swap(nums[MinPos], nums[i]);
    }
}

int main(){
    int nums[] = {3, 4, 2, 6, 1, 5, 8, 9, 10};
    SelectSort(nums, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << nums[i] << "  ";
    }
    cout << endl;

    return 0;
}