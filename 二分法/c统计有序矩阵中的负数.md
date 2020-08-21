### 题目
统计有序矩阵中的负数

### 题意
给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 

请你统计并返回 grid 中 负数 的数目。

 

示例 1：

输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]

输出：8

解释：矩阵中共有 8 个负数。

示例 2：

输入：grid = [[3,2],[1,0]]

输出：0

示例 3：

输入：grid = [[1,-1],[-1,-1]]

输出：3

示例 4：

输入：grid = [[-1]]

输出：1

~~~ c
/**
* 查找数组a中, 首次出现a[i] < x对应位置i
*/
int findPosition(int *a, int n, int x)
{
    if(!a) return -1;

    int low = 0;
    int high = n - 1;
    while(low <= high)
    {
        int middle = (low + high) >> 1;

        if(x > a[middle]) high = middle - 1;
        else if(x <= a[middle]) low = middle + 1;
        //else return middle;
    }

    return low;
}

int countNegatives(int** grid, int gridSize, int* gridColSize){
    if(!grid) return 0;

    int negativeCnt = 0;
    for(int i = 0; i < gridSize; i ++)
    {
        int pos = findPosition(grid[i], gridColSize[i], 0);
        if(pos < gridColSize[i])
            negativeCnt += gridColSize[i] - pos;
    }

    return negativeCnt;
}
~~~
