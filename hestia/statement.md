**Program time limit: 1 second**

**Program memory limit: 512 MB**

Hestia gazes into the night sky and tries to count the stars. Of the constellations she finds 
her favourite: 
<a href="https://en.wikipedia.org/wiki/Serpens" target="_blank">Serpens</a>, 
<a href="https://en.wikipedia.org/wiki/Hydra_(constellation)" target="_blank">Hydra</a>, 
<a href="https://en.wikipedia.org/wiki/Draco_(constellation)" target="_blank">Draco</a>, 
but altogether there are too many stars to count. Despite their abundance, she thinks that counting 
the triples of an array would be faster. 

A *Hestian triple* is a triplet of integers $i$, $j$ and $k$ such that $1 \le i \lt j \lt k \le n$ and $a_i \times a_j = a_k$. She wonders, given an array $a$, how many Hestian triples does it contain?

Help Hestia find the answer.

### Input

The first line of input contains one integer $n$, the length of the array $a$.

The next line has $n$ whitespaced integers, $a_1, a_2, \cdots a_n$ where $a_i$ is the $i^{th}$ element of $a$.

### Constraints

Each input case will satisfy the following constraints

- $1 \le n \le 10\; 000$
- for all $1 \le i \le n$, $1 \le a_i \le 10^{18}$
- for all $1 \le i \lt j \le n$, $1 \le a_i \times a_j \le 10^{18}$

### Output
Output one integer, the number of Hestian Triples in $a$.

### Sample Input 1

```
6
5 2 3 10 2 6
```

### Sample Output 1

```
3
```

### Explanation 1

There are exactly 3 Hestian Triples  
$a_1 \times a_2 = a_4$ ($5 \times 2 = 10$)  
$a_2 \times a_3 = a_6$ ($2 \times 3 = 6$)  
$a_3 \times a_5 = a_6$ ($3 \times 2 = 6$)  

### Sample Input 2 

```
5
5 4 4 20 15
```

### Sample Output 2
```
2
```

### Explanation 2

There are exactly 2 Hestian Triples  
$a_1 \times a_2 = a_4$ ($5 \times 4 = 20$)  
$a_1 \times a_3 = a_4$ ($5 \times 4 = 20$)  

### Scoring
Your program will be tested on multiple inputs one after another. Your score for the submission will be 100% if your program outputs the correct answer for all of these inputs.
