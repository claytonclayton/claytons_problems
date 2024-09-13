**Program time limit: 1 second**

**Program memory limit: 512 MB**

Chef Yamamotosuzukiakihabaraonigawara is preparing a tentacle dish at his 5 star michelin rated restaurant, *Yamamotosuzukiakihabaraonigawara's*. Unfortunately his guests are foreigners (bad) so they will not be able to handle high levels of umami, however cutting tentacles haphazardly will reduce their umami content by too much.

Umaminess is defined as the number of inversions in the tentacle. That is, given a tentacle array $T$ of size $n$, the umaminess of $T$ is the number of pairs of indices $(i, j)$ such that $i < j$ and $T_{i} > T_{j}$.

He can chop off one element either from the front or from the back of the tentacle at a time. What is the minimum number of chops required so that the umaminess of the tentacle becomes at most $k$?

### Input
The first line of input contains the integers $n$ and $k$, the size of the array and the target umaminess respectively.

The second line contains $n$ integers $T_1, T_2, \ldots, T_n$ where $T_i$ is the $i$th element of $T$.

### Constraints
For all test cases:
- $1 \le n \le 200\; 000$.
- $0 \le k \le \frac12 N(N-1)$.
- $1 \le T_i \le 10^9$, for all $i$.

Additionally:
- For Subtask 1 (20% of points), $n \le 50$.
- For Subtask 2 (20% of points), $n \le 750$.
- For Subtask 3 (20% of points), $n \le 5\; 000$.
- For Subtask 4 (40% of points), there are no additional constraints.

### Sample Input 1
```
5 1
3 2 1 5 4
```

### Sample Output 1
```
2
```

### Explanation 1
Since $k = 1$, we need to modify the array to include at most $1$ inversion.
We can do this by removing the first and last element, which leaves the array $[2, 1, 5]$, which has exactly $1$ inversion since $2 > 1$ (but $2 < 5$ and $1 < 5$). This uses $2$ chops, which is the minimum possible.

### Scoring
For each subtask (worth 20%, 20%, 20% and 40% of points, as per the Constraints section), your program will be run on multiple secret test cases one after another, and if it produces the correct output for <b>all</b> test cases, it solves that subtask.  Your program will receive the points for each subtask it solves. Recall that your final score on the task is the score of your highest scoring submission.