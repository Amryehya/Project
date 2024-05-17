#include "RecordManager.h"
#include <iostream>
#include<string>
using namespace std;

void RecordManager::addRecord() {
	string pass;
	cout << "set password\n";
	cin >> pass;
	setPassword(pass);
	getPassword();
	cin.ignore();
	cout << "Enter Name associated with the record\n";
	getline(cin, name);
	cin.sync();
	cout << "Enter Task Duration\n";
	getline(cin, taskduration);
	cin.sync();
	cout << "Enter Address associated with the record\n";
	getline(cin, address);
	cin.sync();
	cout << "Enter Date and time of the record\n";
	getline(cin, datetime);
	cin.sync();

}
void RecordManager::viewrecord() {
	cout << "Name associated with the record : " << name;
	cout << "The task duration : " << taskduration;
	cout << "Address associated : " << address;
	cout << "Datetime of the record : " << datetime;
}
void RecordManager::editrecord() {
	string pass;
	cout << "enter the password\n";
	cin >> pass;
	if (pass == getPassword()) {
		int a;
		cout << "1.Name associated with the record\n ";
		cout << "2.The task duration\n";
		cout << "3.Address associated\n";
		cout << "4.Datetime of the record\n";
		cout << "Enter the desired option you want to edit : ";
		cin >> a;
		cin.ignore();

		switch (a) {
		case 1:
			cout << "Enter new Name associated with the record\n";
			getline(cin, name);
			cin.sync();
			break;
		case 2:
			cout << "Enter new Task Duration\n";
			getline(cin, taskduration);
			cin.sync();
			break;
		case 3:
			cout << "Enter new Address associated with the record\n";
			getline(cin, address);
			cin.sync();
			break;
		case 4:
			cout << "Enter new Date and time of the record\n";
			getline(cin, datetime);
			cin.sync();
			break;
		case 5:
			cout << "exit";
			break;

		}
	}
	else
		cout << " wrong password\n";



}
void RecordManager::deleterecord() {
	string pass;
	cout << "enter the password\n";
	cin >> pass;
	if (pass == getPassword()) {
		taskduration = " ";
		name = " ";
		address = " ";
		datetime = " ";
		system("CLS");
		cout << " All records have been deleted\n";
	}
	else
		cout << " wrong password\n";
}
