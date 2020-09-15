### 题目
求任意多边形的面积

~~~ c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int x[1000];
    int y[1000];
    while(scanf("%d",&n)&&n!=0)
    {
        int  sum=0;
        double ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }

        for(int k=1;k<=n-1;k++)
        {
            sum=sum+(x[k]*y[k+1]-x[k+1]*y[k]);

        }
        sum=sum+(x[n]*y[1]-y[n]*x[1]);
        ans=0.5*abs(sum);
        printf("%.1f\n",ans);

    }
}
~~~
