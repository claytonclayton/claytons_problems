**Program time limit: 1 second**

**Program memory limit: 512 MB**

It’s pride month (at least it was pride month when this question was written) and Rupaul has just announced his new competitive programming game show *Rupaul’s <a href="https://en.wikipedia.org/wiki/Directed_acyclic_graph" target="_blank">DAG</a> Race*. The new season is right around the corner and Rupaul needs YOUR help to find the most fabulous DAGs.

A DAG is FAB if it is not STRAIGHT. A STRAIGHT DAG is a series of nodes that connect to form a straight line. More specifically you can visit all nodes in a STRAIGHT DAG from head to tail within a single journey.

<p align="center">
<img src="/static/straight-1.jpg" width=100%>
<img src="/static/straight-2.jpg" width=80%>
</p>

A FAB DAG is anything that is NOT STRAIGHT.

<p align="center">
<img src="/static/fab-1.jpg" width=70%>
<img src="/static/fab-2.jpg" width=100%>
</p>

Given a DAG is it FAB?

### Input

The first line contains integers $N$ and $M$ representing the number of nodes and the number of edges in the graph respectively. There will be one node for each $i$ in the range $\[1, N\]$.

Each of the next $M$ lines contain two integers $a$ and $b$ representing a directed edge from node $a$ to $b$.

All DAGs are guaranteed to not contain any cycles. i.e you cannot make a journey that returns to the point of origin without revisiting some nodes.

You should read from standard input.

### Output

Output `SLAY` if the DAG is FAB, and output `NAY` otherwise.

You should write to standard output.

In Python, you could use the line `print(answer)`.

In C or C++, you could use the line `printf("%d\n", answer);`.

### Constraints

For all test cases:

- $2 \le N \le 100$
- $1 \le M \le 1000$

### Sample Input 1

```
5 4
3 4
1 2
4 5
2 3
```

### Sample Output 1

```
NAY
```

### Explanation 1

This DAG is the same as the first example STRAIGHT DAG. 

### Sample Input 2

```
5 5
2 5
5 3
3 1
2 4
4 3
```

### Sample Output 2

```
SLAY
```

### Explanation 2

This DAG is the same as the first example FAB DAG. SLAY!

### Scoring

<!-- Your program will be run on the 2 sample cases and 8 secret cases one after another, each worth 10% of the points.
Recall that your final score on the task is the score of your highest scoring submission. -->
