**C Template ([view](/static/shiritori.c), [download](/static/shiritori.c){download=1})** |
**Python Template ([view](/static/shiritori.py), [download](/static/shiritori.py){download=1})** |
**Time limit: 1 second** |
**Memory limit: 1 gigabyte**

Kevin and Stuart are playing the famous Japanese word game, *Shiritori*.
However one important prerequisite to playing this game is the ability to speak Japanese.
Not to worry! They have devised a brand new edition, *Shiritori, Minionese Edition*.
The rules are as follows.

- Player A begins the game by saying an Minionese word. This is easy, because any string of lowercase letters is a Minionese word.
- Player B responds with an Minionese word. **This word must be different from every word said before it, and must begin with the final letter of the previous word.**
- The game continues until a player makes a mistake. That player loses the game.

The rules seem quite straightforward however Kevin and Stuart are silly,
and often don't notice when a player makes a mistake.
Help our gamers find the first word which broke the rules.
Or was the game played perfectly?

### Input

You should read from standard input. We recommend using the templates at the top of the page to help you with input and output.

- The first line contains one integer $N$, the number of words in the game.
- Then follow $N$ lines, each containing a word consisting of lowercase letters.

### Output

You should write to standard output.

- If the game was played perfectly, output `-1`.
- Otherwise, output the first word that breaks the rules.

### Constraints

For all test cases:

- $1 \le N \le 100$.
- Each word is made up of at least $1$ and at most $20$ lowercase letters.

### Sample Input 1

```
6
banana
amsterdam
malingering
gratuitous
sabbatical
rastafarianism
```

### Sample Output 1

```
rastafarianism
```

### Explanation 1

The word "sabbatical" ends with an "l" but the next word "rastafarianism" does not begin with an "l".
All other words follow the rules.

### Sample Input 2

```
5
deuteronomy
ytterbium
murdered
deuteronomy
nascent
```

### Sample Output 2

```
deuteronomy
```

### Explanation 2

The fourth word "deuteronomy" is repeated, which is the first time a rule was broken.
Note that the word "nascent" also breaks a rule.

### Sample Input 3

```
6
umbrage
edification
neuroses
sophism
maniacal
locrian
```

### Sample Output 3

```
-1
```

### Explanation 3

Both players played perfectly. All words follow the rules of Shiritori.

### Scoring

Your program will be run on the 3 sample cases and 7 secret cases one after another, each worth 10% of the points.
Recall that your final score on the task is the score of your highest-scoring submission.