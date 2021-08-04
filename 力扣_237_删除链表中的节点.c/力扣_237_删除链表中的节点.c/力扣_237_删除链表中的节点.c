#include <stdio.h>
#include <stdlib.h>

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int main()
{
	return 0;
}