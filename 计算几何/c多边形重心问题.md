### 题目
多边形重心问题

### 题意
题目描述：
在某个多边形上，取n个点，这n个点顺序给出，按照给出顺序将相邻的点用直线连接， （第一个和最后一个连接），所有线段不和其他线段相交，但是可以重合，可得到一个多边形或一条线段或一个多边形和一个线段的连接后的图形；

如果是一条线段,我们定义面积为0，重心坐标为（0,0）.现在求给出的点集组成的图形的面积和重心横纵坐标的和；

输入，

第一行有一个整数0<n<11,表示有n组数据；

每组数据第一行有一个整数m<10000,表示有这个多边形有m个顶点；

输出，

输出每个多边形的面积、重心横纵坐标的和，小数点后保留三位；

思路：

求多边形面积：将n边形分割为n-2个三角形，分别求三角形面积，又因为已知顶点坐标，所以可以根据向量来求，原点到
某顶点的确定的向量就是这个顶点的坐标，设顶点为 p1, p2, …, pk, 则面积s


对于重心， 设每个三角形面积为st, 对应向量为(x1, y1), (x2, y2), 那么x方向：（x1+x2)/3, y方向： (y1+y2)/3，假设总面积为s, 那么每个三角形权重为st/s, 那么

重心坐标为各个三角形重心乘以其面积求和后除以s,

~~~ c
#include<stdio.h>
#include<math.h>
const int N = 10005;
 
typedef struct 
{
	double x;
	double y;
}POINT;
 
POINT point[N];
 
inline double CrossProduct(int i)
{
	return point[i].x * point[i + 1].y - point[i + 1].x * point[i].y;
}
 
int main()
{
	int n,t;
	int i;
	double temp;
	double area,x,y;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0; i < n; ++i)
			scanf("%lf %lf",&point[i].x, &point[i].y);
 
		point[n].x = point[0].x;//记下第一个点，形成循环
		point[n].y = point[0].y;
 
		area = 0.0;
		x = 0.0;
		y = 0.0;
 
		for(i = 0; i < n; ++i)
		{
			temp = CrossProduct(i) / 2.0;//计算各个三角形的有向面积
			area += temp;
			x += temp * (point[i].x + point[i + 1].x) / 3.0;// 计算每个三角形的重心的横纵坐标并以该三角形的有向面积(与质量等价)作为权重
			y += temp * (point[i].y + point[i + 1].y) / 3.0;
		}
 
		area = fabs(area);//我说了，叉乘有方向，最后记得取绝对值
		if(area < 0.0000001)
			printf("0.000 0.000\n");
		else
			printf("%.3lf %.3lf\n", area, fabs(x + y) / area);
	}
}
~~~

