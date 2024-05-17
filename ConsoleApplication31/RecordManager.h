#pragma once
#include<iostream>
#include<string>
#ifndef RecordManager_h
#define RecordManager_h
#include "PasswordManager.h"
using namespace std;
class RecordManager :public PasswordManager {

protected:

    string taskduration;
    string name;
    string address;
    string datetime;
public:
    void addRecord();
    void viewrecord();
    void editrecord();
    void deleterecord();
};
#endif


