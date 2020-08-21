### 题目
颜色分类

### 题意
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:

不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]

输出: [0,0,1,1,2,2]

~~~ c
void swap(int * a, int * b){
    int temp =*a;
    *a = *b;
    *b= temp;
}
void sortColors(int* nums, int numsSize){
    if(numsSize<2) return ;
    int zero = 0;
    while(zero<numsSize&&nums[zero]==0){
            zero++;                                 //记录第一个非0位置
    }
    int one = zero;
    while(one<numsSize&&nums[one]==1){
            one++;                                  //继续记录第一个非1位置
    }
    for(int i=one;i<numsSize;i++){
        if(nums[i]==0){                             //继续遍历，元素为0就与该是0的位置交换
            swap(&nums[zero],&nums[i]);
            if(zero==one) one++;        //注意，如果被交换的位置原本也该是1的位置，更新0标的同时也要更新1标
            zero++;           
        }
        if(nums[i]==1){                     //此处不用else if的原因：进行0交换过来的元素可能是1，则需再交换一次
            swap(&nums[one],&nums[i]);
            one++;
        }
    }
}
~~~
