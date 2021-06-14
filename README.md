# summerofbitcoin_challenge
Summer of Bitcoin challenge task 1.

Applied Knapsack algorithm for implementation of Greedy based technique where we are doing the following:-

(1) Sorting the transactions in the order of fee/weight.
(2) Using a set (implementing a heap structure) we check if all the parents are already present in the block or not.
(3) If step 2 is true, we include the transaction and update fee and weight and erase it from current set otherwise, go to next higher transaction.

# Time complexity:  O(n²)


# Output:


Total number of transactions read: 5214
Number of tx in final block 3174
Total fee in curr block : 5696031
Total weight : 3.99994e+06
Percentage of weight: 99.9984 %

# References:
[Geeks For Geeks Fractional Knapsack Problem](https://www.geeksforgeeks.org/fractional-knapsack-problem/#:~:text=The%20basic%20idea%20of%20the,as%20much%20as%20we%20can)

[mempool](https://mempool.space/)

[Binace](https://academy.binance.com/en/glossary/mempool)

[Heap](https://en.wikipedia.org/wiki/Heap_(data_structure))
