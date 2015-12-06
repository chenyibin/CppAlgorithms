#include <unordered_map>
#include <iostream>

#include "longest_substring_no_repeated_char.h"

int LongestSubstringNoRepeatedChar::lengthOfLongestSubstring(std::string s)
{
    if (s.empty()) {
        return 0;
    }
    // Keep track of at what index we last saw this character
    // We could use an array here but I prefer having an
    // explicit map even if it is less efficient
    std::unordered_map<char, std::size_t> last_char_index;

    std::size_t max_length = 0;

    // Keep track of the length of the current
    // subsequence with no repeating characters
    std::size_t streak_length = 0;
    std::size_t streak_start = 0;

    for (std::size_t i = 0; i < s.length(); ++i) {
        // Since we need the index we'll use the classical for loop
        const char& character = s[i];

        // Let's see if we've seen this character before
        auto found_iter = last_char_index.find(character);
        if (found_iter != last_char_index.end()) {
            streak_length = i - streak_start;
            max_length = std::max(streak_length, max_length);

            std::size_t last_seen_index = found_iter->second;
            streak_start = std::max(last_seen_index + 1, streak_start);
        }
        last_char_index[character] = i;
    }
    streak_length = s.length() - streak_start;
    max_length = std::max(streak_length, max_length);
    return max_length;
}


