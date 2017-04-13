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



	HANDLE handle;
	if (argc > 1 )
		handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ , false,  atoi(argv[1]));
//	handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, 12016);
	else
		handle = GetCurrentProcess();

	MEMORY_BASIC_INFORMATION info;
	myHandle curr, bigger;
	
	PBYTE iter = 0;
	printf("MEM_FREE 0x10000 \n");
	printf("MEM_COMMIT 0x1000 \n");
	printf("MEM_RESERVE 0x2000 \n \n");
	VirtualQueryEx(handle, iter, &info, sizeof(info));
	curr.startAllocationBase = info.AllocationBase;
	curr.currBlockBase = info.BaseAddress;
	curr.totalsize = 0;
	/*
	printf("base allocation %x \n", info.AllocationBase);
	printf("base address %x \n", info.BaseAddress);
	printf("region size %x \n", info.RegionSize);
	printf("region state %x \n \n", info.State);

	printf("biggest region \n");
	printf("base address %x \n", curr.startAllocationBase);
	printf("Block base %x \n", curr.currBlockBase);
	printf("Total size %x \n \n", curr.totalsize);
	*/

	bigger = curr;
	int count = 0;
	for ( iter = 0; VirtualQueryEx(handle, iter, &info, sizeof(info)) != 0; iter+= info.RegionSize){		//while (sameProcess)

		printf("base allocation %x \n", info.AllocationBase);
		printf("base address %x \n", info.BaseAddress);
		printf("region size %x \n", info.RegionSize);
		printf("region state %x \n \n", info.State);
	}
	for (iter = 0; VirtualQueryEx(handle, iter, &info, sizeof(info)) != 0; iter += info.RegionSize) {		//while (sameProcess)

		if (curr.startAllocationBase == info.AllocationBase) {
			if (info.State == MEM_RESERVE) {
				curr.totalsize += info.RegionSize;
				if (bigger.totalsize < curr.totalsize) {
					bigger.currBlockBase = curr.currBlockBase;
					bigger.startAllocationBase = curr.startAllocationBase;
					bigger.totalsize = curr.totalsize;
					maconha++;
				}
			}/*else {
				curr.startAllocationBase = info.AllocationBase;
				curr.currBlockBase = info.BaseAddress;
				curr.totalsize = 0;
			}*/
		}
		
		
	}
	printf("biggest region \n");
	printf("base address %x \n", curr.startAllocationBase);
	printf("Block base %x \n", curr.currBlockBase);
	printf("Total size %x \n \n", curr.totalsize);
	printf("biggest was affected %i times", count);

	
	
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