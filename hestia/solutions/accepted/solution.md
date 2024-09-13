
## Medium 2-pointer solution in $O(n^2)$:
Let the original array be arr. Create a new array of pairs called a where each a_i = {arr_i, i} sort the array by first element.

For each element of a, a_k we will use a 2-pointer method to find the number of pairs that multiply to get a_k

Define sol = 0
Also set i = 0, j = k - 1, k = n - 1.
if a_i * a_j < a_k, then i++.
if a_i * a_j > a_ k then j--.
if a_i * a_j == a_k, 
then increment i to count the number of elements 
that are duplicates of a_i that have original index 
less than that of a_k's original index (original index 
will be the second item of the pair). Call this icount. 
Decrement j to count the same but for a_j. Call this jcount.

Then for this iteration, the number of triples that satisfy a_i * a_j == a_k will be icount * jcount. 
Then increment sol by icount * jcount

However if a_i * a_j == k and a_i == a_j and icount > 1, then instead increment sol by
icount choose 2. Since a_i == a_j, then a_k is a square number and so the number of pairs
that multiply to get a_k will be the total number of pairs of duplicates of a_i, which is icount choose 2.

Continue the above steps until i < j, is not satisfied. Then decrement k and repeat.

Each iteration of the 2-pointer method is O(n). Since it is used on each element a_k, the algorithm is O(n^2)