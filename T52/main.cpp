#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using std::vector;
using std::pair;

std::map<unsigned, pair<unsigned, unsigned>> participants;
vector<vector<unsigned>> levels = {};

void setLevel(unsigned int parent, unsigned level) {
    if (level >= levels.size()) {
        levels.push_back({parent});
    } else {
        levels[level].push_back(parent);
    }
    auto invited = participants.find(parent)->second;
    ++level;
    if (invited.first > 0u) setLevel(invited.first, level);
    if (invited.second > 0u) setLevel(invited.second, level);
}

int main() {
    std::set<unsigned> children;

    // Read the participants. They are given in an arbitrary order.
    std::ifstream inFile("team.in");
    for (;;) {
        unsigned id, woman, man;
        inFile >> id >> woman >> man;
        if (id == 0u) break;

        participants.insert({id, {woman, man}});
        if (woman > 0u) children.insert(woman);
        if (man > 0u) children.insert(man);
    }
    inFile.close();

    // Find the leader
    auto leader = 0u;
    for (auto person: participants) {
        if (children.find(person.first) == children.end()) {
            leader = person.first;
            break;
        }
    }

    // Calculate the levels
    setLevel(leader, 0);

    // Write result to file
    std::ofstream outFile("team.out");
    for (auto level = levels.size(); level-- > 0;) {
        outFile << level << ": ";
        for (auto person: levels[level]) outFile << person << " ";
        outFile << std::endl;
    }
    outFile.close();
    return 0;
}


