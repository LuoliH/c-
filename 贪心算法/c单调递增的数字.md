### 题目
单调递增的数字


### 题意
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:

输入: N = 10

输出: 9

示例 2:

输入: N = 1234

输出: 1234

示例 3:

输入: N = 332

输出: 299

~~~ c
#define VALID_RANGE 1000000000
int monotoneIncreasingDigits(int N)
{
    if (N > VALID_RANGE) {
        return 0;
    }
    int len = 1;
    int ninePoint = -1;
    long int retN = 0;
    int array[10] = { 0 };
    
    //将整型数据转为数组以及实际有效长度。
    for (int i = 0; i < 10; i++) {
        array[i] = N % 10;
        N = N / 10;
        if (N > 0) {
            len++;
        }
    }

    //从高位到低位找出首次出现低位小于高低的位置ninePoint。
    for (int i= len - 1; i > 0; i--) {
        if (array[i] > array[i - 1]) {
            ninePoint = i - 1;
            break;
        }
    }
    
    //ninePoint位置向高位借位，注意，如果此点高位存在多位数字相同时，要将这几位的最高位借一位，其余低位均赋值为9.
    for (int j = ninePoint + 1; j < len && ninePoint >= 0; j++) {
         if (array[j] > array[j + 1]) {
            array[j]--;
            break;
        } else {
            array[j] = 9;
        }
    }

    //从ninePoint开始向低位全部赋值为9
    for (int j = ninePoint; j >= 0 && ninePoint >= 0; j--) {
        array[j] = 9;
    }

    //将数组还原为整型数据。
    for (int i = len; i >= 0; i--) {
        retN = retN * 10 + array[i];
    }
    return retN;
}

~~~
