/*
 * LogAnalyzer.cpp
 *
 *  Created on: 2019年12月8日
 *      Author: ahen
 */

#include "LogAnalyzer.h"
#include <algorithm>

LogAnalyzer::LogAnalyzer() {
	// TODO Auto-generated constructor stub

}

LogAnalyzer::~LogAnalyzer() {
	// TODO Auto-generated destructor stub
}

bool LogAnalyzer::isValidLogFileName( std::string& fileName )
{
	std::string strExt = ".SLF";
	std::string strEnd = fileName.substr( fileName.length() - strExt.length());

	// Ignore case sensitive
	std::transform( strEnd.begin(), strEnd.end(),strEnd.begin(), ::toupper );

	if( !strEnd.compare( strExt ) )
	{
		return true;
	}

	return false;
}
