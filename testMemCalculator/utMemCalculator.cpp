#include "gtest/gtest.h"
#include "MemCalculator.h"

// Factory
static MemCalculator MakeCalc()
{
	return MemCalculator();
}

TEST( Sum, DefualtReturnZero )
{
	MemCalculator calc;

	int lastSum = calc.doSum();
	EXPECT_EQ( 0, lastSum );
}

TEST( Sum, AddReturnChange )
{
	MemCalculator calc = MakeCalc();
	calc.doAdd( 1 );
	int lastSum = calc.doSum();
	EXPECT_EQ( 1, lastSum );
}

