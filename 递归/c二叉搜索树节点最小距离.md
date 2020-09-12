### 题目
二叉搜索树节点最小距离

### 题意
给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。

 

示例：

输入: root = [4,2,6,1,3,null,null]

输出: 1

解释:

注意，root是树节点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:


          4
          
        /   \
        
      2      6
      
     / \    
     
    1   3  

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
 
~~~ c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define ARRCNT 100
int idx = 0;
void myFunc(struct TreeNode *root, int *arr)
{
    if (root == NULL) {
        return;
    }

    myFunc(root->left, arr);
    arr[idx++] = root->val;
    myFunc(root->right, arr);
}

int minDiffInBST(struct TreeNode* root){
    int arr[ARRCNT] = {0};
    int i, res;

    idx = 0;
    res = INT_MAX;
    myFunc(root, arr);
    for (i = 1; i < idx; i++) {
        res = arr[i] - arr[i - 1] < res ? arr[i] - arr[i - 1] : res;
    }

    return res;
}
~~~
