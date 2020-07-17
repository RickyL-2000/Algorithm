#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= (int)sqrt((double)n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    if (N < 5) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> primes;
    int n;
    for (n = 2; n <= N; n++) {
        if (isPrime(n)) {
            primes.push_back(n);
        }
    }
    int sum = 0;
    for (int i = 0; i < primes.size()-1; i++) {
        if (primes[i+1] - primes[i] == 2) {
            sum++;
        }
    }
    cout << sum;
    return 0;
}