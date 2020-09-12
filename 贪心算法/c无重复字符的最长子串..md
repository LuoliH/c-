### 题目
无重复字符的最长子串

### 题意
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"

输出: 3 

解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: "bbbbb"

输出: 1

解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: "pwwkew"

输出: 3

解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。

     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

~~~ c
int lengthOfLongestSubstring(char * s){
    int i, j = 0, count = 0, max = 0, index[128] = {0}, start = 0;
    for(i=0;s[i]!='\0';i++)     
    {
        if(index[s[i]]>start)   //index用来储存出现重复字符时
        {                       //子串起始下标应移动到的地方
            count = i-start;
            if(count>max)
            {
                max = count;
            }
            start = index[s[i]];
        }
        index[s[i]] = i+1;
    }
    count = i-start;
    return count>max?count:max;
}

~~~
