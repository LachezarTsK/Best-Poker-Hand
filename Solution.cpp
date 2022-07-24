
#include <array>
#include <vector>
using namespace std;

class Solution {
    
    inline static constexpr array<int, 2> RANKS_RANGE {1, 13};
    inline static const int NUMBER_OF_CARDS_IN_POKER_HAND = 5;

public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {

        array<int, RANKS_RANGE[1] + 1 > frequcyInRanks{};
        int maxFrequcyInRanks = 0;
        bool flush = true;

        for (int i = 0; i < NUMBER_OF_CARDS_IN_POKER_HAND; ++i) {
            flush = flush && (suits[i] == suits[0]);
            maxFrequcyInRanks = max(maxFrequcyInRanks, ++frequcyInRanks[ranks[i]]);
        }

        return flush ? "Flush"
               : maxFrequcyInRanks >= 3 ? "Three of a Kind"
               : maxFrequcyInRanks == 2 ? "Pair"
               : "High Card";
    }
};
