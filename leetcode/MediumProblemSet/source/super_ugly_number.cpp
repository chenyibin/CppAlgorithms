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

    std::vector<std::pair<int,std::size_t>> ugly_candidates;
    for (auto prime : primes) {
        // each ugly candidate represents ([prime[i] * multiple, multiple)
        ugly_candidates.emplace_back(prime, 0);
    }

    ugly_numbers.push_back(1);
    while (ugly_numbers.size() < n) {
        // Find the smallest candidate
        int min_candidate = ugly_candidates[0].first;
        for (std::size_t i = 1; i < ugly_candidates.size(); ++i)
        {
            if (min_candidate > ugly_candidates[i].first) {
                min_candidate = ugly_candidates[i].first;
            }
        }

        ugly_numbers.push_back(min_candidate);

        // Update the candidates
        for (size_t j = 0; j < ugly_candidates.size(); ++j) {
            std::pair<int,std::size_t>& candidate = ugly_candidates[j];
            if (candidate.first == min_candidate) {
                candidate.first = primes[j] * ugly_numbers[++candidate.second];
            }
        }
    }
    return ugly_numbers[n-1];
}
