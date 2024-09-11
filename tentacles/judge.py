import os
import re
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
        subtask_values = [0.0, 0.2, 0.2, 0.2, 0.4]
        subtask_results = [
            min(blob[0] for casename, blob in results['cases'].items() if 'sample' in casename),
            min(blob[0] for casename, blob in results['cases'].items() if 'case-1' in casename or 'sample' in casename),
            min(blob[0] for casename, blob in results['cases'].items() if 'case-2' in casename or 'case-1' in casename or 'sample' in casename),
            min(blob[0] for casename, blob in results['cases'].items() if 'case-3' in casename or 'case-2' in casename or 'case-1' in casename or 'sample' in casename),
            min(blob[0] for casename, blob in results['cases'].items() if 'case-4' in casename or 'case-3' in casename or 'case-2' in casename or 'case-1' in casename or 'sample' in casename),
        ]
        score = sum(i*j for i, j in zip(subtask_results, subtask_values))
    return score, json.dumps(results)


