#include "RecordManager.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void RecordManager::addRecord() {
    cin.ignore();
    cout << "Enter the Name of the record\n";
    getline(cin, name);
    cin.sync();
    cout << "Enter Task Duration\n";
    getline(cin, taskduration);
    cin.sync();
    cout << "Enter Address of the record\n";
    getline(cin, address);
    cin.sync();
    cout << "Enter Date of the record (e.g. 2024-05-17)\n";
    getline(cin, date);
    cin.sync();
    cout << "Enter Time of the record (e.g. 14:30)\n";
    getline(cin, time);
    cin.sync();
    cout << "The record is saved successfully to the file\n\n";
}

void RecordManager::viewrecord() {
    cout << "Name associated with the record: " << name << endl;
    cout << "The task duration: " << taskduration << endl;
    cout << "Address associated: " << address << endl;
    cout << "Date of the record: " << date << endl;
    cout << "Time of the record: " << time << endl;
}

void RecordManager::editrecord() {
    ifstream input("record.txt");
    ofstream output("temp.txt", ios::trunc);
    if (!input.is_open() || !output.is_open()) {
        cout << "Failed to open files\n";
        return;
    }

    string line;
    bool found = false;
    bool edited = false;
    string currentName, currentTaskDuration, currentAddress, currentDate, currentTime;

    while (getline(input, line)) {
        if (line.find("Name: " + name) != string::npos) {
            found = true;
            currentName = line;
            getline(input, currentTaskDuration);
            getline(input, currentAddress);
            getline(input, currentDate);
            getline(input, currentTime);

            cout << "What do you want to edit:\n1. Name\n2. Task duration\n3. Address\n4. Date\n5. Time\n";
            int choice;
            cin >> choice;
            cin.ignore();

            string newValue;
            cout << "Enter your new edit: ";
            getline(cin, newValue);

            switch (choice) {
            case 1:
                currentName = "Name: " + newValue;
                break;
            case 2:
                currentTaskDuration = "Task duration: " + newValue;
                break;
            case 3:
                currentAddress = "Address: " + newValue;
                break;
            case 4:
                currentDate = "Date: " + newValue;
                break;
            case 5:
                currentTime = "Time: " + newValue;
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }
            edited = true;

            output << currentName << endl;
            output << currentTaskDuration << endl;
            output << currentAddress << endl;
            output << currentDate << endl;
            output << currentTime << endl;

            while (getline(input, line) && !line.empty());

            output << endl; //<<endl;
        }
        else {
            output << line << endl;
        }
    }

    input.close();
    output.close();

    if (found) {
        if (edited) {
            if (remove("record.txt") != 0) {
                cerr << "Error deleting file\n";
            }
            if (rename("temp.txt", "record.txt") != 0) {
                cerr << "Error renaming file\n";
            }
            cout << "Record edited successfully\n";
        }
        else {
            cout << "No changes made to the record\n";
        }
    }
    else {
        cout << "Name not found\n";
    }
}

void RecordManager::deleterecord() {
    ifstream input("record.txt");
    ofstream output("temp.txt", ios::trunc);
    if (!input.is_open() || !output.is_open()) {
        cerr << "Failed to open files\n";
    }

    string line;
    bool found = false;
    while (getline(input, line)) {
        size_t pos = line.find("Name: " + name);
        if (pos != string::npos) {
            found = true;
            for (int i = 0; i < 5; i++)
                if (!getline(input, line)) break;
        }
        else {
            output << line << endl;
        }
    }

    input.close();
    output.close();

    if (found) {
        if (remove("record.txt") != 0) {
            cerr << "Error deleting file\n";
        }
        if (rename("temp.txt", "record.txt") != 0) {
            cerr << "Error renaming file\n";
        }
        cout << "Record deleted successfully\n";
    }
    else {
        cout << "Record not found\n";
    }
}
