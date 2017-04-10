#include "windows.h"
#include "tchar.h"
#include "stdio.h"
#include "psapi.h"
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <sstream>
#include <array>

struct myHandle {
	PVOID startAllocationBase;
	PVOID currBlockBase;
	SIZE_T totalsize;
} typedef myHandle;
int printProcessInfo(HANDLE handle);

void  main(int argc, char* argv[]) {

//	myHandle curr;
//	myHandle biggest;


	HANDLE handle;
	if (argc > 1 )
		handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ , false,  atoi(argv[1]));
//	handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, 12016);
	else
		handle = GetCurrentProcess();

	MEMORY_BASIC_INFORMATION info;

	VirtualQueryEx(handle, NULL, &info, MAX_PATH);

	
/*
	info -> BaseAddress
	info -> AllocationBase
	info -> RegionSize
	info -> State
*/
	printProcessInfo(handle);
	printf("Region Base Allocation %x \n", info.AllocationBase);
	printf("size %x \n", info.RegionSize);

	CloseHandle(handle);
	getchar();
}


int printProcessInfo(HANDLE handle) {
	TCHAR name[MAX_PATH];
	if (GetModuleFileNameEx(handle, 0, name, MAX_PATH))	{
		printf("Process Name: %s \n", name);
	}
	return 0;
}