#include "iostream"
#include "vector"
#include <map>
#include <string>
#include <list>

using namespace std;

class MyHashSet {
private:
	vector<list<int>> data;
	static const int base = 769;
	static int hash(int key) {
		return key % base;
	}
public:
	/** Initialize your data structure here. */
	MyHashSet() : data(base) {}

	void add(int key) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it) == key) {
				return;
			}
		}
		data[h].push_back(key);
	}

	void remove(int key) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it) == key) {
				data[h].erase(it);
				return;
			}
		}
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it) == key) {
				return true;
			}
		}
		return false;
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
	MyHashSet* obj = new MyHashSet();
	int key = 1;
	int value = 2;
	obj->add(key);

	obj->remove(key);

	bool param_3 = obj->contains(key);
	return 0;
}