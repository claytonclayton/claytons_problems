#!/usr/bin/env python3

def solve(file):
    in_ = [None for _ in range(101)]
    out_ = [None for _ in range(101)]

    f.readline()
    for line in f.readlines():
        if not line.strip():  # in case random blank lines
            continue
        a, b = map(int, line.strip().split())
        if in_[b] or out_[a]:
            return True
        in_[b] = a
        out_[a] = b

    return False

if __name__ == "__main__":
    with open("/dev/stdin") as f:
        if solve(f):
            print("SLAY")
        else:
            print("NAY")