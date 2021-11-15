#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <Windows.h>

#define MB (1024*1024)

using namespace std;

LPVOID getmem(int mb);
void saymem();
void my_last_name_hex();

int main()
{
    setlocale(LC_ALL, "rus");

    int mb = 1 * 1024 * 4 * 256;

    int* arr = (int*)getmem(mb);
    for (int i = 1; i <= sizeof(arr); i++) {
        arr[i - 1] = i;
        cout << arr[i] << endl;
    }

    my_last_name_hex();
    char* lastName = (char*)getmem(mb);
    lastName[0] = 'И';
    lastName[1] = 'в';
    lastName[2] = 'а';

    char buf_1[10], buf_2[10], buf_3[10];
    _itoa_s((int)lastName[0], buf_1, 16);
    _itoa_s((int)lastName[1], buf_2, 16);
    _itoa_s((int)lastName[2], buf_3, 16);

    int page, size_buf = sizeof(buf_1);
    stringstream s_1, s_2;
    for (int i = 0; i < buf_1[i] != '\0'; i++)
    {
        if (buf_1[i] != 'f')
            s_1 << hex << buf_1[i];
    }
    s_1 >> page;


    for (int i = 0; i < buf_2[i] != '\0'; i++)
    {
        if (buf_2[i] != 'f')
            s_2 << hex << buf_2[i];
    }

    for (int i = 0; i < buf_3[i] != '\0'; i++)
    {
        if (buf_3[i] != 'f') {
            s_2 << hex << buf_3[i];
            break;
        }
    }

    int shift;
    s_2 >> shift;

    cout << "page: " << page << "; shift: " << shift;
}

LPVOID getmem(int mb) {
    LPVOID xmemaddr = VirtualAlloc(NULL, mb, MEM_COMMIT, PAGE_READWRITE);
    cout << "-- " << mb << "MB, VirtualAlloc = " << hex << xmemaddr << dec << "\n\n";
    return xmemaddr;
}

void saymem() {
    MEMORYSTATUS ms;
    GlobalMemoryStatus(&ms);
    cout << "  -- Объём физической памяти\t\t\t:" << ms.dwTotalPhys / MB<< endl;
    cout << "  -- Доступно физической памяти\t\t\t:" << ms.dwAvailPhys / MB << endl;
    cout << "  -- Объём виртуальной памяти\t\t\t:" << ms.dwTotalVirtual / MB << endl;
    cout << "  -- Доступно Виртуальной памяти\t\t:" << ms.dwAvailVirtual / MB << endl << endl;
}

void my_last_name_hex() {
    char name[] = "Тех";
    for (int i = 0; i < sizeof(name); i++) {
        cout << hex << (int)name[i] << endl;
    }
}
