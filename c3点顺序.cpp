#include<stdio.h>
int main()
{
	int x1,x2,x3,y1,y2,y3,a,b,c,d;
	printf("����3����ĺ�������\n");	//ABC  3�� 
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    a=x2-x1;
	b=y2-y1;	//	AB
	c=x3-x1;	
	d=y3-y1;	//	AC
	if(a*d-b*c>0)	//������ʽ���� 
		printf("0\n");	//0Ϊ��1Ϊ˳ 
	else
		printf("1\n");
		return 0;
}
