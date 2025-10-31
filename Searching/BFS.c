#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// queue stuff for bfs
struct Queue {
    int items[MAX];
    int front, rear;
};

// graph structure
struct Graph {
    int vertices;
    int adj[MAX][MAX];
    int visited[MAX];
};

// queue functions
struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q))
        return -1;
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return item;
}

// bfs algorithm
void bfs(struct Graph* graph, int start) {
    struct Queue* q = createQueue();

    graph->visited[start] = 1;
    enqueue(q, start);

    printf("BFS traversal: ");
    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adj[current][i] == 1 && graph->visited[i] == 0) {
                graph->visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    struct Graph graph;
    graph.vertices = 6;

    // init adjacency matrix
    for (int i = 0; i < graph.vertices; i++) {
        for (int j = 0; j < graph.vertices; j++)
            graph.adj[i][j] = 0;
        graph.visited[i] = 0;
    }

    // simple graph connections
    graph.adj[0][1] = graph.adj[1][0] = 1;
    graph.adj[0][2] = graph.adj[2][0] = 1;
    graph.adj[1][3] = graph.adj[3][1] = 1;
    graph.adj[2][4] = graph.adj[4][2] = 1;
    graph.adj[3][5] = graph.adj[5][3] = 1;

    bfs(&graph, 0);
    return 0;
}
