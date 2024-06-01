#include<iostream>
using namespace std;

void NumsMinMax(int nums[],int size,int&minvalue,int&maxvalue){
    int i = 0;
    minvalue = maxvalue = nums[0];

    for (i = 0; i < size;i++){
        if(maxvalue <nums[i])
            maxvalue = nums[i];
        if(minvalue >nums[i])
            minvalue = nums[i];
    }
}

//计数主体
void CountSort(int nums[],int size){
    if(size < 2){
        return;
    }

    // 获取最大最小值
    int min, max;
    NumsMinMax(nums, size, min, max);
    
    //分配并初始化临时数组
    int *numsTmp = new int[max - min + 1];
    memset(numsTmp, 0, sizeof(int) * (max - min + 1));

    // 计数
    for (int i = 0; i < size;i++){
        numsTmp[nums[i] - min]++;
    }
    for (int i = 0, j = 0; j < max - min + 1;j++){
        for (int k = 0; k < numsTmp[j];k++){
            nums[i++] = j + min;
        }
    }
    delete[] numsTmp;
}

int main(){
    int nums[] = {1, 4, 6, 7, 3, 4, 6, 3, 2, 8, 10, 20, 24};
    int size = sizeof(nums) / sizeof(int);
    CountSort(nums, size);
    for (int i = 0; i < size;i++){
        cout << nums[i] << "   ";
    }
    cout << endl;
    return 0;
}