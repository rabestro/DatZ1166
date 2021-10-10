#include <iostream>

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

    void insertNodeAtPosition(int pos, int value) {
        Node *pre = new Node;
        Node *current = head;
        Node *temp = new Node;

        for (int i = 1; i < pos; i++) {
            pre = current;
            current = current->next;
        }
        temp->data = value;
        pre->next = temp;
        temp->next = current;
    }

    int pop() {
        int retval = 0;
        Node *next_node = nullptr;

        next_node = head->next;
        retval = head->data;
        delete head;
        head = next_node;

        return retval;
    }

    void pushNode(int value) {
        Node *new_node;
        new_node = new Node;

        new_node->data = value;
        new_node->next = head;

        head = new_node;
    }

    int removeLast() {
        int retval = 0;
        /* if there is only one item in the list, remove it */
        if (head->next == nullptr) {
            retval = head->data;
            delete head;
            return retval;
        }

        /* get to the second to last node in the list */
        Node *current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        /* now current points to the second to last item of the list, so let's remove current->next */
        retval = current->next->data;
        delete current->next;
        current->next = nullptr;
        return retval;
    }

    int removeByIndex(int n) {
        int i = 0;
        int retval = -1;
        Node *current = head;
        Node *temp_node = nullptr;

        if (n == 0) {
            return pop();
        }

        for (i = 0; i < n - 1; i++) {
            if (current->next == nullptr) {
                return -1;
            }
            current = current->next;
        }

        temp_node = current->next;
        retval = temp_node->data;
        current->next = temp_node->next;
        delete temp_node;

        return retval;
    }

    // G20. Create function to insert element with value n after first element with value m.
    void exerciseG20(int n, int m) {
        auto *current = head;
        while (current != nullptr && current->data != m) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << m << " not found" << std::endl;
            return;
        }
        std::cout << m << " found" << std::endl;
        Node *new_node = new Node;

        new_node->data = n;
        new_node->next = current->next;
        current->next = new_node;
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

LinkedList createList() {
    auto list = LinkedList();
    cout << "Enter number of nodes and their values:" << endl;
    int n;
    cin >> n;
    while (n--) {
        int value;
        cin >> value;
        list.createNode(value);
    }
    return list;
}

int main() {
    auto list = createList();
    list.printList();

    int n, m;
    cout << "Enter numbers N and M: " << endl;
    cin >> n >> m;

    list.exerciseG20(n, m);
    list.printList();

    return 0;
}
