#include<stdio.h>
int main(void)
{
	int b,insertpos=0,i,n;
	printf("输入n个元素的一维数组\n");
	scanf("%d",&n);
	int a[n+1];
	for(i=0;i<n;i++)	//输入的数是从小到大排序了的 如果没则代码中还需弄排序法 
	scanf("%d",&a[i]);
	printf("输入插入元素\n");
	scanf("%d",&b);
	for(i=0;i<n;i++)
	{
		if(a[i]<b)
		insertpos++;
		else 
		break;
	}
	for(i=n;i>insertpos;i--)
	a[i]=a[i-1];
	a[insertpos]=b;
	for(i=0;i<=n;i++) 
	printf("%3d",a[i]);
	return 0;
 } 
