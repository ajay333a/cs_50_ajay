import csv
from cs50 import SQL

def main():
    students = []
    houses = []
    assignments = []

    with open("students.csv") as csv_file:
        reader = csv.DictReader(csv_file)
        for row in reader:
            name = row["student_name"]
            house = row["house"]
            head = row["head"]

            create_houses(house, houses, head)
            create_students(name, students)
            create_assignments(name, house, assignments)


    db = SQL("sqlite:///roster.db")
    for student in students:
        db.execute("INSERT INTO students_new (student_name) VALUES (?)", student["student_name"])

    for assignment in assignments:
        db.execute("INSERT INTO assignments (name, house) VALUES (?, ?)", assignment["student_name"], assignment["house"])

    for house in houses:
        db.execute("INSERT INTO houses (house, head) VALUES (?, ?)", house["house"], house["head"])

def create_houses(house, houses, head):
    house_count = 0
    for h in houses:
        if h["house"]  == house:
            house_count +=1
    if house_count == 0:
        houses.append({"house": house, "head":head})


def create_students(name, students):
    students.append({"student_name": name})


def create_assignments(name, house, assignments):
    assignments.append({"student_name": name, "house": house})


main()