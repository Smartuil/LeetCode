#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>

using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))

bool canReach(int upCnt, int rightCnt, string command, int destX, int destY) {
	int loopCnt = 0;
	if (upCnt > 0 && rightCnt > 0)
		loopCnt = MIN(destX / rightCnt, destY / upCnt);
	else if (upCnt > 0)
		loopCnt = destY / upCnt;
	else
		loopCnt = destX / rightCnt;

	destX -= loopCnt * rightCnt;
	destY -= loopCnt * upCnt;

	for (int i = 0; i < command.length(); ++i)
	{
		if (destX == 0 && destY == 0)
			return true;
		if (command[i] == 'U')
			destY--;
		else
			destX--;
	}
	return false;
}

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
bool canReachWithApple(string command, vector < vector < int > > apples, int x, int y) {
	int upCnt = 0;
	int rightCnt = 0;
	for (int i = 0; i < command.length(); ++i)
	{
		if (command[i] == 'U')
			upCnt++;
		else
			rightCnt++;
	}
	// 不能抵达终点，啥都没用
	if (!canReach(upCnt, rightCnt, command, x, y))
		return false;

	bool pick = false;
	for (int i = 0; i < apples.size(); ++i)
	{
		int apple_x = apples[i][0];
		int apple_y = apples[i][1];

		if (apple_x <= x && apple_y <= y && canReach(upCnt, rightCnt, command, apple_x, apple_y))
		{
			pick = true;
			break;
		}
	}
	return pick;


}
/******************************结束写代码******************************/


int main2() {
	bool res;

	string _command;
	getline(cin, _command);
	int _apples_rows = 0;
	int _apples_cols = 0;
	cin >> _apples_rows >> _apples_cols;
	vector< vector < int > > _apples(_apples_rows);
	for (int _apples_i = 0; _apples_i < _apples_rows; _apples_i++) {
		for (int _apples_j = 0; _apples_j < _apples_cols; _apples_j++) {
			int _apples_tmp;
			cin >> _apples_tmp;
			_apples[_apples_i].push_back(_apples_tmp);
		}
	}
	int _x;
	cin >> _x;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	int _y;
	cin >> _y;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



	res = canReachWithApple(_command, _apples, _x, _y);
	cout << res << endl;

	return 0;

}
