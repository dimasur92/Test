#include <iostream>
#include <urlmon.h>
#include <stdio.h>
#include <cstdlib>
#include "Header.h"
#include <gtest/gtest.h>

TEST(HRESULTtest, resulttest)
{
	HRESULT res;
	const char str[58] = { "http://png.ipev.ru/2019/09/05/IMG_0496-04-03-19-04-35.jpg" };
	char buff[18] = { "C:\\Distr\\Test.jpg" };
	res = func(str, buff);
	ASSERT_TRUE(res == S_OK);
}

int _tmain(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}