### 题目
正方形数组的数目

### 题意
给定一个非负整数数组 A，如果该数组每对相邻元素之和是一个完全平方数，则称这一数组为正方形数组。

返回 A 的正方形排列的数目。两个排列 A1 和 A2 不同的充要条件是存在某个索引 i，使得 A1[i] != A2[i]。

 

示例 1：

输入：[1,17,8

输出：2

解释：

[1,8,17] 和 [17,8,1] 都是有效的排列。

示例 2：

输入：[2,2,2]

输出：1

~~~ c
int buf[20];    //本打算保存当前探索状态使用
int g_count = 0;    //计数用途

// 交换
void swap(int *buf, int left, int right)
{
    int tmp = buf[left];
    buf[left] = buf[right];
    buf[right] = tmp;
}
// 排序用的比较函数
int cmp(const void* a, const void *b)
{
    return *(int*)a - *(int*)b;
}
// 判断开平方是否整数
bool judge(int a, int b)
{
    double tmp = sqrt((a  + b));
    int fl = floor(tmp);    // 库函数
    if((tmp - fl) < 0.00001)return true;
    return false;
}

bool backTrack(int *A,int ASize,int step)
{
    // 探索到边界
    if(step == ASize){  
        if(judge(A[step -2], A[step - 1]) == true){
            g_count++;
            return true;
        }
        return false;
    }
    
    for(int i = step; i < ASize; i++){  //为保证当前在step位置的值也能遍历到，所以从step开始
        // 和当前位置的值相同，没必要交换过来
        if(A[step] == A[i] && i != step) continue;
        // 和前一个位置的数相同，没必要交换过来
        if(i > step && A[i] == A[i -1])continue;
        // 如果选择的数和前面的数能满足开平方为整数则进入下一步
        
        if(judge(A[i], A[step - 1]) == true){
            swap(A, step, i);   // 满足后才交换过来
            backTrack(A, ASize, step + 1);

            swap(A, i, step);   // 恢复现场
        }
    }
    return true;
}

int numSquarefulPerms(int* A, int ASize){
    g_count = 0;
    // 排序是为了后续去重
    qsort(A, ASize, sizeof(int), cmp);

    for(int i = 0; i < ASize; i++){
        if(A[0] == A[i] && i != 0) continue;
        if(i >= 1 && A[i] == A[i - 1] )continue;

        swap(A, 0, i);
        backTrack(A,ASize,1);        
        swap(A, i, 0);
    }
    return g_count;
}
~~~
