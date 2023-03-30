#include <iostream>
#include <string>
#include<fstream>
#include<sstream> //Бібліотека , яка дозволяє працювати з строками , конвертувати різні типи даних в строку та навпаки
#include "libr.h"   //personal library
#include <regex>
#include <vector>
#include "cmd.h"
using namespace std;

int main(int argc, char *argv[]) {
    int mode = set_mode(argc, argv);
    if (mode == 2) {
        bool first = true;
        string output;
        string varible;
        ofstream file("output_code.txt");

        if (file.is_open()) {


            cout << "enter your data to file:" << endl;
            while(getline(cin, varible)&&varible!="exit"){
            file << varible << endl;


            }file.close();


         }else {
            cerr << "Couldn`t open file, something went wrong:(" << endl;
        }


        int choice;

        cout << "Do you want to add more info? 1- for yes/2- for no" << endl;

        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            ofstream fileee("output_code.txt", ios::app);
            if (fileee.is_open()) {
                cout << "enter your data to file:" << endl;

                while (getline(cin, varible) && varible != "exit") {
                    fileee << varible << endl;
                }
                fileee.close();
            }

            ifstream filee("output_code.txt");
            if (filee.is_open()) {
                      cout<<"output:"<<endl;
                while (getline(filee, varible)) {
                    cout << varible << endl;
                }
                filee.close();
            } else {
                cerr << "Couldn`t open file, something went wrong:(" << endl;
            }
        }


        ofstream newf("input.txt");
        ifstream rewrite("output_code.txt");
        if (rewrite.is_open() && newf.is_open()) {
            string checkinfo;

            while (getline(rewrite, checkinfo)) {
                string neww;

                for (char b: checkinfo) {
                    if (isdigit(b) && (b == '0' || b == '1')) {

                        neww += b;

                        first = true;
                    } else {
                        first = false;
                    }
                    if (!first) {
                        neww += " ";

                    }
                }


            istringstream check(neww);
            string parts;
            while (check >> parts) {
                newf << parts << endl;
            }
            }
            rewrite.close();
            newf.close();


        } else {
            cerr << "Couldn`t open file, something went wrong:(" << endl;
        }


        check_info("input.txt");

        ofstream thirdfile("decimal.txt");
        fstream decimal("input.txt", ios::in | ios::out);
        int nums;
        if (decimal.is_open() && thirdfile.is_open()) {

            string towrite;
            string helper;
            while (getline(decimal, helper)) {


                nums = stoi(helper, nullptr, 2);


                cout << "\n" << helper << " is :" << nums << " in decimal" << endl;


                thirdfile << nums << endl;

            }


            decimal.close();
        }


        check_info("decimal.txt");

    }

    if (mode == 1) {

        char *variable = new char[10000];

        FILE *file = fopen("input.txt", "w");

        if (file != NULL) {

            cout << "Enter the information to the file (type 'exit' to stop):" << endl;

            while (true) {
                fgets(variable, 10000, stdin);

                // Remove newline character from input
                char *pos;
                if ((pos = strchr(variable, '\n')) != NULL) {
                    *pos = '\0';
                }

                if (strcmp(variable, "exit") == 0) {
                    break;
                }

                fprintf(file, "%s\n", variable);
            }

            fclose(file);
        }

         else {
            cerr << "Unable to create file" << endl;
        }
        delete[] variable;


        int choicep;
        cout << "Do you want to add more info? 1-Yes 2-No" << endl;
        cin >> choicep;
        cin.ignore();
        if (choicep == 1) {
            char *variable2 = new char[10000];

            FILE *fileee = fopen("input.txt", "a");

            if (fileee != NULL) {

                cout << "Add info ,type 'exit' to stop:" << endl;

                while (true) {
                    fgets(variable2, 10000, stdin);


                    char *pos;
                    if ((pos = strchr(variable2, '\n')) != NULL) {
                        *pos = '\0';
                    }

                    if (strcmp(variable2, "exit") == 0) {
                        break;
                    }

                    fprintf(fileee, "%s\n", variable2);
                }
                fclose(fileee);

            } else {
                cerr << "file was not opened,error" << endl;
            }

            delete[] variable2;

        }


        char *output = new char[10000];
        FILE *filee = fopen("input.txt", "r");
        if (filee != NULL) {

            cout << "File output:\n";
            while (fgets(output, 10000, file)) {
                printf("%s", output);

            }


            fclose(filee);
        } else {
            cerr << "Could not open file for reading" << endl;
        }
        delete[] output;


        bool add_ = true;
        char *outtput = new char[1000];
        char *newc = new char[10000];
        FILE *newfile = fopen("second_file.txt", "w");
        FILE *oldfile = fopen("input.txt", "r");
        if (newfile != NULL && oldfile != NULL) {
            while (fgets(newc, 10000, oldfile)) {
                outtput[0] = '\0';
                bool added_newline = true;
                for (char *b = newc; *b != '\0'; b++) {
                    if (isdigit(*b) && (*b == '0' || *b == '1')) {
                        strncat(outtput, b, 1);
                        add_ = true;
                    } else {
                        add_ = false;
                    }
                    if (!add_) {
                        if (!added_newline) {
                            strncat(outtput, "\n", 1);
                            added_newline = true;
                        }
                    } else {
                        added_newline = false;
                    }
                }
                fprintf(newfile, "%s", outtput);
            }
            fclose(newfile);
            fclose(oldfile);


        } else {
            cerr << "error opening file";
        }
        fclose(newfile);
        fclose(oldfile);

        delete[] outtput;
        delete[] newc;

        char *checker = new char[10000];
        FILE *f = fopen("second_file.txt", "r");
        if (f != NULL) {
            printf("File output:\n");
            while (fgets(checker, 10000, f)) {
                printf("%s", checker);
            }
            fclose(f);
        } else {
            cerr << "Error opening file";
        }

        delete[] checker;
        int decimal;
        char *thirdh = new char[10000];
        FILE *third = fopen("third_file.txt", "w");
        FILE *second = fopen("second_file.txt", "r");

        if (third != NULL && second != NULL) {

            while (fgets(thirdh, 10000, second)) {

                decimal = stoi(thirdh, nullptr, 2);

                cout << "\n" << decimal << " is:" << thirdh;


            }


        }
    }


}