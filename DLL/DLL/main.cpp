#include "DLL.h"

int main()
{
	DLL<int> dll;
	dll.push_front(1);
	dll.push_back(4);
	dll.insert(1, 2);
	dll.insert(2, 3);
	dll.insert(4, 5);
	dll.print();
}