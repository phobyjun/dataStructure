#include "Vector.h"

int main()
{
	Vector<char> vec;
	int command;
	char val;
	while (true)
	{
		vec.print();
		cout << "1. 추가" << endl;
		cout << "2. 제거" << endl;
		cout << "0. 종료" << endl;
		cin >> command;

		if (command == 0)
			break;
		else if (command == 1)
		{
			cout << "입력 :: ";
			cin >> val;
			vec.push_back(val);
		}
		else if (command == 2)
		{
			vec.pop_back();
		}
		system("cls");
	}
}