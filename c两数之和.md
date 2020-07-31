### 题目
给定一个已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数。函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2
### 举例子
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
当时脑海中首先想到的解决方案是通过两次循环，每次循环遍历列表。
~~~ c
#include<stdio.h>
#include<stdlib.h>
int* twosum(int* nums, int numssize, int target, int* returnsize){
    int *ret = (int *)malloc(2*sizeof(int));
    int temp;
    for(int i = 0; i < numssize - 1; i++)
    {
        temp = target - nums[i];
        for(int j = i + 1; j < numssize; j++)
        {
            if(nums[j] == temp)
            {
                *ret = i;
                *(ret + 1) = j;
                *returnsize = 2;
                return ret;
            }
        }
    }
    return 0;
}

int main(void)
{
	int *p;
	int a[100],i,n,target,returnsize;
	printf("输入n个数\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("输入目标值\n");
	scanf("%d",&target);
	p=twosum(a,n,target,&returnsize);
	printf("%d\n%d\n",p[0],p[1]);
	free(p);
	return 0;
}
~~~


