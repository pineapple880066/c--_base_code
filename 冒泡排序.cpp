#include <iostream>
using namespace std;

void BubbleSort(int nums[],int size){
    for (int i = 0; i < size;i++){
        for (int ii = i + 1; ii < size;ii++){
            if(nums[i] > nums[ii]){
                int tmp = nums[i];
                nums[i] = nums[ii];
                nums[ii] = tmp;
            }
        }
    }
}

int main(){
    int nums[] = {3, 4, 2, 6, 1, 5, 8, 9, 10};
    BubbleSort(nums, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << nums[i] << "  ";
    }
    cout << endl;

    return 0;
}
