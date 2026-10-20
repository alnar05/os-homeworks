# Homework 7: Process Scheduling Simulation (FCFS & SJF)

## Overview
This repository contains a C program that simulates CPU process scheduling under a Linux environment. It implements two non-preemptive scheduling algorithms:
1. **First Come First Served (FCFS)**
2. **Shortest Job First (SJF)**

The simulator calculates and displays execution timelines (Gantt Charts) and standard scheduling metrics for each process, including Waiting Time (WT), Turnaround Time (TAT), and Response Time (RT).

## Features
* Dynamically handles process data using C structs and dynamic memory allocation.
* Automatically sorts and queues processes based on arrival time and burst time.
* Handles CPU idle time (gaps between process arrivals).
* Outputs a scalable, text-based Gantt Chart for visual execution tracking.
* Calculates average WT, TAT, and RT to evaluate algorithm efficiency.

## Prerequisites
To compile and run this program, you will need:
* A Linux environment (or WSL on Windows / Terminal on macOS).
* The GCC compiler installed (`sudo apt install gcc` on Debian/Ubuntu).

## How to Compile and Run

1. **Clone the repository** (or download the source code):
   ```bash
   git clone https://github.com/alnar05/os-homeworks
   cd os-homeworks/hw7
   ```

2. **Compile the C code**:
   ```bash
   gcc main.c -o scheduler
   ```

3. **Run the executable**:
   ```bash
   ./scheduler
   ```

## Usage and Input Format
Upon running the program, you will be prompted to enter the total number of processes, followed by the **Arrival Time (AT)** and **Burst Time (BT)** for each process separated by a space.

**Example Input:**
```text
Enter the number of processes: 4
Enter the arrival time and burst time for process 1: 0 8
Enter the arrival time and burst time for process 2: 1 4
Enter the arrival time and burst time for process 3: 2 9
Enter the arrival time and burst time for process 4: 3 5
```

## Outputs Included in this Repository
* `main.c` - The complete source code for the scheduling simulator.
* `README.md` - Documentation on how to use the program.
* **Screenshots** - Included in the repository to demonstrate the terminal input/output for both algorithms.

## Developer Notes
* All dynamic memory is safely allocated and freed (`FCFS` and `SJF` operate on deep copies of the process arrays to prevent data mutation overlap).
* Edge cases, such as multiple processes arriving at the same time with identical burst times, are resolved using strict tie-breaking rules (prioritizing earlier arrivals).