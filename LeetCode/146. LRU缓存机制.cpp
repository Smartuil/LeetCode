#include "iostream"
#include <unordered_map>

using namespace std;

class LRUCache {
public:
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator > cache;
	int cap;

	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (cache.find(key) != cache.end()) {
			int res = (*cache[key]).second;
			l.erase(cache[key]);
			l.push_front({ key,res });
			cache[key] = l.begin();
			return res;
		}
		return -1;
	}

	void put(int key, int value) {
		if (cache.find(key) != cache.end()) {
			l.erase(cache[key]);
			l.push_front({ key,value });
			cache[key] = l.begin();
		}
		else
		{
			if (l.size() == cap) {
				cache.erase(l.back().first);
				l.pop_back();
			}
			l.push_front({ key,value });
			cache[key] = l.begin();
		}
	}
};

int main() {
	LRUCache *cache = new LRUCache(2 /* �������� */);

	cache->put(1, 1);
	cache->put(2, 2);
	cache->get(1);       // ����  1
	cache->put(3, 3);    // �ò�����ʹ�ùؼ��� 2 ����
	cache->get(2);       // ���� -1 (δ�ҵ�)
	cache->put(4, 4);    // �ò�����ʹ�ùؼ��� 1 ����
	cache->get(1);       // ���� -1 (δ�ҵ�)
	cache->get(3);       // ����  3
	cache->get(4);       // ����  4
	return 0;
}