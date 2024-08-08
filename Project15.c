#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->r == q->size - 1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}

void bfs(struct queue *q, int start, int visited[5], int a[5][5]) {
    printf("BFS Traversal: ");
    int node;
    int i = start;
    printf("%d ", i);
    enqueue(q, i);
    visited[i] = 1;

    while (!isEmpty(q)) {
        node = dequeue(q);
        int j;
        for (j = 0; j < 5; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
    printf("\n");
}

void dfs(int node, int visited[5], int a[5][5]) {
    printf("%d ", node);
    visited[node] = 1;
    int i;
    for (i = 0; i < 5; i++) {
        if (a[node][i] == 1 && !visited[i]) {
            dfs(i, visited, a);
        }
    }
}

int main() {
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));

    int visited[5] = {0, 0, 0, 0, 0};
    int a[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
    };

   
    int start_node;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &start_node);
    bfs(&q, start_node, visited, a);

    
    int i1;
    for (i1 = 0; i1 < 5; i1++) {
        visited[i1] = 0;
    }


    printf("DFS Traversal (Starting from each node):\n");
    int i2;
    for (i2 = 0; i2 < 5; i2++) {
        if (!visited[i2]) {
            // printf("Starting from Node %d: ", i2);
            dfs(i2, visited, a);
            printf("\n");
        }
    }

    return 0;
}

