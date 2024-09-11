import os
import json
from judging.judge_program import judge_program, CPP, C, PYTHON3

def judge(their_answer, language):
    data_path = os.path.join(os.path.dirname(__file__), 'data')
    language = {
        'CPP': CPP,
        'C': C,
        'PYTHON3': PYTHON3,
    }[language]

    results = judge_program(data_path, their_answer.encode('utf-8'), language)
    score = 0.0
    if results['compile_succeeded']:
        sub1 = min(blob[0] for casename, blob in results['cases'].items() if 'subtask1' in casename or 'subtask12' in casename)
        sub2 = min(blob[0] for casename, blob in results['cases'].items() if 'subtask2' in casename or 'subtask12' in casename)
        sub3 = min(blob[0] for casename, blob in results['cases'].items() if 'subtask3' in casename)
        score = 0.3*sub1 + 0.5*sub2 + 0.2*sub3
    return score, json.dumps(results)
