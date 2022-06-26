#include <iostream>
#include <string>
#include <sstream>
#include <set>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::multiset<int> seq;
    int num;
    while (ss >> num) {
        seq.insert(num);
    }

    for (auto i : seq) {
        std::cout << i << ' ';
    }

    return 0;
}