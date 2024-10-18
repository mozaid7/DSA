#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int wordToDigit(const string &word) {
    map<string, int> wordToNum = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };
    
    if (wordToNum.find(word) != wordToNum.end()) {
        return wordToNum[word];
    } else {
        return -1;
    }
}

int convertWordToNumber(const string &numWord) {
    int number = 0;
    string currentWord = "";
    for (char c : numWord) {
        if (c == 'c') {
            int digit = wordToDigit(currentWord);
            if (digit == -1) return -1; 
            number = number * 10 + digit; 
            currentWord = ""; 
        } else {
            currentWord += c;
        }
    }
    return number;
}

int evaluateOperation(const string &operation, int operand1, int operand2) {
    if (operation == "add") return operand1 + operand2;
    else if (operation == "sub") return operand1 - operand2;
    else if (operation == "mul") return operand1 * operand2;
    else if (operation == "rem") return operand1 % operand2;
    else if (operation == "pow") return pow(operand1, operand2);
    else return -1;
}

void evaluateExpression(const string &input) {
    stringstream ss(input);
    vector<string> tokens;
    string word;

    while (ss >> word) {
        tokens.push_back(word);
    }

    if (tokens.size() < 3) {
        cout << "expression is not complete or invalid" << endl;
        return;
    }

    if (tokens.size() == 3) {
        string operation = tokens[0];
        int operand1 = convertWordToNumber(tokens[1]);
        int operand2 = convertWordToNumber(tokens[2]);

        if (operand1 == -1 || operand2 == -1) {
            cout << "expression evaluation stopped invalid words present" << endl;
            return;
        }

        int result = evaluateOperation(operation, operand1, operand2);
        if (result == -1) {
            cout << "expression is not complete or invalid" << endl;
        } else {
            cout << result << endl;
        }
    } else if (tokens.size() == 5) {
        string operation1 = tokens[0];
        string operation2 = tokens[1];
        int operand1 = convertWordToNumber(tokens[2]);
        int operand2 = convertWordToNumber(tokens[3]);
        int operand3 = convertWordToNumber(tokens[4]);

        if (operand1 == -1 || operand2 == -1 || operand3 == -1) {
            cout << "expression evaluation stopped invalid words present" << endl;
            return;
        }

        int intermediateResult = evaluateOperation(operation2, operand2, operand3);
        if (intermediateResult == -1) {
            cout << "expression is not complete or invalid" << endl;
            return;
        }

        int finalResult = evaluateOperation(operation1, operand1, intermediateResult);
        if (finalResult == -1) {
            cout << "expression is not complete or invalid" << endl;
        } else {
            cout << finalResult << endl;
        }
    } else if (tokens.size() == 6) {
        string operation1 = tokens[0];
        int operand1 = convertWordToNumber(tokens[1]);
        string operation2 = tokens[2];
        int operand2 = convertWordToNumber(tokens[3]);
        int operand3 = convertWordToNumber(tokens[4]);

        if (operand1 == -1 || operand2 == -1 || operand3 == -1) {
            cout << "expression evaluation stopped invalid words present" << endl;
            return;
        }

        int intermediateResult = evaluateOperation(operation2, operand2, operand3);
        if (intermediateResult == -1) {
            cout << "expression is not complete or invalid" << endl;
            return;
        }

        int finalResult = evaluateOperation(operation1, operand1, intermediateResult);
        if (finalResult == -1) {
            cout << "expression is not complete or invalid" << endl;
        } else {
            cout << finalResult << endl;
        }
    } else {
        cout << "expression is not complete or invalid" << endl;
    }
}

int main() {
    string input;
    getline(cin, input);
    evaluateExpression(input);
    return 0;
}
