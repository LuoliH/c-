### 题目
接雨水
### 题意
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
找山峰，边上山边统计。当前最大水位就是当前最大高度，当前雨水量为水位-当前高度
~~~ c
#include<stdio.h>
#include<stdlib.h>
int trap(int *height ,int heightsize)
{
    int i ;
    int max_index = 0, max = 0;
    int water_lvl = 0;
    int water = 0;
    // 找最高峰
	for(i=0;i<heightsize;i++)
   	 {
		 if(height[i] > max)
          {
            max_index = i;
            max = height[i];
          }
	 }
	 // 水位是递增的，当前水位即为当前最大高度
    // 雨水量=当前最大水位-当前高度
	for(i=0;i<max_index;i++)
	 {
		if(height[i]>water_lvl)
	     {
			water_lvl=height[i];
	    }
		water+=water_lvl-height[i];
	 }
	  // 右坡同样过程
	water_lvl=0;
	for(i=heightsize-1;i>max_index;i--)
	 {
		if(height[i]>water_lvl)
		 {
			water_lvl=height[i];
	     }
	water+=water_lvl-height[i];
     }
    return water;
}
int main(void)
{
	int i,*a,n,water;
	printf("输入n个整数\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	water=trap(a,n);
	printf("接的雨水为%d",water);
	free(a);
	return 0;
}
~~~



















