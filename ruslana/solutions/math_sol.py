# see prog_sol.cpp for explanations

from fractions import Fraction

# chance of getting one specific future is the chance of drawing 2 specific tiles
one = Fraction(1, 3**2)
# to be stationary you can either travel to your own house after 1 day, or travel to any house after 2 or 3 days. This is the chance of drawing t=1 and h=(your house) plus the chance of drawing t > 1 and any h.
stat = one + Fraction(2, 3)

sol = 0
sol += one ** 3                             # three anticlockwise
sol += one ** 3                             # three clockwise
sol += stat ** 3                            # all stationary
sol += 3 * one ** 2 * stat                  # one clockwise, two stationary
sol += 3 * one * stat ** 2                  # two clockwise, one stationary
sol += 3 * one ** 2 * 1/2 * (one + stat)    # two duel, one either stationary or clockwise

print(sol)
print(float(sol))
