### 题目
跳水板

### 题意
你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。

返回的长度需要从小到大排列。

示例 1

输入：

shorter = 1

longer = 2

k = 3

输出： [3,4,5,6]

解释：

可以使用 3 次 shorter，得到结果 3；使用 2 次 shorter 和 1 次 longer，得到结果 4 。以此类推，得到最终结果。

~~~ c
int* divingBoard(int shorter, int longer, int k, int* returnSize){
    int *re=(int *)malloc(sizeof(int)*(k+1));
    *returnSize=0;
    if(k==0)//考虑特殊情况
    {
        return re;
    }
    int i=0,cnt=0,myarr[k+1];
    for(i=0;i<=k;i++)//i表示使用长木板的次数，从0到k
    {
        myarr[i]=longer*i+shorter*(k-i);
    }
    re[0]=myarr[0];
    (*returnSize)++;
    for(i=1;i<=k;i++)//消除重复
    {
        if(myarr[i]!=myarr[i-1])
        {
            re[*returnSize]=myarr[i];
            (*returnSize)++;
        }
    }
    return re;
}
~~~
