### 题目
排列硬币

### 题意
你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。

给定一个数字 n，找出可形成完整阶梯行的总行数。

n 是一个非负整数，并且在32位有符号整型的范围内。

示例 1:

n = 5

硬币可排列成以下几行:

¤

¤ ¤

¤ ¤

因为第三行不完整，所以返回2.

示例 2:

n = 8

硬币可排列成以下几行:

¤

¤ ¤

¤ ¤ ¤

¤ ¤

因为第四行不完整，所以返回3.

~~~ c
#include<stdio.h>
int sum_n(int n)
{
	int les;
	les=(n+1)*n/2;
	return les;
}
int arrangeCoins(int n)
{
	int low=0,high=n;
	int mid;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(sum_n(mid)==n)
		{
			return mid;
		}
		else if(sum_n(mid)<n)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return low-1;
}
int main(void)
{
	int n;
	printf("输入n\n");
	scanf("%d",&n);
	n=arrangeCoins(n);
	printf("%d",n);
	return 0;
}
~~~
