#include<stdio.h>
int main()
 {
	int i,n,j;
	printf("����һ����\n");
	scanf("%d",&n); 			//��2��n֮�������
	int a[n+1]; 
	for(i=2;i<=n;i++)
		a[i]=0;               //�Ƚ�ȫ������ֵΪ0����ɸѡ
	for(i=2;i<=n;i++)
		{
			if(a[i]==0)
				for(j=i*2;j<=n;j=j+i)		//��2����ʼ��ȥ��Ϊ1�����ᣩ 
					a[j]=1;
		}
	for(i=2;i<=n;i++)
		if(a[i]==0)
			printf("%4d",i); 
	
	
 }
