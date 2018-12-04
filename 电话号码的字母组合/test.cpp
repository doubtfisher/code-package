#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	char* num_to_str[10] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

	void combinations(const string& digits, size_t index, vector<string>& strv, const string& combineStr)
	{
		if (index == digits.size())//���ݹ鵽���һ������һ���ַ�ʱ����index�ټ�һ�Σ���ʱindex�ѷ�����ϣ���ʱ�����Ϻõ��ַ���β�嵽strv�����У����˳���ǰ�ݹ���ȣ�������һ��ĵݹ鴦��
		{
			strv.push_back(combineStr);
			return;
		}
		int num = digits[index] - '0';
		string str = num_to_str[num];
		for (auto ch : str)
		{
			combinations(digits, index + 1, strv, combineStr + ch);//�ݹ�ȥ����ַ���
		}
	}

	vector<string> letterCombinations(string digits)
	{
		if (digits.empty())//��������ǿմ����򷵻ؿ�vector
		{
			return vector<string>();
		}
		size_t index = 0;//digits����������ַ���������0��ʼ��
		vector<string> strv;//�������ַ���������
		string combineStr;//�����Ϻ���ַ���
		combinations(digits, index, strv, combineStr);

		return strv;
	}
};

int main()
{
	
	system("pause");
	return 0;
}