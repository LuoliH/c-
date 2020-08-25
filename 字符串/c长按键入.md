### 题目
长按键入

###题意
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

 

示例 1：

输入：name = "alex", typed = "aaleex"

输出：true

解释：'alex' 中的 'a' 和 'e' 被长按。

示例 2：

输入：name = "saeed", typed = "ssaaedd"

输出：false

解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。

示例 3：

输入：name = "leelee", typed = "lleeelee"

输出：true

示例 4：

输入：name = "laiden", typed = "laiden"

输出：true

解释：长按名字中的字符并不是必要的。

~~~ c
bool isLongPressedName(char * name, char * typed){
	int i = 0;
	int n = strlen(name);
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (name[i] == typed[j])
        {
			j++;
        }
		else if (i != 0 && name[i - 1] == typed[j])
		{
			while (name[i - 1] == typed[j])
			{
				j++;
			}
            i--;//当前字符未匹配到，但是for循环i会+1.在这里减回去
		}
		else
		{
			return false;
		}
	}
	return true;
}
~~~
