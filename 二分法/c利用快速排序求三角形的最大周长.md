### 题目
利用快速排序求三角形的最大周长

### 题意
给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。

如果不能形成任何面积不为零的三角形，返回 0。

 

示例 1：

输入：[2,1,2]

输出：5

示例 2：

输入：[1,2,1]

输出：0

示例 3：

输入：[3,2,3,4]

输出：10

示例 4：

输入：[3,6,2,3]

输出：8

先对A数组进行升序快排（其他排序会导致超时），然后从后往前对A里面的三个数进行遍历查找是否有满足条件的3个数

~~~ c
void quicksort(int* A,int left,int right){
    int i,j,t,tmp;
    if(left>right)
    return;
    tmp=A[left];
    i=left;
    j=right;
    while(i!=j){
        while(A[j]>=tmp&&i<j){
            j--;
        }
        while(A[i]<=tmp&&i<j){
            i++;
        }
        if(i<j){
            t=A[i];
            A[i]=A[j];
            A[j]=t;
        }
    }
    A[left]=A[i];
    A[i]=tmp;
    quicksort(A,left,i-1);
    quicksort(A,i+1,right);
}
int largestPerimeter(int* A, int ASize){
  quicksort(A,0,ASize-1);
  int sum=0;
  for(int i=ASize-1;i>=2;i--){
      if(A[i-1]+A[i-2]>A[i]){
          sum=A[i]+A[i-1]+A[i-2];
          break;
      }
  }
  return sum;
}
~~~
