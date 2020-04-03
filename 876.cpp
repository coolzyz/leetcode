/*
 * =====================================================================================
 *
 *       Filename:  876.cpp
 *
 *    Description:  求链表中间节点（变量取出size后取中间或者快慢指针，快指针一次2步，慢指针1次1步，快指针到底，慢指针在中间
 *
 *        Version:  1.0
 *        Created:  2020年03月23日 11时01分25秒
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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* middleNode(ListNode* head) {
			int size = 0;
			ListNode *t = head;
			for (;t != NULL; t=t->next) {
				++size;
			}

			int target = size / 2;
			t = head;
			for (int i = 0; i < target; ++i) {
				t = t->next;
			}
			return t;
		}

		void print(ListNode *head) {
			for (ListNode *t = head; t != NULL; t = t->next) {
				std::cout << t->val << ",";
			}
		}
};

int main() {

	struct ListNode *one = new struct ListNode(1);
	struct ListNode *two = new struct ListNode(2);
	struct ListNode *three = new struct ListNode(3);
	struct ListNode *four = new struct ListNode(4);
	struct ListNode *five = new struct ListNode(5);
	// struct ListNode *six = new struct ListNode(6);

	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = NULL;
	// six->next = NULL;

	Solution *s = new Solution();
	s->print(one);
	s->print(s->middleNode(one));
	return 0;
}






