#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to determine if a string can be segmented into space-separated
// sequence of one or more dictionary words
bool wordBreak(vector<string> const &dict, string word)
{
    // return true if the end of the string is reached
    if (word.size() == 0) {
        return true;
    }

    for (int i = 1; i <= word.size(); i++)
    {
        // consider all prefixes of the current string
        string prefix = word.substr(0, i);

        // return true if the prefix is present in the dictionary and the remaining
        // string also forms a space-separated sequence of one or more
        // dictionary words

        if (find(dict.begin(), dict.end(), prefix) != dict.end() &&
                wordBreak(dict, word.substr(i))) {
            return true;
        }
    }

    // return false if the string can't be segmented
    return false;
}

// Word Break Problem Implementation in C++
int main()
{
    // vector of strings to represent a dictionary
    // we can also use a Trie or a set to store a dictionary

    vector<string> dict = { "this", "th", "is", "famous", "Word", "break",
            "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

    // input string
    string word = "Wordbreakproblem";

    if (wordBreak(dict, word)) {
        cout << "The string can be segmented";
    }
    else {
        cout << "The string can't be segmented";
    }

    return 0;
}
