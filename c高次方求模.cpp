#include<stdio.h>
int PowerMod(int a,int b,int c)	//�ߴη���ģ==a��b�η���cȡ���� 
{
	int ans=1;
	a=a%c;		//a��b�η���cȡ�����  a��cȡ�� ��b�η���cȡ�� ���򻯼������� 
	while(b>0)
	{
		if(b%2==1)	// ���Ϊ�����ȱ��� 
		ans=(ans*a)%c;	// ��2��ansָ������ȥ��һЩ�η� ������aʱ��Ϊԭ���Ĵη� 
		b=b/2; 	//��ȥ2�������� �η� 
		a=(a*a)%c;	//���η��η����ټ����� 
	}
	return ans;
}
int main()
{
	int a,b,c,sum;
	printf("please enter the a,b,c:\n");
	scanf("%d%d%d",&a,&b,&c);
	sum=PowerMod(a,b,c);
	printf("The result is %d\n",sum);
	return 0;
}
