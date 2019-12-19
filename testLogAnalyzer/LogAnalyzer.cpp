/*
 * LogAnalyzer.cpp
 *
 *  Created on: 2019年12月8日
 *      Author: ahen
 */

#include "LogAnalyzer.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>

// Chapter3
#include "FileExtensionManager.h"

LogAnalyzer::LogAnalyzer() {
	// TODO Auto-generated constructor stub

}

LogAnalyzer::~LogAnalyzer() {
	// TODO Auto-generated destructor stub
}

bool LogAnalyzer::isValidLogFileName( std::string& fileName )
{
	std::string strExt = ".SLF";

	// Filename has to be provided
	if( fileName.length() == 0 )
	{
		std::string errMsg = "Filename has to be provided";
		throw std::logic_error( errMsg );
	}

	// Ignore case sensitive
	std::string strFileName = fileName;
	std::transform( strFileName.begin(), strFileName.end(),strFileName.begin(), ::toupper );

	// Invalid extension
	std::size_t pos = strFileName.rfind( strExt );
	if( pos == -1 )
	{
		return false;
	}

	// Filename has to be provided
	std::string strName = fileName.substr( 0, fileName.length() - strExt.length() );
	if( strName.length() == 0 )
	{
		std::string errMsg = "Filename has to be provided";
		throw std::logic_error( errMsg );
	}

	return true;
}
bool LogAnalyzer::isValidLogFileNameEx( std::string& fileName)
{
	IExtensionManager* mgr = (IExtensionManager*)new FileExtensionManager();
	return mgr->isValid(fileName);
}
