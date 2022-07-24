
/**
 * @param {number[]} ranks
 * @param {character[]} suits
 * @return {string}
 */
var bestHand = function (ranks, suits) {
    const RANKS_RANGE = [1, 13];
    const NUMBER_OF_CARDS_IN_POKER_HAND = 5;

    const frequcyInRanks = new Array(RANKS_RANGE[1] + 1).fill(0);
    let maxFrequcyInRanks = 0;
    let flush = true;

    for (let i = 0; i < NUMBER_OF_CARDS_IN_POKER_HAND; ++i) {
        flush = flush && (suits[i] === suits[0]);
        maxFrequcyInRanks = Math.max(maxFrequcyInRanks, ++frequcyInRanks[ranks[i]]);
    }

    return flush ? "Flush"
           : maxFrequcyInRanks >= 3 ? "Three of a Kind"
           : maxFrequcyInRanks === 2 ? "Pair"
           : "High Card";
};
