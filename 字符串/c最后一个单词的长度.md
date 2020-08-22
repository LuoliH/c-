### 题目
最后一个单词的长度

### 题意
定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。

 

示例:

输入: "Hello World"

输出: 5

题目要求最后一个单词的长度，由于顺序遍历需要考虑的东西较多，可以反向考虑。

先将数组下标指向最后一个元素，然后向前(左边)移动，直到遇到空格。

字符串为空时，直接返回 0 ；

反向遍历数组，直到遇到空格停止。

~~~ c
int lengthOfLastWord(char * s){
    if (s == NULL) {
        return 0;
    }

    int len = strlen(s);
    int lastWordLen = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            lastWordLen++;
        }  else if (lastWordLen != 0) {
            break;
        }
    }

    return lastWordLen;
}
~~~

