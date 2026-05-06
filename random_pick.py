import os
import random
import sys

phase = sys.argv[1] if len(sys.argv) > 1 else "phase1"
folder = os.path.join(os.path.dirname(__file__), phase)

files = [f for f in os.listdir(folder) if f.endswith(".cpp") and not f.startswith("ok_")]

if not files:
    print(f"No remaining problems in {phase}!")
else:
    print(random.choice(files))
