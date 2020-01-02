/*
 * FileExtensionManager.cpp
 *
 *  Created on: 2019年12月19日
 *      Author: ahen
 */

#include "FileExtensionManager.h"

FileExtensionManager::FileExtensionManager() {
	// TODO Auto-generated constructor stub

}

FileExtensionManager::~FileExtensionManager() {
	// TODO Auto-generated destructor stub
}

bool FileExtensionManager::isValid( std::string fileName) {
	return true;
}

// ExtensionManagerFactory
ExtensionManagerFactory::ExtensionManagerFactory() {

}

ExtensionManagerFactory::~ExtensionManagerFactory(){

}

IExtensionManager* ExtensionManagerFactory::create(){
	if( customManager != nullptr)
	{
		return customManager;
	}
	return (IExtensionManager*)new FileExtensionManager();
}

void ExtensionManagerFactory::setManager( IExtensionManager* mgr ) {
	customManager = mgr;
}
