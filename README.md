# Singly Linked List - Student Record Management System

A C-based command-line application to manage student records using a **Singly Linked List (SLL)** data structure.

---

## Project Structure

.
├── headersll.h   # Header file with struct definition and function declarations
└── sll.c         # Main program with all linked list operations

---

## Data Structure

Each node stores:
| Field    | Type    | Description          |
|----------|---------|----------------------|
| rollno   | int     | Student roll number  |
| name     | char[20]| Student name         |
| marks    | float   | Marks obtained       |
| next     | pointer | Pointer to next node |

---

## Compilation & Run

gcc sll.c -o sll
./sll

---

## Features

| Option | Function         | Description                            |
|--------|------------------|----------------------------------------|
| 1      | add_begin        | Insert node at the beginning           |
| 2      | add_end          | Insert node at the end                 |
| 3      | add_middle       | Insert node in sorted order by roll no |
| 4      | print_node       | Print all records                      |
| 5      | count_nodes      | Count total nodes                      |
| 6      | save_file        | Save records to std.txt                |
| 7      | read_file        | Load records from std.txt              |
| 8      | reverse_print    | Print list in reverse (iterative)      |
| 9      | print_rec        | Print list using recursion             |
| 10     | reverse_rec      | Print list in reverse using recursion  |
| 11     | delete_all       | Delete all nodes                       |
| 12     | delete_node      | Delete a node by roll number           |
| 13     | search_node      | Search a student by name               |
| 14     | sort_node        | Sort records by roll number (bubble)   |
| 15     | reverse_links    | Reverse the linked list in-place       |
| 16     | exit             | Exit the program                       |

---

## File I/O

- Records are saved to and loaded from **std.txt** in the working directory.
- File format: rollno name marks (one record per line)

---

## Key Concepts Demonstrated

- Dynamic memory allocation (malloc, free)
- Pointer-to-pointer (**ptr) for head updates
- Recursive traversal and reverse printing
- Bubble sort on linked list nodes
- File handling with fprintf / fscanf
- ANSI escape codes for colored terminal output

---

## Notes

- There is a minor bug in delete_node() — the "record deleted" message is printed inside the traversal loop instead of after deletion. Fix: move printf before return.
- reverse_print() uses an O(n^2) approach; can be optimized using a stack.

---

## Author

Student project — Data Structures Lab
Language: C | Platform: Linux/Unix
