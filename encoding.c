#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
  char letter;
  int count;
} lettercount;

void leftRotatebyOne(char arr[], int n) {   // Shifts array
  int temp = arr[0], i; 
  for (i = 0; i < n - 1; i++) 
    arr[i] = arr[i + 1]; 
  arr[i] = temp; 
}

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

void sortGrid(char arr[][BUFFER_SIZE], int n) { 
  int i, j; 
  char key[BUFFER_SIZE];
  for (i = 1; i < n; i++) { 
    strncpy(key, arr[i], n);
    j = i - 1; 

    while (j >= 0 && strncmp(arr[j], key, n) > 0) { 
      strncpy(arr[j + 1], arr[j], n);
      j = j - 1; 
    } 
    strncpy(arr[j + 1], key, n);
  } 
} 

int findInput(char input[BUFFER_SIZE], char grid[][BUFFER_SIZE], int n) {
  for (int i = 0;i < n;i++) {
    int pos = strncmp(grid[i], input, n);
    if (pos == 0) {
      return i;
    }
  }
  return -1;
}

void makeCluster(char grid[][BUFFER_SIZE], lettercount cluster[BUFFER_SIZE], int n) {
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
  char input[BUFFER_SIZE];
  lettercount cluster[BUFFER_SIZE];

  fgets(input, BUFFER_SIZE, stdin);
  replaceChar(input, '\n', '\0');
  int n = strlen(input);

  createGrid(input, grid, n);
  sortGrid(grid, n);
  int newPosition = findInput(input, grid, n);
  makeCluster(grid, cluster, n);

  printf("%d\n", newPosition);
  printCluster(cluster, n);
}

/* Mississippi */
/* 0 */
/* 1 i 1 p 2 s 1 M 1 p 1 i 2 s 2 i */
