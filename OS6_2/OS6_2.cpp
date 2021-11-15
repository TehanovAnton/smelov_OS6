#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
	for (size_t i = 0; i < 100000; i++)
	{
		cout << i << endl;
		Sleep(1000);
	}
}
