### 题目
学生出勤记录

### 题意
给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：

'A' : Absent，缺勤

'L' : Late，迟到

'P' : Present，到场

如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。

你需要根据这个学生的出勤记录判断他是否会被奖赏。

示例 1:

输入: "PPALLP"

输出: True

示例 2:

输入: "PPALLL"

输出: False

~~~ c
bool checkRecord(char * s)
{
    int i,a=0,length=0;
    while(s[length]!=0)
	 length++;
    for(i=0;i<length;i++)
	{
        if(s[i]=='A') 
		 a++;
        if(a>1) return 0;
    }
    for(i=0;i<length-2;i++)
	 {
        if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L')
		  return 0;
     }
    return 1;
}
~~~
