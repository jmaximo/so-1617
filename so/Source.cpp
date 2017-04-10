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
	PVOID base;
	PVOID allocationBase;
	SIZE_T totalsize;
}; typedef myHandle;

void  main(int argc, char* argv[]) {

	myHandle curr;
	myHandle biggest;
	
	HANDLE handle;
	if (argc > 1 )
		handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ , false,  atoi(argv[1]));
	else
		handle = GetCurrentProcess();

	PMEMORY_BASIC_INFORMATION info;

	VirtualQueryEx(handle, NULL, info, MAX_PATH);

	if (info->State != MEM_RESERVE) {
		info->RegionSize += curr.totalsize;

	}





}