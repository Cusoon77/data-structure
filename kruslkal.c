#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int parent[MAX];

int find(int i){
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i,int j){
    if(i != j){
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main(){
    int vertex_count=0;
    int cost_matrix[MAX][MAX];
    int edge_count, count=1, sum_cost=0;
    int min_cost, row_no, column_no, edge1, edge2;

    printf("Implementation of Kruskal's algorithm\n\n");
    printf("Total number of vertices: ");
    scanf("%d", &vertex_count);

    if(vertex_count > MAX){
        printf("Vertex count exceeds maximum allowed!\n");
        return 1;
    }

    for(int i=0;i<MAX;i++) parent[i] = 0;

    printf("Enter cost adjacency matrix (0 for no edge):\n");
    for(int i=0;i<vertex_count;i++){
        for(int j=0;j<vertex_count;j++){
            scanf("%d",&cost_matrix[i][j]);
            if(cost_matrix[i][j] == 0)
                cost_matrix[i][j] = 999; 
        }
    }

    edge_count = vertex_count - 1;

    while(count <= edge_count){
        min_cost = 999;
        for(int i=0;i<vertex_count;i++){
            for(int j=0;j<vertex_count;j++){
                if(cost_matrix[i][j] < min_cost){
                    min_cost = cost_matrix[i][j];
                    edge1 = i;
                    edge2 = j;
                }
            }
        }

        row_no = find(edge1);
        column_no = find(edge2);

        if(uni(row_no, column_no)){
            printf("Edge %d is (%d -> %d) with cost: %d\n", count++, edge1+1, edge2+1, min_cost);
            sum_cost += min_cost;
        }

        cost_matrix[edge1][edge2] = cost_matrix[edge2][edge1] = 999;
    }

    printf("\nMinimum cost = %d\n", sum_cost);
    return 0;
}

