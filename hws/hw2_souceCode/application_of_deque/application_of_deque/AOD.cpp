/*
	该作业为广度优先搜索(BFS)的很好示例
	使用deque双向队列存放搜索顺序
	广度优先搜索相关的内容请看tutorials下的BFS.md
*/
#include <deque>
#include <vector>
#include <iostream>
//深度优先搜索函数
int BFS(std::vector<std::vector<std::pair<int, bool>>>&);
//可达到（边界处）1的邻居递归变为0
void reachableToZero(std::vector<std::vector<std::pair<int, bool>>>&);
int main() {
	int numOfRow = 0; int numOfCol = 0;
	std::cin >> numOfRow >> numOfCol;
	std::vector<std::vector<std::pair<int, bool>>> vec(numOfRow);
	for (int row = 0; row < numOfRow; row++) {
		vec[row].resize(numOfCol);
	}
	//数组的初始化
	for (int row = 0; row < numOfRow; row++) {
		for (int col = 0; col < numOfCol; col++) {
			int tmp;
			std::cin >> tmp;
			vec[row][col].first = tmp;
			vec[row][col].second = false;
		}
	}
	std::cout << BFS(vec) << std::endl;
	return 0;
}
int BFS(std::vector<std::vector<std::pair<int, bool>>>& vec) {
	
}