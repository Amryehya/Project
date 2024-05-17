#include "PasswordManager.h"
#include<iostream>
#include<string>
using namespace std;
void PasswordManager::setPassword(string newpassword) {

	password = newpassword;
}
string PasswordManager::getPassword() {

	return password;
}
