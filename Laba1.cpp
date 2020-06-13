#include <iostream>
#include <fstream>
#include "Program.h"

using namespace std;
void container_Init(container& c);
void container_Clear(container& c);
void container_In(container& c, ifstream& ifst);
void container_Out(container& c, ofstream& ofst);
void Sort(container& c);
void OutComplex(container& c, ofstream& ofst);
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "incorrect command line! "
            "Waited: command input.txt output.txt"
            << endl;
        exit(1);
    }

    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    cout << "Start" << endl;

    container c;
    container_Init(c);
    container_In(c, ifst);
    ofst << "Filled container. " << endl;
    Sort(c);
    //container_Out(c, ofst);
    OutComplex(c, ofst);
    container_Clear(c);
    ofst << "Empty container. " << endl;
    container_Out(c, ofst);

    cout << "Done";
    return 0;
}
