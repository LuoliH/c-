### 题目
最长连续递增序列数

### 题意
给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。

示例 1:

输入: [1,3,5,4,7]

输出: 3

解释: 最长连续递增序列是 [1,3,5], 长度为3。

尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 

示例 2:

输入: [2,2,2,2,2]

输出: 1

解释: 最长连续递增序列是 [2], 长度为1。

~~~ c
#include<stdio.h>
#include<stdlib.h>
int find(int *nums,int n)
{
	if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    int i;
    int length = 1;
    int ans = 1;
    for(i=0;i<n;i++)
    	{
    		if(nums[i]<nums[i+1])
    			length++;
    		else
    			length=1;
    		if(length>ans)
    		 {
    			ans=length;
    	     }
		}
	return ans;
}
int main(void)
{
	int i,*a,n,p;
	printf("输入n个整数\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	p=find(a,n);
	printf("最长连续递增序列数为%d",p);
	free(a);
	return 0;
}
~~~
