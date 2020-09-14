### 题目
判断点是否在线段上

### 题意
创设情境：

给定一点Q(a,b),和线段M的首尾两个端点P1(X1,Y1),P2(X2,Y2),要求判断点Q否在线段M上；

(为了方便理解,这里我们就认为X1>X2,Y1>Y2)

看到这个题，我们说先会想到的肯定是判断该点是否在线段的范围内，如果不在，肯定在线段上。

所以我们首先应该保证：X2<=a<=X1 && Y2<=b<=Y1

这样点Q就在以P1，P2为首位的矩形内，我们就排除了Q在M的延长线上的可能。


然后判断点是否在线段上了，今天我看到了两种方法，各具特色


向量法：


其实思路很简单，就是判断

Q-P1 == k * (P1-P2) ?Yes : No;

这个三目就把向量法的思想给体现出来了

剩下xy的2个关系略同理可得

~~~ c
#include<stdio.h>
int main(void)
{
	double a,b,x1,x2,y1,y2;
	scanf("%lf%lf",&a,&b);
	scanf("%lf%lf",&x1,&y1);
	scanf("%lf%lf",&x2,&y2);
	double s1,t1,s2,t2;
	s1=a-x1;
	t1=b-y1;
	s2=x1-x2;
	t2=y1-y2;
	if(x1>x2&&y1>y2)
	 {
		if(a<x2||a>x1||b<y2||b>y1)
		{
			printf("NO");
	   		return 0;
	    }
	   else
		{
			if(s1/s2==t1/t2)
			printf("YES");
			else
			printf("NO");
			return 0;
		}
	
	}
	if(x2>x1&&y2>y1)
	 {
		if(a<x1||a>x2||b<y1||b>y2)
	   	 {
			printf("NO");
			return 0;
		 }
		else
		 {
			if(s1/s2==t1/t2)
				printf("YES");
			else
				printf("NO");
				return 0;
	    }
	
   	}
   	return 0;
} 
~~~
