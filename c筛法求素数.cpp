#include<stdio.h>
int main()
 {
	int i,n,j;
	printf("输入一个数\n");
	scanf("%d",&n); 			//求2到n之间的素数
	int a[n+1]; 
	for(i=2;i<=n;i++)
		a[i]=0;               //先将全部数赋值为0用来筛选
	for(i=2;i<=n;i++)
		{
			if(a[i]==0)
				for(j=i*2;j<=n;j=j+i)		//从2倍开始舍去（为1就是舍） 
					a[j]=1;
		}
	for(i=2;i<=n;i++)
		if(a[i]==0)
			printf("%4d",i); 
	
	
 }
