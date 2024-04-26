#include "iostream"
#include "vector"
#include <map>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class SnapshotArray {
private:
	vector<vector<pair<int, int>>> allChanges;  // allChanges[i]表示索引i的变更历史列表，列表中每个索引为(snap_id, val)表示在快照号snap_id时索引i的值变更为val
	int snap_id = -1;   // 快照id，初始为-1

public:
	SnapshotArray(int length) {
		allChanges.resize(length);
		// 每个索引的初始值为0，因此变更历史中因为有个初始状态(-1, 0)
		for (auto& changes : allChanges) {
			changes.emplace_back(snap_id, 0);
		}
	}

	void set(int index, int val) {
		// 如果当前快照号和索引index的快照历史表的最后一个记录的快照号一致，说明是在同一个快照号内进行设置，更新一下这个快照号最新值即可
		if (snap_id == allChanges[index].back().first) {
			allChanges[index].back().second = val;
			return;
		}
		// 否则，加入新的变更记录
		allChanges[index].emplace_back(snap_id, val);
	}

	int snap() {
		return ++snap_id;   // 每次调用，快照id递增
	}

	int get(int index, int snap_id) {
		// 对索引index的变更历史表进行二分查找，找到最后一个小于snap_id的记录，即为snap_id对应快照时index的值
		vector<pair<int, int>>& changes = allChanges[index];
		int left = 0;
		int right = changes.size();
		while (left < right) {
			int mid = left + ((right - left) >> 1);
			if (changes[mid].first < snap_id) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		// 因为变更历史首个元素的快照号为id，给定的snap_id >= 0，因此一定存在小于snap_id的记录【left-1就是答案，一定有解】
		return changes[left - 1].second;
	}
};

int main() {
	SnapshotArray* snapshotArray = new SnapshotArray(3);
	snapshotArray->set(0, 5);
	snapshotArray->snap();
	snapshotArray->set(0, 6);
	cout << snapshotArray->get(0, 0);
	return 0;
}