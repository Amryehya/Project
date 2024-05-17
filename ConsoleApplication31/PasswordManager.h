#pragma once
#include<iostream>
#include<string>
using namespace std;
#ifndef PasswordManager_h
#define PasswordManager_h
class PasswordManager
{
private:
	string password;
public:
	string getPassword();
	void setPassword(string);

};
#endif