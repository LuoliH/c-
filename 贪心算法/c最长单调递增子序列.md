### 题目
最长单调递增子序列

### 题意
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]

输出: 4 

解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

思路：

首先需明确自定义一个数组来保存最长上升子序列 lis[]， 长度最长为 numsSize

其次，也是算法的重点，就是在外层遍历每一个元素时，拿这个元素 nums[i] 和子序列数组的最后一个值 lis[index] 来比较，有以下三种情况：


nums[i] 大，则子序列长度加一，新增该元素；

lis[index] 大，则子序列长度不变，在子序列中从尾部（即最大值）开始遍历，找到那对左右正好一个比他大和另一个比他小的两个元素，将那个小的替换成 nums[i]，跳出小遍历；（此处需注意，当所有数都比nums[i]大时将lis[0]替换）
两者相等，无事发生

可能有些人说上述算法第二个情况好像不太对，换了子序列的非最后元素的一个后不会产生问题吗（这个问题得自己去尝试写写画画，我也不知道怎么描述，因为一开始我也有想到这点）？但其实要知道的是，我们并不用管 lis[] 里面怎么来怎么去，我们只需确保一件事：不管你替换还是不替换，我只要这个数组的实际长度：length。而 length 在替换那部分算法里面，并没有丝毫变动哦~ 换句话说，这都只是为了第一种情况服务的

然后关于我后来看到子序列有二分查找的解法，因为C语言写二分还是比较耗地方的，懒得去改进之类的，有兴趣的小伙伴可以自己尝试~

~~~ c
int lengthOfLIS(int* nums, int numsSize){
    if (numsSize <= 1) return numsSize;
    int lis[numsSize];
    int length = 1, index = 0;
    lis[index] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > lis[index]) {
            lis[++index] = nums[i];
            length++;
        }
        else if (nums[i] < lis[index]) {
            if (index == 0) lis[index] = nums[i];
            else {
                for (int j = index; j >= 0; j--) {
                    if (j == 0 || lis[j - 1] < nums[i]) {
                        lis[j] = nums[i];
                        break;
                    }
                }
            }
        }
    }
    return length;
}
~~~
