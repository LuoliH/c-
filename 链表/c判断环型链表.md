### 题目
判断环型链表

### 题意
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1

输出：true

解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0

输出：true

解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1

输出：false

解释：链表中没有环。

### 题解
快慢指针法：

定义两个指针，刚开始均指向头结点；

快指针走两步，慢指针走一步；

如果存在环，则快慢指针必然会相遇。

一个快指针（next两步）一个慢指针（next一步），如果环了肯定会相遇

~~~ c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(NULL == head)
        return false;

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;//不用担心越界，while条件里保证了可以访问到两个next
        if(slow == fast)
            return true;
    }

    return false;
}
~~~
