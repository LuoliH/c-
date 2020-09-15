### 题目
判断矩阵是否包含点

### 题意
设计一个函数，判断在矩阵中是否存在一条包含某字符串所有字符的路径。路径可从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。

例如：对于以下矩阵

a b t f

c f c s

j d e h

该矩阵包含bfce路径，但不包含abfb路径。

这道题目是一道典型的回溯法题目。

首先在main函数中定义好矩阵和待检验的字符串；

然后在 matrix_path函数中写好逻辑，即循环检测每个方格的路径；

vertify_path函数是核心的判断函数，用来检测从某个方格开始是否有待检测路径；

最后，通过两个测试用例完成功能测试。

注意：边界值测试可以令matrix或str指向空来测试，当然也可以令rows/cols小于等于0来判断。

~~~ c
#include<stdio.h>
#include<stdlib.h>   //包含malloc函数
#include<string.h>   //包含memset函数

#define true 1
#define false 0

int matrix_path(char* matrix, int rows,int cols, char* str) {

	if ((matrix == NULL) || (str == NULL) || (rows <= 0) || (cols <= 0))
		return false;
	
	int* visited;
	visited = (int*)malloc((rows * cols) * sizeof(int));
	memset(visited, 0, (rows * cols) * sizeof(int));

	// 测试visited数组是否初始化成功
	//for (int i = 0; i < rows; i++) {
	//	for (int j = 0; j < cols; j++) {
	//		printf("%d ", visited[i * cols + j]);
	//	}
	//	printf("\n");
	//}

	int pathLength = 0;

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (vertify_path(matrix, rows, cols, str, row, col, pathLength, visited))
				return true;
		}
	}

	free(visited);

	return false;

}

int vertify_path(const char* matrix, int rows, int cols, char* str, int row, int col, int pathLength, int* visited) {

	if (visited == NULL)
		return false;

	if (str[pathLength] == '\0')
		return true;

	int path = false;

	if ((row >= 0) && (row < rows) && (col >= 0) && (col < cols) && (matrix[row * cols + col] == str[pathLength]) && (!visited[row * cols + col])) {

		pathLength++;
		visited[row * cols + col] = true;

		path = vertify_path(matrix, rows, cols, str, row, col - 1, pathLength, visited) ||
			vertify_path(matrix, rows, cols, str, row, col + 1, pathLength, visited) ||
			vertify_path(matrix, rows, cols, str, row - 1, col, pathLength, visited) ||
			vertify_path(matrix, rows, cols, str, row + 1, col, pathLength, visited);

		if (!path) {
			pathLength--;
			visited[row * cols + col] = false;
		}
	}

	return path;
}
//功能测试
int test1() {
	int rows = 3;
	int cols = 4;

	char matrix[3][4] = { 'a','b','t','g',\
		'c','f','c','s',\
		'j','d','e','h' };

	char str[5] = { 'b','f','c','e' };

	int  result = matrix_path(matrix, rows, cols, str);
	
	return result;
}

int test2() {
	int rows = 3;
	int cols = 4;

	char matrix[3][4] = { 'a','b','t','g',\
		'c','f','c','s',\
		'j','d','e','h' };

	char str[5] = { 'a','b','f','b' };

	int  result = matrix_path(matrix, rows, cols, str);
	
	return result;
}

void main() {

	int result1 = test1();

	if (result1)
		printf("find it!\n");
	else
		printf("This path no exist!\n");

	int result2 = test2();

	if (result2)
		printf("find it!\n");
	else
		printf("This path no exist!\n");
}
~~~
