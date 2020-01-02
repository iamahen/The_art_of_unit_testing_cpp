/*
 * LogAnalyzer.h
 *
 *  Created on: 2019年12月8日
 *      Author: ahen
 */

#ifndef LOGANALYZER_H_
#define LOGANALYZER_H_

#include <string>
#include <cctype>

// Chapter 3.4.3
#include "FileExtensionManager.h"

class LogAnalyzer {
public:
	LogAnalyzer();
	// Chapter 3.4.3
	LogAnalyzer(IExtensionManager* mgr);
	~LogAnalyzer();

	bool isValidLogFileName( std::string& fileName );
	bool isValidLogFileNameEx( std::string& fileName);

	// Chapter 3.4.5
	void set( IExtensionManager* mgr );
	IExtensionManager* get();

private:
	IExtensionManager* manager;
};
#endif /* LOGANALYZER_H_ */
