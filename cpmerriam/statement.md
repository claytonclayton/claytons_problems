**Program time limit: 1 second**

**Program memory limit: 512 MB**

The famous and reputable dictionary writing company CPM-erriam-Webster wants to revolutionise the dictionary market. Introducing, The CPM-erriam-Webster Abridged Dictionary, now with fewer words.

The genius idea behind CPM-erriam-Webster Abridged Dictionary is that it does not contain definitions of words that people with an intermediate reading level should already understand, reducing page count, creating ease of look up for experienced English speakers.

While developing this dictionary CPM notices something interesting. If a word's definition only contains words that are “obvious” (words that are not defined in the dictionary), then someone with an intermediate understanding could learn this new word by piecing together definitions they already know.

After these new words are learnt, even more words can be learned. A word is “learnable” if its definition only contains words that are either obvious or learnable.

Given a dictionary, how many words are learnable?

### Input

The first line contains the integer $N$, the number of entries in the dictionary

The next line contains $N$ integers where the $i^{th}$ integer denotes the number of words in the $i^{th}$ entry of the dictionary

Each of the next $N$ lines represent an entry in the dictionary, a word followed by a ": " followed by its definition, a number of space seperated words.

You should read from standard input.

### Output

Output a single integer, the number of words in the dictionary that are learnable.

### Constraints

For all test cases:

- $2 \le N \le 20\; 000$
- Each line will contain 2 to 10 words
- Each word consists of 1 to 10 english characters

For Subtask 1 ($50\%$ of points):

- $2 \le N \le 1000$

For Subtask 2 ($50\%$ of points):

- There are no additional constraints.


### Sample Input 1

```
3
9 6 5
portcullis: a strong heavy grating that blocks a gateway
heavy: difficult to lift or move
grating: sounding harsh and unpleasant
```

### Sample Output 1

```
3
```

### Explanation 1

None of the words in the definition for "heavy" have entries in the dictionary. The same is true for "grating". So both "heavy" and "grating" are learnable. All words in the definition for "portcullis" also do not have entries except for the words "heavy" and "grating", however these words are learnable, hence "portcullis" is learnable. All 3 words are learnable.

### Sample Input 2

```
5
5 5 5 6 4 
plumbus: a type of clumbus
clumbus: a type of glumbus
glumbus: a type of plumbus
type: a way to classify things
things: plural of thing
```

### Sample Output 2

```
2
```

### Explanation 2

There are only 2 words in the dictionary that are learnable: "things" and "type".


### Scoring

For each subtask (each worth $50\%$ of points, as per the Constraints section), your program will be run on multiple secret test cases one after another, and if it produces the correct output for **all** test cases, it solves that subtask. Your program will receive the points for each subtask it solves. Recall that your final score on the task is the score of your highest scoring submission.
