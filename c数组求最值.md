### 题目
利用数值求最大最小值

### 分析
因为求2值所以每次数组加2比较这2数大小在分别与最值比较减少计算量
注意当为奇数时会多出来一个数应该用if分别求其单出来的数将与最值分别比较
~~~ c
#include<stdio.h>
int main(void)
{
	int i,n,min,max;
	printf("请输入n元素的一维数组\n");
	scanf("%d",&n);
	int a[n]; 
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=min=a[0];
	for(i=0;i<n;i=i+2)
	 {
		if(i<=n-2)
		 {
			if(a[i]<a[i+1])
			 {
			    if(a[i]<min)
			    min=a[i];
			  	if(a[i+1]>max)
				max=a[i+1];
			 }
			else
			 {
				if(a[i+1]<min)
				min=a[i+1];
				if(a[i]>max)
				max=a[i];
		     }
	    }
		else
		{
			if(a[n-1]<min)
			min=a[n-1];
			if(a[n-1]>max)
			max=a[n-1];
		}
     } 
	printf("最大值是%d最小值是%d",max,min);
}
~~~
