# summerofbitcoin_challenge
Summer of Bitcoin challenge task 1.

Applied Knapsack algorithm for implementation of Greedy based technique where we are doing the following:-

(1) Sorting the transactions in the order of fee/weight.
(2) Using a set (implementing a heap structure) we check if all the parents are already present in the block or not.
(3) If step 2 is true, we include the transaction and update fee and weight and erase it from current set otherwise, go to next higher transaction.

# Time complexity:  O(n²)


# The main code is written in C++in [solution.cpp](https://github.com/REEKRAJROY/Summer-of-Bitcoin/blob/main/solution.cpp) file and the output block generated in [block.txt](https://github.com/REEKRAJROY/Summer-of-Bitcoin/blob/main/block.txt)

# Output:


Total number of transactions read: 5214 <br>
Number of tx in final block 3174 <br>
Total fee in curr block : 5696031 <br>
Total weight : 3.99994e+06 <br>
Percentage of weight: 99.9984 % <br>

# Screenshot of output:


![Screenshot from 2021-06-14 22-00-41](https://user-images.githubusercontent.com/55712612/121926891-105abf00-cd5c-11eb-8bbf-aac35894c8b6.png)


# References:
[Geeks For Geeks Fractional Knapsack Problem](https://www.geeksforgeeks.org/fractional-knapsack-problem/#:~:text=The%20basic%20idea%20of%20the,as%20much%20as%20we%20can)

[mempool](https://mempool.space/)

[Binace](https://academy.binance.com/en/glossary/mempool)

[Heap](https://en.wikipedia.org/wiki/Heap_(data_structure))
