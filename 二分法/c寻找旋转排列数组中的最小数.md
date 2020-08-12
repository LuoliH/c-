### 题目
寻找旋转排列数组中的最小数

### 题意
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]

输出: 1

示例 2:

输入: [4,5,6,7,0,1,2]

输出: 0

### 分析
方法：二分法
2，此题寻找最小值，由于是升序排序的数组，所以最小值出现在nums[0]的位置
3，由于是旋转排序数组，找到拐点 nums[i] 则最小值为 MIN(nums[0], nums[i])
4，使用二分法快速找到拐点

~~~ c

//方法一：二分法
//1，和 33题、 81 题、 154题 类似
//2，此题寻找最小值，由于是升序排序的数组，所以最小值出现在nums[0]的位置
//3，由于是旋转排序数组，找到拐点 nums[i] 则最小值为 MIN(nums[0], nums[i])
//4，使用二分法快速找到拐点


#define     MIN(a, b)       ((a) < (b) ? (a) : (b))

int findMin(int* nums, int numsSize){
    int     iLeft   = 0;
    int     iMid    = 0;
    int     iRight  = 0;
    int     iMin    = 0;

    if(NULL == nums) return -1;
    if(1 == numsSize) return nums[0];
    if(2 == numsSize) return MIN(nums[0], nums[1]);

    iMin = nums[0];
    iLeft = 1;
    iRight = numsSize - 1;
    iMid = (iLeft + iRight) / 2;
    
    while(iLeft < iRight){
        if(nums[iMid] < iMin)
        {
            iRight = iMid;
            iMid = (iLeft + iRight) / 2;
        }
        else
        {
            iLeft = iMid + 1;
            iMid = (iLeft + iRight) / 2;
        }
    }

    return MIN(iMin, nums[iMid]);
}
~~~
