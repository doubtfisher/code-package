//11.给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

struct ListNode *detectCycle(struct ListNode *head)
{
	struct ListNode* meet = NULL;
	struct ListNode* slow = head;
	struct ListNode* fast = slow;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			meet = slow;
			break;
		}
	}
	if (meet == NULL)
	{
		return NULL;
	}
	while (meet&&head)
	{
		if (meet == head)
		{
			return meet;
		}
		meet = meet->next;
		head = head->next;
	}
	return NULL;
}
