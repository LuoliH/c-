### 题目
青蛙跳台阶问题

### 题意
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2

输出：2

示例 2：

输入：n = 7

输出：21

示例 3：

输入：n = 0

输出：1

解题思路

1.n==0时，返回的步数时1？（因为题目就是这么规定的，如果要理解： 0 层台阶也有一种跳法（即不跳））

2.递归三步走：

a.定义函数。

b.找到出口，n==0时，返回的步数时1；n==1时，返回1；

c.找到等价交换式。f(n)=f(n-1)+f(n-2);

3.使用递归函数，等台阶到43时，就会报出时间超时。

4.进行优化，因为递归时会存在重复计算的场景，申请一个固定长度的数组，用于保存过程数据。

5.执行结果：

~~~ c
#include<stdio.h>
#define MAX_VALUE  1010
int arr[1010]={-1};
int func(int n)
{
	if(n==0)
	return 1;
	if(n==1)
	return 1;
	if(n==2)
	return 2;
	if(arr[n]!=-1)
	return arr[n];
	arr[n]=(func(n-1)+func(n-2))%1000000007; 
	return arr[n];	
}
int numWays(int n)
 {
	int value;
	int i;
	for(i=0;i<MAX_VALUE;i++)
	 {
	  arr[i]=-1;
      }
     value=func(n);
     return value;
	
 }
 int main(void)
 {
 	int n;
 	printf("请输入n\n");
 	scanf("%d",&n);
 	n=numWays(n);
 	printf("%d",n);
 	return 0;
 }
 ~~~
