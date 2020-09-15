### 题目
判断点是否在多边形内

~~~ c
typedef struct tagST_POINT {

int x;

int y;

} ST_POINT;

/**

* 功能：判断点是否在多边形内

* 方法：求解通过该点的水平线（射线）与多边形各边的交点

* 结论：单边交点为奇数，成立!

* 参数：p 指定的某个点

ptPolygon 多边形的各个顶点坐标（首末点可以不一致） 

nCount 多边形定点的个数

* 说明：

*/

BOOL PtInPolygon(ST_POINT p, ST_POINT* ptPolygon, int nCount) 

{ 

int nCross = 0, i;

double x;

ST_POINT p1, p2;

for (i = 0; i < nCount; i++) 

{ 

p1 = ptPolygon[i]; 

p2 = ptPolygon[(i + 1) % nCount];

// 求解 y=p.y 与 p1p2 的交点

if ( p1.y == p2.y ) // p1p2 与 y=p.y平行 

continue;

if ( p.y < min(p1.y, p2.y) ) // 交点在p1p2延长线上 

continue; 

if ( p.y >= max(p1.y, p2.y) ) // 交点在p1p2延长线上 

continue;

// 求交点的 X 坐标 -------------------------------------------------------------- 

x = (double)(p.y - p1.y) * (double)(p2.x - p1.x) / (double)(p2.y - p1.y) + p1.x;

if ( x > p.x ) 

{

nCross++; // 只统计单边交点 

}

}

// 单边交点为偶数，点在多边形之外 --- 

return (nCross % 2 == 1); 

}

// 注意：在有些情况下x值会计算错误，可把double类型改为long类型即可解决

~~~
