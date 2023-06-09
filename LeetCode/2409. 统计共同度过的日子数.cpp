#include "iostream"
#include "vector"
#include <map>
#include <string>


using namespace std;

class Solution {
public:
	vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	map<int, int> AliceDaysMap;
	map<int, int> BobDaysMap;

	void initData(){
		for (int i = 1; i <= 365; i++){
			AliceDaysMap[i] = 0;
			BobDaysMap[i] = 0;
		}
	}

	int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
		int ret = 0;

		initData();

		int AliceDays = caclDays(arriveAlice, leaveAlice, AliceDaysMap);
		int BobDays = caclDays(arriveBob, leaveBob, BobDaysMap);

		for (int i = 1; i <= 365; i++) {
			if (AliceDaysMap[i] == 1 && BobDaysMap[i] == 1) {
				ret++;
			}
		}

		return ret;
	}

	int caclDays(string start, string end, map<int, int>& dayMap) {
		int allDays = 0;

		int startLeft = stoi(start.substr(0, 2));
		int startRight = stoi(start.substr(3, 2));

		int endLeft = stoi(end.substr(0, 2));
		int endRight = stoi(end.substr(3, 2));

		if ((endLeft - startLeft) == 0) {
			allDays = endRight - startRight + 1;
		}
		else if((endLeft - startLeft) > 0) {
			allDays += months[startLeft] - startRight + 1;

			for (int i = startLeft + 1; i < endLeft; i++) {
				allDays += months[i];
			}

			allDays += endRight;
		}

		int startDay = 0;
		if (startLeft == 1) {
			startDay = startRight;
		}
		else {
			for (int i = 1; i < startLeft; i++) {
				startDay += months[i];
			}
			startDay += startRight;
		}

		for (int i = startDay; i < startDay + allDays; i++) {
			dayMap[i] = 1;
		}

		return allDays;
	}
};

class Solution2 {
public:
	int getDays(string& date) {
		const int days_of_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int m, d;
		sscanf_s(date.c_str(), "%d-%d", &m, &d);
		for (int i = 0; i < m - 1; i++) d += days_of_month[i];
		return d;
	}

	int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
		string leave = min(leaveAlice, leaveBob);
		string arrive = max(arriveAlice, arriveBob);
		return max(0, getDays(leave) - getDays(arrive) + 1);
	}
};

int main() {
	Solution2* solution = new Solution2();
	string arriveAlice = "01-01";
	string leaveAlice = "12-19";
	string arriveBob = "06-19";
	string leaveBob = "10-20";
	cout << solution->countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob);
	return 0;
}