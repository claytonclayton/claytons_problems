# -*- coding: utf-8 -*-
"""
Created on Wed Jan 31 20:53:34 2024

@author: hambu
"""

"""

"""

# %% Inputs

# n, m = map(int, input().split())

with open("mins", 'r') as f:
    mins = [int(i) for i in f.readlines()]

mins = [0] + mins

for i in range(1, 2):

    n = mins[i]
    m = i

    # %% Finding the ratio of 2:4 to maximise the potential m
    # This step is O(n), and intentionally unoptimsied, but my gut feeling is that it's always around a ratio of 2:1
    best = 0
    for two_qty in range(n):
        possible = two_qty*(two_qty-1)/2 * (n-two_qty) # twoC2 * fourC1
        if possible > best:
            best = possible
            num_twos = two_qty
    """
    Seems that the optimal is
    n%3 = 0: num_fours = n/3
    n%3 = 1: num_fours = (n-1)/3
    n%3 = 2: num_fours = (n+1)/3

    Put as one line, num_fours = (n+1)//3
    """

    # %% Main loop
    """
    Assumption: every value for m from 0 to best, inclusive, is possible
    Approach:
        Start with the optimal number of twos
        Try to slide 4s down to the right as far as they can go
        Note that the final answer will be constructed in reverse order since it's faster
    """

    if m > best:
        print("-1, IMPOSSIBLE")
    else:
        num_fours = n - num_twos
        answer_array = []
        while m > 0:
            contribution = num_twos*(num_twos-1)/2
            moved_fours = int(m//contribution)
            m = m%contribution
            for i in range(moved_fours):
                answer_array.append(4)
                num_fours -= 1
            num_twos -= 1
            answer_array.append(2)
        for j in range(num_twos):
            answer_array.append(2)
        for j in range(num_fours):
            answer_array.append(4)
        if num_fours < 0:
            print("-1, IMPOSSIBLE")
        else:
            answer_array.reverse()
            print(len(answer_array))

    """
    Edge cases before I forget:
    With n=2, we can only get m = 0

    """

    """
    Edge cases before I forget:
    With n=2, we can only get m = 0

    """
