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
	vector<vector<pair<int, int>>> allChanges;  // allChanges[i]��ʾ����i�ı����ʷ�б��б���ÿ������Ϊ(snap_id, val)��ʾ�ڿ��պ�snap_idʱ����i��ֵ���Ϊval
	int snap_id = -1;   // ����id����ʼΪ-1

public:
	SnapshotArray(int length) {
		allChanges.resize(length);
		// ÿ�������ĳ�ʼֵΪ0����˱����ʷ����Ϊ�и���ʼ״̬(-1, 0)
		for (auto& changes : allChanges) {
			changes.emplace_back(snap_id, 0);
		}
	}

	void set(int index, int val) {
		// �����ǰ���պź�����index�Ŀ�����ʷ������һ����¼�Ŀ��պ�һ�£�˵������ͬһ�����պ��ڽ������ã�����һ��������պ�����ֵ����
		if (snap_id == allChanges[index].back().first) {
			allChanges[index].back().second = val;
			return;
		}
		// ���򣬼����µı����¼
		allChanges[index].emplace_back(snap_id, val);
	}

	int snap() {
		return ++snap_id;   // ÿ�ε��ã�����id����
	}

	int get(int index, int snap_id) {
		// ������index�ı����ʷ����ж��ֲ��ң��ҵ����һ��С��snap_id�ļ�¼����Ϊsnap_id��Ӧ����ʱindex��ֵ
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
		// ��Ϊ�����ʷ�׸�Ԫ�صĿ��պ�Ϊid��������snap_id >= 0�����һ������С��snap_id�ļ�¼��left-1���Ǵ𰸣�һ���н⡿
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