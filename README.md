# 🌳 Process Tree Management System

## Overview

The Process Tree Management System is a menu-driven Operating System project developed in C. The project demonstrates process creation, parent-child relationships, process hierarchy visualization, and process management using Linux system calls.

The application allows users to create multiple levels of child processes, display process information, visualize the process tree structure, and manage process data interactively.

## Features

✅ Create child processes using `fork()`

✅ Display Process ID (PID) and Parent Process ID (PPID)

✅ Generate multi-level process hierarchy

✅ Store process information in a structured table

✅ Display process information in tabular format

✅ Visualize process tree structure

✅ Process synchronization using `wait()`

✅ Reset stored process information

✅ Linux `pstree` command support for real-time process visualization

## Technologies Used

* C Programming Language
* Linux Operating System
* Process Management System Calls
* GCC Compiler

## Operating System Concepts Demonstrated

* Process Creation
* Parent and Child Processes
* Process Hierarchy
* Process Synchronization
* Process Control Block Concepts
* Fork System Call
* Wait System Call
* Process Identification (PID & PPID)

## Menu Options

### 1. Create Process Tree

Creates a chain of child processes up to the specified level.

### 2. Display Process Table

Displays all process information including:

* Process ID (PID)
* Parent Process ID (PPID)

### 3. Show Process Tree

Displays the hierarchical structure of created processes.

### 4. Reset Data

Clears all stored process information.

### 5. Exit

Terminates the application.

## Sample Process Tree

```text
Parent
|-- Level 1
   |-- Level 2
      |-- Level 3
         |-- Level 4
```

## Learning Outcomes

Through this project, I gained practical experience in:

* Linux Process Management
* System Programming
* Operating System Concepts
* Process Synchronization
* Process Hierarchy Visualization
* Fork and Wait System Calls
* Menu-Driven Application Development

## Project Structure

```text
Process-Tree-Management-System
│
├── osproj.c
├── README.md
```

## Future Enhancements

* Graphical Process Tree Visualization
* Process Termination Management
* CPU Scheduling Simulation
* Process State Monitoring
* Resource Allocation Tracking
* Multi-Branch Process Tree Support

## How to Compile and Run

### Compile

```bash
gcc process_tree.c -o process_tree
```

### Run

```bash
./process_tree
```

### Visualize Process Tree

Open another terminal and run:

```bash
pstree -p <parent_pid>
```

## Developer

**Bhakti Shakhawar**

Third Year Diploma Student
Computer Engineering Department
Government Polytechnic Pune

GitHub:
https://github.com/bhaktishakhawar27-netizen

LinkedIn:
https://www.linkedin.com/in/bhakti-shakhawar-835397340/
