import sys
import csv
import sqlite3

if len(sys.argv) != 2:
    exit("Usage: python import.py data.csv ")

with open(sys.argv[1], "r") as f, sqlite3.connect("students.db") as db:
    reader = csv.DictReader(f)
    cursor = db.cursor()

    for row in reader:
        names = row.get("name").split(" ")

        cursor.execute(
            "INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?);", (
                names[0],
                names[1] if len(names) == 3 else None,
                names[2] if len(names) == 3 else names[1],
                row.get("house"),
                row.get("birth")
            ))

    db.commit()
