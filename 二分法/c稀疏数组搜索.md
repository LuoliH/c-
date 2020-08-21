### 题目
稀疏数组搜索

### 题意
稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。

示例1:

 输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ta"
 
 输出：-1
 
 说明: 不存在返回-1。
 
示例2:

 输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ball"
 
 输出：4

~~~ c
//二分法，利用题目给出条件，字符串数组已经排序好，只要对字符串数组进行不断地收缩边界和比较中值就可以判断目标字符串的位置，如果轮询没有找到则返回-1
int findString(char** words, int wordsSize, char* s){
    int left=0,right=wordsSize-1;

    while(left<=right){
        //收缩边界直到边界均不为空为止
        while(strlen(words[right])==0){
            right--;
        }
        while(strlen(words[left])==0){
            left++;
        }
        int mid=(right+left)/2;
        //将mid指向一个不为空的字符串
        while(strlen(words[mid])==0){
            mid++;
        }
        //使用中点字符串和目标字符串进行比较
        if(!strcmp(words[mid],s)){
            return mid;
        }else if(strcmp(words[mid],s) < 0){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }

    return -1;
}
~~~
