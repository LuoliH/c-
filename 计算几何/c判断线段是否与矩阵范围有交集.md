### 题目
判断线段是否与矩阵范围有交集

### 题意
这里的矩形指的是边与坐标轴平行的矩形，可用x和y上最大最小值表示。

判断是否相交，先快速排斥，再做跨立，通过向量的叉积判断矩形的四个顶点是否在线段的两侧，是说明有交集。

（如果判断与矩形的边是否有交集的话，可判断线段是否与矩形的每条边是否有交集，线段与线段的交集判断。）

 

这里在介绍另外一种方法，降维的方法：

例如，有线段AB和矩形MN，如图所示：



通过M和N点的y坐标计算直线AB上的D和C点，B和C点中取y值小的点B，A和D点中取y值大的点D，

最后确定了线段BD在x轴上的投影GH，矩形在x轴上的投影EF，判断EF和GH是否有交集。

 

C语言代码如下：

/*
 * 判断区间[x1, x2]和区间[x3, x4](x4可能小于x3)是否有交集，有返回1，无0
 */

~~~ c
int IntervalOverlap(double x1, double x2, double x3, double x4)
{
	double t;
	if (x3 > x4)
	{
		t = x3;
		x3 = x4;
		x4 = t;
	}
	
	if (x3 > x2 || x4 < x1)
		return 0;
	else
		return 1;
}

/*
 * 判断矩形r和线段AB是否有交集，有返回1，无0
 */
int RSIntersection(Rectangle r, Point A, Point B)
{
	if (A.y == B.y)	// 线段平行于x轴
	{
		if (A.y <= r.ymax && A.y >= r.ymin)
		{
			return IntervalOverlap(r.xmin, r.xmax, A.x, B.x);
		}
		else
		{
			return 0;
		}
	}
	// AB两点交换，让B点的y坐标最大
	Point t;
	if (A.y > B.y)
	{
		t = A;
		A = B;
		B = t;
	}
	
	// 在线段AB上确定点C和D
	// 两点确定一条直线: (x-x1)/(x2-x1)=(y-y1)/(y2-y1)
	double k = (B.x - A.x)/(B.y - A.y);
	Point C, D;
	if (A.y < r.ymin)
	{
		C.y = r.ymin;
		C.x = k * (C.y - A.y) + A.x;
	}
	else
		C = A;
		
	if (B.y > r.ymax)
	{
		D.y = r.ymax;
		D.x = k * (D.y - A.y) + A.x;
	}
	else
		D = B;
		
	if (D.y >= C.y)	// y维上有交集
	{
		return IntervalOverlap(r.xmin, r.xmax, D.x, C.x);
	}
	else
	{
		return 0;
	}
}
~~~
