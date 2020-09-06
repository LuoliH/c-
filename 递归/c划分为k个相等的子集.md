### 题目
划分为k个相等的子集

### 题意
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4

输出： True

说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。

~~~ c
bool flag [16]={};

bool  IsPartition(int start ,int* nums,int numsSize, bool* flag,int k,int progresssum,int targetsum );

bool canPartitionKSubsets(int* nums, int numsSize, int k){
    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    for(int i=0;i<16;i++){
        flag [i]=false;
    }
    if(k==0||sum%k!=0){
        return false;
    }
    return IsPartition(0,nums,numsSize,flag,k,0,sum/k);
}

bool  IsPartition(int start ,int* nums,int numsSize, bool* flag,int k,int progresssum,int targetsum ){
    if(k==1){
        return true;
    }
    if(progresssum==targetsum){
        return IsPartition(0,nums,numsSize,flag,k-1,0,targetsum);
    }
    else if(progresssum>targetsum){
        return false;
    }
    
    for(int i=start;i<numsSize;i++){
        if(!flag[i]){
            flag[i]=true;
            if(IsPartition(i+1,nums,numsSize,flag,k,progresssum+nums[i],targetsum)){
                return true;
            }
            flag[i]=false;
        } 
    }
    return false;
}
~~~
