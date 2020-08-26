#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
bool canPlantTrees(vector < int > road, int n) {

	int count = 0;
	for (int i = 0; i < road.size(); ++i)
	{
		if (road[i] == 0 &&
			(i == 0 || road[i - 1] == 0) &&
			(i == road.size() - 1 || road[i + 1] == 0))
		{
			road[i] = 1;
			count++;
		}
		if (count >= n)
			return true;
	}

	return false;

}
/******************************����д����******************************/


int main1() {
	bool res;

	int _road_size = 0;
	cin >> _road_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _road;
	int _road_item;
	for (int _road_i = 0; _road_i < _road_size; _road_i++) {
		cin >> _road_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		_road.push_back(_road_item);
	}


	int _n;
	cin >> _n;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



	res = canPlantTrees(_road, _n);
	cout << res << endl;

	return 0;

}
