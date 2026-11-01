#include <stdio.h>
#include <string.h>

#define MAX_NODES 50
#define NAME_LEN 50

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
char nodeName[MAX_NODES][NAME_LEN];
int n, targetFound;

int findNode(const char name[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nodeName[i], name) == 0)
            return i;
    }
    return -1;
}

void BFS(int start, const char target[]) {
    int queue[MAX_NODES], front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%s ", nodeName[current]);

        if (strcmp(nodeName[current], target) == 0)
            found = 1;

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\nBFS Result: File '%s' %s.\n",
           target, found ? "found" : "not found");
}

void DFSVisit(int current, const char target[], int *found) {
    visited[current] = 1;
    printf("%s ", nodeName[current]);

    if (strcmp(nodeName[current], target) == 0)
        *found = 1;

    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i])
            DFSVisit(i, target, found);
    }
}

void DFS(int start, const char target[]) {
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFSVisit(start, target, &found);

    printf("\nDFS Result: File '%s' %s.\n",
           target, found ? "found" : "not found");
}

int main(void) {
    char startName[NAME_LEN], targetName[NAME_LEN];

    printf("Enter number of files/directories (1-%d): ", MAX_NODES);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_NODES) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter the name of each file/directory (one word each):\n");
    for (int i = 0; i < n; i++)
        scanf("%49s", nodeName[i]);

    printf("Enter the %d x %d adjacency matrix (0 or 1):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &graph[i][j]) != 1 ||
                (graph[i][j] != 0 && graph[i][j] != 1)) {
                printf("Invalid adjacency matrix. Use only 0 and 1.\n");
                return 1;
            }
        }
    }

    printf("Enter starting file/directory: ");
    scanf("%49s", startName);

    printf("Enter file/directory to search: ");
    scanf("%49s", targetName);

    int start = findNode(startName);
    if (start == -1) {
        printf("Starting node '%s' does not exist.\n", startName);
        return 1;
    }

    if (findNode(targetName) == -1) {
        printf("Target node '%s' does not exist in the graph.\n", targetName);
        return 1;
    }

    BFS(start, targetName);
    DFS(start, targetName);

    return 0;
}
