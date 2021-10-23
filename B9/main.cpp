#include <iostream>
#include <fstream>

using namespace std;

int lineNumWithMostDigits(string filename) {
    string line;
    auto maxSize = 0ull;
    int numLine = 0;
    ifstream file(filename);
    for (int curLine = 0; getline(file, line); ++curLine) {
        if (line.size() > maxSize) {
            numLine = curLine;
            maxSize = line.size();
        }
    }
    file.close();
    return numLine;
}

int main() {
    cout << lineNumWithMostDigits("../test.txt") << endl;
    return 0;
}
