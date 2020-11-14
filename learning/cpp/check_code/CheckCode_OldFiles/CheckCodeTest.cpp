#include <iostream>
#include "rlutil.h"
#include <fstream> //Stream class for file management

using namespace std;

int main() {

    //Variables
    string code;
    bool runw = true;
    //rlutil default
    rlutil::saveDefaultColor();

    //start program
    cout << "Insert a code: "; cin >> code;
    if ( ! runw ) cout << "\nProgram set wrong, Exit.\n" << endl;

    //make object for open file
    ofstream fileop;

    //test actions writing file
    fileop.open("testfile.txt"); //Open File "testfile.txt" !If file doesn't exist, this make a file named "testfile.txt"
    if (fileop.is_open()){} //check if any file is opened by "fileop" object
    else {
        cout << "\nError loading file, Exit.\n" << endl;
        return 1;
    }
    fileop << code; //print to file
    fileop.close(); //Close File "testfile.txt, (?)now object is ready for another use

    //test actions reading file
    ifstream fileop2("testfile2.txt");
    if (fileop2.is_open()) {
        string line;
        rlutil::setColor(3); cout << "\nOtput file opened:\n"; rlutil::resetColor();
        while (getline(fileop2, line)) {
        cout << line << '\n';
        }
    fileop2.close();
    }
    else {
        cout << "\nUnable to open file 2, exit\n";
        return 1;
    }


    //End Normal Program
    return 0;
}
