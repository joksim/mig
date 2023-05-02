#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::generate;
using std::cin;
using std::cout;
using std::max, std::min;


vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k);

vector<int> maxNumber(vector<int> nums, int k);

vector<int> maxNumber(vector<int> nums1, vector<int> nums2);

vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> best;
    for (int k1 = max(k - n2, 0); k1 <= min(k, n1); ++k1)
        best = max(best, maxNumber(maxNumber(nums1, k1),
                                   maxNumber(nums2, k - k1)));
    return best;
}

vector<int> maxNumber(vector<int> nums, int k) {
    int drop = nums.size() - k;
    vector<int> out;
    for (int num: nums) {
        while (drop && out.size() && out.back() < num) {
            out.pop_back();
            drop--;
        }
        out.push_back(num);
    }
    out.resize(k);
    return out;
}

vector<int> maxNumber(vector<int> nums1, vector<int> nums2) {
    vector<int> out;
    while (nums1.size() + nums2.size()) {
        vector<int> &now = nums1 > nums2 ? nums1 : nums2;
        out.push_back(now[0]);
        now.erase(now.begin());
    }
    return out;
}

int main() {
    vector<int> nums1;
    vector<int> nums2;
    int k;

    int n;
    char choice;

    cout << "Press:\n" << "g: generate\n" << "i: input numbers\n";
    cin >> choice;

    if (choice == 'g' || choice == 'G') {
        cout << "\n--nums1--";
        cout << "\nEnter number of integers to generate: ";
        cin >> n;
        nums1 = vector<int>(n);
        generate(nums1.begin(), nums1.end(), []() -> int { return rand() % 10; });

        cout << "\n--nums2--";
        cout << "\nEnter number of integers to generate: ";
        cin >> n;
        nums2 = vector<int>(n);
        generate(nums2.begin(), nums2.end(), []() -> int { return rand() % 10; });
    } else if (choice == 'i' || choice == 'I') {
        cout << "\n--nums1--";
        cout << "\nEnter the values, press 'q' to finish";
        while (true) {
            cin >> choice;
            if (choice >= '0' && choice <= '9') {
                nums1.push_back(choice - '0');
            } else if (choice == 'q' || choice == 'Q') {
                break;
            }
        }
        cout << "\n--nums2--";
        cout << "\nEnter the values, press 'q' to finish";
        while (true) {
            cin >> choice;
            if (choice >= '0' && choice <= '9') {
                nums2.push_back(choice - '0');
            } else if (choice == 'q' || choice == 'Q') {
                break;
            }
        }
    }

    cout<< "\n-- num1 -- \n";
    for (auto v: nums1){
        cout << v << ' ';
    }
    cout<< "\n-- num2 -- \n";
    for (auto v: nums2){
        cout << v << ' ';
    }

    cout << "\nEnter k: ";
    cin >> k;

    vector<int> max = maxNumber(nums1, nums2, k);
    for (auto v: max){
        cout << v << ' ';
    }

    return 0;
}

