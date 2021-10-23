#include <iostream>

using namespace std;

struct LinkedList {
    int value;
    LinkedList *next;
};

void deleteFirstTwoDescending(LinkedList **first) {
    auto root = *first;
    auto prev = root;
    for (auto curr = prev->next; curr; root = prev, prev = curr, curr = curr->next) {
        if (prev->value > curr->value) {
            if (prev == *first) *first = curr->next;
            else root->next = curr->next;
            return;
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    LinkedList a, b, c;
    c.value = 6; c.next = NULL;
    b.value = 7; b.next = &c;
    a.value = 3; a.next = &b;

    auto root = &a;
    cout << a.value << endl << a.next << endl;
    deleteFirstTwoDescending(&root);

    cout << a.value << endl << a.next << endl;

    return 0;
}
