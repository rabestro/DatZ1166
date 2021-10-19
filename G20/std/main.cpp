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
void exerciseG20(list<int> &list, int n, int m) {
    auto it = list.begin();
    while (it != list.end() && *it != m) it++;

    if (it == list.end()) {
        std::cout << m << " not found" << std::endl;
        return;
    }

    std::cout << *it << " found" << std::endl;
    list.insert(++it, n);
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
