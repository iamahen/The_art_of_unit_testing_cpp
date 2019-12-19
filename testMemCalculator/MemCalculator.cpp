/*
 * MemCalculator.cpp
 *
 *  Created on: 2019年12月9日
 *      Author: ahen
 */

#include "MemCalculator.h"

MemCalculator::MemCalculator() {
	// TODO Auto-generated constructor stub

}

MemCalculator::~MemCalculator() {
	// TODO Auto-generated destructor stub
}

void MemCalculator::doAdd( int number )
{
	sum += number;
}

int MemCalculator::doSum()
{
	int temp = sum;
	sum = 0;
	return temp;
}
