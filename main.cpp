#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "RC4.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 3) {
        cout << "\nUsage:\n";
        cout << argv[0] << " INPUT_FILE OUTPUT_FILE\n\n";
        return 1;
    }

    string key;
    cout << "Enter a key: ";
    getline(cin, key);
    //cout << "You've entered `" << key << "`\n";


    RC4 encoder(key);


    fstream in(argv[1], ios::in | ios::binary);
    if (!in.is_open()) {
        cerr << "Failed to open input file " << argv[1] << "\n";
        return 2;
    }

    fstream out(argv[2], ios::out | ios::binary);
    if (!out.is_open()) {
        cerr << "Failed to open output file " << argv[2] << "\n";
        return 3;
    }

    //encoder.proc(in, out);

    std::string input;
    while(!in.eof()) {
        input += (char)in.get();
    }

    std::string result = encoder.proc(input);

    out << result;

    return 0;
}
