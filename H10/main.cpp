#include <map>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
/**
 * Lab. H10
 *
 * Read text from two given text files.
 * Text in both given file contains identified words.
 * One line in file is one word in format <integer ID> <Word max 30 characters>
 *
 * Merge both files in third file.
 * Print data in third file in descending order by ID value.
 * The same ID may not appear twice in third file.
 * If two words have the same ID, concatenate them in third file.
 */
int main() {
    map<int, string> map;
    int id;
    string word;
    ifstream in;

    in.open("one.txt");
    while (in >> id >> word) map[id] = word;
    in.close();

    in.open("two.txt");
    while (in >> id >> word) map[id] += word;
    in.close();

    ofstream out("out.txt");
    for (auto& i : map) out << i.first << " " << i.second << endl;
    out.close();
}