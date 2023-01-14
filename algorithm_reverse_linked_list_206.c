#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *reverse_list(struct ListNode *head)
{
	if (head != NULL) {
		struct ListNode *prev = NULL;

		while (head->next != NULL) {
			struct ListNode *next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}

		head->next = prev;
	}

	return head;
}

int main(void)
{
}
