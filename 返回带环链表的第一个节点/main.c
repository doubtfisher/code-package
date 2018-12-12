//11.����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

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
