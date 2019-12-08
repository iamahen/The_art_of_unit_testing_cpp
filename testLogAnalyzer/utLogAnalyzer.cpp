#include "gtest/gtest.h"
#include "LogAnalyzer.h"

TEST( IsValidLogFileNameTest, Valid )
{
	LogAnalyzer analyzer;

	//
	std::string test1 = "good.slf";
	std::string test2 = "hello.slf";
	std::string test3 = "good.SLF";

	//
	EXPECT_EQ( true, analyzer.isValidLogFileName(test1));
	EXPECT_EQ( true, analyzer.isValidLogFileName(test2));
	EXPECT_EQ( true, analyzer.isValidLogFileName(test3));
}

TEST( IsValidLogFileNameTest, InValid )
{
	LogAnalyzer analyzer;

	//
	std::string test1 = "bad.txt";
	std::string test2 = "bad.jpeg";
	std::string test3 = "badslf";
	std::string test4 = "badSLF";

	//
	EXPECT_EQ( false, analyzer.isValidLogFileName(test1));
	EXPECT_EQ( false, analyzer.isValidLogFileName(test2));
	EXPECT_EQ( false, analyzer.isValidLogFileName(test3));
	EXPECT_EQ( false, analyzer.isValidLogFileName(test4));
}


