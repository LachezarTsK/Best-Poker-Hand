
public class Solution {

    private static final int[] RANKS_RANGE = {1, 13};
    private static final int NUMBER_OF_CARDS_IN_POKER_HAND = 5;

    public String bestHand(int[] ranks, char[] suits) {

        int[] frequcyInRanks = new int[RANKS_RANGE[1] + 1];
        int maxFrequcyInRanks = 0;
        boolean flush = true;

        for (int i = 0; i < NUMBER_OF_CARDS_IN_POKER_HAND; ++i) {
            flush = flush && (suits[i] == suits[0]);
            maxFrequcyInRanks = Math.max(maxFrequcyInRanks, ++frequcyInRanks[ranks[i]]);
        }

        return flush ? "Flush"
               : maxFrequcyInRanks >= 3 ? "Three of a Kind"
               : maxFrequcyInRanks == 2 ? "Pair"
               : "High Card";
    }
}
