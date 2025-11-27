#include <stdio.h>
#define MAX 10

int main() {
    int vertex_array[MAX];
    int cost_matrix[MAX][MAX];
    int visited[MAX] = {0};

    int vertex_count;
    int i, j;
    int min_cost = 0;

    printf("Total number of vertices: ");
    scanf("%d", &vertex_count);

    if(vertex_count > MAX) {
        printf("Vertex count exceeds MAX limit.\n");
        return 0;
    }

    printf("Enter vertices:\n");
    for(i = 0; i < vertex_count; i++) {
        printf("vertex[%d]: ", i);
        scanf("%d", &vertex_array[i]);
    }

    printf("\nEnter cost matrix (%d × %d):\n", vertex_count, vertex_count);
    for(i = 0; i < vertex_count; i++) {
        for(j = 0; j < vertex_count; j++) {
            scanf("%d", &cost_matrix[i][j]);
            if(cost_matrix[i][j] == 0)
                cost_matrix[i][j] = 999; 
        }
    }

    visited[0] = 1; 

    int edges = vertex_count - 1;
    int count = 0;

    printf("\nSelected Edges:\n");

    while(count < edges) {
        int min = 999;
        int x = -1, y = -1;

        for(i = 0; i < vertex_count; i++) {
            if(visited[i] == 1) {
                for(j = 0; j < vertex_count; j++) {
                    if(visited[j] == 0 && cost_matrix[i][j] < min) {
                        min = cost_matrix[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if(x != -1 && y != -1) {
            printf("Edge %d: (%d -> %d) = %d\n",
                   count + 1, vertex_array[x], vertex_array[y], min);
            min_cost += min;
            visited[y] = 1;
            count++;
        }
    }

    printf("\nMinimum Cost = %d\n", min_cost);
    return 0;
}

