
//ģ��ʵ��strstr

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
//		printf("�Ҳ���\n");
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

//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ�
//�ҳ�ֻ����һ�ε�������Ԫ�ء�

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

//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬
//����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
////����1
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
////����2
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

//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ��������,
//��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2},
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

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

//��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1.

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

//��Ŀ��
//��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1,�������������a��b�������һ���㷨�����a��b�������������ȵı��,
//��������int a, b��Ϊ�������ı�š��뷵��a��b������������ȵı��,ע�������㱾��Ҳ����Ϊ�������ȡ�
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
//��Ŀ��(��������)�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��
//A��������Ҫ���ţ�������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡�
//�����������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)��
//���ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�������ɫ����n(1��n��13), ͬʱ������������Ϊn������left, right,
//�ֱ����ÿ����ɫ���������׵����������ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������

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