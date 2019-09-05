#include <iostream>
#include <urlmon.h>
#include <stdio.h>
#include <cstdlib>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;

#pragma comment (lib, "urlmon.lib") 

HRESULT func(const char* arr1, char* arr2)
{
	return URLDownloadToFile(0, arr1, arr2, 0, 0);
}

int main(int argc, char *argv[])
{
	HRESULT res;
	char buff[18];
	for (int i = 0; i < argc-1; i++)
	{
		sprintf_s(buff, "C:\\Distr\\%d.jpg", i + 1);

		res = func(argv[i+1], buff);

		if (res == S_OK)
			cout << "Download success." << endl;
		else if (res == E_OUTOFMEMORY)
			cout << "Not enough memory" << endl;
		else if (res == INET_E_DOWNLOAD_FAILURE)
			cout << "Error resource" << endl;

		cv::Mat image = cv::imread(buff)
		cv::Mat new_image;

		cv::resize(image, new_image, cv::Size(100, 100));

		cv::namedWindow("resize", CV_WINDOW_AUTOSIZE);
		cv::imshow("resize", new_image);
		waitKey(0);
	}
	return 0;
}