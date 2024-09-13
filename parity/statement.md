**Program time limit: 1 second**

**Program memory limit: 512 MB**

You find a sheet of paper with a grid of numbers $G$ of size $R \times C$ written on it. You fold the paper so that when you unfold it, all numbers are surrounded by fold lines (corner numbers have two adjacent fold lines, edge numbers have 3 adjacent fold lines and inner numbers are surrounded on all sides by 4 adjacent fold lines). For each number you add to it the number of mountain folds it is adjacent to. Is there a series of folds so that all numbers in the resulting grid are even?

Subtask-1 - Assume the paper is always folded with alternating folds starting with U i.e U -> L -> U -> L ...
Subtask-2 - The paper can be folded with arbitrary folds 

Output a series of folds where each fold is of the form UV, UM, LV or LM.
Copied from paper question from IMC contest.

- Up Valley (<code class="d-inline-block">UV</code>).
    - This fold is performed by taking the bottom of the paper and folding it towards you and up onto the front facing side. This would result in a horizontal valley crease when unfolded.

- Up Mountain (<code class="d-inline-block">UM</code>).
    - This fold is performed by taking the bottom of the paper and folding it away from you and up onto the back facing side. This would result in a horizontal mountain crease when unfolded.

- Left Valley (<code class="d-inline-block">LV</code>).
    - This fold is performed by taking the right side of the paper and folding it towards you and left onto the front facing side. This would result in a vertical valley crease when unfolded.

- Left Mountain (<code class="d-inline-block">LM</code>).
    - This fold is performed by taking the right side of the paper and folding it away from you and left onto the back facing side. This would result in a vertical mountain crease when unfolded.

### Input
The first line contains integers $R$ and $C$ representing the row size and column size of the grid respectively. $R$ and $C$ are guaranteed to be powers of 2.

Next follows $R$ lines each with $C$ integers where the $j^{th}$ integer on the $i^{th}$ line represents the integer in row $i$ and column $j$. 
You should read from standard input.

### Constraints
For all test cases
- $2 \le R, C \le 1024$.
- $R$ and $C$ are powers of 2
- 0 \le $G_{ij}$ \le 100

Additionally
- For 50% of test cases, you can assume the paper was folded with alternating folds starting from U.
- For 50% of test cases, there are no additional constraints.

### Output
If there is a valid folding, then the first line will contain YES, then the next line will be an integer $m$ representing the number of folds required.

The next $m$ lines will contain one of UM, UV, LM or LV. If there is no valid folding, then output NO.

### Sample Input 1
```
2 2
2 4
5 1
```

### Sample Output 1
```
YES
2
UM
LM
```

### Explanation 1
