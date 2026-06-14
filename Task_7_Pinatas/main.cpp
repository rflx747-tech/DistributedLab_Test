#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCandies(vector<int>& pinatas) {

    int n = pinatas.size();                           // Get array size
    vector<int> vals(n + 2, 1);                       // New array with "1" at both ends
    for (int i = 0; i < n; i++) 
        vals[i + 1] = pinatas[i];                     // Copy original values
    
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)); // Create 2D array for DP

    for (int len = 1; len <= n; len++) {              // Segment length
        for (int i = 1; i <= n - len + 1; i++) {      // Start index
            int j = i + len - 1;                      // End index
            
            for (int k = i; k <= j; k++) {            // Find the best last element to burst
                int left_part = dp[i][k - 1];         // Max candies from left side
                int current_hit = vals[i - 1] * vals[k] * vals[j + 1]; // Candies for current hit
                int right_part = dp[k + 1][j];        // Max candies from right side
                
                dp[i][j] = max(dp[i][j], left_part + current_hit + right_part); // Save max result
            }
        }
    }
    return dp[1][n];                                  // Return final result
}

int main() {
    int n;
    cout << "Enter the number of pinatas: ";
    if (!(cin >> n) || n <= 0)                        // Input validation
        return 0; 
    
    vector<int> pinatas(n);                           // Create an array of size n
    cout << "Enter the array of nums: ";
    for (int i = 0; i < n; i++) 
        cin >> pinatas[i];                            // Read input loop
    
    cout << "Max amount of candies: ";
    cout << maxCandies(pinatas) << endl;              // Calculate and print
    
    return 0;
}