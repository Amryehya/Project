#pragma once
#include<iostream>
#include<string>
#ifndef FileHandler_h
#define FileHandler_h
#include "RecordManager.h"
using namespace std;
class FileHandler : public RecordManager {
public:
	void saveToFile();
	void readFromFile();
	void updateFile();

};
#endif