#include <iostream>
#include <fstream>
#include <list>

using namespace std;

void print(list<int> &list) {
    for (int n: list) cout << n << " ";
    cout << endl;
}

void removeLower(list<int> &list) {
    if (list.size() < 2) return;

    auto it = list.begin();
    int prev = *it;
    for (auto i = ++it; i != list.end(); i++) {
        cout << "p=" << prev << " i=" << *i << endl;
        if (*i < prev) {
            list.erase(i);
        } else {
            prev = *i;
        }
    }
}

int main() {
    // read from file
    ifstream in("in.txt");

    list<int> myList;

    while (!in.eof()) {
        int n;
        in >> n;
        myList.push_back(n);
    }
    in.close();

    print(myList);
    removeLower(myList);
    print(myList);

    return 0;
}
