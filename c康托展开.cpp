#include<stdio.h>
int jiecheng(int n)	//��׳� 
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
	int a[100];		//��ű�ԭ��С����
	char b[100],zifu;	//���������� 
	int i,j,count=0,k=0,num=0;	//countΪ�������� 
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
	for(i=0;i<count;i++)	//��ÿ�����������С�����ĸ��� 
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
		num=num+a[k]*jiecheng(j);		//����չ��  Ϊ��ǰ���������С�����ĸ�����ʣ���������Ľ׳˵��ۼӺ� 
		k++;
	 }
	printf("������С���������λ��Ϊ%d",num+1);		//����Ϊ����С�����ĸ������������˳��Ҫ��1 
	return 0;
 }
