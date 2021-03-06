#include <iostream>
#include <fstream> //For file managment
#include "rlutil.h"
using namespace std;

/*
    APPUNTI

*/

/*
    Color Codes

0 Black
1 Blue (ANSI red)
2 Green
3 Cyan (ANSI brown)
4 Red (ANSI blue)
5 Magenta
6 Brown (dark yellow)
7 Light Grey (white)
8 Grey (dark grey or light black)
9 Light blue (ANSI light red)
10 Light green
11 Light cyan (ANSI yellow)
12 Light red (ANSI light magenta)
13 Light magenta
14 Yellow (ANSI light cyan)
15 White (bright)
*/


int main()
{
    //Variables
    string code;
    bool found;

    //rlutil default
    rlutil::saveDefaultColor();

    //Request Code
    cout << "Insert your Code: "; rlutil::setColor(8); cin >> code; rlutil::resetColor();

    //Open file
    ifstream inpFile1 ("CodeList1.txt"); //create object can read file
    if (inpFile1.is_open()); //control file opening result
    else {
        rlutil::setColor(4);
        cout << "\nError loading file, Exit.\n";
        rlutil::resetColor();
        return 1;
    }

    //Search correspondences
    string line;
    while (getline(inpFile1, line)) {
        if (line == code) {
            rlutil::setColor(10);
            cout << "\nCode in List!\n";
            rlutil::resetColor();
            return 0;
        }

    }
    inpFile1.close();
    rlutil::setColor(12);
    cout << "\nNo match found\n";
    rlutil::resetColor();
    //End Code (normal not used)
    return 0;
}
