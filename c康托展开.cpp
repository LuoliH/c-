#include<stdio.h>
int jiecheng(int n)	//求阶乘 
 {
	int i,c=1;
	for(i=n;i>=1;i--)
	 {
		c=c*i;
	 }
	return c;
 }
int main()
 {
	int a[100];		//存放比原数小的数
	char b[100],zifu;	//存放输入的数 
	int i,j,count=0,k=0,num=0;	//count为总数个数 
	while(scanf("%c",&zifu))
	 {
		if(zifu=='\n')
			break;
		else
		 {
			b[count]=zifu;
			count++;
		 }
	 }
	for(i=0;i<count;i++)	//求每个数后面比它小的数的个数 
	 {
		for(j=i+1;j<count;j++)
		 {
			if(b[i]>b[j])
			k++;
		 }
		a[i]=k;
		k=0;
	 }
	for(j=count-1;j>=0;j--)
     {
		num=num+a[k]*jiecheng(j);		//康托展开  为当前数后面比它小的数的个数×剩下数个数的阶乘的累加和 
		k++;
	 }
	printf("该数从小到大排序的位置为%d",num+1);		//计算为比它小的数的个数，它本身的顺序还要加1 
	return 0;
 }
