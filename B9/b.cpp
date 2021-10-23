#include <iostream>
#include <fstream>

using namespace std;
/*
 * B[9]. Given text file.
 *
 * Write program in C++ to process the file line by line.
 * It’s allowed to use C++-style character strings.
 * Function, which calculates number of the line (numbering starts with 0)
 * with the biggest amount of digits in it.
 *
 * Example (with // to denote newline).
 * File: “A123B4.//56c789-0//12x345”,
 * answer 1.
 * Comment. Amounts of digits per line: 4,6,5.
 */
int lineNumWithMostDigits(string filename) {
    ifstream file(filename);
    string line;
    auto maxSize = 0ull;
    int numLine = 0;

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
