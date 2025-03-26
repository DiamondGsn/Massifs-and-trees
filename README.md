# Data Search Algorithms Project

## Overview
This project implements and compares different search algorithms (sequential and binary search) 
on multi-dimensional arrays, as well as demonstrates the construction and traversal of an AVL tree. 
The program is written in C++ and provides a practical example of how these algorithms perform in various scenarios.

## Features
- **Sequential Search**: Linear search through a matrix with step counting.
- **Binary Search**: Requires a sorted array, demonstrates logarithmic efficiency.
- **AVL Tree**: Self-balancing binary search tree with:
  - Insertion and balancing operations.
  - Three traversal methods: pre-order, in-order, and post-order.
- **User Interaction**: Input validation for matrix dimensions and search targets.
- **Performance Metrics**: Tracks and displays the number of steps taken for each search method.

## Requirements
- C++ compiler (e.g., g++, clang++, or MSVC).
- Standard Library support (`<vector>`, `<algorithm>`, etc.).

## Usage
1. **Compile the program**:
   ```bash
   g++ main.cpp -o search_algorithms
