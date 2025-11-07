# Student Management System (C Language)

## Overview
This is a simple Student Management System built using the C programming language.
It allows users to add, edit, delete, search, and sort student records, along with saving data to files and exporting to CSV format.
The program is completely menu-driven and runs in the console (terminal).

## Features
- Add new student with multiple courses and marks
- View all students with automatically calculated GPA
- Search students by ID, Name, or Email
- Edit student details easily
- Delete a single student or all records
- Sort student list by ID or Name
- Save data to file (students.dat) and automatically load on startup
- Export student list to a CSV file (students.csv)
- Calculate GPA based on marks (0–100 converted to 0–4 scale)

## How It Works
1. When you start the program, it automatically loads saved student data (if available).
2. You’ll see a menu with different options to manage students.
3. Enter the number for your desired operation (e.g., 1 to add student).
4. When exiting, all data is saved automatically for the next session.

## GPA Calculation
The program converts marks (0–100) to GPA (0–4 scale) using this simple formula:

GPA = (Total Marks / Number of Courses) / 25
Example:
If a student has marks 80 and 90 in two courses,
GPA = ((80 + 90)/2) / 25 = 3.4

## File Handling
- students.dat → Stores all student information in binary format.
- students.csv → Exported file (can be opened in Excel, Google Sheets, etc.).

When you run the program again, it automatically loads data from students.dat.

## Structure of Code
- Course structure – Stores course code, name, and marks.
- Student structure – Stores student ID, name, email, phone, course details, and count.
- Uses arrays and file I/O for data management.
- Each major task (add, edit, delete, search, sort, etc.) is handled by a separate function.

## How to Run
1. Copy the code into a file named student_management.c.
2. Compile it using:
   
   gcc student_management.c -o student_management
   
3. Run the program:
   
   ./student_management
   
4. Follow the menu displayed on screen.

## Example Menu
===== Student Management System =====
1. Add Student
2. Show All Students
3. Search Student (ID/Name/Email)
4. Edit Student
5. Delete Student
6. Delete All Students
7. Sort Students by ID
8. Sort Students by Name
9. Save Data
10. Export to CSV
11. Exit


## Output Files
| File Name      | Description                            |
|----------------|----------------------------------------|
| students.dat   | Stores all student data (binary format) |
| students.csv   | Exported student list (Excel-friendly)  |

## Example Output

ID        Name                 Email               Phone          GPA
-----------------------------------------------------------------------
S101      Dipti Parajuli       dipti@gmail.com     9812345678     3.60

S102      Rohan Sharma         rohan@mail.com      9801234567     3.20


## Notes
- Maximum students: 100
- Maximum courses per student: 10
- Data automatically saved when you exit.
- Works on all platforms that support C

## Author
Dipti Parajuli  
BCA Student | Web & Software Developer  
Kathmandu, Nepal
