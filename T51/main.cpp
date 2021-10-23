#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>

using std::vector;
using std::list;
using std::string;
using std::pair;
using std::map;
using std::cout;
using std::endl;

int main() {
    map<string, list<string>> ask;
    map<string, list<string>> bid;
    map<string, list<string>> offers[2] = {{},
                                           {}};
    vector<string> report;

    std::ifstream inFile("exchange.in");
    do {
        long time;
        char mode;
        string code, cd;
        inFile >> time >> mode >> code >> cd;
        int type = mode - 'A';
        cout << type << " " << time << endl;
        auto list = offers[type][cd];
        if (list.empty()) {
            offers[1 - type][cd].push_back(code);
        } else {
            auto transaction = std::to_string(time) + " ";
            if (mode == 'A') {
                transaction += code + " " + list.front();
            } else {
                transaction += list.front() + " " + code;
            }
            list.pop_front();
            report.push_back(transaction);
        }
    } while (!inFile.eof());
    inFile.close();

    auto outFile = fopen("exchange.out", "w+");

    fclose(outFile);
}
