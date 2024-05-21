#pragma once
#include<iostream>
#include<string>
#ifndef Menu_h
#define Menu_h
#include "FileHandler.h"
#include "PasswordManager.h"
using namespace std;
class Menu : public PasswordManager, public FileHandler
{
public:
	void displayMainMenu();
	void displayRecordList();
	void getUserChoice();

};
#endif
