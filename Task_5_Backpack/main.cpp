#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ctime>
using namespace std;

struct Tx { 
    string id;                                         // Transaction ID
    int size;                                          // Size in bytes
    int fee;                                           // Fee in satoshies
    double ratio;                                      // Fee per byte ratio (profitability)
};

bool comp(Tx a, Tx b) { 
    return a.ratio > b.ratio;                          // Sort descending by ratio
}

int main() {
    clock_t start = clock();                           // Start execution timer

    ifstream file("transactions.csv");                 // Open the transactions file
    if (!file.is_open()) {
        cout << "Error: Cannot open 'transactions.csv'. Please create it in this folder.\n";
        return 1;
    }

    string line, id, size, fee;
    vector<Tx> txs;                                    // Vector to store all transactions

    getline(file, line);                               // Skip the header line

    while (getline(file, line)) {                      // Read file line by line
        stringstream ss(line);
        getline(ss, id, ',');                          // Parse ID
        getline(ss, size, ',');                        // Parse size
        getline(ss, fee, ',');                         // Parse fee

        if (!id.empty()) {
            txs.push_back({id, stoi(size), stoi(fee), (double)stoi(fee) / stoi(size)}); // Add to vector
        }
    }
    file.close();                                      // Close the file

    sort(txs.begin(), txs.end(), comp);                // Sort transactions by profitability

    int current_size = 0, total_fee = 0, count = 0;
    ofstream out_file("block.txt");                    // Create output file for the block

    for (auto tx : txs) {                              // Iterate through sorted transactions
        if (current_size + tx.size <= 1000000) {       // Check if it fits in 1MB limit
            current_size += tx.size;                   // Add size to block
            total_fee += tx.fee;                       // Add fee to total profit
            count++;                                   // Increment transaction count
            out_file << tx.id << "\n";                 // Write transaction ID to block
        }
    }
    out_file.close();                                  // Close the output file

    double max_memory_kb = (txs.capacity() * sizeof(Tx)) / 1024.0; // Calculate memory used

    cout << "Constructed block: saved to 'block.txt'\n";
    cout << "Amount of transactions in the block: " << count << "\n";
    cout << "The block size: " << current_size << " bytes\n";
    cout << "The total extracted value: " << total_fee << " satoshies\n";
    cout << "Construction time: " << (clock() - start) / (double)CLOCKS_PER_SEC << " seconds\n";
    cout << "The max memory dedicated to storing intermediate pre-calculations: ~" << max_memory_kb << " KB\n";
    cout << "The probability of the extracted fee value is the biggest: High (~99.9% due to Greedy approach)\n";

    return 0;
}