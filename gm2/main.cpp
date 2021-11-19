#include <iostream>
#include <fstream>

struct Node {
    int data;
    struct Node *next;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void createNode(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void removeLower() {
        auto *current = head;
        if (current == nullptr) return;
        auto prev = current;
        for (auto it = current->next; it != nullptr; it = it->next) {
            if (it->data < prev->data) {
                prev->next = it->next;
            } else {
                prev = it;
            }
        }

    }

    void printList() {
        Node *current = head;
        std::cout << '[';
        while (current != nullptr) {
            std::cout << current->data;
            current = current->next;
            if (current != nullptr) std::cout << ", ";
        }
        std::cout << ']' << std::endl;
    }

private:
    Node *head;
    Node *tail;
};

using namespace std;

LinkedList createList(string fileName) {
    ifstream in(fileName);
    auto list = LinkedList();

    while (!in.eof()) {
        int n;
        in >> n;
        list.createNode(n);
    }
    in.close();
    return list;
}

int main() {
    auto list = createList("in.txt");

    list.printList();

    list.removeLower();

    list.printList();

    return 0;
}