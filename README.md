
## 🧾 Overview

The **Employee Payroll Management System** is a console-based application developed in **C** as part of the **PG Diploma in Embedded System Design & Development** at the **Indian Institute of Embedded Systems (IIES), Bengaluru**.

It simulates the core backend functionality of a real-world payroll system — managing employee records, computing salaries with defined business logic, and ensuring data persistence across program executions using **file handling (File I/O)**.

> 💡 This project demonstrates practical understanding of **data structures, file I/O, user interface design**, and **C programming fundamentals** in a simplified, real-world context.

---

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [System Architecture](#-system-architecture)
- [Salary Calculation Logic](#-salary-calculation-logic)
- [Project Structure](#-project-structure)
- [Getting Started](#-getting-started)
- [Demo](#-demo)
- [Data Persistence](#-data-persistence)
- [Team](#-team)
- [Institute](#-institute)

---


---

## ✨ Features

| Feature | Description |
|:---|:---|
| ➕ **Add Employee** | Register new employees with ID, name, designation, and basic salary |
| 📋 **View All Records** | Display a formatted table of all employees with full payroll breakdown |
| 🔍 **Search by ID** | Instantly look up any employee record using their unique ID |
| 🧮 **Auto Salary Calculation** | Automatically computes allowances, deductions, and net salary |
| 💾 **Data Persistence** | Saves and loads all records to/from `employees.txt` — data survives restarts |
| 🛡️ **Duplicate ID Prevention** | Validates employee ID uniqueness before adding a new record |
| ⚠️ **Input Error Handling** | Gracefully handles invalid inputs without crashing |

---

## 🏗️ System Architecture

```
┌─────────────────────────────────────────────────────────┐
│                   Main Program Loop                     │
│                     main()                              │
└──────────────────────┬──────────────────────────────────┘
                       │
         ┌─────────────▼─────────────┐
         │       menu()              │
         │  (Display Options 1–4)    │
         └──┬──────┬──────┬──────────┘
            │      │      │
     ┌──────▼──┐ ┌─▼────┐ ┌▼────────┐
     │  add()  │ │show_ │ │search() │
     │         │ │all() │ │         │
     └────┬────┘ └──────┘ └─────────┘
          │
    ┌─────▼──────┐
    │calculate() │  ← 10% allowance, 5% deduction
    └─────┬──────┘
          │
    ┌─────▼──────┐
    │ save_file()│  ← Write to employees.txt
    └────────────┘

  On startup:
    ┌─────────────┐
    │ load_file() │  ← Read from employees.txt
    └─────────────┘
```

---

## 🧮 Salary Calculation Logic

```c
/* Business Logic Applied Per Employee */

Allowances  =  Basic Salary  ×  0.10   // 10% of Basic Pay
Deductions  =  Basic Salary  ×  0.05   //  5% of Basic Pay
Net Salary  =  Basic Salary  +  Allowances  -  Deductions
```

**Example with Basic Salary = ₹50,000:**

| Component | Calculation | Amount |
|:---|:---|---:|
| Basic Salary | — | ₹50,000.00 |
| Allowances (10%) | 50000 × 0.10 | ₹5,000.00 |
| Deductions (5%) | 50000 × 0.05 | ₹2,500.00 |
| **Net Salary** | 50000 + 5000 − 2500 | **₹52,500.00** |

---

## 📁 Project Structure

```
employee-payroll-system/
│
├── payroll.c           # Main source file (all logic)
├── employees.txt       # Auto-generated data persistence file
└── README.md           # Project documentation
```

---

## 🚀 Getting Started

### Prerequisites

- GCC compiler (Linux/macOS) or MinGW (Windows)
- Terminal / Command Prompt

### Compilation

```bash
# Linux / macOS
gcc payroll.c -o payroll

# Windows (MinGW)
gcc payroll.c -o payroll.exe
```

### Run

```bash
# Linux / macOS
./payroll

# Windows
payroll.exe
```

---

## 🖥️ Demo

```
---Welcome to the Employee Payroll System---

--- Main Menu ---
1. Add New Employee
2. View All Employees & Payroll
3. Search Employee by ID
4. Exit
-----------------
Enter your choice: 1

--- Add New Employee ---
Enter Employee ID: 101
Enter Name: Arun
Enter Designation: Senior Engineer
Enter Basic Salary: 50000

Employee Arun added successfully! Payroll calculated.
```

**View All Records:**

```
| ID  | Name                 | Designation     | Basic Salary    | Allowances      | Deductions      | Net Salary      |
|-----|----------------------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 101 | Arun                 | Senior Engineer | 50000.00        | 5000.00         | 2500.00         | 52500.00        |
| 102 | Bala                 | Project Manager | 75000.00        | 7500.00         | 3750.00         | 78750.00        |
```

**Search by ID:**

```
--- Search Employee ---
Enter Employee ID to search: 102

Employee Found:
  ID          : 102
  Name        : Bala
  Designation : Project Manager
  Basic Salary: 75000.00
  Net Salary  : 78750.00
```

---

## 💾 Data Persistence

All employee records are automatically saved to **`employees.txt`** after every addition and reloaded on the next program launch — ensuring no data is lost between sessions.

**File Format (`employees.txt`):**
```
2
101,Arun,Senior Engineer,50000.00,5000.00,2500.00,52500.00
102,Bala,Project Manager,75000.00,7500.00,3750.00,78750.00
```

- Line 1 → Total employee count
- Lines 2+ → `ID,Name,Designation,BasicSalary,Allowances,Deductions,NetSalary`

---

## 👥 Team

<div align="center">

| Name | Role |
|:---:|:---:|
| **Karthikeyan Arun Kumar** | Developer |
| **Sahi Bala R** | Developer |
| **Sriram P** | Developer |

</div>

---

## 🏛️ Institute

<div align="center">

**Indian Institute of Embedded Systems (IIES)**
Koramangala, Bengaluru – 560095

*PG Diploma in Embedded System Design & Development*
**Batch 90 — October 2025**

</div>

---

<div align="center">

Made with ❤️ and `printf()` statements

[![GitHub](https://img.shields.io/badge/GitHub-arunkarthi--03-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/arunkarthi-03)

![Footer](https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=6,11,20&height=100&section=footer&animation=twinkling)

</div>
