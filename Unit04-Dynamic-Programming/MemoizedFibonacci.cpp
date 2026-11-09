#include <iostream>
#include <vector>

using namespace std;

// Helper function for memoized Fibonacci (Top-Down DP)
long long fibMemo(int n, vector<long long>& memo) {
    // Base cases
    if (n <= 1) return n;

    // If already calculated, return the stored result
    if (memo[n] != -1) return memo[n];

    // Otherwise, compute, store in memo table, and return
    return memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
}

// Wrapper function to initialize the memoization table
long long fibonacci(int n) {
    if (n < 0) return -1; // Edge case for negative numbers
    
    // Initialize memoization vector with -1 (indicating uncalculated states)
    vector<long long> memo(n + 1, -1);
    return fibMemo(n, memo);
}

int main() {
    int n = 50; // Using long long to handle larger Fibonacci numbers
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

    return 0;
}