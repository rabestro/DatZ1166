# Lab. F18

Create program in C++ to process text files. Reading from files should be carried out line per line. It is no allowed to store copy of the contents of file in the memory. For details see Lab requirements.

F18. Create program to read given text file and print into another text file number of words by length. Count all one-letter words, all two-letter words, all three-letter words, ... and print number of words into output file. Word in input file is string separated with space or separators like  dot . or comma , or brackets ( ) or exclamation mark ! or question mark ? or end of line.

The solution below split words only be space and it doesn't work correctly. 

```cpp
#include <map>
#include <string>
#include <iostream>
int main() {
  std::map<int, int> map;
  for (std::string word; std::cin >> word;) ++map[word.size()];
  for (auto& i : map) std::cout << i.first << ": " << i.second << '\n';
}
```
