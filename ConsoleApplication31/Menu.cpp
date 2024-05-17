#include "Menu.h"
#include <iostream>
#include<string>
using namespace std;

void Menu::displayMainMenu() {
	cout << "Main menu\n" << "1.Add a new record\n2.view the record list\n3.Edit the existing record\n4.Delete the record";
	cout << "\n5.Close the program\n";
}
void Menu::displayRecordList() {
	readFromFile();
}
void Menu::getUserChoice() {
	int x;
	cout << "Enter the desired option : ";
	cin >> x;
	while (x != 5) {
		switch (x) {
		case 1:
			saveToFile();
			break;
		case 2:
			displayRecordList();
			break;
		case 3:
			editrecord();
			updateFile();
			break;
		case 4:
			deleterecord();
			updateFile();
			break;
		case 5:
			cout << "exit program\n";
			cout << "Press any key to close this window . . .";
			break;
		}
		displayMainMenu();
		cout << "Enter the desired option : ";
		cin >> x;
	}


}
