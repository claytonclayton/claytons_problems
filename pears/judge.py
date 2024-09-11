import re
import os
import json
from judging.judge_program import judge_program, CPP, C, PYTHON3

def extract_subtask(s):
    if "sample" in s:
        return 0
    elif "/sub" in s:
        return int(re.findall(r'(?<=sub)\d+', s)[0])
    else:
        return -1
    
def judge(their_answer, language):
    data_path = os.path.join(os.path.dirname(__file__), 'data')

    results = judge_program(data_path, their_answer.encode('utf-8'), language)
    score = 0.0
    if results['compile_succeeded']:
        subtask_values = [0.0, 0.5, 0.25, 0.25] 
        subtask_results = [
            min(blob[0] for casename, blob in results['cases'].items() if extract_subtask(casename) == i)
            for i in range(len(subtask_values))
        ]
        score = sum(i*j for i, j in zip(subtask_results, subtask_values))
        
    return score, json.dumps(results)
