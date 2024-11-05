# C-_college
Program created for College Assessment ! (OOPS in C++)
## <a href=https://github.com/Unknown4089863/Cpp_college/blob/main/C%2B%2B_Student_data.cpp>Click Here to See :- Student data</a>

## College Management System

This project is a simple C++ program that simulates a basic college management system. It enables users to input, store, and manage student details, including attendance, marks, and personal information. The program demonstrates the use of classes, basic validation, and conditional logic in C++.


## Usage

To run this program, compile it with a C++ compiler and execute the resulting binary. Enter the number of students to record details, then follow the prompts to input personal details, attendance, and marks.

 ## UML Diagram

```plaintext
+-------------------------------------------------+
|                    College                      |
+-------------------------------------------------+
| - name: string                                  |
| - reg_no: int                                   |
| - age: int[3]                                   |
| - Parentage: string                             |
| - roll_no: int                                  |
| - sem: string                                   |
| - attendance: int                               |
| - marks: float[5]                               |
| - total: int                                    |
+-------------------------------------------------+
| + College()                                     |
| + get_details(): void                           |
| + show_details(): void                          |
| + show_name(): void                             |
| + show_rollno(): void                           |
| + show_attendance(): void                       |
| + add_attendance(): float                       |
| + show_shortage(): void                         |
| + show_topper(std[]: College, num: int): void   |
+-------------------------------------------------+
