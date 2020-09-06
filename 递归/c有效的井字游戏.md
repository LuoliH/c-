### 题目
有效的井字游戏

### 题意
用字符串数组作为井字游戏的游戏板 board。当且仅当在井字游戏过程中，玩家有可能将字符放置成游戏板所显示的状态时，才返回 true。

该游戏板是一个 3 x 3 数组，由字符 " "，"X" 和 "O" 组成。字符 " " 代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（" "）中。

第一个玩家总是放字符 “X”，且第二个玩家总是放字符 “O”。

“X” 和 “O” 只允许放置在空位中，不允许对已放有字符的位置进行填充。

当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。

当所有位置非空时，也算为游戏结束。

如果游戏结束，玩家不允许再放置字符。

示例 1:

输入: board = ["O  ", "   ", "   "]

输出: false

解释: 第一个玩家总是放置“X”。

示例 2:

输入: board = ["XOX", " X ", "   "]

输出: false

解释: 玩家应该是轮流放置的。

示例 3:

输入: board = ["XXX", "   ", "OOO"]

输出: false

示例 4:

输入: board = ["XOX", "O O", "XOX"]

输出: true

~~~ c
bool tiankong(char **,char **,int,int,int);
bool isend(char **);

bool validTicTacToe(char ** board, int boardSize){
    char ** res = malloc(sizeof(char*) * boardSize);  //自己模拟下棋过程的棋盘
    for(int i=0;i<boardSize;i++) {  //初始化为全空
        res[i] = malloc(sizeof(char) * boardSize);
        memset(res[i],' ',boardSize);
    }
    int countx = 0, counto = 0;
    for(int i=0;i<boardSize;i++){   //统计X和O的数量
        for(int j = 0; j < boardSize; j++){
            if(board[i][j] == 'X')
                countx++;
            if(board[i][j] == 'O')
                counto++;
        }
    }
    if(countx < counto) //初步判断去掉一些情况
        return false;
    return tiankong(res,board,counto,countx,0);
}

bool tiankong(char **res, char **board, int counto, int countx, int k){  //递归函数，k用来标记当前下X还是O
    if(counto == 0 && countx == 0)
        return true;
    if(isend(res) == true)
        return false;
    if(k % 2 == 0){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 'X' && res[i][j] == ' '){ //如果目标棋盘有，自己的棋盘还没有就下
                    res[i][j] = 'X';
                    if(tiankong(res, board, counto, countx-1, k+1))   //接下来的情况不能递归下去了就回溯
                        return true;
                    res[i][j] = ' ';
                }
            }
        }
    }
    else if(k % 2 == 1){
        for(int i = 0; i < 3; i++){
            for(int j = 0;j < 3; j++){
                if(board[i][j] == 'O' && res[i][j] == ' '){
                    res[i][j] = 'O';
                    if(tiankong(res, board, counto-1, countx, k+1))
                        return true;
                    res[i][j] = ' ';
                }
            }
        }
    }
    return false;
}

bool isend(char ** board){ //判断是否结束
    if(board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != ' ')
        return true;
    if(board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != ' ')
        return true;
    if(board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != ' ')
        return true;
    if(board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != ' ')
        return true;
    if(board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != ' ')
        return true;
    if(board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != ' ')
        return true;
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
        return true;
    if(board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[1][1]!=' ')
        return true;
    return false;
}
~~~
