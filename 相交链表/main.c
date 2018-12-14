//9.��дһ�������ҵ������������ཻ����ʼ�ڵ㡣

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	int lenA = 0;
	int lenB = 0;
	struct ListNode* curA = headA;
	struct ListNode* curB = headB;
	while (curA)
	{
		curA = curA->next;
		lenA++;
	}
	while (curB)
	{
		curB = curB->next;
		lenB++;
	}
	int gap = abs(lenA - lenB);
	struct ListNode* longList = headA, *shortList = headB;
	if (lenA<lenB)
	{
		longList = headB;
		shortList = headA;
	}
	while (gap--)
	{
		longList = longList->next;
	}
	while (longList&&shortList)
	{
		if (longList->val == shortList->val)
		{
			return longList;
		}
		else
		{
			longList = longList->next;
			shortList = shortList->next;
		}
	}
	return NULL;
}
