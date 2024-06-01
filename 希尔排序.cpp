#include<iostream>
using namespace std;
void groupsort(int nums[],int size,int num,int step){
    int tmp;

    for (int i = num + step; i < size;i = i + step){
        tmp = nums[i];
        int j;
        for (j = i - step; j >= 0; j -= step){
            if(nums[j] <= tmp){
                break;
            }
            nums[j + step] = nums[j];
        }
        nums[j + step] = tmp;
    }
}

void ShellSort(int nums[],unsigned int size){
    for (int step = size / 2; step > 0;step = step/2){
        for (int ii = 0; ii < step;ii++){
            groupsort(nums, size, ii, step);
        }
    }
}

int main(){
    int nums[] = {3, 4, 2, 6, 1, 5, 8, 9, 10};
    ShellSort(nums, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << nums[i] << "  ";
    }
    cout << endl;
    return 0;
}
