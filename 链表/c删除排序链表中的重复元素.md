### 题目
删除排序链表中的重复元素

### 题意
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2

输出: 1->2

示例 2:

输入: 1->1->2->3->3

输出: 1->2->3

~~~ c

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){

	if(head == NULL)//单链表为空，返回链表
		return head;

	struct ListNode *lp;
	struct ListNode *p = head;//指针指向单链表
	lp = p;//最后链表返回的位置
	while(p ->next != NULL){
		if(p -> val == p ->next -> val){
			p -> next = p -> next -> next;//删除后者节点，继续遍历
		}
		else{
			p = p -> next;
		}
	}
	return lp;
}
~~~
