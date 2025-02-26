#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*

1.fstreambase
2.ifstream   (derived from 1st)
3.ofstream   (derived from 1st)

// Important: all these three libraries are derived from fstream class


*/
using namespace std;

// ifstream// iterates over the stram and skips the rest part of the line as soon as it encounters a space character

class Solution {
public:
    Solution(istream &inputStream) {
        string inputLine;
        while (getline(inputStream, inputLine)) { // Important: get line takes line by line input from the input treating 1 line at a time
            istringstream lineStream(inputLine);  // Important: It is used to tokenise each string into inputstream onbject "lineStream" is an object and we are converting inputLine(stirng) into lineStream(istringstream)
            string numberToken, extraToken;
            if (lineStream >> numberToken && !(lineStream >> extraToken)) { // Important: in each line it searches for only one token and if it encounters another token then it straightaway sets it to false as it is not valid stream
                if (isValidNumber(numberToken)) {
                    int parsedNumber = stoi(numberToken);
                    if (parsedNumber >= -1000000000 && parsedNumber <= 1000000000) {
                        numberList.push_back(parsedNumber);
                    }
                }
            }
        }
    }

    class NumberIterator {
    public:
        using iterator_category = input_iterator_tag;
        using value_type = int;
        using difference_type = ptrdiff_t;
        using pointer = int *;
        using reference = int &;

        NumberIterator(vector<int>::iterator it) : currentIterator(it) {}

        int operator*() const { return *currentIterator; }
        NumberIterator &operator++() {
            ++currentIterator;
            return *this;
        }
        bool operator!=(const NumberIterator &other) const { return currentIterator != other.currentIterator; }

    private:
        vector<int>::iterator currentIterator;
    };

    NumberIterator begin() { return NumberIterator(numberList.begin()); }
    NumberIterator end() { return NumberIterator(numberList.end()); }

private:
    vector<int> numberList;

    bool isValidNumber(const string &str) {
        if (str.empty() || str == "+" || str == "-")
            return false;
        if (str.size() > 1 && str[0] == '0' && str != "0")
            return false;
        if (str[0] == '+' || str[0] == '-') {
            return all_of(str.begin() + 1, str.end(), ::isdigit);
        }
        return all_of(str.begin(), str.end(), ::isdigit);
    }
};

// Example usage
int main() {
    istringstream input("00\n"
                        "0137\n"
                        "-104\n"
                        "2 58\n" // Invalid: multiple tokens
                        "+0\n"
                        "++3\n"
                        "+1\n"
                        "23.9\n"
                        "2000000000\n" // Invalid: out of range
                        "-0\n"
                        "five\n"
                        "-1\n");

    Solution sol(input);

    for (Solution::NumberIterator it = sol.begin(); it != sol.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}

// Feature	ifstream	istringstream
// Data Source	Reads from a file	Reads from a string
// Header	<fstream>	<sstream>
// Opening Required?	Yes (file.open())	No, initializes directly with a string
// Closing Required?	Yes (file.close())	No
// Use Case	Reading files from disk	Parsing strings or processing input stored in a variable