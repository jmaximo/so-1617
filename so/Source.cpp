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
	

	printf("MEM_FREE 0x10000 \n");
	printf("MEM_COMMIT 0x1000 \n");
	printf("MEM_RESERVE 0x2000 \n \n");


	for (PBYTE iter = 0; VirtualQueryEx(handle, iter, &info, sizeof(info)) != 0; iter+= info.RegionSize)	{
		
		
		printf("base allocation %x \n", info.AllocationBase);
		printf("base address %x \n", info.BaseAddress);
		printf("region size %x \n", info.RegionSize);
		printf("region state %x \n \n", info.State);
	

	}

	
/*
	int i = VirtualQueryEx(handle, &info, &info, MAX_PATH);

	printf("first iter %i \n", i);
	printf("base allocation %x \n", info.AllocationBase);
	iter += info.RegionSize;

	

	i = VirtualQueryEx(handle, &info+iter, &info, MAX_PATH);

	printf("second iter %i \n", i);
	printf("base allocation %x \n", info.AllocationBase);
*/
/*
	info -> BaseAddress
	info -> AllocationBase
	info -> RegionSize
	info -> State

	printProcessInfo(handle);
	printf("Region Base Allocation %x \n", info.AllocationBase);
	printf("size %x \n", info.RegionSize);
*/
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