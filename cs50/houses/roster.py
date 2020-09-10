import sys
import sqlite3

if len(sys.argv) != 2:
    exit("Usage: python import.py data.csv ")

with sqlite3.connect("students.db") as db:
    cursor = db.cursor()

    results = cursor.execute(
        "SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last ASC, first ASC;", (sys.argv[1],))

    for first, middle, last, birth in results:
        name = " ".join(filter(None, (first, middle, last)))

        print(f"{name}, born {birth}")