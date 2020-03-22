#pragma once

#include "iostream"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class MyLiskList {
public:
	MyLiskList() {};
	~MyLiskList() {}

	void insert(ListNode *head, ListNode *linklist, int n) {
		ListNode *tmp = new ListNode(NULL);
		tmp->val = n;
		linklist->next = tmp;
		linklist = tmp;
	}

	void print(ListNode *linklist) {
		while (linklist) {
			cout << linklist->val << "->" << endl;
			linklist = linklist->next;
		}
	}

	void test(int *n) {

	}
};