#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<int, int> map;
    ifstream in("in.txt");
    char c;
    int size = 0;

    while (!in.eof()) {
        in >> noskipws >> c;
        if (isalnum(c)) {
            ++size;
        } else if (size > 0) {
            ++map[size];
            size = 0;
        }
    }
    in.close();

    ofstream out("out.txt");
    for (auto& i : map) out << i.first << ": " << i.second << endl;
}
