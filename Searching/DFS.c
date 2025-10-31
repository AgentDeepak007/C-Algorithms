#include <stdio.h>

// dfs function
void dfs(int vertex, int visited[], int adj[][10], int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i])
            dfs(i, visited, adj, n);
    }
}

int main() {
    int n = 6;
    int adj[10][10] = {0};
    int visited[10] = {0};

    // simple graph setup
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;
    adj[3][5] = adj[5][3] = 1;

    printf("DFS traversal: ");
    dfs(0, visited, adj, n);
    printf("\n");

    return 0;
}
