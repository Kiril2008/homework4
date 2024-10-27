#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void removeLastLine(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    vector<string> lines;
    string line;

    while (getline(inFile, line)) {
        lines.push_back(line);
    }
    
    for (size_t i = 0; i < lines.size() - 1; ++i) {
        outFile << lines[i] << "\n";
    }

    inFile.close();
    outFile.close();
}

int main() {
    removeLastLine("input1.txt", "output2.txt");
    return 0;
}
