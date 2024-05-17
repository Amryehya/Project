#include "FileHandler.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void FileHandler::saveToFile() {
    addRecord();
    ofstream outFile("record.txt", ios::app);
    outFile << "\nName:\t\t" << name << "\nTask Duration :\t" << taskduration << "\nAddress :\t" << address
        << "\nDate and Time:\t" << datetime << "\n\n";
    outFile.close();
    cout << "the record is saved successfuly to the file\n\n";
}
void FileHandler::readFromFile() {
    ifstream inFile("record.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}
void FileHandler::updateFile() {
    ofstream outFile("record.txt", ios::app);
    outFile << "\nName:\t\t" << name << "\nTask Duration :\t" << taskduration << "\nAddress :\t" << address
        << "\nDate and Time:\t" << datetime << "\n\n";
    outFile.close();
    cout << "the file is updated successfully\n\n";
}
