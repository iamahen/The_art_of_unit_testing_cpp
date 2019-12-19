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

class LogAnalyzer {
public:
	LogAnalyzer();
	~LogAnalyzer();

	bool isValidLogFileName( std::string& fileName );
	bool isValidLogFileNameEx( std::string& fileName);
};

#endif /* LOGANALYZER_H_ */
