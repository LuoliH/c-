### 题目
字符串相乘

### 题意
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"

~~~ c
char *multiply(char *num1, char *num2)
{
int i, j;
int len1 = strlen(num1);
int len2 = strlen(num2);
int *temp = (int *)calloc((len1 + len2), sizeof(int));
char *rlt = (char *)calloc((len1 + len2 + 1), sizeof(char));  //字符串需要多一个'/0'所以多一个长度

// 算出错位相乘的乘积每个元素的数字
for (i = len1 - 1; i >= 0; i--) {
    for (j = len2 - 1; j >= 0; j--) {
        temp[i + j + 1] += (int)(num1[i] - '0') * (num2[j] - '0');
    }
}

// 从数组的尾部开始遍历，将第i位的高位通过/累加到第i-1位，然后通过%求余获得当前位的数字。
for (i = len1 + len2 - 1; i > 0; i--) {
    temp[i - 1] += temp[i] / 10;
    temp[i] %= 10;
}

// 转换成字符串
rlt[0] = '0';  // 初始化默认第一个字符是0，防止输入有一个是'0'
for (i = 0, j = 0; i < len1 + len2; i++) {
    // 排除起始开始的'0'直到第一个非0出现
    if ((j == 0) && (temp[i] == 0)) {
        continue;
    }
    rlt[j++] = (char)(temp[i]) + '0';
}

return rlt;
}
~~~
