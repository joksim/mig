#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::vector;
using std::string;
using std::cin, std::cout;

int longestPalindrome_umap(string s) {
    std::unordered_map<char,int> mp;
    for(auto&i:s) mp[i]++;

    int evenLen=0, longestPalindrome=0 , oddLen=0;
    bool visited=0;
    for(auto&it:mp){
        int freq = it.second ;

        //take all freq if even number of times
        if(!(freq&1)){
            evenLen+=freq;
        }
        else if(freq&1){
            //a->3,b->5,c->7 --> take c (7) all and rest freq-1 times i.e a->2 and b->4 , take max one time and left one freq-1 times
            visited=1;
            oddLen+=freq-1;
        }
    }

    longestPalindrome = evenLen;

    if(visited){
        longestPalindrome+=oddLen+1; //+1 bcs max freq was taken freq-1 times above so make it freq times
    }

    return longestPalindrome;

}

int longestPalindrome_array(string s) {
    //Get every character frequency in an array
    vector<int> freqCount(128); // working with the lower ASCII subset
    for (char c : s)
        freqCount[c]++;

    /* Get how many characters have an odd frequency.*/
    /* because of the exception that
one character may have odd frequency, we will set oddCount to -1 */
    int oddCount = -1;
    for (int v : freqCount) {
        if (v % 2) oddCount++;
    }
    /* Return your the number of all characters -
the number of characters that appear an odd number of times. */
    // if there is no letter with odd frequency return full length
    return (oddCount > 0) ? s.length() - oddCount: s.length();
}

int main(){
   string input;

    cin >> input;

    cout<< "\nLongest palindrome length using array is: " <<longestPalindrome_array(input);
    cout<< "\nLongest palindrome length using unordered map is: " <<longestPalindrome_umap(input);

    return 0;
}

