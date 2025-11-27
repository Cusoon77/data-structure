#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES];
    int in_degree[MAX_VERTICES];
};

void createGraph(struct Graph* graph, int V) {
    graph->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
        graph->in_degree[i] = 0;
    }
}

void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->in_degree[v]++;
}

void topologicalSort(struct Graph* graph) {
    int V = graph->V;
    int queue[MAX_VERTICES], front = 0, rear = 0;
    int top_order[MAX_VERTICES];
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (graph->in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];

        top_order[count++] = u;

        for (int v = 0; v < V; v++) {
            if (graph->adj[u][v] == 1) {
                graph->in_degree[v]--;
                if (graph->in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != V) {
        printf("There exists a cycle in the graph.\n");
    } else {
        printf("Topological Sort: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", top_order[i]);
        }
        printf("\n");
    }
}

int main() {
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph graph;
    createGraph(&graph, V);

    printf("Enter each edge (u v) where u → v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid edge. Try again.\n");
            i--;
            continue;
        }

        addEdge(&graph, u, v);
    }

    topologicalSort(&graph);

    return 0;
}

