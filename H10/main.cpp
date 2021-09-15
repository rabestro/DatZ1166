#include <map>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    map<int, string> map;
    int id;
    ifstream in;
    in.open("one.txt");
    for (string word; in >> id >> word;) map[id] = word;
    in.close();
    in.open("two.txt");
    for (string word; in >> id >> word;) map[id] += word;

    ofstream out("out.txt");
    for (auto& i : map) out << i.first << " " << i.second << endl;
}