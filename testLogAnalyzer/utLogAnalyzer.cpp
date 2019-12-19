#include "gtest/gtest.h"
#include "LogAnalyzer.h"

// Parameterized tests
class TestLogAnalyzer : public ::testing::TestWithParam<std::string>
{

};

TEST_P( TestLogAnalyzer, Params ) {
	LogAnalyzer analyzer;

	// Inside a test, access the test parameter with the GetParam() method
	// of the TestWithParam<T> class:
	std::string strIn = GetParam();
	EXPECT_TRUE( analyzer.isValidLogFileName(strIn) );
}

INSTANTIATE_TEST_CASE_P( IsValidLogFileNameTest,
		                TestLogAnalyzer,
                        ::testing::Values("meeny.slf", "miny.SLF", "moe.slf"));

// General tests
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

TEST( IsValidLogFileNameTest, ThrowTest )
{
	LogAnalyzer analyzer;

	//
	std::string test1 = "";
	std::string test2 = ".slf";

	//
	EXPECT_THROW( analyzer.isValidLogFileName(test1), std::logic_error );
	EXPECT_THROW( analyzer.isValidLogFileName(test2), std::logic_error );

}

// Chapter 3.4.3
// Dependency injection via constructor
TEST( IsValidLogFileNameTest_Ex, AlwaysTrue )
{
	FakeExtensionManager *fakeMgr = new FakeExtensionManager();
	fakeMgr->willBeValid = true;

	//
	std::string test = "short.ext";

	//
	LogAnalyzer analyzer( (IExtensionManager*)fakeMgr );
	bool ret = analyzer.isValidLogFileNameEx( test );
	ASSERT_TRUE( ret );
}

// Chapter 3.4.4
// Exception test
TEST( IsValidLogFileNameTest_Ex, AlwaysFalse )
{
	FakeExtensionManager *fakeMgr = new FakeExtensionManager();
	fakeMgr->exceptionWillThrow = "This is fake.";

	//
	std::string test = "anything.anyextension";

	//
	LogAnalyzer analyzer( (IExtensionManager*)fakeMgr );
	bool ret = true;
	try{
		ret = analyzer.isValidLogFileNameEx( test );
	}
	catch( std::string e)
	{
		ret = false;
	}
	ASSERT_FALSE( ret );
}

// Chapter 3.4.5
// Dependency injection via constructor
TEST( IsValidLogFileNameTest_Ex, ReturnTrue )
{
	FakeExtensionManager *fakeMgr = new FakeExtensionManager();
	fakeMgr->willBeValid = true;

	//
	std::string test = "short.ext";

	//
	LogAnalyzer analyzer;
	analyzer.set( (IExtensionManager*)fakeMgr );
	bool ret = analyzer.isValidLogFileNameEx( test );
	ASSERT_TRUE( ret );
}

