#pragma once
#include<iostream>
#include<string>
#ifndef Menu_h
#define Menu_h
#include "RecordManager.h"
#include "FileHandler.h"
using namespace std;
class Menu : public FileHandler
{
public:
	void displayMainMenu();
	void displayRecordList();
	void getUserChoice();

};
#endif
