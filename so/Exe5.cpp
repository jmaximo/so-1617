#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <windows.h>

#ifdef _WIN32
#include <sys/utime.h>
#else
#include <utime.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#endif

typedef struct ifdEnt {
	WORD tag;
	WORD format;
	DWORD numbOfComp;
	DWORD offset;
};

typedef struct ifd{				//4º
	WORD numbOfEntries;
	HANDLE entries;
};

typedef struct TIFF {			//3º
	WORD alingnment;
	WORD tagMark;
	DWORD offset;
};

typedef struct DATA{			// 2º
	WORD size;
	DWORD exif;
	WORD empty;
	HANDLE TiffHeader;
};

typedef struct MARKER {			// 1º hue hue
	WORD mValue;
	WORD size;
	HANDLE data;
} MARKER, *PMARKER;

typedef struct XPTO {
	WORD trash;
	HANDLE data;

}XPTO, *PXPTO;

typedef struct MYINFO {			//final data to process
	CHAR* Model;
	CHAR* DimWidth;
	CHAR* DimHeigth;
	CHAR* Date;
	CHAR* Iso;
	CHAR* Speed;
	CHAR* Exposure;
	CHAR* Oppening;
	CHAR* Lat;
	CHAR* Lon;
	CHAR* Alt;
};


void main(int argc, char* argv[]) {
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
	LPCWSTR fileName =L"file.jpeg";
	HANDLE hFile = CreateFileW(fileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		err = GetLastError();
	HANDLE hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0, NULL);
	if (hMap == INVALID_HANDLE_VALUE)
		err = GetLastError();
	PUCHAR hView = (PUCHAR)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

	PXPTO iter = (PXPTO)hView;

	//iter->data = &hView + sizeof(iter->trash);
	INT abc = (INT)iter;
	printf("something  %x",iter->trash);
	getchar();

}
