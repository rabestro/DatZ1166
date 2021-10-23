#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct Person {
    unsigned id;
    unsigned woman;
    unsigned man;
    unsigned level;
};

unsigned getLevel(vector<Person> persons, unsigned id) {
    for (auto person : persons) {
        if (person.woman == id || person.man == id) {
            return person.level + 1;
        }
    }
    return 0;
}

int main() {
    std::ifstream inFile("team.in");

    vector<Person> persons = {};
    int maxLevel = 0;

    for (;;) {
        Person p;
        inFile >> p.id >> p.woman >> p.man;
        if (p.id == 0) break;
        p.level = getLevel(persons, p.id);
//        cout << p.id << " " << p.woman << " " << p.man << " >> " << p.level << endl;
        if (p.level > maxLevel) maxLevel = p.level;
        persons.push_back(p);
    }
//    cout << persons.size() << endl;
    inFile.close();

    std::ofstream outFile("team.out");

    for (int level = maxLevel; level >= 0; --level) {
        outFile << level << ": ";
        for (auto person : persons) {
            if (person.level == level) outFile << person.id << " ";
        }
        outFile << endl;
    }
    outFile.close();
    return 0;
}
