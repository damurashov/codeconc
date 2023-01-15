#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void list_init(struct ListNode *head, size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		head[i].next = &head[i + 1];
		head[i].val = i + 1;
	}

	head[size - 1].next = NULL;
}

void print_list(struct ListNode *head)
{
	for (; head != NULL; head = head->next) {
		printf("%d ", head->val);
	}

	printf("\n");
}

/// Reverses a part of a list
/// The algorithm:
/// 1. Shift the `head` to a position;
/// 2. Reverse the chunk;
/// 3. Re-link the bounds
struct ListNode *list_reverse_between(struct ListNode *head, int left, int right)
{
	struct ListNode *list_head = head;
	int pos = 1;

	if (head != NULL && head->next != NULL) {
		struct ListNode *last_before = NULL;
		struct ListNode *first_in_initial = head;  // The first element of a chunk in the initial list
		struct ListNode *prev = NULL;
		struct ListNode *next = head->next;

		// 1. Shift the head
		while (head->next != NULL && pos < left) {
			last_before = head;
			head = head->next;
			first_in_initial = head;
			pos += 1;
		}

		// 2. Reverse the chunk
		while (head->next != NULL && pos < right) {
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
			pos += 1;
		}

		next = head->next;
		head->next = prev;

		// 3. Re-link the chunk
		if (last_before != NULL) {
			last_before->next = head;
		}

		// Started from the beginning of the list
		if (left == 1) {
			list_head = head;
		}

		first_in_initial->next = next;
	}

	return list_head;
}

int main(void)
{
	struct ListNode list1[1] = {{.next=NULL, .val=0}};
	struct ListNode list2[2] = {{.next=NULL, .val=0}};
	struct ListNode list3[3] = {{.next=NULL, .val=0}};
	struct ListNode list5[5] = {{.next=NULL, .val=0}};
	list_init(list1, 1);
	list_init(list2, 2);
	list_init(list3, 3);
	list_init(list5, 5);
	print_list(list_reverse_between(list5, 2, 4));
	print_list(list_reverse_between(NULL, 0, 0));
	print_list(list_reverse_between(list2, 1, 1));
	print_list(list_reverse_between(list2, 2, 2));
}
