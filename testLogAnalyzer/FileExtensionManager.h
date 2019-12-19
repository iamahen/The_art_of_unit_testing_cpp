/*
 * FileExtensionManager.h
 *
 *  Created on: 2019年12月19日
 *      Author: ahen
 */

#ifndef FILEEXTENSIONMANAGER_H_
#define FILEEXTENSIONMANAGER_H_

#include <string>

// Chapter 3.4.1
class IExtensionManager{
public:
	IExtensionManager(){};
	virtual ~IExtensionManager(){};
	virtual bool isValid( std::string fileName ) = 0;
};

class FileExtensionManager : IExtensionManager {
public:
	FileExtensionManager();
	~FileExtensionManager();

	bool isValid( std::string fileName);
};

class AlwaysValidFakeExtensionManager : IExtensionManager {
public:
	AlwaysValidFakeExtensionManager(){};
	~AlwaysValidFakeExtensionManager(){};

	bool isValid( std::string fileName){ return true; };
};
#endif /* FILEEXTENSIONMANAGER_H_ */
