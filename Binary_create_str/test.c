//��Ŀ��Ҫ�����ǰ������ķ�ʽ����һ��������ת����һ�������ź�������ɵ��ַ������սڵ�����һ�Կ����� "()" ��ʾ��
//������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�


//����ʵ�֣�

struct TreeNode {
    int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

char valstr[10];
char* _tree2str(struct TreeNode* t, char *str)
{
	if (t == NULL)
		return;

	//������
	sprintf(valstr, "%d", t->val);
	strcat(str, valstr);

	//����������
	if (t->left == NULL)
	{
		if (t->right == NULL)
		{
			return;
		}
		else
		{
			strcat(str, "()");
		}
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->left, str);
		strcat(str, ")");
	}

	//����������
	if (t->right == NULL)
		return;
	else
		strcat(str, "(");
	_tree2str(t->right, str);
	strcat(str, ")");

}

char str[100000];//ע����������ó�ȫ�ֱ�����������ں����ڲ��Ļ���һ��������ͻ�����
char* tree2str(struct TreeNode* t) {
	str[0] = '\0';//�����ʼ����һ��λ��
	_tree2str(t, str);

	return str;
}