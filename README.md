# Design and Analysis of Algorithms (DAA) Lab

A comprehensive collection of algorithm implementations, time/space complexity analyses, and performance benchmarking tools developed during the **Design and Analysis of Algorithms** laboratory coursework.

## Repository Structure

```
DAA/
├── Unit01-Introduction-Algorithms/
│   ├── performanceAnalyzer.py
│   └── Searching/
│       ├── iterativeBinarySearch.cpp
│       ├── linearSearch.cpp
│       └── recursiveBinarySearch.cpp
├── Unit02-Divide-and-Conquer/
│   ├── bubbleSort.cpp
│   ├── insertionSort.cpp
│   ├── mergeSort.cpp
│   ├── quickSort.cpp
│   ├── recursiveBubbleSort.cpp
│   ├── recursiveInsertionSort.cpp
│   └── selectionSort.cpp
├── Unit03-Greedy-Method/
│   ├── kruskalAlgorithm.cpp
│   └── Prims.cpp
└── Unit04-Dynamic-Programming/
    ├── 0-1-Knapsack.cpp
    └── MemoizedFibonacci.cpp

```

*(Note: Compiled Linux executables are also present alongside the `.cpp` source files in their respective directories.)*

## Syllabus & Implemented Algorithms

### Unit 01: Introduction to Algorithms & Searching

Focuses on fundamental searching strategies and empirical performance measurement.

* **Performance Analyzer (`performanceAnalyzer.py`):** Python utility script to benchmark execution times and analyze algorithm scaling.

* **Linear Search (`linearSearch.cpp`):** Sequential element search.

* **Iterative Binary Search (`iterativeBinarySearch.cpp`):** Loop-based logarithmic search on sorted arrays.

* **Recursive Binary Search (`recursiveBinarySearch.cpp`):** Divide-and-conquer recursive approach to binary search.

### Unit 02: Sorting & Divide and Conquer

Covers standard iterative/recursive comparison sorts and classical divide-and-conquer sorting paradigms.

* **Merge Sort (`mergeSort.cpp`):** Stable, recursive divide-and-conquer sorting.

* **Quick Sort (`quickSort.cpp`):** In-place partitioning sort.

* **Bubble Sort (`bubbleSort.cpp` & `recursiveBubbleSort.cpp`):** Iterative and recursive adjacent-swap sorting.

* **Insertion Sort (`insertionSort.cpp` & `recursiveInsertionSort.cpp`):** Iterative and recursive incremental sorting.

* **Selection Sort (`selectionSort.cpp`):** In-place minimum-element selection sorting.

### Unit 03: Greedy Method

Implements greedy optimization strategies for Minimum Spanning Trees (MST) in weighted, undirected graphs.

* **Kruskal's Algorithm (`kruskalAlgorithm.cpp`):** Edge-centric MST construction using Disjoint Set Union (DSU).

* **Prim's Algorithm (`Prims.cpp`):** Vertex-centric MST construction.

### Unit 04: Dynamic Programming

Explores overlapping subproblems and optimal substructure via memoization and tabulation.

* **0/1 Knapsack (`0-1-Knapsack.cpp`):** Classical combinatorial optimization problem solved using DP.

* **Memoized Fibonacci (`MemoizedFibonacci.cpp`):** Top-down DP approach optimizing recursive Fibonacci calculations.

## Complexity Quick Reference

| Algorithm | Best Time | Average Time | Worst Time | Space Complexity | 
| ----- | ----- | ----- | ----- | ----- | 
| **Linear Search** | $O(1)$ | $O(n)$ | $O(n)$ | $O(1)$ | 
| **Binary Search (Iterative)** | $O(1)$ | $O(\log n)$ | $O(\log n)$ | $O(1)$ | 
| **Binary Search (Recursive)** | $O(1)$ | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | 
| **Bubble Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | 
| **Insertion Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | 
| **Selection Sort** | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | 
| **Merge Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | 
| **Quick Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ | 
| **Kruskal's MST** | $O(E \log E)$ | $O(E \log E)$ | $O(E \log E)$ | $O(V + E)$ | 
| **Prim's MST** | $O(E \log V)$ | $O(E \log V)$ | $O(E \log V)$ | $O(V + E)$ | 
| **0/1 Knapsack** | $O(n \cdot W)$ | $O(n \cdot W)$ | $O(n \cdot W)$ | $O(n \cdot W)$ | 
| **Memoized Fibonacci** | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ | 

## Getting Started

### Prerequisites

* **C++ Compiler:** `g++` (GCC) supporting C++11 or later.

* **Python:** Python 3.x (for running `performanceAnalyzer.py`).

### Clone the Repository

```
git clone https://github.com/<your-username>/<your-repo-name>.git
cd DAA

```

### Compiling and Running C++ Programs

You can either run the pre-compiled binaries directly on Linux or recompile any `.cpp` file using `g++`:

```
# Example: Compiling and running Merge Sort
cd Unit02-Divide-and-Conquer
g++ -O2 mergeSort.cpp -o mergeSort
./mergeSort

```

### Running the Python Performance Analyzer

```
cd Unit01-Introduction-Algorithms
python3 performanceAnalyzer.py

```

## Tip for Git Hygiene

Notice that compiled binaries (e.g., `mergeSort`, `quickSort`) are currently tracked alongside source files. If you prefer keeping only source code in your repository, consider adding a `.gitignore` file to ignore extensionless binaries:

```
# Ignore compiled binaries without extensions
*
!*.*
!*/

```