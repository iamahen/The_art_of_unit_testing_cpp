//============================================================================
// Name        : HelloTDD.cpp
// Author      : ahen
// Version     :
// Copyright   : ahen
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char** argv) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	::testing::InitGoogleTest(&argc, argv);

	// Ignore some TEST
	// ::testing::GTEST_FLAG(filter) = "-IsValidLogFileNameTest*";

	RUN_ALL_TESTS();

	return 0;
}
