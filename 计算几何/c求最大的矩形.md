### 题目
最大的矩形

### 题意
问题描述
　　在横轴上放了n个相邻的矩形，每个矩形的宽度是1，而第i（1 ≤ i ≤ n）个矩形的高度是hi。这n个矩形构成了一个直方图。例如，下图中六个矩形的高度就分别是3, 1, 6, 5, 2, 3。



　　请找出能放在给定直方图里面积最大的矩形，它的边要与坐标轴平行。对于上面给出的例子，最大矩形如下图所示的阴影部分，面积是10。

输入格式

　　第一行包含一个整数n，即矩形的数量(1 ≤ n ≤ 1000)。
  
　　第二行包含n 个整数h1, h2, … , hn，相邻的数之间由空格分隔。(1 ≤ hi ≤ 10000)。hi是第i个矩形的高度。
  
输出格式

　　输出一行，包含一个整数，即给定直方图内的最大矩形的面积。
  
样例输入

6

3 1 6 5 2 3

样例输出

10

解题思路：

枚举所有能形成符合要求的矩形，选择最大的输出即可。

需要注意的是矩形的高度由最小整数hi决定，因此需要找出最小hi 。代码见下：

~~~ c
#include<stdio.h>
 #define nmax 1010
 int aera(int a[], int n );
 int main(void)
 {
   int i , n;
    int a[nmax];
     scanf("%d",&n);
    for(i=0 ; i < n ; i ++) 
    {
        scanf("%d",&a[i]);
    }
   printf("%d", aera(a,n ));
    return 0;
  } 
int aera(int a[], int len )
  {
     int i ,low,temp, max_aera = -1;
      for(i = 0 ; i <len ; i++)
      {
          low = a[i];//设最小整数为 low 
          for(int j = i ; j <len ;j++)
          {//以位置 i 为起点，位置 j 为终点，寻找符合要求的矩形 。每一轮起点不变，终点依次+1 
              if(a[j] < low)
                 low = a[j];
              temp = (j - i +1) * low;//矩形面积计算公式 
              if(temp > max_aera)
                  max_aera = temp;
         }
    }
~~~
