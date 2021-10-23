#include <iostream>
#include <list>

using namespace std;

void print(list<int> const &list) {
    for (auto const &i: list) cout << i << " ";
    cout << endl;
}

void deleteFirstTwoDescending(list<int> &list) {
    auto prev = list.begin(), next = prev;
    for (next++; next != list.end(); prev = next, next++) {
        if (*prev > *next) {
            list.erase(next);
            list.erase(prev);
            return;
        }
    }
}

int main() {
    list<int> a = {3, 4, 7, 5, 4, 3};

    print(a);
    deleteFirstTwoDescending(a);
    print(a);

    list<int> b = {5, 4};
    print(b);
    deleteFirstTwoDescending(b);
    print(b);

    return 0;
}
