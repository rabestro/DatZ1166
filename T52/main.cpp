#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using std::vector;
using std::pair;

// Programming task Team

// Participant determines a team member, followed by the people he invites - a woman and a man.
std::map<unsigned, pair<unsigned, unsigned>> participants;

// The trust level
vector<vector<unsigned>> levels;

// The greater the "distance to person", the less you trust it.
void setLevel(unsigned parent, unsigned level) {
    if (parent == 0u) return;
    if (level >= levels.size()) {
        levels.push_back({parent});
    } else {
        levels[level].push_back(parent);
    }
    ++level;
    auto invited = participants.find(parent)->second;
    setLevel(invited.first, level);
    setLevel(invited.second, level);
}

// The complexity of the algorithm is O(n*log(n))
// Memory consumption is O(n)
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

    // Find the team leader
    auto leader = 0u;
    for (auto person: participants) {
        if (children.find(person.first) == children.end()) {
            leader = person.first;
            break;
        }
    }

    // Team leader has the highest level of trust, marked by integer 0.
    setLevel(leader, 0);

    // The team members are grouped in the output according to the "trust levels"
    std::ofstream outFile("team.out");
    for (auto level = levels.size(); level-- > 0;) {
        outFile << level << ": ";
        for (auto person: levels[level]) outFile << person << " ";
        outFile << std::endl;
    }
    outFile.close();
    return 0;
}


