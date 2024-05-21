#include "FileHandler.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void FileHandler::saveToFile() {
	ofstream outFile("record.txt", ios_base::app);
	outFile << "\nName: " << name << endl << "Task duration: " << taskduration << endl << "Address: " << address << endl << "Date: " << date << endl << "Time: " << time << endl;
	outFile.close();
}
void FileHandler::readFromFile() {
	ifstream input;
	input.open("record.txt");
	string line;
	bool found = false;
	while (!input.eof()) {
		while (getline(input, line)) {
			if (line.find("Name: " + name) != string::npos) {
				found = true;
				cout << "The recored named " << name << " : " << endl;
				for (int i = 0; i < 3; ++i) {
					if (!getline(input, line))
						break;
					cout << line << endl;
				}
				break;
			}
		}
		if (found == false) {
			cout << "Name is not found" << endl;
		}
	}
	input.close();
}
void FileHandler::updateFile() {

}
