#include <iostream>

using namespace std;

//function for printing the elements in a list
void print_list(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

list<int> createList() {
    list <int> list;
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

int main() {
    auto list = createList();
    print_list(list);

    int n, m;
    cout << "Enter numbers N and M: " << endl;
    cin >> n >> m;

//    list.exerciseG20(n, m);
//    list.printList();

    return 0;
}
