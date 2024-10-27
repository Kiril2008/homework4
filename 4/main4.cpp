#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findLongestLine(const string& file) {
    ifstream inFile(file);
    string line;
    size_t maxLength = 0;

    while (getline(inFile, line)) {
        if (line.length() > maxLength) {
            maxLength = line.length();
        }
    }

    inFile.close();
    return maxLength;
}

int main() {
    int longestLength = findLongestLine("longest.txt");
    cout << "Довжина найдовшого рядка: " << longestLength << endl;
    return 0;
}
