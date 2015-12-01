#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int best_h_Index = 0;
        int papers_with_more_citations_than_best = 0;
        size_t num_papers = citations.size();

        // Counts the number of papers with number of citations x
        // where x is the index of the array
        // The paper counter is of size num_papers + 1 since we are
        // storing all papers with citations >= num_papers at index num_papers
        int paper_counter[num_papers + 1] = {0};
        for (int num_citations : citations) {
            // Ignore anything that has fewer citations
            // than our currently best HIndex
            if (num_citations < best_h_Index) {
                continue;
            }
            // Update the paper counter - note that we must updated
            // the paper counter for the current best HIndex
            if (num_citations < num_papers) {
                ++paper_counter[num_citations];
            } else {
                ++paper_counter[num_papers];
            }

            if (num_citations > best_h_Index) {
                ++papers_with_more_citations_than_best;
                if (best_h_Index < papers_with_more_citations_than_best) {
                    ++best_h_Index;
                    papers_with_more_citations_than_best -= paper_counter[best_h_Index];
                }
            }
        }
        return best_h_Index;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}