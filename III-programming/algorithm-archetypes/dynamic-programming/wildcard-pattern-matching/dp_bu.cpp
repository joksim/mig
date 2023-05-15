#include <iostream>
#include <string>
using namespace std;

// Function that matches the input string with a given wildcard pattern
bool isMatch(string word, string pattern)
{
    // get the length of string and wildcard pattern
    int n = word.length();
    int m = pattern.length();

    // create a DP lookup table
    // all elements are initialized by false by default
    bool T[n+1][m+1];

    // if both pattern and string are empty: match
    T[0][0] = true;

    // handle empty string case (i == 0)
    for (int j = 1; j <= m; j++)
    {
        if (pattern[j-1] == '*') {
            T[0][j] = T[0][j-1];
        }
    }

    // build a matrix in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[j-1] == '*') {
                T[i][j] = T[i-1][j] || T[i][j-1];
            }
            else if (pattern[j-1] == '?' || word[i-1] == pattern[j-1]) {
                T[i][j] = T[i-1][j-1];
            }
        }
    }

    // last cell stores the answer
    return T[n][m];
}

// Wildcard Pattern Matching Implementation in C
int main()
{
    string word = "xyxzzxy";
    string pattern = "x***x?";

    if (isMatch(word, pattern)) {
        cout << "Match" << endl;
    }
    else {
        cout << "No Match" << endl;
    }

    return 0;
}
