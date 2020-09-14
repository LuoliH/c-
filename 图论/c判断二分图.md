### 题目
判断二分图

### 题意
给定一个无向图graph，当这个图为二分图时返回true。

如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。

graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。


示例 1:

输入: [[1,3], [0,2], [1,3], [0,2]]

输出: true

解释: 

无向图如下:

0----1

|    |

|    |

3----2

我们可以将节点分成两组: {0, 2} 和 {1, 3}。

示例 2:

输入: [[1,2,3], [0,2], [0,1,3], [0,2]]

输出: false

解释: 

无向图如下:

0----1

| \  |

|  \ |

3----2

我们不能将节点分割成两个独立的子集。

基本思路： 使用深度优先搜索，用一个标记数组对经过的点进行归类，当出现当前端点与临界端点的标记符号相同时，意味着该图不是二分图。能够完成归类的所有图都是二分图。

标记数组的取值：

0：未经过的节点；

1：经过的节点，归类为A；

-1：经过的节点，归类为B

以输入数据[[1,5], [0,2], [1,3,6], [2,4], [3,5], [4,0]]为例，生成的无向图为：


  0---1
  
 /     \
 
5       2---6

 \     /
 
  4---3
  
则各节点遍历结果如下：

0	1	2	3	4	5	6

0	0	0	0	0	0	0

1	0	0	0	0	0	0

1	-1	0	0	0	0	0

\vdots⋮	\vdots⋮	\vdots⋮	\vdots⋮	\vdots⋮	\vdots⋮	\vdots⋮

1	-1	1	-1	1	-1	0

1	-1	1	-1	1	-1	-1

遍历至编号为5的节点时，检查编号0的节点与编号5的节点形成的边，两端符号不相同。此后进行回溯，直到编号为2的节点，在此处发现尚未经过的编号为6的节点。

回溯操作通过栈进行，若当前节点存在尚未经过的邻接节点，则将邻接节点压入栈，否则将当前节点弹出栈，返回上一个节点。

假定图是连通的，那么一次遍历即可对所有的节点进行标记处理，但是题目中并没有指定全连通图的条件。从一个节点遍历完成后，需要检查是否存在不连通的节点，循环直到全图没有不连通的节点时，遍历过程结束。

~~~ c
// 栈结构，部分函数只调用一次，添加inline标记以加速
struct Stack
{
    int maxLen;
    int top;
    int *content;
};
// 生成栈
inline struct Stack *getStack(int maxLen)
{
    struct Stack *ret = (struct Stack *)malloc(sizeof(struct Stack));
    ret->maxLen = maxLen;
    ret->top = 0;
    ret->content = (int *)malloc(sizeof(int) * maxLen);
    return ret;
}
// 压入元素
inline bool push(struct Stack *target, int val)
{
    if (target->top == target->maxLen)
        return false;
    target->content[target->top++] = val;
    return true;
}
// 弹出元素
inline bool pop(struct Stack *target, int *ret)
{
    if (target->top == 0)
        return false;
    *ret = target->content[--target->top];
    return true;
}
// 获取栈顶元素
bool getTop(struct Stack *target, int *ret)
{
    if (target->top == 0)
        return false;
    *ret = target->content[target->top - 1];
    return true;
}
bool isBipartite(int** graph, int graphSize, int* graphColSize){
    int *status = (int *)memset(malloc(sizeof(int) * graphSize), 0, sizeof(int) * graphSize),
        i = 0, ret = 0, flag, position;
    struct Stack *stack = getStack(graphSize);
    for (i = 0; i < graphSize; i++)
    {
        if (status[i]) // 检测尚未经历的节点，避免图不连通
            continue;
        status[i] = 1;
        push(stack, i);
        while(getTop(stack, &ret)) // 栈为空时，所有元素归类完成，本次遍历结束
        {
            flag = 1;
            for (i = 0; i < graphColSize[ret]; i++)
            {
                position = graph[ret][i];
                if (status[position] != 0) // 节点已经经历过
                {
                    if (status[position] == status[ret]) // 检查节点
                        return false;
                }
                else // 标记节点
                {
                    flag = 0;
                    status[position] = -status[ret];
                    push(stack, position); // 进入当前节点的下一层
                }
            }
            if (flag) // 当前节点已经遍历完成，返回上一层
                pop(stack, &ret);
        }
    }
    return true; // 归类完成
}
~~~
