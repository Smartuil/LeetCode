#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;
#define ZERO 1e-12

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
vector<vector<int>> point = { {30,30},{60,30},{60,60},{30,60} };
vector<int> ret(9, 0);
double distance(double a1, double a2, double b1, double b2) {
	return sqrt((a1 - b1)*(a1 - b1) + (a2 - b2)*(a2 - b2));
}

int calSquareNum(double x, double y, double r) {
	//1
	double dis1 = distance(point[0][0], point[0][1], x, y);
	if (dis1 < r) {
		ret[0] = 1;
		ret[1] = 1;
		ret[3] = 1;
	}
	else if(abs(dis1-r) < ZERO)
	{
		ret[1] = 1;
		ret[3] = 1;
	}
	else//>
	{
		if (r > (x - 30)) {
			ret[1] = 1;
		}
		if (r > (y - 30)) {
			ret[3] = 1;
		}
	}

	//2
	double dis2 = distance(point[1][0], point[1][1], x, y);
	if (dis2 < r) {
		ret[3] = 1;
		ret[6] = 1;
		ret[7] = 1;
	}
	else if (abs(dis2 - r) < ZERO)
	{
		ret[7] = 1;
		ret[3] = 1;
	}
	else//>
	{
		if (r > (60 - x)) {
			ret[7] = 1;
		}
		if (r > (y - 30)) {
			ret[3] = 1;
		}
	}

	//3
	double dis3 = distance(point[2][0], point[2][1], x, y);
	if (dis3 < r) {
		ret[5] = 1;
		ret[8] = 1;
		ret[7] = 1;
	}
	else if (abs(dis3 - r) < ZERO)
	{
		ret[7] = 1;
		ret[5] = 1;
	}
	else//>
	{
		if (r > (60 - x)) {
			ret[7] = 1;
		}
		if (r > (60 - y)) {
			ret[5] = 1;
		}
	}

	//4
	double dis4 = distance(point[3][0], point[3][1], x, y);
	if (dis4 < r) {
		ret[5] = 1;
		ret[1] = 1;
		ret[2] = 1;
	}
	else if (abs(dis4 - r) < ZERO)
	{
		ret[1] = 1;
		ret[5] = 1;
	}
	else//>
	{
		if (r > (x - 30)) {
			ret[1] = 1;
		}
		if (r > (60 - y)) {
			ret[5] = 1;
		}
	}
	int count = 0;
	for (auto num : ret) {
		if (num == 1) {
			count++;
		}
	}
	return count+1;
}
/******************************结束写代码******************************/


int main3() {
	int res;

	//double _x;
	//cin >> _x;
	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//double _y;
	//cin >> _y;
	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//double _r;
	//cin >> _r;
	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	//res = calSquareNum(_x, _y, _r);
	res = calSquareNum(45, 45, 10);
	cout << res << endl;

	return 0;

}
