/*
 * =====================================================================================
 *
 *       Filename:  2.cpp
 *
 *    Description:  两数相加 3->4->5 + 1->2->3 = 543 + 321 = 864=4->6->8
 *
 *        Version:  1.0
 *        Created:  2020年04月03日 09时09分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zyz (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *ret = NULL;

			int sizea = size(l1);
			int sizeb = size(l2);

			ListNode *add = NULL;
			ListNode *toadd = NULL;
			if (sizea >= sizeb) {
				add = l1;
				toadd = l2;
			} else {
				add = l2;
				toadd = l1;
			}
			if (!add) {
				return toadd;
			}
			if (!toadd) {
				return add;
			}

			ListNode *t = NULL;
			for (; add != NULL; add = add->next) {
				if (toadd != NULL) {
					t = doAdd(add->val, toadd->val, t);
					link(ret, t);
					if (size(t) == 2) {
						t = t->next;
					} else {
						t = NULL;
					}
					toadd = toadd->next;
				} else {
					t = doAdd(add->val, 0, t);
					link(ret, t);
					if (size(t) == 2) {
						t = t->next;
					} else {
						t = NULL;
					}
				}

			}

			// 最高位处理
			if (t != NULL) {
				link(ret, t);
			}

			return ret;
		}

		int size(ListNode *h) {
			int ret = 0;
			for (ListNode *t = h; t != NULL; t = t->next) {
				++ret;
			}
			return ret;
		}

		void link(ListNode* &target, ListNode *param) {
			if (target != NULL) {
				ListNode *t = target;
				while(t->next != NULL) {
					t = t->next;
				}
				t->next = new ListNode(param->val);
			} else {
				target = new ListNode(param->val);
			}
		}


		ListNode* doAdd(int v1, int v2, ListNode *t) {
			int v = v1 + v2;
			if (t != NULL) {
				v += t->val;
			}
			ListNode *ret = NULL;
			if (v >= 10) {
				ret = new ListNode(v % 10);
				ret->next = new ListNode(v / 10);

			} else {
				ret = new ListNode(v);
			}
			return ret;
		}

	public:
		void print(ListNode* h) {
			for (ListNode *t = h; t != NULL; t = t->next) {
				cout << t->val << "->";
			}
			cout << endl;
		}
};

ListNode *createList(const vector<int> &in) {
	ListNode *head = NULL;
	ListNode *tmp = NULL;
	for (auto it = in.begin(); it != in.end(); ++it) {
		ListNode *t = new ListNode(*it);
		if (head == NULL) {
			head = t;
			tmp = head;
		} else {
			tmp->next = t;
			tmp = tmp->next;
		}
	}

	return head;
}

int main() {
	Solution s;
	// vector<int> h1 = {1, 2, 3};
	// vector<int> h1 = {8, 8, 8};
	// vector<int> h1 = {0};
	vector<int> h1 = {1};
	vector<int> h2 = {9, 9};
	ListNode *n1 = createList(h1);
	s.print(n1);
	ListNode *n2 = createList(h2);
	s.print(n2);
	s.print(s.addTwoNumbers(n1, n2));

	return 0;
}
