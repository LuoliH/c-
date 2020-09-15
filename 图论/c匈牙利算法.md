### 题目
匈牙利算法

### 题意
以上是匈牙利算法的关键代码其实实现就是一个找增广路径的过程增广路径字面意思就是把路径越增越广实际意思也是一样的DFS从左边起始点开始搜索1.右边如果没匹配就匹配(link[v]==-1)2.如果右边匹配过了...就从右边点找左边的匹配点再搜索看是否能增广以上两种情况都能使匹配边+1这就是找二分图最大匹配的最简单算法了,代码很短,时间复杂度为O(n^3),网络流当然也能实现咯...记住咯:最小点覆盖=二分图最大匹配最小路径覆盖=|P|-二分图最大匹配...

~~~ c
const int INF = 0x3f3f3f3f; 
const int MAXN=510;
{
    int v;
    {
        {
            used[v]=true;
            {
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int res=0;
    int i,u;
    memset(link,-1,sizeof(link));
    for(u=0;u<uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) 
            res++;
    }
    return res;
}   
~~~
