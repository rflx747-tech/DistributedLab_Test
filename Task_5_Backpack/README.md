How to run:

1. Compile the application and test data generator:
    make

2. Run the test data generator:
    ./gen

3. Run the application:
    ./app

4. Clean build files:
    make clean 

Additional info:

1. I used a greedy algorithm to solve this task because it is fast and practical. The main idea is to calculate the fee-per-byte ratio for every transaction and then pick the most profitable ones first.

2. My solution is classified as O(N log N) for time complexity and O(N) for space complexity. The time complexity is O(N log N) because the heaviest operation in the code is sorting the transactions by their profitability ratio using the built-in sort function. Reading the file and picking the items only takes linear time O(N), so the sorting step defines the overall speed. The space complexity is O(N) because I save all the parsed transactions in a standard vector, which takes memory exactly proportional to the number of input rows.

