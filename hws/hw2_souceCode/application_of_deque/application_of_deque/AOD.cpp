/*
	����ҵΪ�����������(BFS)�ĺܺ�ʾ��
	ʹ��deque˫����д������˳��
	�������������ص������뿴tutorials�µ�BFS.md
*/
#include <deque>
#include <vector>
#include <iostream>
//���������������
int BFS(std::vector<std::vector<std::pair<int, bool>>>&);
//�ɴﵽ���߽紦��1���ھӵݹ��Ϊ0
void reachableToZero(std::vector<std::vector<std::pair<int, bool>>>&);
int main() {
	int numOfRow = 0; int numOfCol = 0;
	std::cin >> numOfRow >> numOfCol;
	std::vector<std::vector<std::pair<int, bool>>> vec(numOfRow);
	for (int row = 0; row < numOfRow; row++) {
		vec[row].resize(numOfCol);
	}
	//����ĳ�ʼ��
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