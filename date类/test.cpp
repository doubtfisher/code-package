#include "Date.h"

int main()
{
	int state = 0;
	do
	{
		cout << "��ѡ��:>>" << endl;
		cout << "************************************" << endl;
		cout << "***** 1.����+����  2.����-���� *****" << endl;
		cout << "***** 3.����-����  0.exit      *****" << endl;
		cout << "************************************" << endl;
		cout << "������:>>" << endl;
		cin >> state;
		if (state == 1)
		{
			Date d;
			cout << "����������:>>" << endl;
			cin >> d;
			int day = 0;
			cout << "����������:>>" << endl;
			cin >> day;
			cout << "������:>> " << d + day << endl;
		}
		else if (state == 0)
		{
			cout << "exit" << endl;
		}
		else if (state == 2)
		{
			Date d;
			cout << "����������:>>" << endl;
			cin >> d;
			int day = 0;
			cout << "����������:>>" << endl;
			cin >> day;
			cout << "������:>> " << d - day << endl;
		}
		else if (state == 3)
		{
			Date d;
			cout << "����������:>>" << endl;
			cin >> d;
			Date d1;
			cout << "����������:>>" << endl;
			cin >> d1;
			cout << "������:>> " << d - d1 << endl;
		}
		else
		{
			cout << "��������������ѡ��:>>" << endl;
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
