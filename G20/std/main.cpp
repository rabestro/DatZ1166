#include <iostream>
#include <list>

using namespace std;

// function for printing the elements in a list
void print_list(list<int> list) {
    for (int value: list) cout << '\t' << value;
    cout << endl;
}


list<int> createList() {
    list<int> list;
    cout << "Enter number of nodes and their values:" << endl;
    int n;
    cin >> n;
    while (n--) {
        int value;
        cin >> value;
        list.push_back(value);
    }
    return list;
}

// G20. Create function to insert element with value n after first element with value m.
void exerciseG20(list<int> list, int n, int m) {
/*    auto *current = head;
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
    current->next = new_node;*/
}


int main() {
    auto list = createList();
    print_list(list);

    int n, m;
    cout << "Enter numbers N and M: " << endl;
    cin >> n >> m;

    exerciseG20(list, n, m);
    print_list(list);

    return 0;
}
