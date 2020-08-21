### 题目
验证回文串

### 题意
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"

输出: true

示例 2:

输入: "race a car"

输出: false

~~~ c
bool isPalindrome(char * s){

    int str_len = strlen(s);
    char *new_s = (char *)malloc( sizeof(char) * str_len);
    int j = 0;

    for (int i =0 ; i < str_len; i++){
        if ( s[i] >= 'A' && s[i] <= 'Z'){
            new_s[j++] =  tolower(s[i]);  //tolower是将大写字母转化为小写字母，因为这里不分大小写；
        } else if ( s[i] >= 'a' && s[i] <= 'z'){
            new_s[j++] = s[i];
        } else if (s[i] >= '0' && s[i] <= '9'){
            new_s[j++] = s[i];
        } else{   //因为只有字母和数字，所以其他类型直接跳过
            continue;
        }
    }
    
    for ( int i = 0; i < (j/2); i ++){
        if (new_s[i] != new_s[j-i-1]){
            return false;
        }
    }
    free(new_s);
    return true;
}
~~~
