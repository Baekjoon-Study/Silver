#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

char area[100][100];  
bool visited[100][100];  
int normal_area = 0;  
int blindness_area = 0;  
int N;  


int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };


void normal_DFS(int x, int y, char color) {
    visited[x][y] = true;


    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

    
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && area[nx][ny] == color) {
            normal_DFS(nx, ny, color);
        }
    }
}

void blindness_DFS(int x, int y, char color) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
            if ((color == 'R' || color == 'G') && (area[nx][ny] == 'R' || area[nx][ny] == 'G')) {
                blindness_DFS(nx, ny, color);
            }
            else if (area[nx][ny] == color) {
                blindness_DFS(nx, ny, color);
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    getchar(); 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%c", &area[i][j]);
        }
        getchar();  
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                normal_DFS(i, j, area[i][j]);
                normal_area++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                blindness_DFS(i, j, area[i][j]);
                blindness_area++;
            }
        }
    }

    printf("%d %d\n", normal_area, blindness_area);

    return 0;
}
