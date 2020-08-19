### 题目
寻找重复数

### 题意
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]

输出: 2

示例 2:

输入: [3,1,3,4,2]

输出: 3

注意到1和n是边界，且1和n是在nums数组里面的。同时，我们需要的是找出这个数是多少。所以，就考虑查找的方法有哪些。然后就考虑到了二分查找。
   
 当时的犹豫：二分查找适用于有序的数组，但是nums不有序，为什么要用勒？
 
   思考：我们用二分查找并不是在nums数组上查找，而是在连续区间[1,n]中进行应用

   方法：在区间【1， n】上，取mid = (1 + n) / 2，这一区间就分为了[1，mid]和[mid + 1, n]
   
         以[1,mid]区间为例子，如果题目所给数组nums中，属于这个区间中的数的个数为a。
         
         当a > mid, 那么重复的数一定在这个区间中；
         
         当a == mid,假设重复的数在[1,mid]中，那么数组nums在[mid + 1, n]区间的数最多为n -mid个，所以nums数组中的元素个数 = mid  + n - mid = n < n + 1, 假设不成立。所以 当a== mid时，重复个数不在[1,mid]中；
         
         当a < mid 时，显而易见，也不在[1,mid]中
         
    
 最后我们只需要不断的收缩，最后当左右边界相等的时候，就可以得到了那个数了。

~~~ c
int findDuplicate(int* nums, int numsSize){
     int i, mid, left = 1, right = numsSize -1;
     int count = 0; //计数器；
     mid = numsSize / 2;
     while(left != right){
         count = 0;
         for(i = 0; i < numsSize; i++){
             if(nums[i] <= mid) count++;
         }
         if(count > mid){
              right = mid;
        } //说明重复的数字，就是在[left, mid]之间
         else{
             left = mid + 1;
         }
         mid = (left + right) / 2;
     }
     return left;
}
~~~
