
//模拟实现strstr

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdlib.h>
//#include <assert.h>
//
//char* my_strstr(char* str, char* substr)
//{
//	assert(str&&substr);
//	const char* cur = str;
//	const char* s1 = str;
//	const char* s2 = substr;
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = substr;
//		while (*s1 && *s2 && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s1=='\0')
//		{
//			return NULL;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cur;
//		}
//		cur++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char* str1 = "hello world";
//	char* str2 = "llo";
//	char* ret=my_strstr(str1, str2);
//	if (ret == NULL)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//
//	system("pause");
//	return 0;
//}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。
//找出只出现一次的那两个元素。

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void singleNumber(vector<int>& nums) {
//
//	int val=0;
//	for (auto& e : nums)
//	{
//		val ^= e;
//	}
//
//	int pos;
//	for (size_t i = 0; i<32; i++)
//	{
//		if (((val >> i) & 1) == 1)
//		{
//			pos = i;
//		}
//	}
//
//	int x = 0, y = 0;
//	for (size_t i = 0; i<nums.size(); i++)
//	{
//		if (((nums[i] >> pos) & 1) == 1)
//			x ^= nums[i];
//		else
//			y ^= nums[i];
//	}
//	vector<int> v;
//	v.push_back(x);
//	v.push_back(y);
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}
//int main()
//{
	//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(5);
	//v.push_back(6);

	//singleNumber(v);

	//system("pause");
	//return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

//给定一个非空整数数组，除了某个元素只出现一次以外，
//其余每个元素均出现了三次。找出那个只出现了一次的元素。

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
////方法1
//void singleNumber1(vector<int>& nums) {
//
//	int count[32] = { 0 };
//	for (size_t i = 0; i<nums.size(); i++)
//	{
//		for (size_t j = 0; j<32; j++)
//		{
//			if (((nums[i] >> j) & 1)==1)
//			{
//				count[31-j]++;
//			}
//		}
//	}
//
//	vector<int> v;
//	v.resize(32, 0);
//
//	for (size_t i = 0; i<32; i++)
//	{
//		if (count[i] % 3 == 1)
//		{
//			v[i]++;
//		}
//	}
//
//	int ret = 0;
//	for (int i = 31; i >= 0; i--)
//	{
//		ret +=v[i] << (31-i);
//	}
//
//	cout << ret << endl;
//
//}
//
////方法2
//int singleNumber2(vector<int>& nums)
//{
//	sort(nums.begin(), nums.end());
//	size_t i = 0;
//	while (i < nums.size() - 1)
//	{
//		if (nums[i] == nums[i + 1] )
//		{
//			i += 3;
//		}
//		else
//		{
//			break;
//		}
//	}
//	return nums[i];
//}
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(8);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	
//
//	//singleNumber(v);
//	cout << singleNumber2(v) << endl;
//
//	system("pause");
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字,
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2},
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

//#include <iostream>
//#include <vector>
//using namespace std;
//
//void MoreThanHalfNum_Solution(vector<int> numbers)
//{
//	int max = numbers[0], min = numbers[0];
//	for (size_t i = 0; i<numbers.size(); i++)
//	{
//		if (numbers[i]>max)
//		{
//			max = numbers[i];
//		}
//		if (numbers[i]<min)
//		{
//			min = numbers[i];
//		}
//	}
//	size_t range = max - min + 1;
//	size_t count[5] = { 0 };
//	for (size_t i = 0; i<numbers.size(); i++)
//	{
//		count[numbers[i] - min]++;
//	}
//	for (size_t i = 0; i<range; i++)
//	{
//		if (count[i]>(numbers.size()/2))
//			cout << i + min << endl;
//	}
//	//cout << 0 << endl;
//}
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(2);
//	v.push_back(2);
//	v.push_back(5);
//	v.push_back(4);
//	v.push_back(2);
//
//	MoreThanHalfNum_Solution(v);
//	system("pause");
//	return 0;
//}


///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

//求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1.

//#include <iostream>
//using namespace std;
//int main()
//{
//	int n=103;
//	int count = 0,ret = 0;
//	while (n)
//	{
//		if ((n & 1))
//		{
//			count++;
//			if (ret <count)
//			{
//				ret = count;
//			}
//		}
//		else
//		{
//			count = 0;
//		}
//		n = n >> 1;
//	}	
//	cout << ret << endl;
//	
//	system("pause");
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//题目：
//有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1,现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号,
//给定两个int a, b。为给定结点的编号。请返回a和b的最近公共祖先的编号,注意这里结点本身也可认为是其祖先。
//
//#include <iostream>
//using namespace std;
//
//int getLCA(int a, int b) 
//{
//	while (a != b)
//	{
//		if (a<b)
//		{
//			b = b / 2;
//		}
//		else
//		{
//			a = a / 2;
//		}
//	}
//	return a;
//}
//
//int main()
//{
//	int tree[7] = { 1, 2, 3, 4, 5, 6, 7 };
//	cout << getLCA(2, 7) << endl;
//	system("pause");
//	return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
//题目：(手套问题)在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。
//A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。
//所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，
//才能保证一定能选出一双颜色相同的手套。给定颜色种数n(1≤n≤13), 同时给定两个长度为n的数组left, right,
//分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//void findMinimum(int n, vector<int> left, vector<int> right) {
//	size_t left_sum = 0, right_sum = 0;
//	int left_min = 26, right_min = 26;
//	int ret = 0;
//	for (size_t i = 0; i<n; i++)
//	{
//		if (left[i] * right[i] == 0)
//		{
//			ret += (left[i] + right[i]);
//		}
//		else
//		{
//			left_sum += left[i];
//			right_sum += right[i];
//			left_min = min(left[i], left_min);
//			right_min = min(right[i], right_min);
//		}
//
//	}
//	if (left_sum <= right_sum)
//	{
//		ret += (left_sum - left_min) + 1;
//		ret += 1;
//	}
//	else
//	{
//		ret += (right_sum - right_min) + 1;
//		ret += 1;
//	}
//
//	cout << ret << endl;
//}
//
//int main()
//{
//	int n = 4;
//	vector<int> v1;
//	vector<int> v2;
//	v1.push_back(0);    
//	v1.push_back(7);
//	v1.push_back(1);
//	v1.push_back(6);
//
//	v2.push_back(1);
//	v2.push_back(5);
//	v2.push_back(0);
//	v2.push_back(6);
//
//	findMinimum(4,v1,v2);
//	system("pause");
//	return 0;
//}