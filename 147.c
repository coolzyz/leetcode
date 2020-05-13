/* =====================================================================================
 *
 *       Filename:  147.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年05月13日 15时28分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zyz (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <errno.h>
#include <math.h>  
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>



struct ListNode {
	int val;
	struct ListNode *next;
};


void print_link(struct ListNode *head) {
	for (struct ListNode *h = head; h != NULL; h = h->next) {
		printf("%d->", h->val);
	}

	printf("\n");
}

struct ListNode * create_link(int *v, int size) {
	struct ListNode *head = NULL;
	struct ListNode *p = NULL;
	for (int i = 0; i < size; ++i) {
		struct ListNode *t = (struct ListNode*)malloc(sizeof(struct ListNode));
		t->val = v[i];
		t->next = NULL;
		if (head == NULL) {
			head = t;
		}
		if (p != NULL) {
			p->next = t;
		} 
		p = t;
	}
	return head;
}

/*
 * 返回插入位置
 */
struct ListNode *find_insert_pos(struct ListNode *head, struct ListNode *end, struct ListNode *target) {
	if (target->val < head->val) {
		return NULL;
	}

	struct ListNode *check = head;
	struct ListNode *p = check;
	while(check != NULL && end != NULL && check != end->next && check->val <= target->val) {
		p = check;
		check = check->next;
	}
	return p;
}

struct ListNode* insertionSortList(struct ListNode* head){
	if (!head || !head->next) {
		return head;
	}

	struct ListNode *t = NULL;
	struct ListNode *m = NULL;
	struct ListNode *sorted_end = head;
	for (struct ListNode *target = sorted_end->next; target != NULL; target = sorted_end->next) {
		struct ListNode *insert_pos = find_insert_pos(head, sorted_end, target);
		printf("check:%d\n", target->val);
		// 头部插入
		if (insert_pos == NULL) {
			t = target->next;
			target->next = head;
			head = target;
			sorted_end->next = t;
		}
		// 尾部插入
		else if (sorted_end == insert_pos) {
			sorted_end = sorted_end->next;
			// 中间插入
		} else {
			t = insert_pos->next;
			m = target->next;
			insert_pos->next = target;
			target->next = t;
			sorted_end->next = m;
		}
		print_link(head);
	}
	return head;
}


int main (int argc, char *argv[])
{
	int a[3] = {3,2,4};
	struct ListNode *head = create_link(a, 3);
	print_link(head);
	print_link(insertionSortList(head));
	return EXIT_SUCCESS;
}

