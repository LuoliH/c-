### 题目
判断点到线段的最小距离

~~~ c
/*************************************************
Description:    // 判断目标点pt到线段（PT1,PT2）最小距离是否小于distance
Input:          // distance:目标距离,pt：目标点；pt1,pt2线段的端点
Return:         // 如目标点到线段最小距离小于目标距离则返回TRUE,反之返回 FALSE
*************************************************/
BOOL IsPointToLine(const double distance,POINT pt, const POINT pt1, const POINT pt2)
{
	POINT p1 = { pt.x - pt1.x,pt.y - pt1.y }, p2 = { pt2.x - pt1.x,pt2.y - pt1.y };
	POINT p3 = { pt1.x - pt2.x,pt1.y - pt2.y }, p4 = { pt.x - pt2.x,pt.y - pt2.y };
	double nLen1 =fabs(sqrt(p1.x *p1.x + p1.y*p1.y));
	double nLen2 =fabs(sqrt(p2.x *p2.x + p2.y*p2.y));
	double nLen3 = fabs(sqrt(p4.x *p4.x + p4.y*p4.y));
	double nNum = p1.x*p2.x + p1.y*p2.y;
	if (nNum <= 0)
		return min(nLen1,nLen2) <distance ? TRUE : FALSE;
	if (p3.x*p4.x + p3.y*p4.y <= 0)
		return min(nLen2, nLen3) <distance ? TRUE : FALSE;
	nNum = nNum / (nLen1*nLen2);
	nNum = nLen1*fabs(pow(1 - pow(nNum, 2), 0.5));
	return nNum < distance ? TRUE : FALSE;
}
~~~
