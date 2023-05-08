#include <iostream>
#include <vector>
#include <string>



using std::cin, std::cout;
using std::vector;
using std::string;

int main() {
    vector <int> nums;
    char choice;
    int number;
    while (true)
    {
        cin >> choice; // note: it's important to discard whitespace


        if (choice == 'q' || choice == 'Q')
            break;

        cin.putback(choice);

        if (!(cin >> number))
            break; // note: exit on error

        nums.push_back(number);
    }
    for (auto n : nums)
        cout << n << " ";

}