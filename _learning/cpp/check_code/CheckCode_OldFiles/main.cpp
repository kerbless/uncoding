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
    string files[5] = {
        "CodeList1.txt",
        "CodeList2.txt",
        "CodeList3.txt",
        "CodeList4.txt",
        "CodeList5.txt",
    };

    //rlutil default
    rlutil::saveDefaultColor();

    //Request Code
    cout << "Insert your Code: "; rlutil::setColor(8); cin >> code; rlutil::resetColor();

    //Open files
    for (int i = 0; i < 5; i++) {
        //cout << endl << files[i];
        ifstream inpFile ("CodeList1.txt"); //create object can read file //questo dovrebbe essere files[i] e non il nome del file
        if (inpFile.is_open()); //control file opening result
        else {
            rlutil::setColor(4);
            cout << "\nError loading file, Exit.\n";
            rlutil::resetColor();
            return 1;
        }

        //Search correspondences
        string line;
        while (getline(inpFile, line)) {
            if (line == code) {
                rlutil::setColor(10);
                cout << "\nCode found in list " << files[i] << endl;
                rlutil::resetColor();
                //return 0;
            }
            else {
                inpFile.close(); //if no match
                rlutil::setColor(12);
                cout << "\nNo match found in list " << files[i];
                rlutil::resetColor();
            }

        }

    }


    //End Code (normal not used)
    cout << endl;
    return 0;
}
