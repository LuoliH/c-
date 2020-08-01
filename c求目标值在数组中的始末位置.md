### 题目
在排序数组中查找元素的第一个和最后一个位置
### 题意
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
~~~ c
#include <stdio.h>
#include <stdlib.h>
int* searchRange(int* nums, int n, int target){
    int *re=(int *)malloc(sizeof(int)*2);
    re[0]=-1;re[1]=-1;
    
    int flag=0;
    for(int i=0;i<n;i++){
        if(flag==0&&nums[i]==target){
            re[0]=i;
            re[1]=i;//为了对付只有一个target元素的情况
            flag=1;
        }
        //flag==1，则表示该元素不是第一个值为target的元素
       else if(flag==1&&nums[i]==target)
       {
       	re[1]=i;
	   }
        }
            
    return re;
}
int main(void)
{
	int n,i,nums[100],target;
	int *p;
	printf("输入n个整数\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&nums[i]);
	 printf("输入目标值\n");
	 scanf("%d",&target);
	 p=searchRange(nums,n,target);
	 printf("该目标值的起始位置是%d,末尾位置是%d",p[0],p[1]);
	 free(p);
	 return 0;
}
~~~
