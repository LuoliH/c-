### 题目
选择排序

### 题意
利用选择排序分析

~~~ c


#include<stdio.h>
#include<stdlib.h>
int main (void)
{
    int i,k,n,temp;
    printf("enter n\n");
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    printf("enter %d integers\n",n);/*提示输入n个数*/
    for(i=0;i<n;i++)       //将输入数赋给数组
        scanf("%d",&a[i]);
    /*对n个数进行赋值*/
  for(k=0;k<n-1;k++)
    	for(i=k+1;i<n;i++)
    	 {
		
       		 if(a[i]<a[k])
        		{
    				 temp=a[i];
    				 a[i]=a[k];   //从小到大排列
    				 a[k]=temp; 
			    }
   		 }
   //最小值与下标为k的值进行交换，也就是与数组最前面一个进行交换
    printf("after sorted:\n");
    for(i=0;i<n;i++)
     { 
      printf("%d\n",a[i]);
     }
    free(a);   
    return 0;
}


~~~
