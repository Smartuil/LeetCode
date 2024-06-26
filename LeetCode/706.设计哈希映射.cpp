#include "iostream"
#include "vector"
#include <map>
#include <string>
#include <list>

using namespace std;

class MyHashMap {
private:
	vector<list<pair<int, int>>> data;
	static const int base = 769;
	static int hash(int key) {
		return key % base;
	}
public:
	/** Initialize your data structure here. */
	MyHashMap() : data(base) {}

	/** value will always be non-negative. */
	void put(int key, int value) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it).first == key) {
				(*it).second = value;
				return;
			}
		}
		data[h].push_back(make_pair(key, value));
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it).first == key) {
				return (*it).second;
			}
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it).first == key) {
				data[h].erase(it);
				return;
			}
		}
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
	MyHashMap* obj = new MyHashMap();
    int key = 1;
    int value = 2;
	obj->put(key, value);

	key = 770;
	value = 2222;
	obj->put(key, value);

	int param_2 = obj->get(key);
	obj->remove(key);
	return 0;
}