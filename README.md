# Challenge 17 – File System Representation and Search Using BFS and DFS

## Files
- `challenge17.c` – complete C program.
- `sample_input.txt` – sample graph and search request.
- `sample_output.txt` – expected traversal and search result.

## What the program does
It represents files/directories as graph nodes and uses an adjacency matrix to store connections. It performs BFS and DFS from the given starting node, prints the traversal order, and reports whether the target node is found.

## Input format
1. Number of nodes.
2. One-word name for each node.
3. An `n x n` adjacency matrix containing only 0 and 1.
4. Starting node name.
5. Target node name.

A `1` at row `i`, column `j` means there is an edge from node `i` to node `j`. The matrix is treated as directed; add reverse edges too if you want an undirected connection.

## Compile and run
Using GCC:

```bash
gcc challenge17.c -o challenge17
./challenge17
```

On Windows with MinGW:

```bash
gcc challenge17.c -o challenge17.exe
challenge17.exe
```

Enter the values from `sample_input.txt` when prompted. The program should produce the traversal orders shown in `sample_output.txt`.

## Before submission
1. Compile and run the program on your computer.
2. Take a screenshot showing the program running and its BFS/DFS results (if your instructor requires one).
3. Create a GitHub repository, for example `challenge-17-bfs-dfs`.
4. Upload `challenge17.c`, `sample_input.txt`, `sample_output.txt`, and this README.
5. Submit the GitHub repository URL through the Google Form in the challenge sheet.
