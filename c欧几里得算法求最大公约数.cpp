#include<stdio.h>
int main ()
{
	int a,b,t,m; 
		printf("����2������\n");
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
		printf("���Լ��Ϊ%d",b);
		return 0;
}
