### 题目
买股票的最佳时机

### 题意
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]

输出: 5

解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
     
示例 2:

输入: [7,6,4,3,1]

输出: 0

解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

### 解题思路
1、以当前点卖出的最大利润 = 当前点价格 - 当前点前的最小值

2、遍历一次，一方面记录当前点前的最小值，一方面记录当前点的利润，更新最大值
~~~ c
#include<stdio.h>
#include<stdlib.h>
int maxprofit(int * nums,int n)
{
	int i,min,diff;
	int max_diff=0;
	if(n==0||n==1)
	return 0;
	min=nums[0];
	for(i=0;i<n-1;i++)
	 {
		if(nums[i]<min)
		 {
			min=nums[i];
		 }
		diff=nums[i+1]-min;
		if(diff>max_diff)
		 {
			max_diff=diff;
		 }
	 }
	return max_diff;
}
int main(void)
{
	int i,n,*a,max_diff;
	printf("请输入n个整数\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	max_diff=maxprofit(a,n);
	printf("买股票的最大利润为%d",max_diff);
	free(a);
	return 0;
}
~~~
