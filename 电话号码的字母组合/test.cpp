#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	char* num_to_str[10] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

	void combinations(const string& digits, size_t index, vector<string>& strv, const string& combineStr)
	{
		if (index == digits.size())//当递归到最后一层的最后一个字符时，让index再加一次，此时index已访问完毕，这时候把组合好的字符串尾插到strv容器中，并退出当前递归深度，返回上一层的递归处。
		{
			strv.push_back(combineStr);
			return;
		}
		int num = digits[index] - '0';
		string str = num_to_str[num];
		for (auto ch : str)
		{
			combinations(digits, index + 1, strv, combineStr + ch);//递归去组合字符串
		}
	}

	vector<string> letterCombinations(string digits)
	{
		if (digits.empty())//如果给的是空串，则返回空vector
		{
			return vector<string>();
		}
		size_t index = 0;//digits里面给出的字符个数，从0开始数
		vector<string> strv;//存放输出字符串的容器
		string combineStr;//存放组合后的字符串
		combinations(digits, index, strv, combineStr);

		return strv;
	}
};

int main()
{
	
	system("pause");
	return 0;
}