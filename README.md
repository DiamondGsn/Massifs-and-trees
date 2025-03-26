Data Search Algorithms Project
Comprehensive Project Description
This C++ project provides a complete implementation and comparison of fundamental data search algorithms, demonstrating their application in both linear and tree-based data structures. The project was developed as part of academic coursework in programming theory and technologies.

Technical Specifications
Programming Language: C++17
Compilation Requirements:
GCC/G++ 9.0+ or equivalent C++17 compatible compiler
Standard Template Library (STL)

Detailed Functionality
1. Matrix Operations
Implementation Details:
Dynamically creates 2D matrices of user-specified dimensions
Populates with pseudo-random integers (0-99 range)
Includes comprehensive input validation:
Positive integer checks
Buffer overflow protection
Type safety enforcement
Key Functions:
inputMatrixSize() - Validates dimension input
printMatrix() - Displays matrix in readable format
Matrix flattening for binary search preparation

2. Search Algorithms
Sequential Search
Scans matrix row-wise
Counts exact comparison operations
Returns first occurrence position
Time Complexity: O(m×n) for m×n matrix
Binary Search
Requires prior array sorting (O(n log n))
Implements classic divide-and-conquer approach
Counts comparison steps
Time Complexity: O(log n)

3. AVL Tree Implementation
Core Components:
Node structure with:
Integer key value
Left/right child pointers
Height tracking
Rotation operations:
Left rotation
Right rotation
Left-right double rotation
Right-left double rotation
Automatic rebalancing after insertions
Traversal Methods:
Pre-order (Root-Left-Right)
In-order (Left-Root-Right) - produces sorted output
Post-order (Left-Right-Roo

Build and Execution
Compilation Options
Basic Compilation:
g++ -std=c++17 -Wall -Wextra -o search_app src/main.cpp
Optimized Build:
g++ -std=c++17 -O3 -march=native -o search_optimized src/main.cpp

Runtime Options
The program operates interactively:
Prompts for matrix dimensions
Generates and displays matrix
Accepts search target input
Displays comprehensive results

Example Use Cases
Educational Demonstration:
Compare actual step counts between algorithms
Visualize tree balancing operations
Performance Testing:
Run with large matrices (1000×1000+)
Benchmark search times
Algorithm Research:
Modify balance factors in AVL implementation
Experiment with different pivot strategies

Development Notes
Key Challenges:
Implementing robust input validation
Ensuring proper AVL tree balancing
Optimizing memory usage for large matrices
Potential Improvements:
Add deletion operations for AVL tree
Implement threaded tree traversal
Add graphical tree visualization
Support for file-based input/output

Academic Applications
This implementation covers several core CS concepts:
Algorithm complexity analysis
Recursive tree operations
Memory management
Input validation techniques
Comparative algorithm studie

License and Attribution
License: MIT License
Academic Use: Permitted with proper citation
Commercial Use: Contact author




This detailed README provides comprehensive documentation for both educational and practical use of the project. The markdown formatting ensures proper display on GitHub and other platforms while maintaining readability in plain text.
