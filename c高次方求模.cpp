#include<stdio.h>
int PowerMod(int a,int b,int c)	//高次方求模==a的b次方对c取余数 
{
	int ans=1;
	a=a%c;		//a的b次方对c取余等于  a对c取余 的b次方对c取余 （简化计算量） 
	while(b>0)
	{
		if(b%2==1)	// 如果为奇数先保留 
		ans=(ans*a)%c;	// 第2个ans指后面舍去的一些次方 当它×a时变为原来的次方 
		b=b/2; 	//舍去2除不尽的 次方 
		a=(a*a)%c;	//将次方次方减少计算量 
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
