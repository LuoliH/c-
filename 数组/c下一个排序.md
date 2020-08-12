### 题目
下一个排序
### 题意
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。
以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
~~~ c
#include<stdio.h>
#include<stdlib.h> 
void * swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void nextxulie(int *a,int n)
{
	if(n==0)
	return ;
	int i,j;
	for(i=n-2;i>=0&&a[i+1]<=a[i];i--);
	if(i>=0)
	{
		for(j=n-1;j>=0&&a[j]<=a[i];j--);
		swap(&a[i],&a[j]);
	}
	for(j=0;j<=(n-2-i)/2;j++)
	swap(&a[i+1+j],&a[n-1-j]);
}
int main(void)
{
	int n,i;
	int *a;
	printf("输入n个整数\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	nextxulie(a,n);
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	free(a);
	return 0;
}
~~~
