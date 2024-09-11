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
        case_scores = [blob[0] for casename, blob in results['cases'].items() if "sample" not in casename]
        score = sum(case_scores) / len(case_scores)
    return score, json.dumps(results)
