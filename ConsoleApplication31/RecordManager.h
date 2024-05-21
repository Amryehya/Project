#pragma once
#include<iostream>
#include<string>
#ifndef RecordManager_h
#define RecordManager_h
using namespace std;
class RecordManager  {

protected:

    string taskduration;
    string name;
    string address;
    string date;
    string time;
public:
    void addRecord();
    void viewrecord();
    void editrecord();
    void deleterecord();
};
#endif
