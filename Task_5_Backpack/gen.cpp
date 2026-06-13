#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    ofstream file("transactions.csv");                 // Create a new CSV file
    file << "tx_id,tx_size,tx_fee\n";                  // Write the required header

    srand(time(0));                                    // Seed the random number generator

    for (int i = 1; i <= 100000; i++) {                // Generate 100,000 transactions
        int size = rand() % 2000 + 50;                 // Random size: 50 to 2049 bytes
        int fee = rand() % 10000 + 10;                 // Random fee: 10 to 10009 satoshies
        
        file << "tx_random_" << i << "," << size << "," << fee << "\n"; // Save to file
    }

    file.close();                                      // Close the file
    cout << "transactions.csv with 100,000 rows generated.\n"; // Print success message
    return 0;
}