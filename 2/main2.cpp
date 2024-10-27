#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

bool Vowel(char ch) {
    string vowels = "аеєиіїоуюяАЕЄИІЇОУЮЯaeiefdfsdgsdfuyDGFJSBCEFAEFAEFY";
    return vowels.find(ch) != string::npos;
}

bool Consonanta(char ch) {
    string consonants = "бвгґджзйклмнпрстфхцчшщБВГҐДЖЗЙКЛМНПРСТФХЦЧШЩbcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    return consonants.find(ch) != string::npos;
}

void fileStatistika(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    
    int numChars = 0, numLines = 0, numVowels = 0, numConsonants = 0, numDigits = 0;
    char ch;

    while (inFile.get(ch)) {
        numChars++;
        if (ch == '\n') numLines++;
        else if (Vowel(ch)) numVowels++;
        else if (Consonanta(ch)) numConsonants++;
        else if (isdigit(ch)) numDigits++;
    }
    numLines++; // Для останнього рядка

    outFile << "Кількість символів: " << numChars << "\n";
    outFile << "Кількість рядків: " << numLines << "\n";
    outFile << "Кількість голосних: " << numVowels << "\n";
    outFile << "Кількість приголосних: " << numConsonants << "\n";
    outFile << "Кількість цифр: " << numDigits << "\n";

    inFile.close();
    outFile.close();
}

int main() {
    fileStatistika("inputt.txt", "outputt.txt");
    return 0;
}
