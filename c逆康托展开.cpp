#include<stdio.h>
#define Max 5	//�������ĸ��� ����107����52413 
const int fact[10] = { 1,1,2,6,24,120,720,5040,40320,362880 };		//����10���ڵĽ׳� 

void revContor(int a[] , int rank)
 {
	int value, i,flag = 0;
	int b[Max+1];		//�����������λ�� 
	rank -= 1;		//˳����Ӧ�ã�1��Ϊ��0��ʼ 
	for (i = 1; i<=Max; i++)
	 {
		value = rank / fact[Max - i];
		rank = rank % fact[Max - i];
		flag = value + 1;		//�����м���������С����������Ҫ+1 
		for (value = 1; value <= Max; value++)
		 {
			if (a[value] != 0)		//�����Ѿ����ֵ���ֱ��+1 
				flag--;
			if (flag == 0)
				break;
		 }
		b[i] = a[value] ;
		a[value] = 0;	//���Ѿ����˵�����ֵΪ0�ų����� 
	 }
	for (i = 1; i <= Max; i++)
		 {
			printf("%d", b[i]);
		 }
}
int main(void) {
	int i;
	int  arrange[Max + 1]; //�ȶ���һ������������,���Һ���0λ 
	int  rank ;  //���е���ţ�
	for (i = 0; i <= Max; i++) {
		arrange[i] = i;
	}
	scanf("%d", &rank);
	revContor(arrange, rank);
	return 0;
}
