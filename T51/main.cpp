#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>

using std::vector;
using std::list;
using std::string;
using std::pair;
using std::map;
using std::cout;
using std::endl;

int main() {
    map<string, list<string>> offers[2];

    std::ifstream inFile("exchange.in");
    std::ofstream outFile("exchange.out");
    do {
        long time;
        char mode;
        string code, cd;
        inFile >> time >> mode >> code >> cd;
        int type = mode - 'A';
        auto list = offers[type][cd];
        if (list.empty()) {
            offers[1 - type][cd].push_back(code);
            continue;
        }
        auto transaction = std::to_string(time) + " ";
        if (mode == 'A') transaction += code + " " + list.front();
        else transaction += list.front() + " " + code;
        list.pop_front();
        outFile << transaction << endl;
    } while (!inFile.eof());
    inFile.close();
    outFile.close();
}
