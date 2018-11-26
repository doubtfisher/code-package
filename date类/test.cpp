#include "Date.h"

int main()
{
	int state = 0;
	do
	{
		cout << "请选择:>>" << endl;
		cout << "************************************" << endl;
		cout << "***** 1.日期+天数  2.日期-天数 *****" << endl;
		cout << "***** 3.日期-日期  0.exit      *****" << endl;
		cout << "************************************" << endl;
		cout << "请输入:>>" << endl;
		cin >> state;
		if (state == 1)
		{
			Date d;
			cout << "请输入日期:>>" << endl;
			cin >> d;
			int day = 0;
			cout << "请输入天数:>>" << endl;
			cin >> day;
			cout << "输出结果:>> " << d + day << endl;
		}
		else if (state == 0)
		{
			cout << "exit" << endl;
		}
		else if (state == 2)
		{
			Date d;
			cout << "请输入日期:>>" << endl;
			cin >> d;
			int day = 0;
			cout << "请输入天数:>>" << endl;
			cin >> day;
			cout << "输出结果:>> " << d - day << endl;
		}
		else if (state == 3)
		{
			Date d;
			cout << "请输入日期:>>" << endl;
			cin >> d;
			Date d1;
			cout << "请输入日期:>>" << endl;
			cin >> d1;
			cout << "输出结果:>> " << d - d1 << endl;
		}
		else
		{
			cout << "输入有误，请重新选择:>>" << endl;
		}

	} while (state);

	/*Date d1(2018, 11, 14);
	d1.Print();
	Date d2 = d1 + 10;
	d2.Print();
	Date d3 = d1 - 12;
	d3.Print();
	(++d1).Print();
	(d1++).Print();

	(--d1).Print();
	(d1--).Print();
	Date d1(2018, 11, 14);
	d1 += 100;
	d1.Print();
	d1 -= 12;
	d1.Print();
	Date d2(2018, 11, 2);
	int d3 = d1 - d2;
	cout << d3 << endl;*/
	system("pause");
	return 0;
}
