#include<iostream>
using namespace std;

void QuickSort(int nums[],int size){
    if(size<2){
        return;
    }

    int mid = nums[0];
    int left = 0; // 左指针
    int right = size - 1; // 右指针
    int move = 2; // 当前应该移动的指针，1为左指针，2为右指针，缺省值为2
    // 刚开始先移动右指针
    while(left<right){
        if(move == 1){ // 移动左指针的情况
            if(nums[left] <= mid){
                left++;
                continue;
            }
            nums[right] = nums[left];
            right--;
            move++;
        }
        else{ // 右指针移动的情况
            if(nums[right] >= mid){
                right--;
                continue;
            }

            nums[left] = nums[right];
            left++;
            move--;
        }
    }

    // 循环结束后左右指针重合，进行递归
    nums[left] = mid;

    QuickSort(nums, left); // mid左边排序
    QuickSort(nums + left + 1, size - left - 1); // mid右边排序
}

int main(){
    int nums[] = {1, 4, 6, 7, 3, 4, 6, 3, 2, 8, 10, 20, 24};
    int size = sizeof(nums) / sizeof(int);
    QuickSort(nums, size);
    for (int i = 0; i < size;i++){
        cout << nums[i] << "   ";
    }
    cout << endl;
    return 0;
}