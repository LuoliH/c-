### 题目
亲密字符

### 题意
给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false 。

 

示例 1：

输入： A = "ab", B = "ba"

输出： true

示例 2：

输入： A = "ab", B = "ab"

输出： false

示例 3:

输入： A = "aa", B = "aa"

输出： true

示例 4：

输入： A = "aaaaaaabc", B = "aaaaaaacb"

输出： true

示例 5：

输入： A = "", B = "aa"

输出： false

此处撰写解题思路

1.用count记录不同的数组下标；

2.count > 2或count = 1则返回false；

3.count = 2时判断两个互换是否相等；

4.count = 0 判断A中是否呦重复元素出现，有返回true否则false；

~~~~ c
bool buddyStrings(char * A, char * B)
{
    int i,j;
    int count = 0;
    int pos;
    int alen = strlen(A);
    int blen = strlen(B);
    if(alen == 0 && blen == 0)
        return false;
    int tmp[3]={1,2,3};                         //记录不同字符的下标数组，起始值设为不相同
    if(alen != blen)
        return false;
    for(i = 0; i < alen;i++)
    {
        if(A[i] - B[i] != 0)
        {
            tmp[count++] = i;                   //记录不同的位置
        }
        if(count > 2)
        {
            return false;
        }
    }
    if(count == 1)  
    {
        return false;
    }
    if(count == 2 && A[tmp[0]] == B[tmp[1]] && A[tmp[1]] == B[tmp[0]])          //两个位置不同，且互相相等。则返回true
    {
        return true;
    }
    else if(count == 0)                                                         //处理A,B全部相等，若出现重复则返回true
    {
        for(i = 0;i < alen;i++)
        {
            for(j = i+1;j < alen;j++)
            {
                if(A[i] == A[j])
                {
                    return true;
                }
            }
        }
    }
    return false;
}
~~~

