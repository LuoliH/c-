#include<stdio.h>
int main ()
{
	int a,b,t,m; 
		printf("输入2个数：\n");
		scanf("%d%d",&a,&b);
		if(a<b)
		  {
			t=a;
			a=b;
			b=t;
	   	  }
		m=a%b;
		while(m!=0)
		 {
			a=b;
			b=m;
			m=a%b;
		 }
		printf("最大公约数为%d",b);
		return 0;
}
