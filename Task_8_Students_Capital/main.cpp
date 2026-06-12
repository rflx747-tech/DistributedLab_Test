#include <iostream>
#include <vector>
using namespace std;

int calculateMaxCapital(int N, int C, const vector<int>& gains, const vector<int>& prices) {
    int K = gains.size();                                   // Total number of laptops
    int current_capital = C;                                // Start with initial capital
    
    vector<bool> used(K, false);                            // Track fixed laptops

    for (int step = 0; step < N; ++step) {                  // Fix up to N laptops
        int best_gain = -1;                                 // Max profit in current step
        int best_laptop_index = -1;                         // Index of the best laptop

        for (int i = 0; i < K; ++i) {                       // Check all laptops

            if (!used[i] && prices[i] <= current_capital) { // If not used and affordable

                if (gains[i] > best_gain) {                 // If it gives better profit
                    best_gain = gains[i];                   // Update best profit
                    best_laptop_index = i;                  // Save laptop index
                }
            }
        }
        
        if (best_laptop_index == -1)                        // Stop if nothing is affordable
            break; 
        
        used[best_laptop_index] = true;                     // Mark laptop as fixed
        current_capital += best_gain;                       // Add profit to capital
    }

    return current_capital;                                 // Return final amount
}

int main() {
    int N, C, K;
    
    cout << "Enter N (max laptops to fix) and C (initial capital): ";
    if (!(cin >> N >> C))                                   // Handle invalid input
        return 0;

    cout << "Enter K (total number of available laptops): ";
    cin >> K;

    vector<int> gains(K);
    cout << "Enter " << K << " values for gains array (separated by space): ";
    for (int i = 0; i < K; ++i)                             // Read gains
        cin >> gains[i];
    
    vector<int> prices(K);
    cout << "Enter " << K << " values for price array (separated by space): ";
    for (int i = 0; i < K; ++i)                             // Read prices
        cin >> prices[i];
    
    cout << "\nCapital at the end of the summer: " << calculateMaxCapital(N, C, gains, prices) << endl;
    
    return 0;
}