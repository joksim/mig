#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Function to determine if a string can be segmented into space-separated
// sequence of one or more dictionary words
bool wordBreak(unordered_set<string> const &dict, string word, vector<int> &lookup)
{
    // `n` stores length of the current substring
    int n = word.size();

    // return true if the end of the string is reached
    if (n == 0) {
        return true;
    }

    // if the subproblem is seen for the first time
    if (lookup[n] == -1)
    {
        // mark subproblem as seen (0 initially assuming string
        // can't be segmented)
        lookup[n] = 0;

        for (int i = 1; i <= n; i++)
        {
            // consider all prefixes of the current string
            string prefix = word.substr(0, i);

            // if the prefix is found in the dictionary, then recur for the suffix
            if (find(dict.begin(), dict.end(), prefix) != dict.end() &&
                wordBreak(dict, word.substr(i), lookup))
            {
                // return true if the string can be segmented
                return lookup[n] = 1;
            }
        }
    }

    // return solution to the current subproblem
    return lookup[n];
}

// Word Break Problem Implementation in C++
int main()
{
    // set of strings to represent a dictionary
    // we can also use a Trie or a vector to store a dictionary
    unordered_set<string> dict = { "this", "th", "is", "famous", "Word", "break",
            "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

    // input string
    string word = "Wordbreakproblem";

    // lookup array to store solutions to subproblems
    // lookup[i] stores if substring word[n-i…n) can be segmented or not
    vector<int> lookup(word.length() + 1, -1);

    if (wordBreak(dict, word, lookup)) {
        cout << "The string can be segmented";
    }
    else {
        cout << "The string can't be segmented";
    }

    return 0;
}
