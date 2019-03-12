#include "String.h"

void testString()
{
	String s1;
	String s2("hello");
	for (size_t i = 0; i < s2.Size(); i++)
	{
		cout << s2[i] << " ";
	}
	String s3(s2);
	cout << s3.c_str() << endl;

	String s4("hello C!");
	s3 = s4;
	cout << s3.c_str() << endl;
}

int main()
{
	testString();
	system("pause");
	return 0;
}