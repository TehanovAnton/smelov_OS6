#include <iostream>
#include <Windows.h>

#define KB 1024
#define PG (4 * KB)

using namespace std;

void sh(HANDLE pheap);

int main()
{
	setlocale(LC_ALL, "rus");
	HANDLE pheap = GetProcessHeap();
	sh(pheap);

	int arr[100000];

	sh(pheap);
}

void sh(HANDLE pheap) {
	PROCESS_HEAP_ENTRY phe;
	phe.lpData = NULL;
	int unallocated = 0, allocated = 0;
	while (HeapWalk(pheap, &phe))
	{
		if (phe.wFlags & PROCESS_HEAP_UNCOMMITTED_RANGE)
			unallocated += phe.cbData;

		if (phe.wFlags & PROCESS_HEAP_ENTRY_BUSY)
			allocated += phe.cbData;		
	}
	cout << "unallocated part = " << unallocated << endl;
	cout << "allocated part = " << allocated << endl;
	cout << "-------------------------------\n\n";
}
