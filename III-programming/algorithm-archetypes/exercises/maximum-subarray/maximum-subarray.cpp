#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>
#include "../../../util/generate/generate.h"

using std::vector;
using std::max;
using std::cin, std::cout;

int maxSubArray_bf(vector<int> &nums);

int maxSubArray_dq(vector<int> &nums);
int maxSubArray_dq(vector<int> &A, int L, int R);

int maxSubArray_dq1(vector<int> &A, int L, int R);
int maxSubArray_dq1(vector<int> &nums);

int maxSubArray_dp(vector<int> &nums);

//////////////////////////////////////////////////////////////////////////
// Brute Force
//////////////////////////////////////////////////////////////////////////
int maxSubArray_bf(vector<int> &nums) {
    int n = size(nums), ans = INT_MIN;
    for (int i = 0; i < n; i++)
        for (int j = i, curSum = 0; j < n; j++)
            curSum += nums[j],
                    ans = max(ans, curSum);
    return ans;
}

//////////////////////////////////////////////////////////////////////////
// Divide & Conquer
//////////////////////////////////////////////////////////////////////////
int maxSubArray_dq(vector<int> &nums) {
    return maxSubArray_dq(nums, 0, size(nums) - 1);
}

int maxSubArray_dq(vector<int> &A, int L, int R) {
    if (L > R) return INT_MIN;
    int mid = (L + R) / 2, leftSum = 0, rightSum = 0;
    // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
    for (int i = mid - 1, curSum = 0; i >= L; i--)
        curSum += A[i],
                leftSum = max(leftSum, curSum);
    // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
    for (int i = mid + 1, curSum = 0; i <= R; i++)
        curSum += A[i],
                rightSum = max(rightSum, curSum);
    // return max of 3 cases
    return max({maxSubArray_dq(A, L, mid - 1), maxSubArray_dq(A, mid + 1, R), leftSum + A[mid] + rightSum});
}

//////////////////////////////////////////////////////////////////////////
// Optimized Divide & Conquer
//////////////////////////////////////////////////////////////////////////

vector<int> pre, suf; //Global vectors

int maxSubArray_dq1(vector<int> &nums) {
    pre = suf = nums;
    for (int i = 1; i < size(nums); i++) pre[i] += max(0, pre[i - 1]);
    for (int i = size(nums) - 2; ~i; i--) suf[i] += max(0, suf[i + 1]);
    return maxSubArray_dq1(nums, 0, size(nums) - 1);
}

int maxSubArray_dq1(vector<int> &A, int L, int R) {
    if (L == R) return A[L];
    int mid = (L + R) / 2;
    return max({maxSubArray_dq1(A, L, mid), maxSubArray_dq1(A, mid + 1, R), pre[mid] + suf[mid + 1]});
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Dynamic programming with memoization
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int solve(vector<int> &A, int i, bool mustPick, vector<vector<int>> &dp) {
    if (i >= size(A)) return mustPick ? 0 : -1e5;
    if (dp[mustPick][i] != -1) return dp[mustPick][i];
    if (mustPick)
        return dp[mustPick][i] = max(0, A[i] + solve(A, i + 1, true, dp));
    return dp[mustPick][i] = max(solve(A, i + 1, false, dp), A[i] + solve(A, i + 1, true, dp));
}

int maxSubArray_dp_memo(vector<int> &nums) {
    vector<vector<int>> dp(2, vector<int>(size(nums), -1));
    return solve(nums, 0, false, dp);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MAIN
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    char choice;
    uint number;
    vector<int> nums;
    cout << "Press:\n" << "g: generate\n" << "i: input numbers\n";
    cin >> choice;

    if (choice == 'g' || choice == 'G') {
        cout << "\nEnter number of integers to generate: ";
        cin >> number;
        nums = MIG::generate_random_vector_values(10000);
    } else if (choice == 'i' || choice == 'I') {

        cout << "\nEnter the values, press 'q' to finish";
        int number;
        while (true) {
            cin >> choice;
            if (choice == 'q' || choice == 'Q')
                break;

            cin.putback(choice);

            if (!(cin >> number))
                break;
            nums.push_back(number);
        }
    }

        cout << "Input is:\n";

        for (auto n: nums)
            cout << n << " ";

        int result;

        using namespace std::chrono;
        using namespace std;

        // brute force
        auto start = high_resolution_clock::now();
        result = maxSubArray_bf(nums);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nBrute force:" << "\nResult: " << result << "\nTime: " << duration.count() << "ms" << std::endl;

        // Dividie & conquer
        start = high_resolution_clock::now();
        result = maxSubArray_dq(nums);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "\nDivide & Conquer:" << "\nResult: " << result << "\nTime: " << duration.count() << "ms" << std::endl;

        // Optimized Divide & Conquer
        start = high_resolution_clock::now();
        result = maxSubArray_dq1(nums);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "\nOptimized Divide & Conquer:" << "\nResult: " << result << "\nTime: " << duration.count() << "ms"
             << std::endl;
    }
