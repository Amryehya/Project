#include "Menu.h"
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

void Menu::displayMainMenu() {
	
	cout << "\nMain Menu\n1.Add a new record\n2.view all records\n3.view record by name\n4.Edit records\n5.Delete a record";
	cout << "\n6.Close the program\n";
}
void Menu::displayRecordList() {
	ifstream inFile("record.txt");
	string line;
	cout << endl;
	while (getline(inFile, line)) {
		cout << line << endl;
	}
	inFile.close();;
}
void Menu::getUserChoice() {
	string pass;
	string get;
	cout << "please set a password\n";
	cin >> pass;
	setPassword(pass);
	system("cls");
	displayMainMenu();
	int x;
	cout << "Enter the desired option : ";
	cin >> x;
	system("cls");
	while (x != 6) {
		switch (x) {
		case 1: 
			cout << "please enter password:";
			cin >> get;
			system("cls");
			if (get == getPassword()) {
				addRecord();
				saveToFile();
			}
			else {
				cout << "\nwrong password\n";
			}
			break;
		case 2:
			cout << "please enter password:";
			cin >> get;
			system("cls");
			if (get == getPassword()) {
				displayRecordList();
			}
			else {
				cout << "\nwrong password\n";
			}
			break;
		case 3:
			cout << "please enter password:";
			cin >> get;
			system("cls");
			if (get == getPassword()) {
				cout << "Enter the name of record you want to view: ";
				cin.ignore();
				getline(cin, name);
				readFromFile();
			}
			else {
				cout << "\nwrong password\n";
			}
			break;
		case 4:
			cout << "please enter password:";
			cin >> get;
			system("cls");
			if (get == getPassword()) {
				cout << "Enter the name of record you want to edit: ";
				cin.ignore();
				getline(cin, name);
				editrecord();
			}
			else {
				cout << "\nwrong password\n";
			}
			break;
		case 5:
			cout << "please enter password:";
			cin >> get;
			system("cls");
			if (get == getPassword()) {
				cout << "Enter the name of record you want to delete: ";
				cin.ignore();
				getline(cin, name);
				deleterecord();
			}
			else {
				cout << "\nwrong password\n";
			}
			break;
		case 6:
			cout << "exit program";
			break;
		
		}
		displayMainMenu();
		cout << "Enter the desired option : ";
		cin >> x;
		system("cls");
	}


}
