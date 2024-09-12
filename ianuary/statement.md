**Program time limit: 1 second**

**Program memory limit: 512 MB**

Ianus sees Hestia counting stars and wonders if he can create an array of his own that mirrors 
her favourite constellations. He knows what size arrays Hestia likes and the number of stars in <a href="https://en.wikipedia.org/wiki/Hydrus" target="_blank">Hydrus</a>,
but he isn't certain if it is even possible to marry these two numbers together.

A *Ianuarian Triple* is a triplet of integers $i$, $j$ and $k$ such that $1 \le i \lt j \lt k \le n$ and $a_i \times a_j = a_k$.
He wonders, does there exist an array $a$ of length $n$, **composed of only 2s and 4s**,
which has exactly $m$ Ianuarian Triples?
If so, help Ianus construct such an array.

### Input

The first line contains one integer $t$, the number of testcases.

The next $t$ lines contain two integers $n$ and $m$, the target length of the array $a$ and the target number of Ianuarian Triples.

### Constraints
- $1 \le t \le 10,000$
- $1 \le n \le 10,000$
- $1 \le m \le 10,000$

### Output

If there does not exist an array of length $n$ with $m$ Ianuarian Triples, output "NO".

If there exists such an array output "YES". On the next line output the array, a string of length $n$ consisting of characters '2' and '4'.

### Sample Input 1
```
3
6 2
7 7
10 100
```

### Sample Output 1
```
YES
422442
YES
2424244
NO
```

### Explanation 1

#### Testcase 1 
422442 has length 6 and has exactly 2 Ianuarian Triples:  
- $a_2 \times a_3 = a_4$
- $a_2 \times a_3 = a_5$


#### Testcase 2
2424244 has length 7 and has exactly 7 Ianuarian Triples:  
- $a_1 \times a_3 = a_4$
- $a_1 \times a_3 = a_6$
- $a_1 \times a_3 = a_7$
- $a_1 \times a_5 = a_6$
- $a_1 \times a_5 = a_7$
- $a_3 \times a_5 = a_6$
- $a_3 \times a_5 = a_7$

#### Testcase 3
It can be shown that there exists no array of length 10 with exactly 100 Ianuarian Triples.

### Scoring
Your program will be tested on multiple inputs one after another. Your score for the submission will be 100% if your program outputs the correct answer for all of these inputs.
