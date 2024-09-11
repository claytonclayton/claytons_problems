from itertools import takewhile

MORA = "n"

def soln(f):
    f.readline()

    words = [x.strip() for x in f.readlines()]

    if len(words) == 0:
        return 0
    comparison = zip(words, words[1:])

    if words[0][-1] == MORA:
        return 0

    length = (
        len(
            list(
                takewhile(
                    lambda x: x[0][-1] == x[1][0] and x[1][-1] != MORA,
                    comparison,
                )
            )
        )
        + 1
    )

    if length == len(words) and words[-1][-1] != MORA:
        return -1

    return length


if __name__ == "__main__":
    with open("/dev/stdin") as f:
        print(soln(f))