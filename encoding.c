#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
  char letter;
  int count;
} lettercount;

void createGrid(char input[], char grid[][BUFFER_SIZE], int n) {  // Populates 2D array
  for (int j = 0;j < n;j++) {
    for (int k = 0;k < n;k++) {
      grid[j][(k-j+n)%n] = input[k];
    }
  }
}

void printArray(char arr[], int n) { 
  int i;
  for (i = 0; i < n; i++) 
    printf("%c", arr[i]);
  printf("\n");
}  

void sortGrid(char *sortedGrid[BUFFER_SIZE], int n) { 
  int i, j; 
  char *key;
  for (i = 1; i < n; i++) { 
    key = sortedGrid[i];
    j = i - 1; 

    while (j >= 0 && strncmp(sortedGrid[j], key, n) > 0) { 
      sortedGrid[j + 1] = sortedGrid[j];
      j = j - 1; 
    } 
    sortedGrid[j + 1] = key;
  } 
} 

int findInput(char input[BUFFER_SIZE], char *grid[BUFFER_SIZE], int n) {
  for (int i = 0;i < n;i++) {
    int pos = strncmp(grid[i], input, n);
    if (pos == 0) {
      return i;
    }
  }
  return -1;
}

void makeCluster(char *grid[BUFFER_SIZE], lettercount cluster[BUFFER_SIZE], int n) {
  char lastKnownChar = 0;
  int clusterIndex = -1;

  for (int i = 0; i < n; i++) {
    if (lastKnownChar == 0 || lastKnownChar != grid[i][n - 1]) {
      clusterIndex++;
      lastKnownChar = grid[i][n - 1];
      cluster[clusterIndex].letter = lastKnownChar;
      cluster[clusterIndex].count = 1;
    } else {
      cluster[clusterIndex].count++;
    }
  }
}

void printCluster(lettercount cluster[BUFFER_SIZE], int n) {
  for (int i = 0; cluster[i].letter != 0; i++) {
    printf("%d%c", cluster[i].count, cluster[i].letter);
  }
  printf("\n");
}

void printGrid(char grid[][BUFFER_SIZE], int n) {
  int j, k;
  for(j=0;j<n;j++) {
    for(k=0;k<n;k++) {
      printf("%c ", grid[j][k]); // printing 2D array
    }
    printf("\n");
  }
}   

void printSortedGrid(char *grid[BUFFER_SIZE], int n) {
  int j;
  for(j=0;j<n;j++) {
    printf("%s\n", grid[j]); // printing 2D array
  }
}   

char *replaceChar(char *str, char find, char replace) {
  char *currentPos = strchr(str, find);
  while (currentPos) {
    *currentPos = replace;
    currentPos = strchr(currentPos, find);
  }
  return str;
}

int main(int argc, char **argv) {
  char grid[BUFFER_SIZE][BUFFER_SIZE];
  char *sortedGrid[BUFFER_SIZE];
  char input[BUFFER_SIZE];
  lettercount cluster[BUFFER_SIZE];

  for (int i = 0; i < BUFFER_SIZE; i++) {
    sortedGrid[i] = grid[i];
  }

  fgets(input, BUFFER_SIZE, stdin);
  replaceChar(input, '\n', '\0');
  int n = strlen(input);

  createGrid(input, grid, n);
  sortGrid(sortedGrid, n);
  int newPosition = findInput(input, sortedGrid, n);
  makeCluster(sortedGrid, cluster, n);

  printf("%d\n", newPosition);
  printCluster(cluster, n);
}

/*
 * 0
 * 1 i 1 p 2 s 1 M 1 p 1 i 2 s 2 i
 * 3
 * 1 i 1 p 2 s 1 M 1 p 1 i 2 s 2 i
 *
 */

