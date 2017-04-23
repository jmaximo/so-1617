#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exe6DLL.h"  


namespace exe6
{
	static void PrintExifTags(TCHAR filename){
		/*	if (argc < 2) {
		printf("file not in inputs");
		exit(1);
		}
		*/


		/*   algorithm goes here

		MARKER to start
		check marker value
		DATA to place
		TIFF to place
		Check TIFF header and allign
		IFD in place and search (for/while?)
		process data or search if offset
		fill return values
		end

		DWORD err = 0;
		HANDLE file = ...
		if(file == INVALID_HANDLE_VALUE)
		err = GetLastError();
		*/
		DWORD err = 0;
		LPCWSTR fileName = L"file.jpeg";
		HANDLE hFile = CreateFileW(fileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hFile == INVALID_HANDLE_VALUE)
			err = GetLastError();
		HANDLE hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0, NULL);
		if (hMap == INVALID_HANDLE_VALUE)
			err = GetLastError();
		PUCHAR hView = (PUCHAR)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

//		PXPTO iter = (PXPTO)hView;

		//iter->data = &hView + sizeof(iter->trash);
		//INT abc = (INT)iter;
	//	printf("something  %x", iter->trash);
		//getchar();

	}
}
