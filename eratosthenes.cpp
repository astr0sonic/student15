#include "eratosthenes.h"
#include <vector>

std::vector<int> sieve(int n) {
    std::vector<int> primes;
	std::vector<bool> a(n + 1, 1);
	for (int i = 2; i * i <= n; i++) {
		if (a[i]) {
			for (int j = i * i; j < n + 1; j += i) a[j] = 0;
		}
	}

	for (int i = 0; i <= n; i++)
		if (a[i])
			primes.push_back(i);
    return primes;
}
