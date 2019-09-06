#include <iostream>
#include <urlmon.h>
#include <string>
#include <stdio.h>
#include <cstdlib>
//#include "opencv2\highgui.hpp"
//#include "opencv2\imgproc.hpp"

using namespace std;

#pragma comment (lib, "urlmon.lib") 

HRESULT func(const char* arr1, char* arr2)
{
	return URLDownloadToFile(0, arr1, arr2, 0, 0);
}