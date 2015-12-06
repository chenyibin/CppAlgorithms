#include <unordered_set>
#include <vector>

#include "super_ugly_number.h"

int SuperUglyNumber::nthSuperUglyNumber(int n, std::vector<int>& primes)
{
    if (n == 1 || primes.empty()) {
        return 1;
    }
    // Storage for all the ugly numbers from 1 to n
    std::vector<int> ugly_numbers;
    ugly_numbers.reserve(n);

    std::unordered_set<int> ugly_numbers_set;

    std::vector<int> ugly_candidates = primes;
    std::vector<std::size_t> prime_indices(primes.size(), 0);

    ugly_numbers.push_back(1);
    while (ugly_numbers.size() < n) {
        int min_candidate = ugly_candidates[0];
        int min_index = 0;
        for (std::size_t j = 1; j < ugly_candidates.size(); ++j)
        {
            if (min_candidate > ugly_candidates[j]) {
                min_index = j;
                min_candidate = ugly_candidates[j];
            }
        }

        if (ugly_numbers_set.find(min_candidate) == ugly_numbers_set.end()) {
            ugly_numbers_set.insert(min_candidate);
            ugly_numbers.push_back(min_candidate);
        }

        // Update the used candidate
        ugly_candidates[min_index] = ugly_numbers[++prime_indices[min_index]] * primes[min_index];
    }
    return ugly_numbers[n-1];
}
