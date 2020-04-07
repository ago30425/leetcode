## Algorithm
* Binary search

## Problem Definition
```
eating speed:   1   2   3       ...     K                              max piles[i]
              +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
              | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
              +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+

0 means Koko cannot eat all the bananas within H hours with the speed.
1 means Koko can eat all the bananas within H hours with the speed.

Find the first occurrence of 1, that is K.
```
