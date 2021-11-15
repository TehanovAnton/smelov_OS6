#include <iostream>
#include <Windows.h>

#define KB 1024
#define PG (4 * KB)

using namespace std;

void sh(HANDLE pheap);

int main()
{
	setlocale(LC_ALL, "rus");
	
	HANDLE heap = HeapCreate(HEAP_NO_SERIALIZE|HEAP_ZERO_MEMORY, 4096, 5120);
	sh(heap);
	int* arr = (int*)HeapAlloc(heap, HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 1000 * sizeof(int));
	for (int i = 0; i < sizeof(arr); i++) {
		arr[i] = i + 1;
	}
	sh(heap);
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
