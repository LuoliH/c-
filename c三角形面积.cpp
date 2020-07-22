#include<stdio.h>
#include<math.h>
int main()		//先要判断三角形存不存在 
{
	float a,b,c,q,size,d1,d2,d3;
	printf("请输入三角行的三条边\n");
	d1=fabs(a-b);
	d2=fabs(a-c);
	d3=fabs(b-c);
	scanf("%f%f%f",&a,&b,&c);
	if((a+b<=c)||(a+c<=b)||(b+c<=a)||(d1>=c)||(d2>=b)||(d3>=a))
	 {
		printf("不存在此三角形\n");
	 }
	else
	 {
		q=(a+b+c)/2;
		size=sqrt(q*(q-a)*(q-b)*(q-c));
		printf("此三角形的面积为%.2f\n",size); //这个三角形面积公式最简单明白 
	 }
	 return 0;
 } 
