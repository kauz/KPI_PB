#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_prime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> fibonacci_sequence(int limit) {
    vector<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    while (sequence.back() < limit) {
        int next_number = sequence[sequence.size()-1] + sequence[sequence.size()-2];
        sequence.push_back(next_number);
    }
    return sequence;
}

int* find_matching_integers(int n) {
    vector<int> fib_sequence = fibonacci_sequence(n);
    int* primes = new int[n+1];
    for (int i = 0; i <= n; i++) {
        primes[i] = 0;
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            // Check if the number is in the Fibonacci sequence
            if (binary_search(fib_sequence.begin(), fib_sequence.end(), i)) {
                primes[i] = i;
            }
            // Check if the number is of the form q^2 + 1
            for (int q = 1; q*q < i; q++) {
                if (i == q*q + 1) {
                    primes[i] = i;
                }
            }
        }
    }
    return primes;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int* primes = find_matching_integers(n);
    cout << "Prime numbers in the range [2, " << n << "] that are numbers of the Fibonacci sequence or numbers of the form q^2 + 1:" << endl;
    for (int i = 2; i <= n; i++) {
        if (primes[i] != 0) {
            cout << primes[i] << " ";
        }
    }
    cout << endl;
    delete[] primes;
    return 0;
}