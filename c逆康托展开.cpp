#include<stdio.h>
#define Max 5	//排列数的个数 比如107就是52413 
const int fact[10] = { 1,1,2,6,24,120,720,5040,40320,362880 };		//给出10以内的阶乘 

void revContor(int a[] , int rank)
 {
	int value, i,flag = 0;
	int b[Max+1];		//存放排列数的位置 
	rank -= 1;		//顺序数应该－1因为从0开始 
	for (i = 1; i<=Max; i++)
	 {
		value = rank / fact[Max - i];
		rank = rank % fact[Max - i];
		flag = value + 1;		//这是有几个数比它小真正的数还要+1 
		for (value = 1; value <= Max; value++)
		 {
			if (a[value] != 0)		//碰到已经出现的数直接+1 
				flag--;
			if (flag == 0)
				break;
		 }
		b[i] = a[value] ;
		a[value] = 0;	//将已经用了的数赋值为0排除干扰 
	 }
	for (i = 1; i <= Max; i++)
		 {
			printf("%d", b[i]);
		 }
}
int main(void) {
	int i;
	int  arrange[Max + 1]; //先定义一个五以内排列,并且忽略0位 
	int  rank ;  //排列的序号；
	for (i = 0; i <= Max; i++) {
		arrange[i] = i;
	}
	scanf("%d", &rank);
	revContor(arrange, rank);
	return 0;
}
