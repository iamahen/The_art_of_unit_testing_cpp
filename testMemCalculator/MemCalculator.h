/*
 * MemCalculator.h
 *
 *  Created on: 2019年12月9日
 *      Author: ahen
 */

#ifndef MEMCALCULATOR_H_
#define MEMCALCULATOR_H_

class MemCalculator {
public:
	MemCalculator();
	virtual ~MemCalculator();

	void doAdd( int number );
	int doSum();

private:
	int sum = 0;
};

#endif /* MEMCALCULATOR_H_ */
