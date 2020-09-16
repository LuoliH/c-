### 题目
求凸包

### 题意
思路：应用分治法思想，把一个大问题分成几个结构相同的子问题，把子问题再分成几个更小的子问题……。然后我们就能用递归的方法，分别求这些子问题的解。最后把每个子问题的解“组装”成原来大问题的解。

步骤：

把所有的点都放在二维坐标系里面。那么横坐标最小和最大的两个点 P1 和 Pn 一定是凸包上的点（为什么呢？用反证法很容易证明，这里不详讲）。直线 P1Pn 把点集分成了两部分，即 X 轴上面和下面两部分，分别叫做上包和下包。

对上包：求距离直线 P1Pn 最远的点，即下图中的点 Pmax 。

作直线 P1Pmax 、PnPmax，把直线 P1Pmax 左侧的点当成是上包，把直线 PnPmax 右侧的点也当成是上包。

重复步骤 2、3。

对下包也作类似操作。

这里写图片描述

 


然而怎么求距离某直线最远的点呢？我们用到公式：

这里写图片描述

设有一个点 P3 和直线 P1P2 。（坐标：p1(x1,y1)，p2(x2,y2)，p3(x3,y3)）

当上式结果为正时，p3在直线 p1p2 的左侧；当结果为负时，p3在直线 p1p2 的右边

对上式的结果取绝对值，绝对值越大，则距离直线越远。

注意：在步骤一，如果横坐标最小的点不止一个，那么这几个点都是凸包上的点，此时上包和下包的划分就有点不同了，需要注意。（但在代码中无需特殊处理，详见代码注释）

 ~~~ c
 #include<stdio.h>
#include<stdlib.h>
 
int g_result[240][2];
 
/*getResult()实现功能：以坐标P0(x1,y1)和Pn(x2,y2)为直线，找出pack里面离这条直线最远的点Pmax
*并找出直线P0Pmax和PmaxPn的上包，进行递归。
*注：Pack[0][0]存放点的个数，pack[1]开始存放点的坐标。
*全局变量g_result[][]用来存放凸包上的点，即最终所要的答案。同样g_result[0][0]存放的是已找到的点的个数。
**/
void getResult(int Pack[240][2], int x1, int y1, int x2, int y2)
{
    int i,t,x3,y3,R,Rmax,tmax;
    int ResultPack[240][2];
    ResultPack[0][0] = 0;
    if(Pack[0][0] <= 2)
    //if(Pack[0][0] <= 1)//从主函数递归调用来看，Pack用的是含有线上两点的上包总点数，所以如果是0或1或2，就可以直接返回
    //这里没用<=2是因为后面的递归算法中的ResultPack没有记录Pack[1][0](这好像产生一个大问题)，所以为了解决这里，下面的for仍应该从1开始吧？
    //就算x3暂时不是凸包点，但如果计算所得的R大于0就很可能成为凸包点，所以我确切认为是从1开始,然后这里也应该相应改成<=2,不然多跑了一趟浪费时间
        return; 
    x3 = Pack[1][0];//这里的Pack[1][0]不一定是x1的
    y3 = Pack[1][1];
    R = x1*y2 + x3*y1 + x2*y3 - x3*y2 - x2*y1 - x1*y3;
    Rmax = R;
    tmax = 1;
    //for(i=2;i<=Pack[0][0];i++)//我把CSDN搞下来上的代码改了
    for(i=1;i<=Pack[0][0];i++)
    {
        x3 = Pack[i][0];
        y3 = Pack[i][1];
        R = x1*y2 + x3*y1 + x2*y3 - x3*y2 - x2*y1 - x1*y3;//R的绝对值越大，那么x3这个点距离x1，x2所连成的线越远(其实不知道公式哪来的，但目前暂时不重要，就是矩阵如下)
        /*
        |x1 y1 1|
        |x2 y2 1|
        |x3 y3 1|
        */
        if(R >= 0)//R>=0在左边，也就是只处理上包
        {
            t = ++ResultPack[0][0];
            ResultPack[t][0] = x3;
            ResultPack[t][1] = y3;
        }
        if(R > Rmax)
        {
            Rmax = R;
            tmax = i;
        }
    }
    if(Rmax <= 0)//这里就是处理凸包一边上有三点的情况
    {
        //for(i=1;i<ResultPack[0][0];i++)//这里少扫到一个点，万一少的那点正好是第三点，那就有bug了，所以我又改了他的代码
        for(i=1;i<=ResultPack[0][0];i++)
        {
            x3 = ResultPack[i][0];
            y3 = ResultPack[i][1];
            R = x1*y2 + x3*y1 + x2*y3 - x3*y2 - x2*y1 - x1*y3;
            if(R == 0 && !((x3==x2&&y3==y2)||(x3==x1&&y3==y1)))
            {
                t = ++g_result[0][0];
                g_result[t][0] = ResultPack[i][0];
                g_result[t][1] = ResultPack[i][1];
            }
        }
        return;
    }
    else
    {
        t = ++g_result[0][0];
        g_result[t][0] = Pack[tmax][0];
        g_result[t][1] = Pack[tmax][1];
        if(ResultPack[0][0] == 0)
            return;
    }
    getResult(ResultPack,x1,y1,Pack[tmax][0],Pack[tmax][1]);//新的上包递归
    getResult(ResultPack,Pack[tmax][0],Pack[tmax][1],x2,y2);//新的下包递归
}
 
int main()
{
    int Point[240][2];//Point存所有点。
    int i=1;
    int x1,y1,x2,y2,x3,y3;
    g_result[0][0]=0;Point[0][0]=0;//Point的第一行第一列元素存放包里面有几个点。初始化为0。
    printf("请输入所有点的坐标：\n");
    while(scanf("%d,%d",&Point[i][0],&Point[i][1]) != EOF)
        i++;
    Point[0][0] = i-1;//前面i=1开始加的
    x1 = Point[1][0];
    y1 = Point[1][1];
    x2 = x1;
    y2 = y1;
    for(i=2;i<=Point[0][0];i++)
    {
        x3 = Point[i][0];
        y3 = Point[i][1];
        if(x3 < x1)//用枚举找最左边的点，用x1保存，最右边用x2保存
 
        //其实这里没有考虑多个最左边点和最右边点的情况
        //不不不，其实考虑了的，因为一开始随便选一条线就行了，多个最右边点可以通过处理上包的时候解决掉
        {
            x1 = x3;
            y1 = y3;
        }
        else if(x3 > x2)
        {
            x2 = x3;
            y2 = y3;
        }
    }
    g_result[1][0] = x1;
    g_result[1][1] = y1;
    g_result[2][0] = x2;
    g_result[2][1] = y2;
    g_result[0][0] += 2;
    getResult(Point, x1, y1, x2, y2);//上包递归
    getResult(Point, x2, y2, x1, y1);//下包递归
 
    printf("\n\n构成凸包的点有：\n");
    for(i=1;i<=g_result[0][0];i++)
        printf("(%d,%d)\n",g_result[i][0],g_result[i][1]);
    system("pause");//提交记得去掉这一行
    return 0;//HDOJ选手代码一般没有这一行
}
~~~
