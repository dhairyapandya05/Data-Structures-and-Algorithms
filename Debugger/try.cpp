#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(istream &inputStream) {
        string inputLine;
        while (getline(inputStream, inputLine)) {
            istringstream lineStream(inputLine);
            string numberToken, extraToken;
            if (lineStream >> numberToken && !(lineStream >> extraToken)) {
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