import os
import math
from judging.judge_program import judge_program, CPP, C, PYTHON3

def judge(their_answer, language):
    data_path = os.path.join(os.path.dirname(__file__), 'data')
    language = {
        'CPP': CPP,
        'C': C,
        'PYTHON3': PYTHON3,
    }[language]

    results = judge_program(data_path, their_answer.encode('utf-8'), language, checker=checker)
    score = 0.0
    if results['compile_succeeded']:
        score = min(blob[0] for blob in results['cases'].values())
    return score, str(results)

def nc2(i):
    return i * (i - 1) / 2

def get_icount(a):
    twos = 0
    total = 0
    for i in range(len(a)):
        if a[i] == '2':
            twos += 1
        elif a[i] == '4':
            total += nc2(twos)
        else:
            return -1
    return total

def checker(student_output_file, input_path, output_path):
    try:
        student_output = student_output_file.read().split()
    except:
        return 0.0

    with open(output_path) as f:
        judge_output = f.read().split()

    with open(input_path) as f:
        inputt = [i.strip().split() for i in f.readlines()[1:]]
        for i in range(len(inputt)):
            inputt[i] = [int(j) for j in inputt[i]]

    i = 0
    j = 0
    k = 0
    while (i < len(student_output) and j < len(judge_output) and k < len(inputt)):
        if (student_output[i] != judge_output[j]):
            return 0.0
        elif (student_output[i] == 'NO'):
            i += 1
            j += 1
            k += 1
        elif (student_output[i] == 'YES'):
            i += 1
            j += 1
            if (len(student_output[i]) != inputt[k][0]):
                return 0.0
            if (get_icount(student_output[i].strip()) != inputt[k][1]):
                return 0.0
            i += 1
            j += 1
            k += 1
        else:
            return 0.0
    return 1.0

# student_output_path = "data/sample/sample-1.out"
# input_path = "data/sample/sample-1.in"
# output_path = student_output_path

# student_output_file = open(student_output_path, 'r')

# print(checker(student_output_file, input_path, output_path))
