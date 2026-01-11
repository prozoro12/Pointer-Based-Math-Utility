# Pointer-Based Math Utility (C++)

A menu-driven C++ console application built to practice **core memory concepts**:
- pointers
- references
- dynamic memory allocation (`new` / `delete`)
- pointer arithmetic
- basic input validation

This project was created as part of **Week 3** of a structured C++ learning roadmap.

---

## Features

- Dynamically allocates memory based on user input
- Stores numbers on the heap
- Menu-driven interface:
  - Enter numbers
  - Display numbers
  - Find maximum value
  - Find minimum value
  - Calculate average
- Safe memory handling (no leaks, no dangling pointers)
- Uses pointer arithmetic instead of array indexing

---

##  Concepts Practiced

- Stack vs Heap memory
- Pointer dereferencing
- Pointer arithmetic (`*(arr + i)`)
- Passing pointers to functions
- Input validation using `cin.fail()`
- Manual memory management

---

## Menu Options

1. Enter numbers
2. Display numbers
3. Find maximum
4. Find minimum
5. Calculate average
6. Exit

---

## How to Build & Run

### Using Visual Studio (Windows)
1. Create a **Console App** project
2. Replace the default `.cpp` file with `main.cpp`
3. Build and run (Ctrl + F5)

### Using g++
```bash
g++ main.cpp -o math_utility
./math_utility
