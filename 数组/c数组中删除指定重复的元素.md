### 题目
数组中删除指定重复的元素

### 分析
用循环一个个与要删除的元素判断相等则删除
用原长度减去后面长度为不为0判断删除是否成功
注意：当删除一个元素时后面的数组前移，元素的个数减一并且要重新从改位置判断所以最后n需要减一、i还需要-1

~~~ c
#include <stdio.h>
int shanchu(int a[],int n,int del)		//del为重复的元素 
{
	int i=0,j=0,tem;
	tem=n;
	for(i=0;i<n;i++)
	{
		if(a[i]==del)		//找到需要删除的元素 
		{
			for(j=i;j+1<n;j++)
			{
				a[j]=a[j+1];		//将该元素后面的所有元素前移 
			}
			n--;		//减少元素个数 
			i--;	//防止重复元素删除时位置的后移需要重新从那个位置开始判断 
		}
	}
	if(!(tem-n))
	return -1;
	else
	return n;
}
int main(void)
{
	int del,n,i;
	printf("输入n个元素的一维数组\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("请输入要删除的数据\n");
	scanf("%d",&del);
	n=shanchu(a,n,del);
	if(n==-1)
	printf("删除失败\n");
	else
	{
		for(i=0;i<n;i++)
		printf("%5d",a[i]);
	}
	return 0;
}
~~~
