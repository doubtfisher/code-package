//问题：给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点, 要求返回这个链表的深度拷贝。

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	//1.复制结点

	struct RandomListNode* cur = head;
	while (cur)
	{
		struct RandomListNode* next = cur->next;
		struct RandomListNode* copy = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));

		copy->label = cur->label;
		copy->next = NULL;
		cur->next = copy;
		copy->next = next;
		cur = next;
	}
	//2.置复制节点的Random

	cur = head;
	while (cur)
	{
		struct RandomListNode* copy = cur->next;
		if (cur->random)
		{
			copy->random = cur->random->next;
		}
		else
		{
			copy->random = NULL;
		}
		cur = copy->next;
	}
	//3.拆解链表

	struct RandomListNode* newhead, *newtail;
	newhead = newtail = NULL;
	cur = head;
	while (cur)
	{
		struct RandomListNode* copy = cur->next;
		struct RandomListNode* next = copy->next;
		if (newtail == NULL)
		{
			newhead = newtail = copy;
		}
		else
		{
			newtail->next = copy;
			newtail = newtail->next;
		}
		cur->next = next;
		cur = next;
	}
	return newhead;
}