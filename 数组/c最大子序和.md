### 题目
最大子序和
### 题意
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
~~~ c
#include<stdio.h>
#include<stdlib.h>
int maxsubarray(int *nums, int n)
{
	int i,j;
	int max,t;
	max=nums[0];
	for(i=0;i<n;i++)
	{
		t=0;
		for(j=i;j<n;j++)
		{
			t=t+nums[j];
			if(t>max)
			max=t;
		}
	}
	return max;
}
int main(void)
{
	int i,*a,max,n;
	printf("输入n个整数\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	max=maxsubarray(a,n);
	printf("连续数组的最大值为%d",max);
	free(a);
	return 0;
}
~~~
