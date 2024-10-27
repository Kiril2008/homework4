#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void compFile(const string& file1, const string& file2) {
    ifstream f1(file1), f2(file2);
    string line1, line2;
    int lineNum = 1;

    while (getline(f1, line1) || getline(f2, line2)) {
        if (line1 != line2) {
            cout << "Line " << lineNum << " differs:\n";
            cout << file1 << ": " << line1 << "\n";
            cout << file2 << ": " << line2 << "\n";
        }
        lineNum++;
        line1.clear();
        line2.clear();
    }

    f1.close();
    f2.close();
}

int main() {
    compFile("file1.txt", "file2.txt");
    return 0;
}
