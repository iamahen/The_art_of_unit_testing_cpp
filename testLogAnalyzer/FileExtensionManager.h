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

class FileExtensionManager : public IExtensionManager {
public:
	FileExtensionManager();
	~FileExtensionManager();

	bool isValid( std::string fileName);
};

class AlwaysValidFakeExtensionManager : public IExtensionManager {
public:
	AlwaysValidFakeExtensionManager(){};
	~AlwaysValidFakeExtensionManager(){};

	bool isValid( std::string fileName){ return true; };
};

// Chapter 3.4.3
class FakeExtensionManager : public IExtensionManager {
public:
	FakeExtensionManager(){};
	~FakeExtensionManager(){};

	bool willBeValid = false;

	// Chapter 3.4.4
	std::string exceptionWillThrow = "";


	bool isValid( std::string fileName){
		if( !exceptionWillThrow.empty() )
		{
			throw exceptionWillThrow;
		}
		return willBeValid;
	};
};

// Chapter 3.4.6
class ExtensionManagerFactory{
public:
	ExtensionManagerFactory();
	~ExtensionManagerFactory();

	IExtensionManager* create();
	void setManager( IExtensionManager* mgr );

private:
	IExtensionManager* customManager = nullptr;
};


#endif /* FILEEXTENSIONMANAGER_H_ */
