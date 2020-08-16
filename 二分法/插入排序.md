### 题目
插入排序

### 题意
插入排序的基本思想是：每步将一个待排序的纪录，按其关键码值的大小插入前面已经排序的文件中适当位置上，直到全部插入完为止。

插入排序实例：

待排元素序列： 53 27 36 15 69 42

第一次排序： 27 53 36 15 69 42

第二次排序： 27 36 53 15 69 42

第三次排序： 15 27 36 53 69 42

第四次排序： 15 27 36 53 69 42

第五次排序： 15 27 36 42 53 69

插入次数为n-1次

~~~ c
#include<stdio.h>
#include<stdlib.h>
void insertsort(int *k,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
		{
			temp=k[i];		//将要保存的值先缓存起来留一个空位，方便移动 
			j=i-1;
			while(j>=0&&k[j]>temp)		//比较直到出现小于等于temp的值或者向前找到头 
				{
					k[j+1]=k[j];		//将前面的值往前移 
					j--;
				}
			k[j+1]=temp;		//插在k[j]的后面 
		}
}
int main()
{
	int i,n;
	printf("输入正整数n\n");
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	printf("输入n个正整数\n");
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		insertsort(a,n);
		printf("输出排序后的数组\n");
		for(i=0;i<n;i++)
			{
				printf("%d\n",a[i]);
			}
			free(a);
			return 0;
 } 
 ~~~
