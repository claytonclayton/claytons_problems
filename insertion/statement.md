**Program time limit: 1 second**

**Program memory limit: 512 MB**

You can *insert* a string $X$ into a string $Y$ by splitting $Y$ into two parts (one of which may be empty), and placing $X$ in between those two parts.

For example, you can insert ```train``` into ```sage``` to get ```strainage```, since ```sage``` can be split into the two parts ```s``` and ```age```, and then ```train``` can be placed in between them to obtain ```s``` + ```train``` + ```age``` = ```strainage```.

Given two strings $X$ and $Y$ of lowercase letters, determine whether there exists a string that you can insert into $X$ to obtain $Y$.

### Input

The first line of input contains two integers $|X|$ and $|Y|$, the length of $X$ and the length of $Y$ respectively. The second line contains the string $X$ of $|X|$ lowercase letters. The second line contains the string $Y$ of $|Y|$ lowercase letters.

### Constraints

Each input case will satisfy the following constraints:
- $1 \le |X| \le |Y| \le 100,000$.

Additionally
- For Subtask 1 (30% of points), $|X| = 1$
- For Subtask 2 (50% of points), $Y \le 1000$.
- For Subtask 3 (20% of points), there are no additional constraints.

### Output

If you can insert a string into $X$ to obtain $Y$, output YES.  
Otherwise, output NO

### Sample Input 1

```
4 9
sage
strainage
```

### Sample Output 1
```
YES
```

### Explanation 1
In this case, you can insert the string ```train```

### Sample Input 2
```
3 6
khi
kimchi
```

### Sample Output 2
```
YES
```

### Explanation 2
In this case, you can insert the string ```imc```

### Sample Input 3
```
5 7
catan
caravan
```

### Sample Output 3
```
NO
```

### Explanation 3
In this case, there is no string you can insert.

### Scoring
For each subtask (worth 30%, 50% and 20% of points, as per the Constraints section), your program will be run on multiple secret test cases one after another, and if it produces the correct output for <b>all</b> test cases, it solves that subtask. Your program will receive the points for each subtask it solves. Recall that your final score on the task is the score of your highest scoring submission.
