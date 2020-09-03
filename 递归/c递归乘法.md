### 题目
递归乘法

### 题意
递归乘法。 写一个递归函数，不使用 * 运算符， 实现两个正整数的相乘。可以使用加号、减号、位移，但要吝啬一些。

示例1:

 输入：A = 1, B = 10
 
 输出：10
 
示例2:

 输入：A = 3, B = 4
 
 输出：12

~~~ c
#include<stdio.h>
int multiply(int A,int B)
{
	int result;
	 if(B>1)
	  {
		result=multiply(A,B-1)+A;
	  }
     else
      {
      	return A;
	  }
	  return result;
}
int main(void)
{
	int A,B,m;
	printf("输入A,B\n");
	scanf("%d%d",&A,&B);
	m=multiply(A,B);
	printf("%d",m);
	return 0;
}
~~~
