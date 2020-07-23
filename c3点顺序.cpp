#include<stdio.h>
int main()
{
	int x1,x2,x3,y1,y2,y3,a,b,c,d;
	printf("输入3个点的横纵坐标\n");	//ABC  3点 
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    a=x2-x1;
	b=y2-y1;	//	AB
	c=x3-x1;	
	d=y3-y1;	//	AC
	if(a*d-b*c>0)	//用行列式计算 
		printf("0\n");	//0为逆1为顺 
	else
		printf("1\n");
		return 0;
}
