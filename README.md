# Algorithms and Data Structures in C

Welcome!
This repository is a space for personal exploration dedicated to the C language, low-level performance, and how theoretical computer science concepts can solve practical, everyday problems.

## About the Project

The goal is not merely the mechanical implementation of classic algorithms, but an exploration of their **practical utility**. Each mini-project starts with a simple question: *"Where and why would we choose this data structure in the real world?"*

### What I aim for in every implementation:
* **Cleanliness and modularity:** clear separation between interface (`.h`) and logic (`.c`).
* **Memory safety:** zero memory leaks, verified with `valgrind`.
* **Easy automation:** each project includes its own `Makefile` with clear compilation and cleanup targets.
* **Clear documentation:** each subdirectory contains step-by-step explanations regarding complexity and functionality.

---

## Project Catalog

Below is a summary of completed or ongoing experiments. Each folder contains the full source code and its own usage guide:
s
| # | Project | Concepts / Structures | Practical Application Explored |
| :-: | :--- | :--- | :--- |
| **01** | **The Maze** | Backtracking, DFS, Heuristics, 2D Matrices | 2D Grid Pathfinding, Shortest Route Optimization & Greedy Exploration |
| **02** | **Task Dependency Scheduler** | DAGs, Kahn's Algorithm, Min-Heap / Priority Queue, In-Degree Tracking | Workflow Dependency Resolution, Build Pipelines & Deadlock/Cycle Detection |

*(The table is updated periodically as I explore new scenarios.)*

---

## Requirements and Execution

To run any of the projects, you need a C99/C11-compatible compiler and the `make` utility.