#include<stdio.h>
int main(void)
{
	int b,insertpos=0,i,n;
	printf("����n��Ԫ�ص�һά����\n");
	scanf("%d",&n);
	int a[n+1];
	for(i=0;i<n;i++)	//��������Ǵ�С���������˵� ���û������л���Ū���� 
	scanf("%d",&a[i]);
	printf("�������Ԫ��\n");
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
