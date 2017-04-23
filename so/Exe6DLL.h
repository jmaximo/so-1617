#pragma once  
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <windows.h>


#define Exe6DLL_API __declspec(dllexport)   

namespace Exe6DLL
{

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

	
	 static void PrintExifTags(TCHAR filename);

}