//���⣺����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ�, Ҫ�󷵻�����������ȿ�����

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	//1.���ƽ��

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
	//2.�ø��ƽڵ��Random

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
	//3.�������

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