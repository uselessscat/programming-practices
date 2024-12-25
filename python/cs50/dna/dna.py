import sys
import csv

if len(sys.argv) != 3:
    exit("Usage: python dna.py data.csv sequence.txt")

with open(sys.argv[1], "r") as f:
    reader = csv.reader(f)

    header = list(next(reader))

    counts = {sequence: 0 for sequence in header[1:]}
    people = []

    for row in reader:
        people.append({
            'name': row[0],
            **{s: int(c) for s, c in zip(counts.keys(), row[1:])}
        })

with open(sys.argv[2], "r") as f:
    sequence = f.read()

## this is bad :C
i = 0
while i < len(sequence):
    sub_sequence = sequence[i:]

    for seq in counts.keys():
        aux = 0
        offset = i
        while seq == sequence[offset: offset + len(seq)]:
            aux += 1
            offset += len(seq)

        if aux > counts.get(seq):
            counts[seq] = aux

    i += 1

# check who is
for p in people:
    for i, c in counts.items():
        if p.get(i) != c:
            break
    else:
        print(p.get('name'))
        break
else:
    print("No match")
