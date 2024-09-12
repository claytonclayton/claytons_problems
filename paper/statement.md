**Program time limit: 1 second**

**Program memory limit: 512 MB**

One day, you continually fold a piece of paper in half and in half again,
until you stop and unfold the paper to its original size. You see an $R$ by $C$ grid of rectangles, with each rectangle surrounded creases. The vertical creases form their own $R$ by $C-1$ grid, and the horizontal creases form their own $R-1$ by $C$ grid.

You wonder if you saw someone else's unfolded paper whether you could determine the folds they used to create it. Given whether each crease is a valley or a mountain, find a sequence of folds that could have created resulted in those creases, or determine that no such sequence exists.

There are two different fold directions, Up and Left, and two different fold types, Valley and Mountain. Therefore all folds in consideration are of one of the following types: 

- Up Valley (<code class="d-inline-block">UV</code>).
    - This fold is performed by taking the bottom of the paper and folding it towards you and up onto the front facing side. This would result in a horizontal valley crease when unfolded.

- Up Mountain (<code class="d-inline-block">UM</code>).
    - This fold is performed by taking the bottom of the paper and folding it away from you and up onto the back facing side. This would result in a horizontal mountain crease when unfolded.

- Left Valley (<code class="d-inline-block">LV</code>).
    - This fold is performed by taking the right side of the paper and folding it towards you and left onto the front facing side. This would result in a vertical valley crease when unfolded.

- Left Mountain (<code class="d-inline-block">LM</code>).
    - This fold is performed by taking the right side of the paper and folding it away from you and left onto the back facing side. This would result in a vertical mountain crease when unfolded.

The diagrams below depict an Up Valley fold, Up Mountain fold, Left Valley fold and Left Mountain fold respectively.
<img src="/static/UV.png" height="300">
<img src="/static/UM.png" height="300">
<img src="/static/LV.png" height="300">
<img src="/static/LM.png" height="300">

### Input
The first line of input contains the two integers $R$ and $C$, which is the size of grid of rectangles formed by the creases.

$R$ lines follow, each containing $C-1$ integers. This is the grid of vertical creases, where $0$ represents a valley crease and $1$ represents a mountain crease. 

$R-1$ lines follow, each containing $C$ integers. This is the grid of horizontal creases, where $0$ represents a valley crease and $1$ represents a mountain crease.

### Constraints
For all test cases:
- $2 \le R, C \le 1024$.
- $R$ and $C$ are both powers of 2.
- Every value in each grid is either $0$ or $1$.

### Output
If there is no sequence of folds that could have resulted in the given creases, output ```NO```.

Otherwise, on the first line, output ```YES```, and on each of the following lines, output either ```UM```, ```UV```, ```LM```, or ```LV```, specifying the sequence of folds.

### Sample Input 1
```
4 2
1
1
1
1
0 1
0 1
1 0
```

### Sample Output 1
```
YES
LM
UV
UV
```

### Explanation 1
The given creases are depicted below.
<img src="/static/sample1-final.png" height="300">

A sequence of folds which would result in those given creases is depicted below.
<img src="/static/sample1-step-1.png" height="300">
<br>
<img src="/static/sample1-step-2.png" height="300">
<br>
<img src="/static/sample1-step-3.png" height="150">
<br>

### Sample Input 2
```
4 4
0 0 1
1 0 1
0 1 1
1 1 0
0 0 1 1
1 1 1 1
1 1 0 0
```

### Sample Output 2
```
NO
```

### Explanation 2
In this case, it can be shown that no sequence of folds results in the given creases.

### Scoring
Your program will be run on multiple secret test cases one after another,
and if it produces the correct output for <b>all</b> test cases, it solves the task.