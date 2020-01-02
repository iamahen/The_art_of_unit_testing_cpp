/*
 * TestableLogAnalyzer.h
 *
 *  Created on: 2020年1月2日
 *      Author: ahen
 */

#ifndef TESTABLELOGANALYZER_H_
#define TESTABLELOGANALYZER_H_

#include "FileExtensionManager.h"

// Chapter 3.4.6(3.7)
class LogAnalyzerUsingFactoryMethod {
public:
	bool isValidLogFileName(std::string fileName){ return getManager()->isValid( fileName ); }

protected:
	virtual IExtensionManager* getManager(){ return new FileExtensionManager(); };
};

class TestableLogAnalyzer : public LogAnalyzerUsingFactoryMethod {
public:
	TestableLogAnalyzer( IExtensionManager* mgr );
	virtual ~TestableLogAnalyzer();

	IExtensionManager *manager;
};

#endif /* TESTABLELOGANALYZER_H_ */
