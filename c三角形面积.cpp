#include<stdio.h>
#include<math.h>
int main()		//��Ҫ�ж������δ治���� 
{
	float a,b,c,q,size,d1,d2,d3;
	printf("�����������е�������\n");
	d1=fabs(a-b);
	d2=fabs(a-c);
	d3=fabs(b-c);
	scanf("%f%f%f",&a,&b,&c);
	if((a+b<=c)||(a+c<=b)||(b+c<=a)||(d1>=c)||(d2>=b)||(d3>=a))
	 {
		printf("�����ڴ�������\n");
	 }
	else
	 {
		q=(a+b+c)/2;
		size=sqrt(q*(q-a)*(q-b)*(q-c));
		printf("�������ε����Ϊ%.2f\n",size); //��������������ʽ������� 
	 }
	 return 0;
 } 
