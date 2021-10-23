#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

// Programming task CD exchanges
//
// The complexity of the algorithm is O(n*log(n))
// Memory consumption is O(n)
int main() {
    bool isFound = false;
    map<string, list<string>> offers[2];

    ifstream inFile("exchange.in");
    ofstream outFile("exchange.out");

    do {
        long time;
        char action;
        string code, cd;
        inFile >> time >> action >> code >> cd;
        int type = action - 'A'; // convert action to 0 or 1
        auto list = offers[type][cd];
        if (list.empty()) {
            offers[1 - type][cd].push_back(code);
            continue;
        }
        isFound = true;
        // The found person pairs recorded in the following format:
        // Time, Person_code_A, Person_code_B
        outFile << std::to_string(time) + " ";
        if (action == 'A') outFile << code + " " + list.front();
        else outFile << list.front() + " " + code;
        list.pop_front();
        outFile << endl;
    } while (!inFile.eof());

    // If no pairs are found, the application should print “0” number.
    if (!isFound) outFile << 0;

    inFile.close();
    outFile.close();
}
