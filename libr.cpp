//
// Created by Acer on 24.03.2023.
//
#include "libr.h"
#include <iostream>
#include <string>


void check_info(const string &filename) {
    ifstream finalfile(filename);

    if (finalfile.is_open()) {

        string outt;
        cout << "Here is output  file:" << endl;
        while (getline(finalfile, outt)) {

            cout << outt << endl;


        }


        finalfile.close();

    } else {
        cerr << "Unable to open file" << endl;
    }
}