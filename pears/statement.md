**Program time limit: 1 second**

**Program memory limit: 512 MB**

Mazaalai loves pears and wants to find the most delicious species of pear. He has $n$ parent pear species and can splice the $i^{th}$ and $j^{th}$ species to create a new spliced pear, $(i, j)$. He splices each combination one by one in the order

$$(1, 2), (1, 3), (1, 4) ... (1, n), (2, 3), (2, 4), (2, 5) ... (2, n), (3, 4) ... ... (n - 1, n)$$

in total making ${n \choose 2}$ pears. In a very slow and arduous $O(n^2)$ fashion, he tries them one by one in order and decides that the $k^{th}$ pear is the most delicious, however he has already forgotten which two parent species were used to create it. Help mazaalai find the parents of his treasured pear.

### Input

The first line contains the integer $n$, the number of parent pears. 

The second line contains the integer $k$, the $k^{th}$ spliced pear.

### Output

Output two space seperated integers, the first and second pears (in ascending order) used to create the $k^{th}$ spliced pear.

### Constraints

For all test cases:

- $2 \le n \le 10^9$
- $1 \le k \le {n \choose 2}$

For Subtask 1 ($50%$ of points):

- $n \le 1000$

For Subtask 2 ($25%$ of points):

- $n \le 10^6$

For Subtask 3 ($25%$ of points):

- There are no additional constraints.

### Sample Input 1

```
5
6
```

### Sample Output 1

```
2 4
```

### Explanation 1

For $n = 5$, parent pears are spliced in the following order:

$(1, 2), (1, 3), (1, 4), (1, 5),$

$(2, 3), (2, 4), (2, 5),$

$(3, 4), (3, 5),$

$(4, 5)$ 

The $6^{th}$ spliced pear is $(2, 4)$.

### Scoring

For each subtask (worth $50%$, $25%$, and $25%$ of points, as per the Constraints section), your program will be run on multiple secret test cases one after another, and if it produces the correct output for **all** test cases, it solves that subtask. Your program will receive the points for each subtask it solves. Recall that your final score on the task is the score of your highest scoring submission.
